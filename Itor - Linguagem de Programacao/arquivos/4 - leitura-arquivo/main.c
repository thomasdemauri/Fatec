#include <stdio.h>

#define FILENAME "../2 - escrita-simples-arquivo/blog.txt"
#define MAX 5

typedef struct {
    char title[50];
    char body[200];
    int  year;
} Post;

int main() {

    FILE *file = fopen(FILENAME, "r");
    Post posts[MAX];
    int index = 0;

    char buffer[256];

    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    fgets(buffer, sizeof(buffer), file);

    while (fscanf(file, "%[^,],%[^,],%d\n", posts[index].title, posts[index].body, &posts[index].year) == 3) {
        index++;
    }

    for (int i=0; i<index; i++) {
        printf("Title: %s\nBody: %s\nYear:%d\n", posts[i].title, posts[i].body, posts[i].year);
        printf("\n");
    }

    fclose(file);
    
    return 0;
}