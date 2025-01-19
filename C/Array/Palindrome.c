//Palindrome Check
#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the amount of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Numbers:\n");
    for(i=0; i<n; i++){
        printf("Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0, j=n-1; i<j; i++, j--){
        if(arr[i]!=arr[j]){
            printf("Not a Palindrome\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}
