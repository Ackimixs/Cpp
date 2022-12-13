
#include "cesar.h"

char shiftCharacter(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        c = c + shift;
        if (c > 'Z') {
            c = c - 26;
        } else if (c < 'A') {
            c = c + 26;
        }
    } else if (c >= 'a' && c <= 'z') {
        c = c + shift;
        if (c > 'z') {
            c = c - 26;
        } else if (c < 'a') {
            c = c + 26;
        }
    }
    return c;
}

void shiftString(char* string, char* shiftedString, int shift) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            shiftedString[i] = shiftCharacter(string[i], shift);
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            shiftedString[i] = shiftCharacter(string[i], shift);
        }
        i++;
    }
    shiftedString[i] = '\0';
}

void loopOnKeys(char* encryptedText) {
    for (int i = 0; i < 26; i++) {
        char *d = malloc(sizeof(char) * 100);
        shiftString(encryptedText, d, -i);
        printf("key : %d -> %s\n",i, d);
        free(d);
    }
}

int searchKey(char* encryptedText, WordList* wordList) {
    int key = -1;
    for (int i = 0; i < 26; i++) {
        char *d = malloc(sizeof(char) * 100);
        shiftString(encryptedText, d, -i);
        if (containsWord(wordList, d)) {
            key = i;
        }
        free(d);
    }
    return key;
}

double computeMatching(WordList* decryptedWords, WordList* referenceWords) {
    double matching = 0;
    Word *temp = decryptedWords->head;
    for (int i = 0; i < getNbWords(decryptedWords); i++) {
        if (containsWord(referenceWords, temp->word)) {
            matching++;
        }
        temp = temp->next;
    }
    return (matching / getNbWords(decryptedWords))*100;
}

WordList* cutSpaceString(char str[]) {
    char *word = strtok(str, " ");
    WordList *list = newWordList();
    while (word != NULL) {
        addWordToList(list, upCaseString(word));
        word = strtok(NULL, " ");
    }
    return list;
}

char* upCaseString(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i];
        }
        else {
            string[i] = ' ';
        }
        i++;
    }
    return string;
}

void decryptAll(char* string) {
    WordList* wordList = newWordList();
    fillFromFile(wordList, "bigWordList.txt");

    WordList* cutList = cutSpaceString(string);

    int key = searchKey(cutList->head->word, wordList);

    WordList* decryptedList = newWordList();
    Word *temp = cutList->head;

    for (int i = 0; i < getNbWords(cutList); i++) {
        char *d = malloc(sizeof(char) * 100);
        shiftString(temp->word, d, -key);
        addWordToList(decryptedList, d);
        temp = temp->next;
        free(d);
    }

    double percentage = computeMatching(decryptedList, wordList);

    if (percentage > 70) {
        printf("The key is %d and the percentage is %f\n", key, percentage);
    } else {
        printf("The key is not found\n");
    }

    printSentenceFromWordList(decryptedList);

    deleteWordList(wordList);
    deleteWordList(cutList);
    deleteWordList(decryptedList);
}

void printSentenceFromWordList(WordList* wordList) {
    Word *temp = wordList->head;
    for (int i = 0; i < getNbWords(wordList); i++) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
}