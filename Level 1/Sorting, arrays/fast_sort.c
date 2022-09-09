#include <stdio.h>
#define N_MAX 10

int input(int *data) {
    int status = 0;
    for (int i = 0; i < N_MAX; i++) {
        status += scanf("%d", &data[i]);
    }
    if (status != N_MAX) {
        printf("n/a");
        return 1;
    }
    char c = getchar();
    if (c != '\n') {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *data) {
    for (int i = 0; i < N_MAX - 1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d", data[N_MAX - 1]);
}

void heapify(int *data, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && data[l] > data[largest])
        largest = l;
    if (r < n && data[r] > data[largest])
        largest = r;
    if (largest != i) {
        int temp = data[i];
        data[i] = data[largest];
        data[largest] = temp;
        heapify(data, n, largest);
    }
}

void heap_sort(int *data, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(data, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        heapify(data, i, 0);
    }
}

void quick_sort(int *data, int left, int right) {
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = data[left];
    while (left < right) {
        while ((data[right] >= pivot) && (left < right))
            right--;
        if (left != right) {
            data[left] = data[right];
            left++;
        }
        while ((data[left] <= pivot) && (left < right))
            left++;
        if (left != right) {
            data[right] = data[left];
            right--;
        }
    }
    data[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quick_sort(data, left, pivot - 1);
    if (right > pivot)
        quick_sort(data, pivot + 1, right);
}

int main() {
    int data[N_MAX];
    if (input(data) != 1) {
        int n = sizeof(data) / sizeof(data[0]);
        heap_sort(data, n);
        output(data);
        printf("\n");
        quick_sort(data, 0, N_MAX - 1);
        output(data);
    }
    return 0;
}
