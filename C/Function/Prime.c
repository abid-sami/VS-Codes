//Check Prime Number 
#include<stdio.h>
int prime(int n);
int main(){
    int n;
    printf("Input Number:");
    scanf("%d",&n);
    if(prime(n)){
        printf("%d is a prime number",n);
    }
    else{
        printf("%d is not a prime number",n);
    }
    return 0;
}

int prime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
