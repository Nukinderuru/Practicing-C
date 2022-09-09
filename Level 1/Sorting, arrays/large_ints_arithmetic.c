#include <stdio.h>
#include <math.h>
#define LEN 100

void input(int *buff1, int *len1, int *buff2, int *len2) {
  char c = getchar();
  int l1 = 0, l2 = 0;
  while (c != '\n') {
    if (c != ' ' && c >= 48 && c <= 57) {
      buff1[l1] = c - 48;
      l1++;
    }
    c = getchar();
  }
  *len1 = l1;
  c = getchar();
    while (c != '\n') {
      if (c != ' ' && c >= 48 && c <= 57) {
        buff2[l2] = c - 48;
        l2++;
      }
      c = getchar();
  }
  *len2 = l2;
}

void output(int *result, int result_length) {
  int flag = 0;
  for (int i = 0; i < result_length; i++) {
    if ((result[i] == 0 && flag != 0) || result[i] != 0)
    printf("%d", (int)result[i]);
    if (result[i] != 0) {
      flag = 1;
    }
  }
}

void to_even_length(int len1, int *buff2, int len2) {
  int temp[len2];
  if (len1 < len2) {
    printf("n/a");
  } else if (len1 > len2) {
    for (int i = 0; i < len2; i++) {
      temp[i] = buff2[i];
    }
    for (int i = 0; i < len1 - len2; i++) {
      buff2[i] = 0;
    }
    for (int i = len1 - len2; i < len1; i++) {
      buff2[i] = temp[i - len1 + len2];
    }
  }
}

void sum(int *buff1, int len1, int *buff2, int *result, int *result_length) {
  int dec = 0, r = 0;
  for (int i = len1 - 1; i >= 0; i--) {
    if (dec == 1) {
      result[i] = buff1[i] + buff2[i] + 1;
    } else {
      result[i] = buff1[i] + buff2[i];
    }
    if (result[i] > 9 && i != 0) {
      dec = 1;
      result[i] -= 10;
    } else  if (result[i] > 9 && buff1[0]) {
      result[len1] = 0;
    } else {
      dec = 0;
    }
    r++;
  }
  *result_length = r;
}

int sub(int *buff1, int len1, int *buff2, int *result, int *result_length) {
  int m = 0, r = 0;
  for (int i = len1 - 1; i >= 0; i--) {
    if (m == 1) {
      buff1[i]--;
    }
    if (buff1[i] < buff2[i] && i != 0) {
      result[i] = 10 + buff1[i] - buff2[i];
      m = 1;
    } else if (buff1[i] < buff2[i] && i == 0) {
      printf("n/a");
      return 1;
    } else {
      result[i] = buff1[i] - buff2[i];
      m = 0;
    }
    r++;
  }
  *result_length = r;
  return 0;
}

int main() {
  int len1 = 0, len2 = 0, result_length = 0, \
  buff1[LEN], buff2[LEN], result[LEN];
  input(buff1, &len1, buff2, &len2);
  if (len2 > len1) {
    printf("n/a");
    return 1;
  }
  to_even_length(len1, buff2, len2);
  sum(buff1, len1, buff2, result, &result_length);
  output(result, result_length);
  printf("\n");
  if (sub(buff1, len1, buff2, result, &result_length) != 1) {
    output(result, result_length);
  }
  return 0;
}
