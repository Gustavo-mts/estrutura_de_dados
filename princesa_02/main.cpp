#include <iostream>
#include <vector>

using namespace std;

void show_vet(vector<int> vet, int sword)
{
    for (int i = 0; i < (int)vet.size(); i++)
    {
        cout << vet[i] << (i == sword ? "> " : " ");
    }
    cout << endl;
}

int main()
{
    int size{}, sword{};
    cin >> size >> sword;
    vector<int> vet(size);
    for (int i = 1; i < size; i++)
        vet[i] = i;
    sword -= 1;
    int qtd = vet.size() - 1;
    do
    {
        show_vet(vet, sword);
        sword = (sword + 1) % vet.size();
        vet.erase(vet.begin() + sword);
        sword = sword % vet.size();
    } while (qtd--);
}