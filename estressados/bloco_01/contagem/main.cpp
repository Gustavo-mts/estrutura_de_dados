#include <iostream>
#include <vector>

using namespace std;

// Contagem
float calcular_stress_medio(vector<int>& fila) {

    float adder;
    for(int i = 0; i < fila.size(); i++) {
        adder += fila[i];
    }
    float result = adder/(fila.size());
    cout << result << endl;
    return 0.0;
};

string metade_mais_estressada(vector<int>& fila){
    int adder_first=0;
    int adder_second=0;
    for(int i = 0; i < fila.size()/2; i++) {
        adder_first += fila[i];
    }
    for(int i =( fila.size()/2); i < fila.size(); i++) {
        adder_second+= fila[i]; 
    }

    if(adder_first > adder_second) {
        cout << "primeira" << endl;
    } else if (adder_first < adder_second) {
        cout << "segunda" << endl;
    } else
        cout << "empate" << endl;
        return "";
}

string  quem_eh_mais_estressado(vector<int>& fila){
    
    int adder=0;
    for(int i = 0; i < fila.size(); i++) {
        adder += fila[i];
    }

    if(adder > 0) {
        cout << "homens" << endl;
    } else if (adder < 0) {
        cout << "mulheres" << endl;
    } else
        cout << "empate" << endl;
    return " ";
}

int main()
{
    vector<int> vet{ -110,110, -4, 1, 3};
    //calcular_stress_medio(vet);
    //metade_mais_estressada(vet);
    quem_eh_mais_estressado(vet);
}