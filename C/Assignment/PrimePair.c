//Prime number pairs, whose sum is equal to a positive even number
#include<stdio.h>
int check(int n){
    if(n<2||n%2==0){
        return 0;
    }
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    printf("N= ");
    scanf("%d",&n);
    for(int i=2; i<=n/2; i++){
        if(check(i)&&check(n-i)){
            printf("%d %d\n",i,n-i);
        }
    }
    return 0;
}
