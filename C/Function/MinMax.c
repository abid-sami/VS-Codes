//Finding Minimum & Maximum Number
#include<stdio.h>
int fmax(int num[],int n){
    int max=num[0];
    for(int i=0; i<n; i++){
        if(max<num[i]){
            max=num[i];
        }
    }
    return max;
}

int fmin(int num[],int n){
    int min=num[0];
    for(int i=0; i<n; i++){
        if(min>num[i]){
            min=num[i];
        }
    }
    return min;
}

int main(){
    int n;
    printf("Input Amount of arrays:");
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++){
        printf("Input Elements:");
        scanf("%d",&num[i]);
    }
    int max=fmax(num,n);
    int min=fmin(num,n);
    printf("Maximum value:%d\n",max);
    printf("Minimum value:%d\n",min);
    return 0;
}
