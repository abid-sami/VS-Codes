#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[7];
    gets(a);
    puts(a);

    int i,n = strlen(a);

    char item;
    int loc=0;
    scanf("%c",&item);
    for(i=0;i<n;i++)
    {
        if(item==a[i])
        {
            printf("%c found at location %d\n",item,i);
            loc=1;
        }
    }
    if(loc==0)
    {
        printf("\nNot Found");
    }
    return 0;
}
