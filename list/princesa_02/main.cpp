#include <iostream>
#include <list>

using namespace std;

void toShow(list<int>& list, int ax) {
    cout << "[ ";

    auto i = list.begin();
    while( i != list.end()) {
        if (*i > 0 && *i == ax)
            cout << *i << "> ";
        else if(*i < 0 && *i == (-ax))
            cout << "<" << *i << " ";
        else
            cout << *i << " ";
        i++;
    }

    cout << "]" << endl;
}

void toKill(list<int>& list, int ax) {
    auto i = list.begin();

    while(*i != ax)
        i++;

    if(i == list.end() && *i > 0)
        list.front();
    else if(i == list.begin() && *i < 0)
        list.pop_back();
    else if(*i > 0)
        list.remove(*next(i));
    else if(*i < 0)
        list.remove(*prev(i));
}

void toStart(list<int>& list, int size, int signal) {
    int i = 0;
    while( i < size) {
        list.push_back((i + 1) * signal);
        signal *= -1;

        i++;
    }
}

int main() {
    int size {}, ax {}, signal {};

    cout << "Digite o número de pessoas que irão participar: ";
    cin >> size;

    cout << "Digite com quem ira comecar o machado: ";
    cin >> ax;

    cout << "Digite o sinal: ";
    cin >> signal;

    list<int> list;

    toStart(list, size, signal);
    toShow(list, ax);

    while(list.size() > 1){
        toKill(list, ax);
        ax = (ax + 1) % list.size();
        toShow(list, ax);
    }
}