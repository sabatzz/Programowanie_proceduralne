#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include wskazniki.h



int main() {
    // Tworzenie struktury DynamicArray
    struct DynamicArray myArray;
    int arraySize = 5;

    initialize(&myArray, arraySize);

    // Wype�nienie tablicy losowymi liczbami z przedzia�u
    double min, max;
    printf("Lower range: ");
    scanf("%lf", &min);
    printf("Upper range: ");
    scanf("%lf", &max);
    printf("********************\n");

    fill(&myArray, min, max);

    // Wy�wietlenie zawarto�ci tablicy 
    printf("Array in the structure:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    printf("\n********************\n");
    sort(&myArray);

    // Wy�wietlenie tablicy po sortowaniu
    printf("Array after sorting:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    // Wywo�anie funkcji obliczaj�cej sum�
    double sum = calculateSum(&myArray);

    // Wy�wietlenie wyniku
    printf("\n********************\n");
    printf("Sum of all elements: %.2lf\n", sum);

    // Wywo�anie funkcji znajduj�cej najmniejszy element
    double minElement = findMin(&myArray);

    // Wy�wietlenie wyniku
    printf("+++++++++++++++++++++++\n");
    printf("Smallest element: %.2lf\n", minElement);

    // Wywo�anie funkcji znajduj�cej najwi�kszy element
    double maxElement = findMax(&myArray);

    // Wy�wietlenie wyniku
    printf("Largest element: %.2lf\n", maxElement);


    // Zwolnienie pami�ci
    free(&myArray);
    return 0;
}