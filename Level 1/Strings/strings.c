#include <stdio.h>
#include "strings.h"

int my_strlen(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) { continue; }
    return i;
}

int my_strcmp(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    int result = *(const unsigned char*)str1 - *(const unsigned char*)str2;
    if (result != 0) {
        result = (result > 0) ? 1 : -1;
    }
    return result;
}

char *my_strcpy(char *str1, char *str2) {
    char *ptr = str1;
    if (str1 == NULL) {
        ptr = NULL;
    } else {
        for (; (*str1 = *str2) != '\0'; ++str2, ++str1) { continue; }
    }
    return ptr;
}

char *my_strcat(char *str1, char *str2) {
    int i, j;
    char *ptr = str1;
    if (str1 == NULL) {
        ptr = NULL;
    } else {
        for (i = 0; str1[i] != '\0'; i++) { continue; }
        for (j = 0; str2[j] != '\0'; j++) {
            str1[i + j] = str2[j];
        }
        str1[i + j] = '\0';
    }
    return ptr;
}

char *my_strchr(char *str, char *ch) {
    int i = 0;
    while (str[i] && str[i] != *ch) ++i;
    return *ch == str[i] ? (char*)str + i : NULL;
}

char *my_strstr(char *str1, char *str2) {
    int m = my_strlen(str1), n = my_strlen(str2);
    if (*str2 == '\0' || n == 0) {
        return str1;
    }
    if (*str1 == '\0' || n > m) {
        return NULL;
    }
    int next[n + 1];
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int j = next[i + 1];
        while (j > 0 && str2[j] != str2[i]) {
            j = next[j];
        }
        if (j > 0 || str2[j] == str2[i]) {
            next[i + 1] = j + 1;
        }
    }
    for (int i = 0, j = 0; i < m; i++) {
        if (*(str1 + i) == *(str2 + j)) {
            if (++j == n) {
                return (str1 + i - j + 1);
            }
        } else if (j > 0) {
            j = next[j];
            i--;
        }
    }
    return NULL;
}

int my_strspn(char *str1, char *str2) {
int i, k, count = 0;
for (i = 0; str1[i] != '\0'; i++) {
    if (count != i) { break; }
    for (k = 0; str1[k] != '\0'; k++) {
        if (str1[i] == str2[k]) { count++; }
    }
}
return count;
}

int my_strcspn(char *str1, char *str2) {
	char *p, *spanp;
	char c, sc;
	for (p = str1; ;) {
		c = *p++;
		spanp = str2;
		do {
			if ((sc = *spanp++) == c) { return (p - 1 - str1); }
		} while (sc != 0);
	}
}

char *my_strtok_r(char *s, char *delim, char **save_ptr) {
    char *end;
    if (s == NULL) { s = *save_ptr; }
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    /* Scan leading delimiters.  */
    s += my_strspn (s, delim);
    if (*s == '\0') {
        *save_ptr = s;
        return NULL;
    }
    /* Find the end of the token.  */
    end = s + my_strcspn (s, delim);
    if (*end == '\0') {
        *save_ptr = end;
        return s;
    }
    /* Terminate the token and make *SAVE_PTR point past it.  */
    *end = '\0';
    *save_ptr = end + 1;
    return s;
}

char *my_strtok (char *s, char *delim) {
    static char *olds;
    return my_strtok_r (s, delim, &olds);
}