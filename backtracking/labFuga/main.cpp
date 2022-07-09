#include <iostream>
#include <vector>

using namespace  std;

void toShow(vector<string>& maze) {
    for(auto elem : maze) {  
        cout << elem << endl;
    }
}

void verifyLoop(vector<string>& maze, int line, pair<int, int>& start, pair<int, int>& final) {
    int column = 0;
    while ( column < int (maze[0].size() - 1)) {
        if (maze[line][column] == 'I') {
            maze[line][column] = '_';
            start.first = line;
            start.second = column;
        }

        if (maze[line][column] == 'F') {
            maze[line][column] = '_';
            final.first = line;
            final.second = column;
        }
        column++;
    }   
}

void toVerify(vector<string>& maze, pair<int, int>& start, pair<int, int>& final) {
    
    for (int line = 0; line < int (maze.size() - 1); line++) {
       verifyLoop(maze, line, start, final);
    }
}

bool toSolve(vector<string>& maze, int line_position, int column_position, pair<int, int>& final) {
    int line_num = maze.size();
    int column_num = maze[0].size();

    if(line_position >= line_num || column_position >= column_num || line_position < 0 || column_num < 0) 
        return false;
    else if(maze[line_position][column_position] == '#' || maze[line_position][column_position] == '.')
        return false;
    else if(line_position == final.first && column_position == final.second) {
        maze[line_position][column_position] = '.';
        return true;
    }

    maze[line_position][column_position] = '.';

    if(toSolve(maze, line_position, column_position - 1, final)) {
        maze[line_position][column_position] = '.';
        return true;
    }

    if(toSolve(maze, line_position + 1, column_position, final)) {
        maze[line_position][column_position] = '.';
        return true;
    }

    if(toSolve(maze, line_position, column_position + 1, final)) {
        maze[line_position][column_position] = '.';
        return true;
    }

    if(toSolve(maze, line_position - 1, column_position, final)) {
        maze[line_position][column_position] = '.';
        return true;
    }

    maze[line_position][column_position] = '_';
    return false;
}

int main() {
    int line_num {}, column_line {};

    auto start = make_pair(0,0);
    auto final = make_pair(0,0);

    cout << "Digite o numero de linhas: ";
    cin >> line_num;

    cout << "Digite o numero de colunas: ";
    cin >> column_line;

    cin.ignore();

    vector<string> maze(line_num);

    int line = 0;
    while( line < line_num) {
        cout << "Elemento " << line << " da linha: ";
        cin >> maze[line];
        line++;
    }

    toVerify(maze, start, final);
    toSolve(maze, start.first, start.second, final);

    toShow(maze);
}
