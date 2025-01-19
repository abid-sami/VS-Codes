#include<stdio.h>
int main(){
    struct book{
        char title[100];
        char auth[100];
        float price;
    };
    printf("Enter amount of Books: ");
    int n,i;
    scanf("%d",&n);
    struct book b[n];
    for(i=0; i<n; i++){
        getchar();
        printf("Title: ");
        gets(b[i].title);
        printf("Author: ");
        gets(b[i].auth);
        printf("Price: ");
        scanf("%f",&b[i].price);
    }
    printf("Enter value: ");
    float val;
    scanf("%f",&val);
    printf("Title\t Author\t Price\n");
    for(i=0; i<n; i++){
        if(b[i].price>val){
        printf("%s\t %s\t %.2f\n",b[i].title,b[i].auth,b[i].price);
        }
    }

}