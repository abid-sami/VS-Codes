#include<stdio.h>
int main (){
  double n,grade6,grade7,grade8,grade9,grade10;

  printf("Enter Grade :");
  scanf("%lf", &n);

  grade6 = 35500 + .15 * 35500 + .15 * 35500 - 0.10 * 35500;
  grade7 = 29500 + .15 * 29500 + .15 * 29500 - 0.10 * 29500;
  grade8 = 26500 + .15 * 26500 + .15 * 26500 - 0.10 * 26500;
  grade9 = 22000 + .15 * 22000 + .15 * 22000 - 0.10 * 22000;
  grade10 = 16000 + .15 * 16000 + .15 * 16000 - 0.10 * 16000;

  if(n==6){
    printf("Gross Salary is %.2lf tk", grade6);
  }
  else if(n==7){
    printf("Gross Salary is %.2lf tk", grade7);
  }
  else if(n==8){
    printf("Gross Salary is %.2lf tk", grade8);
  }
  else if(n==9){
    printf("Gross Salary is %.2lf tk", grade9);
  }
  
  else{
    printf("Gross Salary is %.2lf tk", grade10);
  }

  return 0;
}