#include <stdio.h>
#include <math.h>

int main() {

    int yearBirth, currentAge;

    printf("Enter your birth year: ");
    scanf("%d", &yearBirth);

    currentAge = 2024 - yearBirth;

    printf("Age: %d", currentAge);
    
    return 0;
}