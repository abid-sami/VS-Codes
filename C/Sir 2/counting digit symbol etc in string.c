#include<stdio.h>
int main()
{
    char str[1000];
    gets(str);
    puts(str);
    int vowel=0,consonant=0,digit=0,symbol=0;
    for(int i=0;str[i];i++)
    {
        if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
        {
            if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='u'||str[i]=='o')
            {
                vowel++;
            }
            else
                consonant++;
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            digit++;
        }
        else
            symbol++;
    }
    printf("Vowel = %d\nConsonant = %d\nDigit = %d\nSymbol = %d\n",vowel,consonant,digit,symbol);


}
