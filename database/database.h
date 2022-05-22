#ifndef LAB_12_11_DB_H
#define LAB_12_11_DB_H

#endif //LAB_12_11_DB_H


int getCounter();


struct Book {
    char reader[20];
    int booksCount;
    char books[64];
    char dateIssued[64];
    char dateReturn[64];
};

int insert(struct Book *book);

int truncate();

struct Book *get(int *n);
