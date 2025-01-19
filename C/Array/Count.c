//Count Array elements by using sizeof() operator
#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the amount of arrays: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    int as = sizeof(array) / sizeof(array[0]);

    printf("The number of elements in the array is: %d\n", as);

    return 0;
}
