#include <stdio.h>
#define N_MAX 10

int input(int *buffer, int *length) {
  if (scanf("%d", length) != 1) {
    printf("n/a");
    return 1;
  }
  char c = getchar();
  if (c != '\n') {
    printf("n/a");
    return 1;
  }
  int status = 0;
  for (int i = 0; i < *length; i++) {
    status += scanf("%d", &buffer[i]);
  }
  if (status != *length) {
    printf("n/a");
    return 1;
  }
  c = getchar();
  if (c != '\n') {
    printf("n/a");
    return 1;
  }
    return 0;
}

void output(int *buffer, int length) {
  for (int i = 0; i < length - 1; i++) {
    printf("%d ", buffer[i]);
  }
  printf("%d", buffer[length - 1]);
}

int sum_numbers(int *buffer, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum += buffer[i];
    }
  }
    return sum;
}

int find_numbers(int* buffer, int length, int number, int* numbers) {
  int j = 0;
  for (int i = 0; i < length; i++) {
    if ((buffer[i]!= 0) && (number % buffer[i] == 0)) {
      numbers[j] = buffer[i];
      j++;
    }
  }
    return j;
}

int main() {
  int length, buffer[N_MAX];
  if (input(buffer, &length) != 1) {
    int sum = sum_numbers(buffer, length);
    if (sum != 0) {
      printf("%d\n", sum);
    } else {
      printf("n/a");
      return 1;
    }
    int numbers[length];
    int new_length = find_numbers(buffer, length, sum, numbers);
    output(numbers, new_length);
  }
    return 0;
}
