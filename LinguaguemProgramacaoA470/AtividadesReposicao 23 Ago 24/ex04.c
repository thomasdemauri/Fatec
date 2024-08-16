#include <stdio.h>

int main() {

    int     intNumber = 0;
    float   floatNumber = 0;

    printf("Enter a int number: ");
    scanf("%d", &intNumber);

    printf("Enter a float number: ");
    scanf("%f", &floatNumber);
    
    printf("<int> number: %d", intNumber);
    printf("<float> number: %f", floatNumber);
    return 0;
}