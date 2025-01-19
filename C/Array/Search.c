//Find a number from array elements
#include<stdio.h>
int main(){
    int n, i, v, pos=-1;
    printf("Enter the amount of the array:");
    scanf("%d",&n);
    int num[n];
    printf("Enter Numbers:\n");
    for(i=0; i<n; i++){
        printf("Element %d:",i+1);
        scanf("%d",&num[i]);
    }
    printf("Enter search number:");
    scanf("%d",&v);
    for(i=0; i<n; i++){
        if(v==num[i]){
            pos=i+1;
            break;
        }
    }
    if(pos==-1){
        printf("Not found");
    }
    else{
        printf("Value is found at position %d\n",pos);
    }
    return 0;
}

