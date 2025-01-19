#include <stdio.h>
int main() {
    char x[101];
    fgets(x,101,stdin);
 
    for (int i=0; x[i]!='\0'; i++) {
        char c = x[i];
        if (c>= 'A' && c<= 'Z') {
            c = c + 'a' - 'A';
        }
 
        if (c!='a' && c!= 'e' && c!='i' && c!='o' && c!='u' && c!='y') {
            printf(".%c",c);
        }
    }
 
    return 0;
}