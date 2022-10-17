#include <stdio.h>
#include "strings.h"

void my_strlen_tests() {
    int result;
    puts("Tests for strlen:");
    puts("========================");
    result = my_strlen(TEST_1);
    printf("input: %s\nresult: %d\n", TEST_1, result);
    if (result == 0) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strlen(TEST_2);
    printf("input: %s\nresult: %d\n", TEST_2, result);
    if (result == 1) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strlen(TEST_3);
    printf("input: %s\nresult: %d\n", TEST_3, result);
    if (result == 22) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strlen(TEST_4);
    printf("input: %s\nresult: %d\n", TEST_4, result);
    if (result == 12) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strlen(TEST_5);
    printf("input: %s\nresult: %d\n", TEST_5, result);
    if (result == 23) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

void my_strcmp_tests() {
    int result;
    puts("Tests for strcmp:");
    puts("========================");
    result = my_strcmp(TEST_1, TEST_2);
    printf("input: %s, %s\nresult: %d\n", TEST_1, TEST_2, result);
    if (result == -1) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcmp(TEST_1, TEST_3);
    printf("input: %s, %s\nresult: %d\n", TEST_1, TEST_3, result);
    if (result == -1) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcmp(TEST_3, TEST_5);
    printf("input: %s, %s\nresult: %d\n", TEST_3, TEST_5, result);
    if (result == -1) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcmp(TEST_3, TEST_3);
    printf("input: %s, %s\nresult: %d\n", TEST_3, TEST_3, result);
    if (result == 0) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcmp(TEST_3, TEST_4);
    printf("input: %s, %s\nresult: %d\n", TEST_3, TEST_4, result);
    if (result == 1) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

void my_strcpy_tests() {
    puts("Tests for strcpy:");
    puts("========================");
    char test1[5] = TEST_6;
    char test2[25] = TEST_3;
    char test3[15] = TEST_4;
    char test4[2] = TEST_2;
    char test5[1] = TEST_1;
    char test6[25] = TEST_5;
    char *result = my_strcpy(test2, test1);
    printf("input: %s, %s\nresult: %s\n", TEST_3, TEST_6, test1);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcpy(test2, test3);
    printf("input: %s, %s\nresult: %s\n", TEST_3, TEST_4, test2);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strcpy(test4, test5);
    printf("input: %s, %s\nresult: %s\n", TEST_2, TEST_1, test4);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test7[25] = TEST_3;
    result = my_strcpy(test6, test7);
    printf("input: %s, %s\nresult: %s\n", TEST_5, TEST_3, test6);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

void my_strcat_tests() {
    puts("Tests for strcat:");
    puts("========================");
    char test1[45] = TEST_4;
    char test2[25] = TEST_3;
    char *result = my_strcat(test1, test2);
    printf("input: %s, %s\nresult: %s\n", TEST_4, TEST_3, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test3[15] = TEST_4;
    char test4[5] = TEST_6;
    result = my_strcat(test3, test4);
    printf("input: %s, %s\nresult: %s\n", TEST_4, TEST_6, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test5[25] = TEST_3;
    char test6[45] = TEST_4;
    result = my_strcat(test5, test6);
    printf("input: %s, %s\nresult: %s\n", TEST_3, TEST_5, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

void my_strchr_tests() {
    puts("Tests for strchr:");
    puts("========================");
    char *ch = "e";
    char *result = my_strchr(TEST_3, ch);
    printf("input: %s, %s\nresult: %s\n", TEST_3, ch, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strchr(TEST_4, ch);
    printf("input: %s, %s\nresult: %s\n", TEST_4, ch, result);
    if (result == NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strchr(TEST_1, ch);
    printf("input: %s, %s\nresult: %s\n", TEST_1, ch, result);
    if (result == NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    ch = "";
    result = my_strchr(TEST_6, ch);
    printf("input: %s, %s\nresult: %s\n", TEST_6, ch, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    ch = "\0";
    result = my_strchr(TEST_7, ch);
    printf("input: %s, %s\nresult: %s\n", TEST_7, ch, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

void my_strstr_tests() {
    puts("Tests for strstr:");
    puts("========================");
    char test0[5] = TEST_6;
    char *result = my_strstr(TEST_4, test0);
    printf("input: %s, %s\nresult: %s\n", TEST_4, test0, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result = my_strstr(TEST_3, test0);
    printf("input: %s, %s\nresult: %s\n", TEST_3, test0, result);
    if (result == NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test01[5] = TEST_1;
    result = my_strstr(TEST_1, test01);
    printf("input: %s, %s\nresult: %s\n", TEST_1, test01, result);
    if (result != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
 }

void my_strtok_tests() {
    puts("Tests for strtok:");
    puts("========================");
    char test0[2] = " ";
    char test1[30] = TEST_3;
    char *result1 = my_strtok(test1, test0);
    printf("input: %s, " "\nresult: %s\n", TEST_3, result1);
    if (result1 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result1 = my_strtok(NULL, test0);
    printf("input: %s, " "\nresult: %s\n", TEST_3, result1);
    if (result1 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result1 = my_strtok(NULL, test0);
    printf("input: %s, " "\nresult: %s\n", TEST_3, result1);
    if (result1 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result1 = my_strtok(NULL, test0);
    printf("input: %s, " "\nresult: %s\n", TEST_3, result1);
    if (result1 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result1 = my_strtok(NULL, test0);
    printf("input: %s, " "\nresult: %s\n", TEST_3, result1);
    if (result1 == NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test2[15] = TEST_4;
    char test3[5] = TEST_6;
    char *result2 = my_strtok(test2, test0);
    printf("input: %s, %s\nresult: %s\n", TEST_4, TEST_6, result2);
    if (result2 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result2 = my_strtok(NULL, test0);
    printf("input: %s, %s\nresult: %s\n", TEST_4, TEST_6, result2);
    if (result2 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result2 = my_strtok(NULL, test3);
    printf("input: %s, %s\nresult: %s\n", TEST_4, TEST_6, result2);
    if (result2 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    char test4[5] = TEST_7;
    char *result3 = my_strtok(test1, test4);
    printf("input: %s, %s\nresult: %s\n", TEST_3, TEST_7, result3);
    if (result3 != NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
    result3 = my_strtok(NULL, test4);
    printf("input: %s, %s\nresult: %s\n", TEST_3, TEST_7, result3);
    if (result3 == NULL) {
        puts("SUCCESS");
    } else {
        puts("FAIL");
    }
    puts("========================");
}

int main() {
    #ifdef MY_STRLEN_TESTS
        my_strlen_tests();
    #elif MY_STRCMP_TESTS
        my_strcmp_tests();
    #elif MY_STRCPY_TESTS
        my_strcpy_tests();
    #elif MY_STRCAT_TESTS
        my_strcat_tests();
    #elif MY_STRCHR_TESTS
        my_strchr_tests();
    #elif MY_STRSTR_TESTS
        my_strstr_tests();
    #elif MY_STRTOK_TESTS
        my_strtok_tests();
    #endif
    return 0;
}