bst_create_test.o: bst_test.c bst.c bst.h
	gcc -g -Wall -Wextra -Werror -DBST_CREATE_TEST -c bst_test.c bst.c

bst_create_test: bst_create_test.o
	gcc -g -Wall -Wextra -Werror *.o -o ./build/Quest_1

bst_insert_test.o: bst_test.c bst.c bst.h
	gcc -g -Wall -Wextra -Werror -DBST_INSERT_TEST -c bst_test.c bst.c

bst_insert_test: bst_insert_test.o
	gcc -g -Wall -Wextra -Werror *.o -o ./build/Quest_2

bst_applyf_test.o: bst_test.c bst.c bst.h
	gcc -g -Wall -Wextra -Werror -DBST_APPLYF_TEST -c bst_test.c bst.c

bst_applyf_test: bst_applyf_test.o
	gcc -g -Wall -Wextra -Werror *.o -o ./build/Quest_3

clean:
	rm -rf *.o