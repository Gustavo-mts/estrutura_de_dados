#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
using namespace std;

void show_forest(vector<string> map) {
    for(int i = 0; i < (int) map.size(); i++)
        cout << map[i] << endl;
}

bool check(vector<string>& map, int line, int col) {
    int nl = map.size();
    int nc = map[0].size();

    if(line < 0 || line >= nl || col < 0 || col >= nc)
        return true;

    return false;
}

int toBurn(vector<string>& map, int line_pos, int col_pos) {
    if(check(map, line_pos, col_pos) || map[line_pos][col_pos] != '#') {
        return 0;
    }

    int total = 1;
    map[line_pos][col_pos] ='o';

    total +=
    toBurn(map, line_pos - 1, col_pos) +
    toBurn(map, line_pos, col_pos - 1) +
    toBurn(map, line_pos + 1, col_pos) +
    toBurn(map, line_pos, col_pos + 1);

    map[line_pos][col_pos] = 'x';

    return total;
}


int main() {
    ifstream forest("mapa.txt");

    vector<string> map;

    int nl {}, nc {}, li {}, ci {};
    forest >> nl >> nc >> li >> ci;

    for(int i = 0; i < nl; i ++) {
        string line;
        forest >> line;
        map.push_back(line);
    }

    show_forest(map);

    cout << endl << "============" << endl;
   
    int burned_tree = toBurn(map, li, ci);
    show_forest(map);

    cout << "Arvores queimadas: " << burned_tree << endl;

}