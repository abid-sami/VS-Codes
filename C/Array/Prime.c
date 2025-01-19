//Check Prime Number
#include<stdio.h>
int main(){
    int m,n,i,j,f;
    printf("Enter the amount of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Numbers(without 1):\n");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++){
        m=a[i];
        f=0;
        for(j=2; j<m; j++){
            if(m%j==0){
                f=1;
                break;
            }
        }
        if(f==0)
            printf("%d is Prime Number\n",m);
    }
    return 0;
}
