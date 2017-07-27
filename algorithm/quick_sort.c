#include <stdio.h>
void quicksort(int *arr, int p, int r);
int partion(int *arr, int p, int r);

int main() {
  int arr[] = {3,5,9,7,4,2,8,7};
  int i, len;
  len = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0,  len - 1);
  for (i = 0; i < len; i++)
    printf("%d ", *(arr + i));
  printf("\n");
  return 0;
}

void quicksort(int *arr, int p, int r) {
  int q;
  if (p < r) {
    q = partion(arr, p, r);
    quicksort(arr, p, q - 1);
    quicksort(arr, q + 1, r);
  }
};

int partion(int *arr, int p, int r) {
  int i, j, temp;
  i = p - 1;
  for (j = p; j <= r - 1; j++) {
    if (arr[j] < arr[r]) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return i + 1;
};
