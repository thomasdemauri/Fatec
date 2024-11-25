#include <stdio.h>

typedef struct {
    char name[20];
    int  age;
} Person;

int main() {

    Person p1 = {"Nicolas Tesla", 34};
    Person buffer;

    FILE *file = fopen("person.bin", "wb");
    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    fwrite(&p1, sizeof(Person), 1, file);

    fclose(file);

    // De proposito estou abrindo o arquivo novamente, como se fosse outro exercicio
    file = fopen("person.bin", "rb");
    if (file == NULL) {
        printf("Error.\n");
        return 2;
    }


    fread(&buffer, sizeof(Person), 1, file);

    printf("Name: %s\n", buffer.name);
    printf("Age: %d\n", buffer.age);


    return 0;
}