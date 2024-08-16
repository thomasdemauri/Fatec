#include <stdio.h>
#include <math.h>

int main() {

    int number_1 = 0;
    int number_2 = 0; 

    printf("Number 1: ");
    scanf("%d", &number_1);

    printf("Number 2: ");
    scanf("%d", &number_2);

    printf("%d^%d = %.2f\n", number_1, number_2, pow(number_1, number_2));
    
    return 0;
}