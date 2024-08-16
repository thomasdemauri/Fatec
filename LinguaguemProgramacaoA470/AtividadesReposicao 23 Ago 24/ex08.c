#include <stdio.h>
#include <math.h>

int main() {

    float celsius, fahrenheit = 0;

    printf("Graus celsius: ");
    scanf("%d", &celsius);
    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f graus celsius para fahrenheit = %.2f graus fahrenheit", celsius, fahrenheit);
    
    return 0;
}