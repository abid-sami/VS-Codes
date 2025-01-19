//Swap first element with last, second to second last and so on (reversing elements) 
#include<stdio.h>
int main(){
    int n, i;
    printf("Enter the amount of the arrays:");
    scanf("%d",&n);
    int arr[n],brr[n];
    printf("Input Numbers: ");
    for(i=0; i<n; i++){ 
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++){
        brr[i]=arr[n-i-1];
    }
    printf("Reversed Array: ");
    for(i=0; i<n; i++){
        printf("%d ",brr[i]);
    }
    printf("\n");
    return 0;
}

