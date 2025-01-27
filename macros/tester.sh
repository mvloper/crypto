cat <(grep -i "CHOICE" macros.c) <(grep -i "MEDIAN" macros.c) <(grep -i "ROTATE" macros.c) tester.c | gcc -xc - -Wno-pointer-to-int-cast -o test ; ./test ; echo $?
