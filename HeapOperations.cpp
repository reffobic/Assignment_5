//
// Created by Mohamed El-Refai on 27/11/2023.
//

#include <iostream>
#include <algorithm>
#include "HeapOperations.h"

using namespace std;

void MaxHeapify(ExchangeData arr[], int N, int i){
    int largest = i; //we assume the current node is the largest

    int l = 2 * i + 1;
    int r = 2 * i + 2; // Calculate indices of left and right children

    if (l < N && arr[l].exchange> arr[largest].exchange){
        largest = l; // Check if the left child is larger than the current largest
    }

    if (r < N && arr[r].exchange > arr[largest].exchange){
        largest = r; // Check if the right child is larger than the current largest
    }

    if (largest != i) { // If the largest is not the current node, swap values and recursively heapify
        swap(arr[i].exchange, arr[largest].exchange);
        swap(arr[i].date, arr[largest].date);
        MaxHeapify(arr, N, largest);
    }
}

void Build_Max_Heap(ExchangeData arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        MaxHeapify(arr, n, i); // Build a max heap by calling MaxHeapify on each non-leaf node in reverse order
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Extract elements from the max heap one by one and maintain the heap property
        MaxHeapify(arr, i, 0); // Call MaxHeapify on the reduced heap
    }
}

void MinHeapify(ExchangeData arr[], int n, int i) {
    int min = i; //we assume the current node is the minimum

    int l = 2 * i + 1;
    int r = 2 * i + 2; // Calculate indices of left and right children

    if (l < n && arr[l].exchange < arr[min].exchange) {
        min = l;
    } // Check if the left child is smaller than the current minimum

    if (r < n && arr[r].exchange < arr[min].exchange) {
        min = r;
    } // Check if the right child is smaller than the current minimum

    if (min != i) { // If the minimum is not the current node, swap values and recursively heapify
        swap(arr[i], arr[min]);
        MinHeapify(arr, n, min); // Recursively heapify the affected sub-tree
    }
}

void Build_Min_Heap(ExchangeData arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, n, i); // Build a min-heap by calling MinHeapify on each non-leaf node in reverse order
    }
    // Extract elements from the heap in decreasing order and maintain the min-heap property
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Swap the root (minimum element) with the last element in the heap
        MinHeapify(arr, i, 0); // Re-heapify the remaining elements to maintain the min-heap property
    }
}

float MaxSumSub(temp arr[], int n,float mean) {
    for (int i = 0; i < n; i++) { // Adjust each exchange rate by subtracting the mean value
        arr[i].exchange = arr[i].exchange - mean;
    }

    int i = 0;  // Start index at 0
    int im = 0;
    int jm = 0;
    float Sij = 0, Smax = 0;

    for (int j = 0; j < n; j++) { // Find the maximum sum subsequence using Kadane's algorithm
        Sij = Sij + arr[j].exchange;
        if (Sij > Smax) {
            Smax = Sij; // Update the maximum sum and corresponding indices
            im = i;
            jm = j;
        } else if (Sij < 0) { // If the current sum becomes negative, reset the start index
            i = j + 1;
            Sij = 0;
        }
    }
    // Print the results
    cout << "The indexes are " << im << " " << jm << endl;
    cout << "Dates corresponding to the indexes: " << arr[im].date << " " << arr[jm].date << endl;
    cout << "Max sum subsequence is: ";
    return Smax;
}

void PositiveEx (ExchangeData d[], int n, float mean){
    cout << "Positive rates are: " << endl;

    Build_Min_Heap(d, 6668); // Build a min heap using the Build_Min_Heap function

    for (int i = 0; i < n; i++) { // Check if the exchange rate (adjusted by mean) is greater than 0
        if (d[i].exchange - mean > 0) {
            cout << "Date: " << d[i].date << " " << d[i].exchange - mean << endl;
        } // Print the date and adjusted exchange rate for positive numbers
    }
}

void NegativeEx (ExchangeData d[], int n, float mean){
    cout << "Negative rates are: " << endl;

    Build_Max_Heap(d, 6668); // Build a max heap using the Build_Max_Heap function

    for (int i = 0; i < n; i++) { // Check if the exchange rate (adjusted by mean) is less than 0
        if (d[i].exchange - mean < 0) {
            cout << "Date: " << d[i].date << " " << d[i].exchange - mean << endl;
        } // Print the date and adjusted exchange rate for negative numbers
    }
}

void GetMean(ExchangeData d[],int n, float &mean){
    float sum = 0;

    for (int i = 0; i < n; i++) { // Calculate the sum of exchange rates
        sum = sum + d[i].exchange;
    }

    mean = sum / n; // Calculate the mean by dividing the sum by the number of elements
}

void StoreData(ExchangeData d[], temp arr[], int n){
    for(int i =0;i<n;i++) { // Copy exchange rates and dates from ExchangeData array to temp array
        arr[i].exchange=d[i].exchange;
        arr[i].date=d[i].date;
    }
}