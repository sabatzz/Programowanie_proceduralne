#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include wskazniki.h



int main() {
    // Tworzenie struktury DynamicArray
    struct DynamicArray myArray;
    int arraySize = 5;

    initialize(&myArray, arraySize);

    // Wype³nienie tablicy losowymi liczbami z przedzia³u
    double min, max;
    printf("Lower range: ");
    scanf("%lf", &min);
    printf("Upper range: ");
    scanf("%lf", &max);
    printf("********************\n");

    fill(&myArray, min, max);

    // Wyœwietlenie zawartoœci tablicy 
    printf("Array in the structure:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    printf("\n********************\n");
    sort(&myArray);

    // Wyœwietlenie tablicy po sortowaniu
    printf("Array after sorting:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    // Wywo³anie funkcji obliczaj¹cej sumê
    double sum = calculateSum(&myArray);

    // Wyœwietlenie wyniku
    printf("\n********************\n");
    printf("Sum of all elements: %.2lf\n", sum);

    // Wywo³anie funkcji znajduj¹cej najmniejszy element
    double minElement = findMin(&myArray);

    // Wyœwietlenie wyniku
    printf("+++++++++++++++++++++++\n");
    printf("Smallest element: %.2lf\n", minElement);

    // Wywo³anie funkcji znajduj¹cej najwiêkszy element
    double maxElement = findMax(&myArray);

    // Wyœwietlenie wyniku
    printf("Largest element: %.2lf\n", maxElement);


    // Zwolnienie pamiêci
    free(&myArray);
    return 0;
}