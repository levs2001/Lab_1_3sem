#define _CRT_SECURE_NO_WARNINGS

#include "listInit.h"
#include<stdio.h>
#include <string.h>

typedef struct {
  char surname[20];
  char name[20];
  char patron[20];
}SNP;

//static myList* Last;

void PrintList(myList *man)
{
  while (man->next != NULL)
  {
    printf("%s\n", man->surname);
    man = man->next;
  }
}

int main(void) {
  myList* start = NULL;
  FILE* file = NULL;
  char buf[20];
  char* word;
  file = fopen("manList.txt", "r");

  if (file == NULL)
    printf("The file manList wasn't open");
  start = InitList();
  fscanf(file, "%s", buf);
  while (!feof(file)) {
    word = (char*)malloc(strlen(buf)+1);
    strcpy(word, buf);
    Add2List(start, word, "test", "test");
    fscanf(file, "%s", buf);
  }
  
  PrintList(start);
  return 0;
}
