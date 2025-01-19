//Student Grade Calculator
#include<stdio.h>
struct grade{
    char name[30];
    int id;
    float mark;
};
void gr(float x){
    if(x>=0 && x<40){
        printf("Grade: F");
    }
    else if (x>=40 && x<=44){
        printf("Grade: D");
    }
    else if (x>=45 && x<=49){
        printf("Grade: C");
    }
    else if (x>=50 && x<=54){
        printf("Grade: C+");
    }
    else if (x>=55 && x<=59){
        printf("Grade: B-");
    }
    else if (x>=60 && x<=64){
        printf("Grade: B");
    }
    else if (x>=65 && x<=69){
        printf("Grade: B+");
    }
    else if (x>=70 && x<=74){
        printf("Grade: A-");
    }
    else if (x>=75 && x<=79){
        printf("Grade: A");
    }else if (x>=80 && x<=100){
        printf("Grade: A+");
    }
    else{
        printf("Error!");
    }
}

int main(){
    int n,i;
    printf("Enter Students Amount: ");
    scanf("%d",&n);
    struct grade g[n];
    for(i=0; i<n; i++){
        printf("Enter Name: ");
        getchar();
        gets(g[i].name);
        printf("Enter ID: ");
        scanf("%d",&g[i].id);
        printf("Enter Mark: ");
        scanf("%f",&g[i].mark);
    }
    printf("\tStudent Info\n");
    for(i=0; i<n; i++){
        printf("Name: %s\n",g[i].name);
        printf("ID: %d\n",g[i].id);
        printf("Mark: %.2f\n",g[i].mark);
        gr(g[i].mark);
    }
    
}