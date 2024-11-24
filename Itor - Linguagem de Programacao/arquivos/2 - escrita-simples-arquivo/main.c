#include <stdio.h>
#include <string.h>

#define FILENAME "blog.txt"

typedef struct {
    char title[50];
    char body[200];
    int  year;
} Post;


int main() {

    Post posts[3];

    FILE *file = fopen(FILENAME, "w");
    
    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    for (int i=0; i<3; i++) {
        printf("Title: ");
        fgets(posts[i].title, sizeof(posts[i].title), stdin);
        strtok(posts[i].title, "\n");
        setbuf(stdin, NULL);

        printf("Post: ");
        fgets(posts[i].body, sizeof(posts[i].body), stdin);
        strtok(posts[i].body, "\n");
        setbuf(stdin, NULL);

        printf("Year: ");
        scanf("%d", &posts[i].year);
        setbuf(stdin, NULL);
    }

    fprintf(file, "Title, Body, Year\n");
    for (int i=0; i<3;i++) {
        fprintf(file, "%s,", posts[i].title);
        fprintf(file, "%s,", posts[i].body);
        fprintf(file, "%d\n", posts[i].year);
    }

    fclose(file);

    return 0;
}