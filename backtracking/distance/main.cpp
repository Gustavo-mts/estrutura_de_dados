#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool toInsert(string& line, int index, int limit, int value) {
    for(int i {index - limit}; i < index + limit + 1; i++ )
        if(line[i] == value)
            return false;
    return true;
}

bool toFill(string& line, int index, int limit) {
    if((int) line.size() == index)
        return true;

    if(line[index] != '.')
        return toFill(line, index + 1, limit);

    char value {'0'}; 
    while(value <= limit + '0') {
        if(toInsert(line, index, limit, value)) {
            line[index] = value;
            cout << line << endl;

            if(toFill(line, index + 1, limit))
                return true;
        }
        value++;
    }

    line[index] = '.';
    cout << line << endl;

    return false;
}

int main() {
    string line;
    int limit{};
    ifstream doc("doc.txt");
    doc >> line >> limit;
    toFill(line, 0, limit);
}