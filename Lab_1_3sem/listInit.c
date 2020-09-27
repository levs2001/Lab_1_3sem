#define _CRT_SECURE_NO_WARNINGS

#include "listInit.h"
#include <string.h>
#include <stdlib.h>

myList* InitList(void) {
  myList* nMan = (myList*)malloc(sizeof(myList));

  nMan->next = NULL;
  return nMan;
}

myList* AddMan(myList* next, myList* pMan, char* surname, char* name, char* patron) {
  myList* nMan = (myList*)malloc(sizeof(myList));
  nMan->next = next;
  pMan->next = nMan;
  EnterSNP(nMan, surname, name, patron);

  return nMan;
}

void EnterSNP(myList* man, char* surname, char* name, char* patron) {
  strcpy(man->surname, surname);
  strcpy(man->name, name);
  strcpy(man->patron, patron);
}

myList* Add2List(myList* start, char* surname, char* name, char* patron) {
  myList* OfList = start;
  myList* nMan = NULL;
  myList* pMan = NULL;
  int pointer = 0;

  //Здесь надо по очереди сравнивать каждую букву фамилии, если совпадают, то каждую букву имени и т.д.
  OfList = start;

  do {

    for (pointer = 0; pointer < isize; pointer++) {
      if (surname[pointer] != OfList->surname[pointer])
        break;
    }

    if (surname[pointer] < OfList->surname[pointer]) {
      nMan = AddMan(OfList, pMan, surname, name, patron);
      break;
    }
    else if (surname[pointer] > OfList->surname[pointer]) {
      if (OfList->next != NULL) {
        pMan->next = OfList;
        OfList = OfList->next;
      }
      else {
        nMan = AddMan(NULL, pMan, surname, name, patron);
      }
    }
    else {
      //Бежим по имени и отчеству уже раз фамилии полностью совпали
    }
  } while (OfList->next != NULL);

  //if (Oflist == )
    /*while (strcmp(OfList, surname))
      OfList = OfList->next;

    if (OfList != Last) {

    }

    nMan = (myList*)malloc(sizeof(myList));
    nMan->next = OfList;
    EnterSNP(nMan, surname, name, patron);
  */


  return nMan;
}
