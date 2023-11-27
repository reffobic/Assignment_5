
//Done by Mohamed El Refai 900222334

#include <iostream>
#include <fstream>
#include "HeapOperations.h"

using namespace std;


void ReadData(string line ,ExchangeData exchanged[]) {

    int n=6668;
    ifstream infile("euro-dollar.txt");
    if (!infile.is_open()) {
        cout << "Error reading file" << endl;
        return;
    }

    int index = 0;


    while (getline(infile, line)) {
        // Assuming the date and exchange rate are separated by a space or tab
        size_t pos = line.find_first_of(" \t");
        if (pos != string::npos) {
            exchanged[index].date = line.substr(0, pos);
            exchanged[index].exchange = stof(line.substr(pos + 1));
            index++;
        }
    }

    infile.close();
}

int main() {

    string x;
    int n=6668, p;
    float mean = 0;
    ExchangeData d[n];
    temp arr[n];
    cout << endl;

    ReadData(x, d);
    GetMean(d, n, mean);
    StoreData(d, arr, n);
    PositiveEx (d, 10, mean);
    NegativeEx (d, 10, mean);
    cout << MaxSumSub(arr, n, mean);

    return 0;
}
