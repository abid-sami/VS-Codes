//A game to guess the randomly generated number
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int a,b,x,y;
    printf("Enter Range: ");
    scanf("%d %d",&a,&b);
    srand(time(NULL)); 
    x=rand()%b;

    while(1){
        printf("Guess: ");
        scanf("%d",&y);

        if(y==x){
            printf("Congratulations! You guessed the number!");
            break;
        } else if(x>y){
           printf("Low\n");
        } else {
            printf("High\n");
        }      
    }
    return 0;
    
}