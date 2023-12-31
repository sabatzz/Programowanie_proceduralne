#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include wskazniki.h



int main() {
    // Tworzenie struktury DynamicArray
    struct DynamicArray myArray;
    int arraySize = 5;

    initialize(&myArray, arraySize);

    // Wypełnienie tablicy losowymi liczbami z przedziału
    double min, max;
    printf("Lower range: ");
    scanf("%lf", &min);
    printf("Upper range: ");
    scanf("%lf", &max);
    printf("********************\n");

    fill(&myArray, min, max);

    // Wyświetlenie zawartości tablicy 
    printf("Array in the structure:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    printf("\n********************\n");
    sort(&myArray);

    // Wyświetlenie tablicy po sortowaniu
    printf("Array after sorting:\n");
    for (int i = 0; i < myArray.size; i++) {
        printf("%.2lf ", myArray.array[i]);
    }
    // Wywołanie funkcji obliczającej sumę
    double sum = calculateSum(&myArray);

    // Wyświetlenie wyniku
    printf("\n********************\n");
    printf("Sum of all elements: %.2lf\n", sum);

    // Wywołanie funkcji znajdującej najmniejszy element
    double minElement = findMin(&myArray);

    // Wyświetlenie wyniku
    printf("+++++++++++++++++++++++\n");
    printf("Smallest element: %.2lf\n", minElement);

    // Wywołanie funkcji znajdującej największy element
    double maxElement = findMax(&myArray);

    // Wyświetlenie wyniku
    printf("Largest element: %.2lf\n", maxElement);


    // Zwolnienie pamięci
    free(&myArray);
    return 0;
}