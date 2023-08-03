#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}
int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the sorted elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);
    int index = binarySearch(arr, 0, size - 1, target);
    if (index != -1) {
        printf("Number %d found at index %d.\n", target, index);
    } else {
        printf("Number not found in the array.\n");
    }
    return 0;
}

