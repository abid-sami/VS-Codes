//Employee Salary Total Calculator
#include<stdio.h>
struct emp{
     int id;
     char name[30];
     float salary;
};
int main(){
    int n, i;
    float s=0;
    printf("Enter Amount of Employee: ");
    scanf("%d",&n);
    struct emp e[n];
    for(i=0; i<n; i++){
        printf("Enter ID: ");
        scanf("%d",&e[i].id);
        printf("Enter Name: ");
        getchar();
        gets(e[i].name);
        printf("Enter Salary: ");
        scanf("%f",&e[i].salary);
    }
    for(i=0; i<n; i++){
        s+=e[i].salary;
    }
    printf("\tTotal Salary Paid: %.2f",s);
}