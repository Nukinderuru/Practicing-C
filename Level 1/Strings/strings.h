#ifndef STRINGS_H
#define STRINGS_H

#define TEST_1 ""
#define TEST_2 "\n"
#define TEST_3 "Just some test string."
#define TEST_4 "123 456 7890"
#define TEST_5 " Some other test string"
#define TEST_6 "456"
#define TEST_7 "test"
#define TEST_8 "Just some"

int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *str1, char *str2);
char *my_strcat(char *str1, char *str2);
char *my_strchr(char *str, char *ch);
char *my_strstr(char *str1, char *str2);
char *my_strtok(char *str1, char *str2);

#endif