ldapsearch -x uid="z*" | grep cn: | cut -d ' ' -f 2 -f 3 | sort -r -f
