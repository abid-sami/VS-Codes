#include<stdio.h>
int main(){
    struct emp{
    int id;
    char name[100];
    float sal;
};
    int n, i;
    float s=0.0;
    printf("Enter amount of Employee: ");
    scanf("%d",&n);
    struct emp e[n];
    for(i=0; i<n; i++){ 
        printf("ID: ");     
        scanf("%d",&e[i].id);
        getchar();
        printf("Name: ");
        gets(e[i].name);
        printf("Salary: ");     
        scanf("%f",&e[i].sal);
        s=s+e[i].sal;
    }
    printf("Total salary: %.2f",s);

return 0;

}