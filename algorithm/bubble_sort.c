#include <stdio.h>

int main()
{
    int arr[] = {3, 5, 9, 7, 4, 2, 8, 7};
    int i, j, len, tmp;
    len = sizeof(arr) / sizeof(*arr);
    for(i = 0; i < len; i++) {
        for(j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    for(i = 0; i < len; i++)
        printf("%d", arr[i]);
    return 0;
}  

