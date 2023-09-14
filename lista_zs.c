#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gradeNode {
    char lastName[20];
    double grade;
    struct gradeNode* nextPtr;
};

typedef struct gradeNode GradeNode;
typedef GradeNode* GradeNodePtr;

void insertNode(GradeNodePtr* startPtr, const char* newLastName, double newGrade) {
    //alokacja pami�ci nowego w�z�a o typie GradeNote
    GradeNodePtr newPtr = (GradeNodePtr)malloc(sizeof(GradeNode));
    if (newPtr != NULL) {
        strcpy(newPtr->lastName, newLastName);
        newPtr->grade = newGrade;
        newPtr->nextPtr = NULL;

        //sledzenie poprzedniego wezla
        GradeNodePtr previousPtr = NULL;
        GradeNodePtr currentPtr = *startPtr;

        printf("Przed petla:\n");
        printf("previousPtr: %p, currentPtr: %p\n", (void*)previousPtr, (void*)currentPtr);
        printf("**************************\n");

        while (currentPtr != NULL && strcmp(newLastName, currentPtr->lastName) > 0) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL) {
            newPtr->nextPtr = *startPtr;
            *startPtr = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
        printf("Po petli:\n");
        printf("previousPtr: %p, currentPtr: %p\n", (void*)previousPtr, (void*)currentPtr);
        printf("---------------------------\n");
    }
    else {
        //obs�uga b��du
        fprintf(stderr, "B��d alokacji pami�ci.\n");
    }
}
void sort(GradeNodePtr* startPtr) {

    //jezeli lista jest pusta albo jednoelementowa
    if (*startPtr == NULL || (*startPtr)->nextPtr == NULL) {
        return;
    }

    GradeNodePtr sortedList = NULL;
    GradeNodePtr currentPtr = *startPtr;

    while (currentPtr != NULL) {
        GradeNodePtr nextPtr = currentPtr->nextPtr;
        insertNode(&sortedList, currentPtr->lastName, currentPtr->grade);
        currentPtr = nextPtr;
    }

    *startPtr = sortedList;
}

int main() {

    /* a) Utworzenie wska�nika prowadz�cego na pocz�tek listy o nazwie startPtr.
    Ta lista jest pusta.*/

    GradeNodePtr startPtr = NULL;

    /* b) Utworzenie  nowego  w�z�a  typu GradeNode,  do  kt�rego  prowadzi  wska�nik newPtr typu GradeNodePtr.
    Nale�y przypisa� ci�g tekstowy "Janowski" elementowi sk�adowemu lastName i warto�� 91.5 elementowi sk�adowemu
    grade. Zdefiniuj wszystkie niezb�dne deklaracje i polecenia.*/

    insertNode(&startPtr, "Jankowski", 91.5);

    /* c) Przyjmij za�o�enie, �e lista, do kt�rej prowadzi startPtr, sk�ada si� z dw�ch w�z��w
    �zawieraj� one po jednym ci�gu tekstowym "Janowski" i "Szczepaniak".
    Te w�z�y s� u�o�one w kolejno�ci alfabetycznej. Zdefiniuj polecenia niezb�dne do
    wstawienia w prawid�owej kolejno�ci w�z��w z nast�puj�cymi danymi
    dla element�w sk�adowych lastName i grade:
    "Adamczyk" 85.0
    "Taczy�ski" 73.5
    "Przybylski" 66.5
    Podczas operacji wstawiania wykorzystaj wska�niki previousPtr, currentPtr i newPtr.
    Wy�wietl warto�ci previousPtri currentPtr przed  poszczeg�lnymi  operacjami  wstawienia.
    Przyjmij za�o�enie, �e newPtr zawsze prowadzi do nowego w�z�a, kt�ry ma ju� przypisane dane.*/


    insertNode(&startPtr, "Szczepaniak", 0.0);

    //poczatkowa lista
    GradeNodePtr currentPtr = startPtr;
    while (currentPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }

    //dodawanie danych 
    insertNode(&startPtr, "Adamczyk", 85.0);
    insertNode(&startPtr, "Taczy�ski", 73.5);
    insertNode(&startPtr, "Przybylski", 66.5);

    //sortowanie listy 
    sort(&startPtr);

    //posortowana lista
    currentPtr = startPtr;
    while (currentPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }
    /* d) Utw�rz p�tl� while wy�wietlaj�c� dane poszczeg�lnych w�z��w na li�cie.
    Do poruszania si� po li�cie wykorzystaj wska�niki currentPtr.*/

    currentPtr = startPtr;
    printf("Dane poszczeg�lnych w�z��w na li�cie:\n");
    while (currentPtr != NULL) {
        printf("Nazwisko: %s, Ocena: %.2lf\n", currentPtr->lastName, currentPtr->grade);
        currentPtr = currentPtr->nextPtr;
    }

    /* e) Utw�rz p�tl� while usuwaj�c� wszystkie w�z�y na li�cie i zwalniaj�c� pami�� zaalokowan� dla poszczeg�lnych w�z��w.
    Do poruszania si� po li�cie i zwalniania pami�ci wykorzystaj wska�niki odpowiednio currentPtr i tempPtr.*/

    currentPtr = startPtr;
    while (currentPtr != NULL) {
        GradeNodePtr tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
    return 0;
}
