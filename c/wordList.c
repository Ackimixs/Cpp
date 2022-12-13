
#include "wordList.h"
#define boolToString(b) (b ? "true" : "false")


WordList *newWordList() {
    WordList *list = malloc(sizeof(WordList));
    if (list == NULL) {
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addWordToList(WordList *list, char *word) {
    Word *newWord = malloc(sizeof(Word));
    if (newWord == NULL) {
        exit(1);
    }
    char* wordCopy = malloc(sizeof(char) * (strlen(word) + 1));
    if (wordCopy == NULL) {
        exit(1);
    }
    strcpy(wordCopy, word);
    newWord->word = wordCopy;
    newWord->next = NULL;

    if (!list->tail) {
        list->head = newWord;
        list->tail = newWord;
        newWord->previous = NULL;
    } else {
        list->tail->next = newWord;
        newWord->previous = list->tail;
        list->tail = newWord;
    }

    list->size++;
}

void printWordList(WordList *list) {
    Word *temp = list->head;
    for (int i = 0; i < getNbWords(list); i++) {
        printf("Word %d : %s\n",i, temp->word);
        temp = temp->next;
    }
}

unsigned int getNbWords(WordList *list) {
    return list->size;
}

void deleteWordList(WordList *list) {
    Word *temp = list->head;
    Word *next;
    while (temp) {
        next = temp->next;
        free(temp->word);
        free(temp);
        temp = next;
    }
    free(list);
}

bool containsWord(WordList *list, char *word) {
    Word *temp = list->head;
    for (int i = 0; i < getNbWords(list); i++) {
        if (strcmp(temp->word, word) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void fillFromFile(WordList* wordList, char* fileName) {
    FILE* file = fopen(fileName, "r");
    char* word = malloc(sizeof(char) * 100);
    while (fscanf(file, "%s", word) != EOF) {
        addWordToList(wordList, word);
    }
    free(word);
    fclose(file);
}

bool baseTesting() {
    WordList* wordList = newWordList();
    printf("%d\n", getNbWords(wordList));
    printWordList(wordList);
    addWordToList(wordList, "foo");
    addWordToList(wordList, "bar");
    printf("%d\n", getNbWords(wordList));
    printWordList(wordList);
    printf("%s\n", boolToString(containsWord(wordList, "foo")) );
    printf("%s\n", boolToString(containsWord(wordList, "bar")) );
    printf("%s\n", boolToString(containsWord(wordList, "baz")) );
    deleteWordList(wordList);
    return true;
}

void testFile() {
    WordList* wordList = newWordList();
    fillFromFile(wordList, "bigWordList.txt");
    //printWordList(wordList);
    deleteWordList(wordList);
}