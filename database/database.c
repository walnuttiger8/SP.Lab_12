#include <stdio.h>
#include <stdlib.h>
#include "database.h"

const char counterFilename[] = "db_counter.txt";
const char filename[] = "db.db";

int getCounter() {
    FILE *f;
    int counter;

    if (fopen_s(&f, counterFilename, "r")) {
        printf("Error opening file '%s'", counterFilename);
        return 0;
    }

    fscanf_s(f, "%d", &counter);

    fclose(f);

    return counter;

}

int setCounter(int counter) {
    FILE *f;

    if (fopen_s(&f, counterFilename, "w")) {
        printf("Error opening file '%s'", counterFilename);
        return 0;
    }

    fprintf(f, "%d", counter);
    fclose(f);
    return 1;
}


void incCounter() {
    int counter;

    counter = getCounter();
    counter++;
    setCounter(counter);
}


int insert(struct Book *book) {
    FILE *f;

    if (fopen_s(&f, filename, "a")) {
        printf("Error opening file '%s'", filename);
        return 0;
    }

    fwrite(book, sizeof(struct Book), 1, f);
    fclose(f);

    incCounter();

    return 1;
}


int truncate() {
    FILE *f;

    if (fopen_s(&f, filename, "wb")) {
        printf("Error opening file '%s'", filename);
        return 0;
    }

    fclose(f);

    setCounter(0);
    return 1;
}


struct Book *get(int *n) {
    FILE *f;
    *n = getCounter();
    struct Book *books;

    if (fopen_s(&f, filename, "rb")) {
        printf("Error opening file '%s'", filename);
        return 0;
    }

    books = calloc(*n, sizeof(struct Book));

    fread(books, sizeof(struct Book), *n, f);
    fclose(f);

    return books;
}
