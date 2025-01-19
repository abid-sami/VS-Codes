//Filter Books By Price
#include<stdio.h>
int main(){
    int n, i, f;
    printf("Enter amount of books: ");
    scanf("%d",&n);
    struct books{
        char title[50];
        char author[50];
        float price;
    }books[n];

    for(i=0; i<n; i++){
        printf("Enter Title: ");
        getchar();
        gets(books[i].title);
        printf("Enter Author: ");
        gets(books[i].author);
        printf("Enter Price: ");
        scanf("%f",&books[i].price);
    }
    printf("Enter Filter Price: ");
    scanf("%d",&f);
    printf("\tBooks Info\n");
    for(i=0; i<n; i++){
        if(books[i].price>f){
            printf("Title: %s\n",books[i].title);
            printf("Author: %s\n",books[i].author);
            printf("Price: %.2f",books[i].price);
        }
    }
    return 0;
}