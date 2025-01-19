//Store and display information of multiple students
#include<stdio.h>
int main(){
    struct student{
        char name[100];
        int roll;
        float mark;
    }st1;
    printf("Enter Name: ");
    gets(st1.name);
    printf("Enter Roll: ");
    scanf("%d",&st1.roll);
    printf("Enter Mark: ");
    scanf("%f",&st1.mark);

    printf("\tStudent Info\n");
    printf("Name: %s\n",st1.name);
    printf("Roll: %d\n",st1.roll);
    printf("Mark: %f\n",st1.mark);
    return 0;
}