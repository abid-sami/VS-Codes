//Generate Pythagorean Triplets 
#include<stdio.h>
int main(){
    int a,b,c,i,f;
    printf("Enter Initial & Final value: ");
    scanf("%d %d",&i,&f);
    for(a=i; a<=f; a++){
        for(b=i; b<=f; b++){
            for(c=i; c<=f; c++){
                if(a*a+b*b==c*c){
                    printf("%d, %d, %d\n",a,b,c);
                }
            }
        }
    }
    return 0;
}