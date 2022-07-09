#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool shape(string data, int limit, int index, char value) {
    int size = data.size();
    int initiation = max(index - limit, 0);
    int final = min(index + limit + 1, size);

    for(int i = initiation; i < final; i++) {
        if(data[i] == value)
            return false;
    }

    return true;
}

int next(string data, int index) {
    int size = data.size();

    for(int i = index + 1; i < size; i++) {
        if(data[i] == '_')
            return i;
    }

    return size;
}

char dig(int dig) {
    return dig + '0';
}

bool distance_create(string& data, int limit, int index) {
    if(index == (int) data.size())
        return true;

    if(data[index] != '_')
        distance_create(data, limit, index + 1);

    char value = '0';
    while(value <= dig(limit)) {
        if(shape(data, limit, index, value)){
            data[index] = value;
            cout << data << endl;

            if(distance_create(data, limit, index + 1))
                return true;
        }
        value++;
    }

    data[index] = '_';
    return false;
}

int main() {
    string sequel;
    int limit{};
  
    cin >> sequel;
    cin >> limit;

    distance_create(sequel, limit, 0);
}