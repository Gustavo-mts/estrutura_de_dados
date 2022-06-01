#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void toShow(vector<int> vet) {
    for(auto i : vet)
        cout << i << ' ';
}

void toReverse(vector<int> vet) {
    for(int i = (int) vet.size() - 1; i >= 0; i--)
        cout << vet[i] << ' ';
}

int toSum(vector<int> vet) {
    int sumNumber{};

    for(int i : vet) {
        sumNumber += i;
    }

    return sumNumber;
}

int toMultiply(vector<int> vet){
    int multiplyNumber {1};

    for(int i : vet){
        multiplyNumber *= i;
    }

    return multiplyNumber;
}

int smallest_element(vector<int> vet) {
    int smaller = vet[0];

    for(int i = 0; i < (int) vet.size(); i++){
        if(vet[i] < smaller)
            smaller = vet[i];
    }

    return smaller;
}

vector<int> toInverse(vector<int>& vet){
    vector<int> aux(vet);
    reverse(aux.begin(), aux.end());
    toShow(aux);
}

int main() {
    cout << "Digite os elementos do vetor: " << endl;

    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> vet;

    int elem{};
    while (ss >> elem){
        vet.push_back(elem);
    }

    cout << "Vet: [ ";
    toShow(vet);
    cout << "]" << endl;

    cout << "rvet: [ ";
    toReverse(vet);
    cout << "]" << endl;

    cout << "Sum: " << toSum(vet) << endl;

    cout << "mult: " << toMultiply(vet) << endl;

    cout << "Min: " << smallest_element(vet) << endl;

    cout << "inv: [ " ;
        toInverse(vet);
    cout << "]";
}