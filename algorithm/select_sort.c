#include <stdio.h>

int main()
{
    int arr[] = {3,5,9,7,4,2,8,7};
    int len, tmp, min;
    int i, j;
    len = sizeof(arr) / sizeof(*arr);
    for(i = 0; i < len; i++) {
        min = i;
        for(j = i; j < len; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
    for(i = 0; i < len; i++)
        printf("%d", arr[i]);
    return 0;
}  

