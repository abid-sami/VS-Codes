#include<stdio.h>

int strlen(char str[])//CSE
{
    int length = 0;
    for(int i=0;str[i]!='\0';i++)
    {
        ++length;
    }
    return length;

}
int main()
{
    char a[1000];
    gets(a);//string input--- CSE
    puts(a);// string output
    printf("Length = %d\n",strlen(a));

    return 0;
}
