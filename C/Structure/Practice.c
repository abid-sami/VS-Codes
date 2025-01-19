#include<stdio.h>
int main(){
    int n,i,b;
    printf("Enter Books Amount: ");
    scanf("%d",&n);
    
    struct book
    {
        char title[30];
        char auth[30];
        int price;
    }book[n];

    for(i=0; i<n; i++){
    printf("Enter Name: ");
    getchar();
    gets(book[i].title);
    printf("Enter Author: ");
    gets(book[i].auth);
    printf("Enter Price: ");
    scanf("%d",&book[i].price );
    }

    printf("Enter Price: ");
    scanf("%d",&b);
    if(book[i].price>b){
    for(i=0; i<n; i++){
       printf("Name: %s",book[i].title);
       printf("Author: %s",book[i].auth); 
       printf("Price: %d",book[i].price); 
        }
    }
    
}