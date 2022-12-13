#include "wordList.h"

#ifndef UNTITLED_CESAR_H
#define UNTITLED_CESAR_H

char shiftCharacter(char c, int shift);
void shiftString(char* string, char* shiftedString, int shift);
void loopOnKeys(char* encryptedText);
int searchKey(char* encryptedText, WordList* wordList);
double computeMatching(WordList* decryptedWords, WordList* referenceWords);

WordList* cutSpaceString(char *string);
char* upCaseString(char *string);
void decryptAll(char* string);
void printSentenceFromWordList(WordList* wordList);
#endif //UNTITLED_CESAR_H
