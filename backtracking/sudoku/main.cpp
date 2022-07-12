#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void toShow(const vector<vector<int>>& vetor) {
    for(auto& line : vetor) {
        cout << "[ ";
        
        for (auto& element : line) {
            cout << element << " ";
        }
        
        cout << "]" << endl;
    }
}

bool validate_position(int line, int column, int size) {  
    if (line >= 0 && column >= 0 && line < size && column < size) {
        return true;
    }

    return false;
}

bool authenticate_element(const vector<vector<int>>& frame, int line, int column) {
    int size = frame.size();
    int value = frame[line][column];  

    int i = 0;
    while( i < size) {
        if (i != line && i != column && (frame[i][column] == value || frame[line][i] == value)) {
            return false;
        }
        i++;
    }

    return true;
}

bool verifyAuthenticate(const vector<vector<int>>& frame, int start_column, int line, int column, int square_size, int i, int value) {
    for(int j = start_column; j < start_column + square_size; j++) {
        if (i != line && j != column && frame[i][j] == value) {
            return false;
        }
    }

    return true;
}

bool authenticate_number(const vector<vector<int>>& frame, int line, int column) {
    int size = frame.size();
    int value = frame[line][column];
    int square_size = sqrt(size);
    int start_line = line - (line % square_size);
    int start_column = column - (column % square_size);

    int i = start_line;
    while( i < start_line + square_size) {
        verifyAuthenticate( frame, start_column, line, column, square_size, i, value);
        i++;
    }

    return true;
}

pair<int, int> next(int line, int column, int size) {
    if (column == size - 1) {
        return {line + 1, 0};
    }
    
    return {line, column + 1};
}

bool toSolve(vector<vector<int>>& frame, int line, int column) {
    static vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = frame.size();

    if(line == size || column == size)
        return true;
    else if(!validate_position(line, column, size))
        return false;
    
    random_shuffle(values.begin(), values.end());

    for(auto choice : values) {
        frame[line][column] = choice;
        
        if (!authenticate_element(frame, line, column) || !authenticate_number(frame, line, column)) {
            frame[line][column] = 0;
            continue;
        }
        
        auto [next_line, next_column] = next(line, column, size);

        if (toSolve(frame, next_line, next_column)) {
            return true;
        }
    }

    return false;
}

vector<vector<int>> sudoku(int size) {
    vector<vector<int>> solve(size, vector<int>(size, 0));
    toSolve(solve, 0, 0);

    return solve;
}

int main() {
    srand(time(0));

    auto solution = sudoku(4);

    toShow(solution);
}