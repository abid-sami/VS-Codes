 #include<stdio.h>
int square(int n);
int main(){
    int n,s;
    printf("Input Number:");
    scanf("%d",&n);
    s=square(n);
    printf("Square: %d",s);
    return 0;
}
int square(int n){

    return n*n;
}