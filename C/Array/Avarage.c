//Sum & Avarage
#include<stdio.h>
int main (){
    int n, i, sum = 0;
    printf("Enter amount of numbers: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter numbers: ");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++){
        sum=sum+a[i];
    }
        printf("Sum= %d\n",sum);
        printf("Avarage= %.2f",(float)sum/n);

return 0;
}