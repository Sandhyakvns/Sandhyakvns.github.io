#include <stdio.h>
#include <stdlib.h>
void mergeKArrays(int *arr[], int output[], int k, int n) {
    int index[k];
    for (int i = 0; i < k; i++) {
        index[i] = 0;
    }
    for (int i = 0; i < n * k; i++) {
        int min_index = -1;
        int min_value;
        for (int j = 0; j < k; j++) {
            if (index[j] < n && (min_index == -1 || arr[j][index[j]] < min_value)) {
                min_index = j;
                min_value = arr[j][index[j]];
            }
        }
        output[i] = min_value;
        index[min_index]++;
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int k, n;
    printf("Enter the number of arrays (k): ");
    scanf("%d", &k);
    printf("Enter the size of each array (n): ");
    scanf("%d", &n);
    int **arr = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < k; i++) {
        printf("Enter values for array %d (sorted):\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int *output = (int *)malloc(k * n * sizeof(int));
    mergeKArrays(arr, output, k, n);
    printf("Merged Array: ");
    printArray(output, k * n);
    for (int i = 0; i < k; i++) {
        free(arr[i]);
    }
    free(arr);
    free(output);
    return 0;
}
    