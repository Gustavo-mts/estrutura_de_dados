#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct Position{
    int line, column;

    Position(int line, int column) : line(line), column(column) {}

    bool operator==(Position position) {
        if(position.line == this->line && position.column == this->column)
            return true;
        
        return false;
    }
};

void toShow(vector<string>& matrix) {
    for(auto elem : matrix)
        cout << elem << endl;
}

vector<Position> getNextElem(Position position) {
    auto [line, column] = position;

    return {{line, column - 1}, {line - 1, column}, {line, column + 1}, {line + 1, column}};
}

void loopStartEnd(vector<string>& matrix, Position& startMatrix, Position& endMatrix, int i) {
    for (int j = 0; j < (int) (matrix[0].size() - 1); j++) {
        if(matrix[i][j] == 'I') {
            matrix[i][j] = ' ';
            startMatrix.line = i;
            startMatrix.column = j;
        }

        if(matrix[i][j] == 'F') {
            matrix[i][j] = ' ';
            endMatrix.line = i;
            endMatrix.column = j;
        }
    }
}

void startEnd(vector<string>& matrix, Position& startMatrix, Position& endMatrix) {
    for(int i = 0; i < (int) (matrix.size() - 1); i++) {
      loopStartEnd(matrix, startMatrix, endMatrix, i);  
    }
}

void toAdvance(vector<string>& matrix, Position& startMatrix, Position& endMatrix) {
    int number_lines = matrix.size();
    int number_columns = matrix[0].size();

    auto [line,column] = startMatrix;

    stack<Position> position_way;
    stack<list<Position>> neigs;

    matrix[line][column] = '.';
    position_way.push(startMatrix);

    while(position_way.empty() != true) {
        list<Position> nextElements {};
        
        if(position_way.top() == endMatrix)
            return;

        for(auto elem : getNextElem(position_way.top())) {
            if(elem.line >= number_lines || elem.column >= number_columns || elem.line < 0 || elem.column < 0)
                continue;
            else if (matrix[elem.line][elem.column] == ' ') {
                nextElements.push_back(elem);
            }
        }
        
        if(nextElements.empty()) {
            matrix[position_way.top().line][position_way.top().column] = ' ';
            position_way.pop();

            while(neigs.top().empty() == true) {
                neigs.pop();
                matrix[position_way.top().line][position_way.top().column] = ' ';
                position_way.pop();
            }
            
            position_way.push(neigs.top().back());
            neigs.top().pop_back();
            matrix[position_way.top().line][position_way.top().column] = '.';
        } else {
            position_way.push(nextElements.back());
            nextElements.pop_back();
            neigs.push(nextElements);
            matrix[position_way.top().line][position_way.top().column] = '.';
        }

        toShow(matrix);
        getchar();
    }
}

int main() {
    int number_lines, number_columns;

    cin >> number_lines >> number_columns;
    cin.ignore();

    vector<string> matrix(number_lines);

    for(int i = 0; i < number_lines; i++)
        getline(cin, matrix[i]);

    Position startMatrix(0, 0);
    Position endMatrix(0, 0);

    startEnd(matrix, startMatrix, endMatrix);
    toAdvance(matrix, startMatrix, endMatrix);
    toShow(matrix);
}