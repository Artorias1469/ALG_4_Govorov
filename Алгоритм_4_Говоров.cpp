#include <iostream>
#include <ctime>
#include <cstdlib>
const int ARRAY_SIZE = 50;
int MaxSearch(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int MinSearch(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int main() {
    srand(static_cast<unsigned>(time(0)));
    int sizes[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sizes[i] = (rand() % 950) + 50; // Генерируем размеры массивов от 50 до 999 элементов
    }
    std::cout << "Array Size\tMax Time (ms)\tMax Value\tMin Time (ms)\tMin Value\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int arrSize = sizes[i];
        int* arr = new int[arrSize];
        for (int j = 0; j < arrSize; j++) {
            arr[j] = rand() % 1000; // Заполняем массив случайными числами от 0 до 999
        }
        int max, min;
        clock_t start, end;

        double MaxTime = 0, MinTime = 0;
        int numIterations = 50;
        for (int j = 0; j < numIterations; j++) {
            start = clock();
            max = MaxSearch(arr, arrSize);
            end = clock();
            MaxTime += (double)(end - start) / CLOCKS_PER_SEC * 1000;
            start = clock();
            min = MinSearch(arr, arrSize);
            end = clock();
            MinTime += (double)(end - start) / CLOCKS_PER_SEC * 1000;
        }
        MaxTime /= numIterations;
        MinTime /= numIterations;

        std::cout << arrSize << "\t" << MaxTime << "\t" << max << "\t" << MinTime << "\t" << min << "\n";

        delete[] arr;
    }

    return 0;
}
