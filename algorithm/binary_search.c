#include <stdio.h>

int binary_search(int *arr, int x, int length);

int main() {
  int arr[] = {1,2,3,4,5};
  printf("index = %d\n", binary_search(arr, 5, sizeof(arr)/ sizeof(arr[0])));
  printf("index = %d\n", binary_search(arr, 6, sizeof(arr)/ sizeof(arr[0])));
  return 0;
}

int binary_search(int *arr, int x, int length) {
  int low, mid, high;
  low = 0;
  high = length - 1;
  while(low <= high) {
    mid = (low + high) / 2;
    if(arr[mid] < x)
      low = mid + 1;
    else if(arr[mid] > x)
      high = mid - 1;
    else
      return mid;
  }
  return -1;
}
