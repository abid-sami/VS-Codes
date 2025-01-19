//Find Minimum Number using array
#include<stdio.h>
int main(){
    int n,i;
    printf("How many numbers do you want to enter: ");
    scanf("%d",&n);
    int num[n];
    for(i=0; i<n; i++){
        scanf("%d",&num[i]);
    }
    int min=num[0];
    for(i=0; i<n; i++){
        if(min>num[i]){
            min=num[i];
        }
    }
    printf("Minimum Number: %d",min);
    return 0;
}
