//Search String
#include<stdio.h>
int main(){
    int i, pos=-1;
    char str[100],s;
    printf("Enter String: ");
    gets(str);
    printf("Enter Search: ");
    scanf("%c",&s);
    for(i=0; str[i]!='\0'; i++){
        if(s==str[i]) {
            pos=i+1;
            break;
        }
    }
    if(pos==-1){
        printf("Not Found");
    }else{
        printf("Found at %d",pos);
    }
    return 0;
}
