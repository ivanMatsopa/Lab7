//Ivan Matsopa
//Lab 7

#include <stdio.h>

//function that performs bubblesort and calculates swaps
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, totalSwaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swaping arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                //increment swaps for the swapped elements
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;

                //increment totalSwaps
                totalSwaps += 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }

    printf("total # of swaps: %d\n\n", totalSwaps);
}

//function to perform selectionsort and swap
void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp, totalSwaps = 0;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        //swap arr[i] and arr[minIndex]
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        //increment swaps for the swapped elements
        swaps[arr[i]]++;
        swaps[arr[minIndex]]++;

        //increment totalSwaps
        totalSwaps += 2;
    }

    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }

    printf("total # of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1_bubble[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array1_selection[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};

    int array2_bubble[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array2_selection[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    int size1 = sizeof(array1_bubble) / sizeof(array1_bubble[0]);
    int size2 = sizeof(array2_selection) / sizeof(array2_selection[0]);

    //initialize the swaps arrays to zeros
    int swaps1_bubble[100] = {0};
    int swaps1_selection[100] = {0};
    int swaps2_bubble[100] = {0};
    int swaps2_selection[100] = {0};

    printf("array1 Bubble Sort:\n");
    bubbleSort(array1_bubble, size1, swaps1_bubble);

    printf("array1 Selection Sort:\n");
    selectionSort(array1_selection, size1, swaps1_selection);

    printf("array2 Bubble Sort:\n");
    bubbleSort(array2_bubble, size2, swaps2_bubble);

    printf("array2 Selection Sort:\n");
    selectionSort(array2_selection, size2, swaps2_selection);

    return 0;
}
