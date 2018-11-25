/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:06:05 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/17 11:18:29 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <float.h>

/*
#include <stdint.h>
 #include <stdio.h>
 
    typedef union
    {
      double value;
      struct
      {
        uint32_t lsw;
        uint32_t msw;
      } parts;
      uint64_t word;
    } ieee_double_shape_type;
    
    # define EXTRACT_WORDS64(i,d)                                        \
    do {                                                                \
      ieee_double_shape_type gh_u;                                        \
      gh_u.value = (d);                                                \
      (i) = gh_u.word;                                                \
    } while (0)
    
    # define INSERT_WORDS64(d,i)                                        \
    do {                                                                \
      ieee_double_shape_type iw_u;                                        \
      iw_u.word = (i);                                                \
      (d) = iw_u.value;                                                \
    } while (0)
    
    double
    ft_modf(double x, double *iptr)
    {
            int64_t i0;
            int32_t j0;
            EXTRACT_WORDS64(i0,x);
            j0 = ((i0>>52)&0x7ff)-0x3ff;        // exponent of x 
            if(j0<52) {                        // integer part in x 
                if(j0<0) {                        // |x|<1 
                    //iptr = +-0 
                    INSERT_WORDS64(*iptr,i0&UINT64_C(0x8000000000000000));
                    return x;
                } else {
                    uint64_t i = UINT64_C(0x000fffffffffffff)>>j0;
                    if((i0&i)==0) {                // x is integral 
                        *iptr = x;
                        // return +-0 
                        INSERT_WORDS64(x,i0&UINT64_C(0x8000000000000000));
                        return x;
                    } else {
                        INSERT_WORDS64(*iptr,i0&(~i));
                        return x - *iptr;
                    }
                }
            } else { // no fraction part 
                *iptr = x;
                //We must handle NaNs separately.  
                if (j0 == 0x400 && (i0 & UINT64_C(0xfffffffffffff)))
                  return x;
                INSERT_WORDS64(x,i0&UINT64_C(0x8000000000000000));        // return +-0 
                return x;
            }
    }*/

/*
int main()
{
   double k1 = -1E308;
   double k2 = -1E43;
   double l1;
   double l2;
  
  printf("%f \n%.8f \n", k1, k2);
  
  k1 = ft_modf(-k1, (double *)&l1);
 k2 = ft_modf(-k2, (double *)&l2);
  printf ("%f %f\n", k1, l1);
  printf( "%.8f %f", k2, l2);


  return 0;
    
}

*/


#include <math.h>


int        main(void)
{
    char *s = "|toto%+.0d et %+i et   !!!|";
//    double f1 = 9.56;
 //   double f2;
  //  char ret = '2';
  //  int		tret = 122;
 //   double ld = 31.0;
  //  long double        d = -ld; //4321.234567890123456789012345678901;
  //  float         f = ld ; // 4321.234567890123456789012345678901;

//	printf("%+f %d\n",f1,	 10.0 > modf(f1, &f2));
 
    printf("\n%d\n", printf(s, 0, 13));
	printf("\n%d\n", ft_printf(s, 0, 13));
    return (0);
}


/*

TEST : toto%+.0d et %+.i et   !!!, 0, 0
ft_printf  --> toto et  et 
ret = 18
printf     --> toto et + et 
ret = 19
[KO]


TEST : coco et %-#-#--24O titi%#012o, 12, -874
ft_printf  --> coco et O                        titi000000000014
ret = 49
printf     --> coco et 014                      titi037777776226
ret = 49
[KO]


*/