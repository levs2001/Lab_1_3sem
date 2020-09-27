#pragma once
#define isize 20

typedef struct myList{
  struct myList* next;
  char surname[isize];
  char name[isize];
  char patron[isize];
}myList;

myList* InitList(void);
myList* AddMan(myList* next, myList* pMan, char* surname, char* name, char* patron);
void EnterSNP(myList* man, char* surname, char* name, char* patron);
myList* Add2List(myList* start, char* surname, char* name, char* patron);
