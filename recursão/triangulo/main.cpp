#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void toShow(vector<int> vet) {
    cout << "[";

    for(auto index : vet)
        cout << index << " ";

    cout << "]" << endl;
}

void toCalculate(vector<int> vet) {
    if((int) vet.size() == 1)
        return;

    vector<int> aux;

    for(size_t index = 0; index < (int) vet.size() - 1; index++)
        aux.push_back(vet[index] + vet[index + 1]);

    toCalculate(aux);
    toShow(aux);
}

int main() {
    cout << "Insirir números(quantos quiser): " << endl;

    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> vet;
    int value;

    while(ss >> value)
        vet.push_back(value);

    toCalculate(vet);
    toShow(vet);
}