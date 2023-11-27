//
// Created by Mohamed El-Refai on 27/11/2023.
//

#include <iostream>
#include <algorithm>
#include "HeapOperations.h"

using namespace std;


void MaxHeapify(ExchangeData arr[], int N, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l].exchange> arr[largest].exchange){
        largest = l;
    }

    if (r < N && arr[r].exchange > arr[largest].exchange){
        largest = r;
    }

    if (largest != i) {
        swap(arr[i].exchange, arr[largest].exchange);
        swap(arr[i].date, arr[largest].date);
        MaxHeapify(arr, N, largest);
    }
}

void Build_Max_Heap(ExchangeData arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        MaxHeapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

void MinHeapify(ExchangeData arr[], int n, int i) {
    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].exchange < arr[min].exchange) {
        min = l;
    }

    if (r < n && arr[r].exchange < arr[min].exchange) {
        min = r;
    }

    if (min != i) {
        swap(arr[i], arr[min]);
        MinHeapify(arr, n, min);
    }
}

void Build_Min_Heap(ExchangeData arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        // place deleted node at the end
        swap(arr[0], arr[i]);
        MinHeapify(arr, i, 0);
    }
}

float MaxSumSub(temp arr[], int n,float mean) {
    for (int i = 0; i < n; i++) {
        arr[i].exchange = arr[i].exchange - mean;
    }

    int i = 0;  // Start index at 0
    int im = 0;
    int jm = 0;
    float Sij = 0, Smax = 0;

    for (int j = 0; j < n; j++) {
        Sij = Sij + arr[j].exchange;
        if (Sij > Smax) {
            Smax = Sij;
            im = i;
            jm = j;
        } else if (Sij < 0) {
            i = j + 1;
            Sij = 0;
        }
    }

    cout << endl << "The indexes are " << im << " " << jm << endl;
    cout << "Dates corresponding to the indexes: " << arr[im].date << " " << arr[jm].date << endl;
    cout << "Max sum subsequence is: " << endl;

    return Smax;
}

void PositiveEx (ExchangeData d[], int n, float mean){
    cout << "Positive numbers are: " << endl;

    Build_Min_Heap(d, 6668);

    for (int i = 0; i < n; i++) {
        if (d[i].exchange - mean > 0) {
            cout << "Date: " << d[i].date << " " << d[i].exchange - mean << endl;
        }
    }

    cout << endl;
}

void NegativeEx (ExchangeData d[], int n, float mean){
    cout << "Negative numbers are: " << endl;

    Build_Max_Heap(d, 6668);

    for (int i = 0; i < n; i++) {
        if (d[i].exchange - mean < 0) {
            cout << "Date: " << d[i].date << " " << d[i].exchange - mean << endl;
        }
    }
}

void GetMean(ExchangeData d[],int n, float &mean){
    float sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + d[i].exchange;
    }

    mean = sum / n;
}

void StoreData(ExchangeData d[], temp arr[], int n){
    for(int i =0;i<n;i++) {
        arr[i].exchange=d[i].exchange;
        arr[i].date=d[i].date;
    }
}