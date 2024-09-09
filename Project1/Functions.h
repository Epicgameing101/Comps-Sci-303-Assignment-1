#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int search(int arr[], int size, int value);

// Function to modify the value at a given index
void modify(int arr[], int size, int index, int newValue, int& oldValue);

// Function to add an integer at the end of the array
void add(int arr[], int& size, int value);

// Function to remove an integer or set its value to 0
void remove(int arr[], int& size, int index);