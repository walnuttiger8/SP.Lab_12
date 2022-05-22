#include <stdio.h>
#include <string.h>
#include "database/database.h"

int main() {
    struct Book *books;
    char reader[] = "Sharipov";
    int n;

    books = get(&n);

    for (int i = 0; i < n; i++) {
        struct Book b = books[i];
        if (!strcmp(b.reader, reader)) {
            printf("Books: %s\n", b.books);
            printf("Books count: %d\n", b.booksCount);
            printf("Date issued: %s\n", b.dateIssued);
            printf("Date return: %s\n", b.dateReturn);
        }
    }
    return 0;
}
