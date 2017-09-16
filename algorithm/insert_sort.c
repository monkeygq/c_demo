#include <stdio.h>

int main()
{
    int arr[] = {3,5,9,7,4,2,8,7};
    int len, tmp;
    int i, j;
    len = sizeof(arr) / sizeof(*arr);
    for(i = 0; i < len; i++) {
        tmp = arr[i];
        for(j = i - 1; j >= 0; j--) {
            if(arr[j] > tmp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = tmp;
    }
    
    for(i = 0; i < len; i++)
        printf("%d", arr[i]);
    return 0;
}  

