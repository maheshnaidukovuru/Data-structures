#include <stdio.h>

#define MAX_SIZE 100

// Function to insert an element at a specific index in the array
int insert(int arr[], int size, int index, int value) {
    if (size >= MAX_SIZE || index < 0 || index > size)
        return size; // No change if the array is full or index is invalid
    
    // Shift elements to the right to make space for the new element
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[index] = value;
    return size + 1;
}

// Function to delete an element at a specific index in the array
int deleteElement(int arr[], int size, int index) {
    if (size <= 0 || index < 0 || index >= size)
        return size; // No change if the array is empty or index is invalid
    
    // Shift elements to the left to fill the gap left by the deleted element
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;
}

// Function to display the elements of the array
int display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5;
    
    display(arr, size);
    
    // Inserting an element at index 2 with value 10
    size = insert(arr, size, 2, 10);
    display(arr, size);
    
    // Deleting the element at index 3
    size = deleteElement(arr, size, 3);
    display(arr, size);
    
    return 0;
}

