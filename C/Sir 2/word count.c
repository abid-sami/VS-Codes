#include<stdio.h>
int main()
{
    char str[100];
    gets(str);
    int i,length=0,word=1;
    for(i=0;str[i];i++)
    {
        length++;
        if(str[i]==' ')
            word++;
    }
    printf("Length = %d\nWord = %d\n",length-word+1,word);
}
