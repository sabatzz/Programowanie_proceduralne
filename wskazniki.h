
/* Zadeklarowana struktura z³o¿ona z dynamicznej tablicy liczb rzeczywistych i zmiennej
przechowuj¹cej jej rozmiar; */
struct DynamicArray {
    double* array;
    int size;
};
/*  Funkcja tworz¹ca tablicê w strukturze; */
void initialize(struct DynamicArray* arr, int size) {
    arr->array = (double*)malloc(size * sizeof(double));

    if (arr->array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    arr->size = size;
}
/* Funkcja wype³niaj¹ca tablicê wartoœciami losowymi z podanego przez u¿ytkownika
przedzia³u */
void fill(struct DynamicArray* arr, double min, double max) {
    // generator liczb pseudolosowych
    srand(time(NULL));

    for (int i = 0; i < arr->size; i++) {
        // generowanie losowej liczby z zakresu [min, max]
        double randomValue = ((double)rand() / RAND_MAX) * (max - min) + min;
        arr->array[i] = randomValue;
    }
}
/* Funkcja sortuj¹ca tablicê*/

void sort(struct DynamicArray* arr) {
    // sortowanie b¹belkowe
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
/*Funkcja licz¹ca sumê wszystkich elementów.*/
double calculateSum(struct DynamicArray* arr) {
    double sum = 0.0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->array[i];
    }
    return sum;
}
/*Funkcja znajduj¹ca najmniejszy element tablicy.*/
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
/*Funkcja znajduj¹ca najwiêkszy element tablicy*/
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

/* Funkcja zwalniaj¹ca pamiêæ przydzielon¹ tablicy;*/
void free(struct DynamicArray* arr) {
    free(arr->array);
    arr->array = NULL;
}