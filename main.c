#include <stdio.h>
#include "database/database.h"

int main() {
    struct Book *books;

    books = get();

    for (int i = 0; i < getCounter(); i++) {
        struct Book b = books[i];
        printf("%s\n", b.reader);
    }
    return 0;
}
