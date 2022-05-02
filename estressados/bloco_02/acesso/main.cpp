#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>

using namespace std;

vector<int> inverter_com_copia(const std::vector<int> v){
    vector<int> vCopy;
   for (int i= 0; i< v.size(); i++)
        vCopy.push_back(v[i] * (-1));
    
    for(int i=0; i<vCopy.size(); i++)
        cout << vCopy[i] << endl;
    return vCopy;
}

vector<int> reverter_inplace(vector<int> v){
    
   for (int i = 0; i < v.size(); i++)
        v[i] *= -1;
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return v;
}

int sortear(const std::vector<int>& v) {
    srand(time(NULL));
    cout << (v[rand() % (v.size())]);
    return 0;
}

void embaralhar(std::vector<int>& v) {
    srand(time(NULL));
    for(int i =0; i < v.size(); i++) {
        int mix = rand() % v.size();
        int aux = v[i];
        v[i] = v[mix];
        v[mix] = aux;
        
    }
    for(int i =0; i < v.size(); i++)
        cout << v[i] << " ";
}

void ordenar(std::vector<int>& v) {
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}


int main()
{
    vector<int> vet{ -110,110, -4, 1, 3, 50, -9};
    inverter_com_copia(vet);
    reverter_inplace(vet);
    sortear(vet);
    embaralhar(vet);
    ordenar(vet);
}