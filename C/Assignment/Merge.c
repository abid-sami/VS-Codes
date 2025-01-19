#include <stdio.h>
void merge(char m[], char a[], char b[]){
    int i,j;
    for (i=0; a[i]!='\0'; i++){
        m[i] = a[i];
    }
    for(j=0; b[j]!='\0'; j++){
        m[i+j]=b[j];
    }
    m[i+j]='\0';
}

int main(){
    char a[100],b[100],m[200];
    int i,j;
    printf("Enter First String: ");
    gets(a);
    printf("Enter Second String: ");
    gets(b);
    merge(m,a,b);
    printf("Merge Result: %s",m);
    return 0;
}
