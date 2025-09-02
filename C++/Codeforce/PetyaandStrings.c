#include<stdio.h>
int main(){
char s1[100],s2[100];
int i=0;
scanf("%s",&s1);
scanf("%s",&s2);
while(s1[i]!='\0' && s2[i]!='\0'){
    char ch1=s1[i] ;
    char ch2=s2[i];
   if(ch1>='A' &&  ch1<='Z'){
    ch1=ch1+32;
   }
    if(ch2>='A' && ch2<='Z') {
    ch2=ch2+32;
   }
 if(ch1<ch2) {
printf("-1\n");
return 0;
}
else if(ch1>ch2){
 printf("1\n") ;
 return 0;
}
i++;
}
printf("0\n");
return 0;
}