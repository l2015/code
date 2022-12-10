#include <stdio.h>
#include <time.h>

#define N 1000000

int main() {
    // Declare an array of integers and initialize it
    int array[N];

    // Declare a pointer to an integer and initialize it
    // to the base address of the array
    int *ptr = array;

    // Record the starting time
    clock_t start = clock();

    // Access the elements of the array using the index of the element
    for (int i = 0; i < N; i++) {
        array[i] = i;
    }

    // Record the ending time
    clock_t end = clock();

    // Calculate the elapsed time in milliseconds
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    // Print the elapsed time
    printf("Elapsed time (index): %f ms\n", elapsed);

    // Record the starting time
    start = clock();

    // Access the elements of the array using the pointer
    for (int i = 0; i < N; i++) {
        *(ptr + i) = i;
    }

    // Record the ending time
    end = clock();

    // Calculate the elapsed time in milliseconds
    elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    // Print the elapsed time
    printf("Elapsed time (pointer): %f ms\n", elapsed);

    return 0;
}
