//
// Created by Mohamed El-Refai on 27/11/2023.
//

#ifndef ASS_5_HEAPOPERATIONS_H
#define ASS_5_HEAPOPERATIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct ExchangeData { // Structure to represent exchange rate data with a date and exchange value
    string date = " "; // Date associated with the exchange rate
    float exchange = 0; // Exchange rate value
};

struct temp { // Temporary structure to store exchange rate data with a date and modified exchange value
    float exchange; // Modified exchange rate value
    string date = " "; // Date associated with the exchange rate
};

void MaxHeapify(ExchangeData arr[], int N, int i);
void Build_Max_Heap(ExchangeData arr[], int n);
void MinHeapify(ExchangeData arr[], int n, int i);
void Build_Min_Heap(ExchangeData arr[], int n);
float MaxSumSub(temp arr[], int n, float mean);
void PositiveEx(ExchangeData d[], int n, float mean);
void NegativeEx(ExchangeData d[], int n, float mean);
void GetMean(ExchangeData d[], int n, float &mean);
void StoreData(ExchangeData d[], temp arr[], int n);

#endif //ASS_5_HEAPOPERATIONS_H