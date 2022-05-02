#include <iostream>
#include <vector>

using namespace std;

vector<int> separar(vector<int>& v) {
    vector<int> repetidos;
    for(int i = 0; i < v.size(); i++) {
        for(int k = 0; k < v.size(); k++) {
            if(v[i] == v[k]) {
                repetidos.push_back(v[k]);
                v.erase([i]);
            }
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << endl;
        cout << repetidos[i] << " ";
    };
}


int main()
{
    vector<int> vet{1, 3, 4, 3, -1, -2, -2};
    separar(vet);
}