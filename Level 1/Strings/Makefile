my_strings.o: strings.h strings.c
	gcc -Wall -Wextra -Werror -c strings.c

my_strlen_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRLEN_TESTS -c strings_tests.c

my_strlen_tests: my_strings.o my_strlen_tests.o
	gcc *.o -o ./build/Test_1

my_strcmp_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRCMP_TESTS -c strings_tests.c

my_strcmp_tests: my_strings.o my_strcmp_tests.o
	gcc *.o -o ./build/Test_2

my_strcpy_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRCPY_TESTS -c strings_tests.c

my_strcpy_tests: my_strings.o my_strcpy_tests.o
	gcc *.o -o ./build/Test_3

my_strcat_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRCAT_TESTS -c strings_tests.c

my_strcat_tests: my_strings.o my_strcat_tests.o
	gcc *.o -o ./build/Test_4

my_strchr_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRCHR_TESTS -c strings_tests.c

my_strchr_tests: my_strings.o my_strchr_tests.o
	gcc *.o -o ./build/Test_5

my_strstr_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRSTR_TESTS -c strings_tests.c

my_strstr_tests: my_strings.o my_strstr_tests.o
	gcc *.o -o ./build/Test_6

my_strtok_tests.o: strings_tests.c
	gcc -Wall -Wextra -Werror -DMY_STRTOK_TESTS -c strings_tests.c

my_strtok_tests: my_strings.o my_strtok_tests.o
	gcc *.o -o ./build/Test_7

clean:
	rm -rf *.o