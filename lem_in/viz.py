# Read from STDIN
import pygame


class Ant:
    def __init__(self, id, pos):
        self.id = id
        self.pos = pos

    def move(self, new_pos):
        self.pos = new_pos

class Room:
    def __init__(self, name, x, y, is_start=False, is_end=False):
        self.name = name
        self.x = x
        self.y = y
        self.conn = []
        self.is_start = is_start
        self.is_end = is_end

    def get_pos(self):
        return self.x, self.y

    def put_room(self):
        print(self.name, end='')
        if self.is_start:
            print(" [start]", end='')
        elif self.is_end:
            print(" [end]", end='')
        print(" ({}, {}): ".format(self.x, self.y), end='')
        print(self.conn)


class Lemin (object):
    def __init__(self):
        self.n = 0
        self.rooms = dict()
        self.movements = list()
        self.ants = list()
        self.start = None
        self.end = None

    def add_room(self, name, x, y, is_start=False, is_end=False):
        if name in self.rooms.keys():
            raise ValueError("Duplicate room name")
        self.rooms[name] = Room(name, int(x), int(y))
        if is_start:
            self.start = self.rooms[name]
        if is_end:
            self.end = self.rooms[name]

    def add_link(self, frm, to):
        if frm not in self.rooms.keys() or to not in self.rooms.keys() or frm == to:
            raise ValueError("Bad link", frm, to)
        self.rooms[frm].conn.append(to)
        self.rooms[to].conn.append(frm)

    def init_ants(self):
        for i in range(1, self.n + 1):
            self.ants.append(Ant(i, self.start.get_pos()))

    def put_ants(self):
        for ant in self.ants:
            print("{}: ({}, {})".format(ant.id, ant.pos[0], ant.pos[1]))

    def put_info(self):
        for k, v in self.rooms.items():
            v.put_room()

    def ants_iteration(self):
        line = self.movements.pop(0)
        ant_rooms = [x.split('-') for x in line.split()]
        print(ant_rooms)
        for id, room in ant_rooms:
            ant = self.ants[int(id[1:]) - 1]
            pos = self.rooms[room].get_pos()
            ant.move(pos)


class Viz:
    def __init__(self, lem: Lemin, width=1700, height=1300): #made smoller window width=1600, height=1600
        pygame.init()
        self.width = width
        self.height = height
        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Lem-in Viz")

        self.clock = pygame.time.Clock()
        self.lem = lem
        self.colors = self.init_colors()
        self.ant = pygame.image.load('resources/ant_small.png')
        self.normalize_room_coords()
        self.lem.init_ants()

    @staticmethod
    def init_colors():
        colors = dict()
        colors['white'] = (255, 255, 255)
        colors['red'] = (255, 0, 0)
        colors['green'] = (0, 255, 0)
        colors['blue'] = (0, 0, 255)
        colors['space_cadet'] = (29, 52, 97)
        colors['coral'] = (251, 54, 64)
        colors['peach'] = (255, 204, 102)
        colors['black'] = (0, 0, 0)
        return colors

    def normalize_room_coords(self):
        # Min-max scaling of x and y coordinate, then multiply the max width/height of the window
        x_coords = [room.x for room in self.lem.rooms.values()]
        y_coords = [room.y for room in self.lem.rooms.values()]
        x_min, x_max = min(x_coords), max(x_coords)
        y_min, y_max = min(y_coords), max(y_coords)
        for room in self.lem.rooms.values():
            room.x = 50 + int((room.x - x_min) / (x_max - x_min) * (self.width - 200))
            room.y = 50 + int((room.y - y_min) / (y_max - y_min) * (self.height - 200))

    def get_pos(self, room, adj=0):
        return room.x - adj, room.y - adj

    def draw_text(self, text, pos):
        font = pygame.font.Font('freesansbold.ttf', 15)
        text_surface = font.render(text, True, self.colors['black'])
        self.screen.blit(text_surface, pos)

    def draw_rooms(self):
        for room in self.lem.rooms.values():
            pygame.draw.circle(self.screen, self.colors['peach'], room.get_pos(), 10)
            self.draw_text(room.name, self.get_pos(room, 5))

    def draw_links(self):
        for room in self.lem.rooms.values():
            for conn in room.conn:
                to = self.lem.rooms[conn]
                pygame.draw.line(self.screen, self.colors['white'], room.get_pos(), to.get_pos(), 2)

    def draw_ants(self):
        for ant in self.lem.ants:
            self.screen.blit(self.ant, ant.pos)

    def visualize(self):
        paused = False
        running = True
        pygame.time.wait(3000)
        while running:
            self.screen.fill(self.colors['coral'])
            for event in pygame.event.get():
                if event.type == pygame.QUIT or (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
                    running = False
                elif event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                    paused = not paused
                print(event, event.type)
            if paused:
                continue
            self.draw_links()
            self.draw_rooms()
            self.draw_ants()
            if self.lem.movements:
                self.lem.ants_iteration()
            pygame.display.update()
            pygame.time.wait(500)
            self.clock.tick(60)

    def __del__(self):
        pygame.display.quit()
        pygame.quit()


def parse_input(l: Lemin):
    is_first_line = True
    is_start = False
    is_end = False
    while True:
        try:
            line = input()
        except EOFError:
            break
        if line == '##start':
            is_start = True
        elif line == '##end':
            is_end = True
        if line.startswith("#") or not len(line):
            continue
        if is_first_line:
            l.n = int(line)
            is_first_line = False
        elif line and '-' not in line: # room
            tk = [_ for _ in line.split() if _]
            if len(tk) == 3:
                l.add_room(*tk, is_start, is_end)
                if is_start:
                    is_start = False
                if is_end:
                    is_end = False
            else:
                raise ValueError("Bad room:", line)
        elif '-' in line and 'L' not in line:
            tk = [_ for _ in line.split('-') if _]
            if len(tk) == 2:
                l.add_link(*tk)
            else:
                raise ValueError("Bad coords")
        elif line.startswith('L'):
            l.movements.append(line)

if __name__ == '__main__':
    lem = Lemin()
    parse_input(lem)
    lem.put_info()
    lem.put_ants()
    if lem.n > 0 and lem.rooms and lem.movements and lem.start and lem.end:
        viz = Viz(lem)
        viz.visualize()
