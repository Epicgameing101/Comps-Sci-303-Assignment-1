#include "Functions.h"


int search(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void modify(int arr[], int size, int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds!");
    }
    oldValue = arr[index]; // Store old value
    arr[index] = newValue; // Modify with new value
}

void add(int arr[], int& size, int value) {
    if (size >= 100) { // assuming array has a max size of 100
        throw length_error("Array size exceeded!");
    }
    arr[size++] = value; // Add the new value and increase size
}

void remove(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds!");
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1]; // Shift elements left
    }
    size -= 1;
}