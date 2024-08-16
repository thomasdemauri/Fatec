#include <stdio.h>
#include <math.h>

int main() {

    float length, width, area = 0;

    printf("Length (meters): ");
    scanf("%f", &length);

    printf("Width (meters): ");
    scanf("%f", &width);

    area = length * width;

    printf("Length: %.2f\nWidth: %.2f\nArea: %.2f m²\n", length, width, area);
    
    return 0;
}