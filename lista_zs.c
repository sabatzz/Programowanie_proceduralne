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
    //alokacja pamiêci nowego wêz³a o typie GradeNote
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
        //obs³uga b³êdu
        fprintf(stderr, "B³¹d alokacji pamiêci.\n");
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

    /* a) Utworzenie wskaŸnika prowadz¹cego na pocz¹tek listy o nazwie startPtr.
    Ta lista jest pusta.*/

    GradeNodePtr startPtr = NULL;

    /* b) Utworzenie  nowego  wêz³a  typu GradeNode,  do  którego  prowadzi  wskaŸnik newPtr typu GradeNodePtr.
    Nale¿y przypisaæ ci¹g tekstowy "Janowski" elementowi sk³adowemu lastName i wartoœæ 91.5 elementowi sk³adowemu
    grade. Zdefiniuj wszystkie niezbêdne deklaracje i polecenia.*/

    insertNode(&startPtr, "Jankowski", 91.5);

    /* c) Przyjmij za³o¿enie, ¿e lista, do której prowadzi startPtr, sk³ada siê z dwóch wêz³ów
    —zawieraj¹ one po jednym ci¹gu tekstowym "Janowski" i "Szczepaniak".
    Te wêz³y s¹ u³o¿one w kolejnoœci alfabetycznej. Zdefiniuj polecenia niezbêdne do
    wstawienia w prawid³owej kolejnoœci wêz³ów z nastêpuj¹cymi danymi
    dla elementów sk³adowych lastName i grade:
    "Adamczyk" 85.0
    "Taczyñski" 73.5
    "Przybylski" 66.5
    Podczas operacji wstawiania wykorzystaj wskaŸniki previousPtr, currentPtr i newPtr.
    Wyœwietl wartoœci previousPtri currentPtr przed  poszczególnymi  operacjami  wstawienia.
    Przyjmij za³o¿enie, ¿e newPtr zawsze prowadzi do nowego wêz³a, który ma ju¿ przypisane dane.*/


    insertNode(&startPtr, "Szczepaniak", 0.0);

    //poczatkowa lista
    GradeNodePtr currentPtr = startPtr;
    while (currentPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }

    //dodawanie danych 
    insertNode(&startPtr, "Adamczyk", 85.0);
    insertNode(&startPtr, "Taczyñski", 73.5);
    insertNode(&startPtr, "Przybylski", 66.5);

    //sortowanie listy 
    sort(&startPtr);

    //posortowana lista
    currentPtr = startPtr;
    while (currentPtr != NULL) {
        currentPtr = currentPtr->nextPtr;
    }
    /* d) Utwórz pêtlê while wyœwietlaj¹c¹ dane poszczególnych wêz³ów na liœcie.
    Do poruszania siê po liœcie wykorzystaj wskaŸniki currentPtr.*/

    currentPtr = startPtr;
    printf("Dane poszczególnych wêz³ów na liœcie:\n");
    while (currentPtr != NULL) {
        printf("Nazwisko: %s, Ocena: %.2lf\n", currentPtr->lastName, currentPtr->grade);
        currentPtr = currentPtr->nextPtr;
    }

    /* e) Utwórz pêtlê while usuwaj¹c¹ wszystkie wêz³y na liœcie i zwalniaj¹c¹ pamiêæ zaalokowan¹ dla poszczególnych wêz³ów.
    Do poruszania siê po liœcie i zwalniania pamiêci wykorzystaj wskaŸniki odpowiednio currentPtr i tempPtr.*/

    currentPtr = startPtr;
    while (currentPtr != NULL) {
        GradeNodePtr tempPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
        free(tempPtr);
    }
    return 0;
}
