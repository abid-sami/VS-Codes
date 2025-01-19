//Write a program to input information about students and calculate the grade of each student based on their marks. 

#include <stdio.h>
#include <string.h>

void grade(float x);

void main() {
    int i, n;

    printf("How many student info do you want to store : ");
    scanf("%d", &n);
    getchar();
    struct student{
        char name[30];
        int id;
        float marks;
    } student[n];

    for (i=0; i<n; i++){
        printf("\n---------Enter student %d Info ----------\n", i+1);

        printf("Enter student %d name : ", i+1);
        gets(student[i].name);
        printf("Enter student %d ID : ", i+1);      
        scanf("%d", &student[i].id);
        printf("Enter student %d marks : ", i+1);
        scanf("%f", &student[i].marks);
        getchar();

        
    }


      for (i=0; i<n; i++){
            printf("\n----------Book %d Info ----------\n", i+1);
            printf("Student name : %s\n", student[i].name);
            printf("Student ID : %d \n", student[i].id);
            printf("Marks :  %.2f\n ", student[i].marks);
            grade(student[i].marks);

        }
}



//function to calculate grade
void grade(float x){
    if (x>=0 && x<33)
        printf("Grade : F ");
    
    else if(x>=33 && x<40)
        printf("Grade : D ");
    
    else if(x>=40 && x<45)
        printf("Grade : D+ ");
    
    else if(x>=45 && x<50)
        printf("Grade : C ");
    
    else if(x>=50 && x<55)
        printf("Grade : B ");
    
    else if(x>=55 && x<60)
        printf("Grade : B+ ");
    
    else if(x>=60 && x<70)
        printf("Grade : A- ");

    else if(x>=70 && x<80)
        printf("Grade : A ");

    else if(x>=80 && x<=100)
        printf("Grade : A+ ");

    else 
        printf("Grade : Invalid  marks Input !!!");
}