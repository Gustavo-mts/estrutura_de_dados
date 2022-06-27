#include <iostream>
#include <vector>

using namespace std;

void toStart(vector<int>& row, int sign, int size) {
    if(sign < 0) {
        int counter = 1;

        for (int i = 0; i < size; i++) {
            if (counter % 2 == 0)
                row.push_back(counter);
            else
                row.push_back(-counter);

            counter++;
        }
    } else {
        int counter = 1;

        for (int i = 0; i < size; i++) {
            if ((counter%2) == 0)
                row.push_back(-counter);
            else
                row.push_back(counter);

            counter++;
        }
    }
}

void toShow(vector<int>& row, int cut) {
    cout << "[";

    for (int i = 0; i < (int) row.size(); i++) {
        if (i == cut && row[i] > 0)
            cout << row[i] << ">";
        else if (i == cut && row[i] < 0)
            cout << "<" << row[i];
        else
            cout << row[i];
        if(i != (int) row.size() -1)
            cout << ", ";
    }

    cout << " ]" << endl; 
}

void toKill(vector<int>& fila, int posicao) {
    fila.erase(fila.begin() + posicao);
}

int main() 
{
    int size{}, position{}, sign{};

    cout << "Digite o tamanho: ";
    cin >> size;

    cout << "Digite a posicao de quem vai iniciar com o machado: ";
    cin >> position;

    cout << "Digite o sinal: ";
    cin >> sign;

    vector<int> row;
    toStart(row, sign, size);
    position--;

    while((int) row.size() != 1) {
        if(position < 0)
            position = (int)row.size() - 1;

        toShow(row, position);
        position = position % (int)row.size();

        if(row[position] < 0) {
            if (position - 1 < 0) {
                toKill(row, (int)row.size() - 1);
                position = (int)row.size() - 1;
            } else {
                position--;
                toKill(row, position);
                position--;
                position = position % (int)row.size();
            }
        } else {
            position++;
            position = position % (int)row.size();
            toKill(row, position);    
        }
    }

    cout << "[";

    for(int i = 0; i < (int) row.size(); i++) {
        cout << row[i];
        if (i != (int) row.size() -1)
            cout << ", ";
    }

    cout  << "]";
}