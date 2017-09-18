#include <stdio.h>

void merge(int *arr, int *tmp, int low, int mid, int high);
void merge_sort(int *arr, int *tmp, int low, int high);

int main()
{
    int arr[8] = {3, 5, 9, 7, 4, 2, 8, 7}, tmp[8], i;
    merge_sort(arr, tmp, 0, 7);
    for(i = 0; i < 8; i++)
        printf("%d", arr[i]);
    return 0;
}

void merge(int *arr, int *tmp, int low, int mid, int high) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while((i <= mid) && (j <= high)) {
        if(arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while(i <= mid)
        tmp[k++] = arr[i++];
    while(j <= high)
        tmp[k++] = arr[j++];
    for(k = low; k <= high; k++)
        arr[k] = tmp[k];
}

void merge_sort(int *arr, int *tmp, int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, tmp, low, mid);
        merge_sort(arr, tmp, mid + 1, high);
        merge(arr, tmp, low, mid, high);
    }
}

