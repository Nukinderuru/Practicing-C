door_struct: dmanager.c door_struct.h
	gcc -Wall -Werror -Wextra dmanager.c -o ./build/Quest_1

list_test: list.c list.h list_test.c door_struct.h
	gcc -Wall -Werror -Wextra list.c list_test.c -o ./build/Quest_2

stack_test: stack.c stack.h stack_test.c
	gcc -g -Wall -Werror -Wextra stack.c stack_test.c -o ./build/Quest_3

clean:
	rm -rf *.o