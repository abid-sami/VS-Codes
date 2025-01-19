#include<stdio.h>
int main(){
    int cp;
    printf("Enter Cost Price: ");
    scanf("%d",&cp);
    int sp;
    printf("Enter Selling Price: ");
    scanf("%d",&sp);
    
    if(sp>cp){
    printf("Profit");
    }
    else{
    printf("Loss");
    }

return 0;
}