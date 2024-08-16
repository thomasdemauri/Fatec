#include <stdio.h>

int main() {

    float number_1 = 0;
    float number_2 = 0;
    float result = 0;
    int option; 
    

    printf("Number 1: ");
    scanf("%f", &number_1);

    printf("Number 2: ");
    scanf("%f", &number_2);

    printf(" [1] Sum\n [2] Sub\n [3] Mul\n [4] Div\n");
    printf("Choose an option: ");

    scanf("%d", &option);

    printf("\n");

    switch (option) {
        case 1:
            result = number_1 + number_2;
            printf("Result: %f\n", result);
            break;
        
        case 2:
            result = number_1 - number_2;
            printf("Result: %f\n", result);
            break;

        case 3:
            result = number_1 * number_2;
            printf("Result: %f\n", result);
            break;

        case 4:
            result = number_1 / number_2;
            printf("Result: %f\n", result);
            break;
        
        default:
            printf("Error! Choose a valid option [1-4]\n");
            break;
    }   
    

    return 0;
}