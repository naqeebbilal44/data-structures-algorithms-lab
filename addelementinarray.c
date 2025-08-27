#include <stdio.h>

void inputArray(int arr[], int *size) {
    printf("How many elements? ");
    scanf("%d", size);

    for(int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void addAtEnd(int arr[], int *size, int element) {
    arr[*size] = element;
    (*size)++;
}

void displayArray(int arr[], int size) {
    printf("Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size;

    inputArray(arr, &size);
    displayArray(arr, size);

    int newElement;
    printf("Enter element to add at the end: ");
    scanf("%d", &newElement);

    addAtEnd(arr, &size, newElement);
    displayArray(arr, size);

    return 0;
}
