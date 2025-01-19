//Swap Numbers
#include<stdio.h>
int swap(int a, int b) {
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf("Swap Numbers: %d %d\n",a,b);
}
int main() {
    int a,b;
    printf("Input Numbers: ");
    scanf("%d %d",&a,&b);
     
    swap(a,b);
    return 0;
}