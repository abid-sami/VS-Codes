#include <stdio.h>
int main(){
    int i, arrsize;
    int arr[1000];
    printf("Input Array");
    for(i=1; i<1000; i++){
        scanf("%d", &arr[i]);
    }
    arrsize=sizeof(arr)/sizeof(arr[0]);
    return 0;

}
