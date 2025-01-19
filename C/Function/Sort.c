//Sort Numbers ascending
#include<stdio.h>
void sort(int a[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void printArray(int a[],int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int n,i;
    printf("Enter Array Size:");
    scanf("%d",&n);
    int a[n];
    printf("Input Array Elements:");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    printf("Sorted Array:");
    printArray(a,n);
    return 0;
}
