#include <stdio.h>
#define MIN 10000
#define MAX -10000
void counting_sort(int *arr, int len) {
  int min, max;
  int i;
  min = MIN;
  max = MAX;
  for(i = 0; i < len; ++i) {
    if(arr[i] < min)
      min = arr[i];
    if(arr[i] > max)
      max = arr[i];
  }
  int ret[len], slot[max - min + 1];
  for(i = 0; i < max - min + 1; ++i)
    slot[i] = 0;
  for(i = 0; i < len; ++i)
    slot[arr[i] - min]++;
  for(i = 1; i < max - min + 1; ++i)
    slot[i] += slot[i - 1];
  for(i = 0; i < len; ++i) {
    ret[slot[arr[i] - min] - 1] = arr[i];
    slot[arr[i] - min]--;
  }
  for(i = 0; i < len; ++i)
    printf("%d ", ret[i]);
  printf("\n");
}

int main() {
  int arr[] = {2,5,3,0,2,3,0,3};
  counting_sort(arr, 8);
  int arr1[] = {2};
  counting_sort(arr1, 1);
}
