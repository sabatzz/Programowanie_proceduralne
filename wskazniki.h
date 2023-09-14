
/* Zadeklarowana struktura z�o�ona z dynamicznej tablicy liczb rzeczywistych i zmiennej
przechowuj�cej jej rozmiar; */
struct DynamicArray {
    double* array;
    int size;
};
/*  Funkcja tworz�ca tablic� w strukturze; */
void initialize(struct DynamicArray* arr, int size) {
    arr->array = (double*)malloc(size * sizeof(double));

    if (arr->array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    arr->size = size;
}
/* Funkcja wype�niaj�ca tablic� warto�ciami losowymi z podanego przez u�ytkownika
przedzia�u */
void fill(struct DynamicArray* arr, double min, double max) {
    // generator liczb pseudolosowych
    srand(time(NULL));

    for (int i = 0; i < arr->size; i++) {
        // generowanie losowej liczby z zakresu [min, max]
        double randomValue = ((double)rand() / RAND_MAX) * (max - min) + min;
        arr->array[i] = randomValue;
    }
}
/* Funkcja sortuj�ca tablic�*/

void sort(struct DynamicArray* arr) {
    // sortowanie b�belkowe
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->array[j] > arr->array[j + 1]) {
                double temp = arr->array[j];
                arr->array[j] = arr->array[j + 1];
                arr->array[j + 1] = temp;
            }
        }
    }
}
/*Funkcja licz�ca sum� wszystkich element�w.*/
double calculateSum(struct DynamicArray* arr) {
    double sum = 0.0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->array[i];
    }
    return sum;
}
/*Funkcja znajduj�ca najmniejszy element tablicy.*/
double findMin(struct DynamicArray* arr) {
    if (arr->size == 0) {
        fprintf(stderr, "Empty array\n");
        exit(1);
    }

    double min = arr->array[0];
    for (int i = 1; i < arr->size; i++) {
        if (arr->array[i] < min) {
            min = arr->array[i];
        }
    }
    return min;
}
/*Funkcja znajduj�ca najwi�kszy element tablicy*/
double findMax(struct DynamicArray* arr) {
    if (arr->size == 0) {
        fprintf(stderr, "Empty array\n");
        exit(1);
    }

    double max = arr->array[0];
    for (int i = 1; i < arr->size; i++) {
        if (arr->array[i] > max) {
            max = arr->array[i];
        }
    }
    return max;
}

/* Funkcja zwalniaj�ca pami�� przydzielon� tablicy;*/
void free(struct DynamicArray* arr) {
    free(arr->array);
    arr->array = NULL;
}