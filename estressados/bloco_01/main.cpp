#include <iostream>
#include <vector>

using namespace std;

// existe
bool exist_number(vector<int> vet, int number)
{
    int counter = 0;
    for (int i = 0; i < vet.size(); i++)
        if (number == vet[i])
        {
            cout << "true" << endl;
            return 0;
        }
        else
            counter++;
    if (counter == vet.size())
    {
        cout << "false";
    }
    cout << endl;
    return false;
}

// contar
int counter_number(vector<int> vet, int number)
{
    int counter = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (number == vet[i])
            counter++;
    }
    if (counter == 0)
    {
        cout << -1 << endl;
    }
    else
        cout << counter << endl;
    return 0;
}

// encontrar
int find_number(vector<int> vet, int number)
{
    int counter = 0;
    for (int i = 0; i < vet.size(); i++)
    {
        if (number == vet[i])
        {
            cout << (i + 1) << endl;
            return 0;
        }
        else
        {
            counter++;
        }
    }
    if (counter == vet.size())
    {
        cout << -1 << endl;
    }
    return 0;
}

int main()
{
    int value{};
    cin >> value;
    vector<int> vet{1, 98, 40, -10, -90, 5, 98, 5, 40, 5};
    exist_number(vet, value);
    counter_number(vet, value);
    find_number(vet, value);
}