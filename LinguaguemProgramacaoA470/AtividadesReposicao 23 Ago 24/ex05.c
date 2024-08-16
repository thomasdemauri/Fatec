#include <stdio.h>

int main() {

    int number_1 = 0;
    int number_2 = 0;
    int sum, sub, mul, div;

    printf("Number 1: ");
    scanf("%d", &number_1);

    printf("Number 2: ");
    scanf("%d", &number_2);

    sum = number_1 + number_2;
    sub = number_1 - number_2;
    mul = number_1 * number_2;
    div = number_1 / number_2;

    printf("%d + %d = %d\n", number_1, number_2, sum);
    printf("%d - %d = %d\n", number_1, number_2, sub);
    printf("%d * %d = %d\n", number_1, number_2, mul);
    printf("%d / %d = %d\n", number_1, number_2, div);

    return 0;
}