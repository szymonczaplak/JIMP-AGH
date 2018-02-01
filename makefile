compile: xoxoxo_in_C_main_2.c funkcje_programu_2.c
	gcc -o xoxoxo -std=c11 -Wall -pedantic -Wextra -Werror xoxoxo_in_C_main_2.c  funkcje_programu_2.c  -I.
run: xoxoxo_in_C_main_2.c funkcje_programu_2.c
	./xoxoxo
clean: xoxoxo_in_C_main_2.c funkcje_programu_2.c
	rm xoxoxo
