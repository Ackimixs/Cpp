#include <stdio.h>
#include <malloc.h>
#include <string.h>

#ifndef TP1B_WORDLIST_H
#define TP1B_WORDLIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct word {
    char *word;
    struct word *next;
    struct word *previous;
} Word;

typedef struct {
    Word *head;
    Word *tail;
    unsigned int size;
} WordList;

WordList *newWordList();
void addWordToList(WordList *list, char *word);
void printWordList(WordList *list);
unsigned int getNbWords(WordList *list);
void deleteWordList(WordList *list);
bool containsWord(WordList *list, char *word);

void fillFromFile(WordList* wordList, char* fileName);

bool baseTesting();
void testFile();

#endif //TP1B_WORDLIST_H
