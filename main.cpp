
//Done by Mohamed El Refai 900222334

#include <iostream>
#include <fstream>
#include "HeapOperations.h"

using namespace std;


void ReadData(string line ,ExchangeData exchanged[]) {

    ifstream infile("euro-dollar.txt"); //open the file

    if (!infile.is_open()) { //error check if the file is not read
        cout << "Error reading file" << endl;
        return;
    }

    int index = 0;

    while (getline(infile, line)) { // Read each line from the file
        size_t pos = line.find_first_of(" \t");
        if (pos != string::npos) { // Extract date and exchange rate from the line
            exchanged[index].date = line.substr(0, pos);
            exchanged[index].exchange = stof(line.substr(pos + 1));
            index++;
        }
    }

    infile.close(); // Close the file after reading
}

int main() {

    string x;
    int n=6668, N; // Number of data points (total), and N for the number of values to display
    float mean = 0;
    ExchangeData d[n]; // Array to store original data
    temp arr[n]; // Array to store temporary data
    cout << endl;

    cout << "Please enter the number of values you want to display: ";
    cin >> N; // Get the user input for the number of values to display
    cout << "-----------------------------" << endl;

    ReadData(x, d); // Read data from the file
    GetMean(d, n, mean); // Calculate the mean of exchange rates
    StoreData(d, arr, n); // Store data in a temporary array

    PositiveEx (d, N, mean); // Display positive exchange rates
    cout << "-----------------------------" << endl;
    NegativeEx (d, N, mean); // Display negative exchange rates
    cout << "-----------------------------" << endl;
    cout << MaxSumSub(arr, n, mean) << endl; // Display maximum sum subsequence
    cout << "-----------------------------" << endl;

    return 0;
}
