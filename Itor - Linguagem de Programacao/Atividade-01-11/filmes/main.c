#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 64  // Max of characters
#define MOV 100 // Max of movies

/**
 * Professor, devido o pouco tempo nao deu pra caprichar no projetinho...
 */

typedef struct {
    char title[LEN];
    char director[LEN];
    char category[LEN];
    unsigned short int release_year;
    unsigned short int duration;    
} Movie;

void remnewline(char *str);
void insert_movie();
int show_menu();
int show_submenu();
void show_srcmenu();
void list_all_movies();
void search_by(char *substr, int filter);


Movie movies[MOV] = {};
int last_movie = 0;        // Store the number of movies added

int main() {

    bool exit = false;

    while (!exit) {

        system("clear");
        int op = show_menu();
        
        switch (op) {
        case 1:
            insert_movie();
            break;
        case 2:
            show_srcmenu();   // submenu 
            break;
        case 0:
            exit = true;
            break;
        default:
            break;
        }

    }

    return 0;
}

/**
 * Prints the result
 */
void search_by(char *substr, int filter) {

    Movie tmp_movies[MOV];
    int count = 0;

    switch (filter) {
    case 1:
        for (int i=0; i<last_movie; i++) {
            char *ptr = strstr(movies[i].title, substr);
            if (ptr != NULL) {
                tmp_movies[count] = movies[i];
                count++;
            }
        }
        break;
    case 2:
        for (int i=0; i<last_movie; i++) {
            char *ptr = strstr(movies[i].category, substr);
            if (ptr != NULL) {
                tmp_movies[count] = movies[i];
                count++;
            }
        }
        break;
    default:
        break;
    }

    system("clear");
    printf("%-32s %-32s %-32s %-32s %-32s\n", "TITLE", "DIRECTOR", "CATEGORY", "RELEASE YEAR", "DURATION");
    for (int i=0; i<count; i++) {
        printf("%-32s %-32s %-32s %-32d %-32d\n", 
            tmp_movies[i].title, tmp_movies[i].director, tmp_movies[i].category, tmp_movies[i].release_year, tmp_movies[i].duration);  
    }

    printf("Press any key to continue...\n");
    getchar();

    return;
}

/**
 * Show search menu
 */
void show_srcmenu() {
    system("clear");
    int op = show_submenu();

    switch (op) {
    case 1:
        list_all_movies();
        break;
    case 2:
        char title[64];
        printf("[FILTER] TITLE: ");
        fgets(title, sizeof(title), stdin);
        remnewline(title);
        search_by(title, 1);
        break;
    case 3:
        char category[64];
        printf("[FILTER] CATEGORY: ");
        fgets(category, sizeof(category), stdin);
        remnewline(category);
        search_by(category, 2);
        break;
    default:
        break;
    }

    return;
}

void list_all_movies() {

    system("clear");
    printf("%-32s %-32s %-32s %-32s %-32s\n", "TITLE", "DIRECTOR", "CATEGORY", "RELEASE YEAR", "DURATION");

    for (int i=0; i<last_movie; i++) {
        printf("%-32s %-32s %-32s %-32d %-32d\n", 
            movies[i].title, movies[i].director, movies[i].category, movies[i].release_year, movies[i].duration);  
    }

    printf("Press any key to continue...\n");
    getchar();
    return;
}

int show_menu() {
    
    int op;

    do {
        system("clear");
        printf("[1] INSERT MOVIE\n");
        printf("[2] SEARCH...\n");
        printf("[0] EXIT\n");

        scanf("%d", &op);
        getchar(); // clear the buffer
    } while (op < 0 || op > 3);

    return op;
}

int show_submenu() {

    int op;
    do {
        system("clear");
        printf("[1] ALL MOVIES\n");
        printf("[2] SEARCH BY TITLE\n");
        printf("[3] SEARCH BY CATEGORY\n");
        printf("[0] << BACK\n");

        scanf("%d", &op);
        getchar(); // clear the buffer

    } while (op < 0 || op > 3);

    return op;
}

void insert_movie() {
    
    Movie movie;

    do {
        system("clear");
        printf("TITLE: ");
        fgets(movie.title, sizeof(movie.title), stdin);
        remnewline(movie.title);
        printf("DIRECTOR: ");
        fgets(movie.director, sizeof(movie.director), stdin);
        remnewline(movie.director);
        printf("CATEGORY: ");
        fgets(movie.category, sizeof(movie.category), stdin);
        remnewline(movie.category);
        printf("RELEASE YEAR: ");
        scanf("%hu", &movie.release_year);
        printf("DURATION (MIN): ");
        scanf("%hu", &movie.duration);
        getchar();
    } while (strlen(movie.title) < 4 || strlen(movie.director) < 4 || strlen(movie.category) < 4 || movie.release_year < 1900 || movie.duration < 5);

    movies[last_movie] = movie;
    last_movie++;

    return;
}

void remnewline(char *str) {

    int length = strlen(str);

    if (str[length-1] == '\n') {
        str[length-1] = '\0';
    }

    return;
}