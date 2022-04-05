#include <iostream>
#include <vector>

using namespace std;

// encontrar o menor
int find_smaller(vector<int> vet)
{
    int smaller = vet[0];
    for (int i = 0; i < vet.size(); i++)
    {

        if (vet[i] < smaller)
        {
            smaller = vet[i];
        }
    }
    cout << smaller << endl;
    return 0;
}

int main()
{
    vector<int> vet{1, 98, 70, 90, 5, 498, 52, 40, 15};
    find_smaller(vet);
}