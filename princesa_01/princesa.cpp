#include <iostream>
#include <vector>
using namespace std;

void show_vet(vector<int> vet, int sword)
{
    for (int i = 0; i < (int)vet.size(); i++)
    {
        cout << vet[i] << (i == sword ? ">" : " ");
    }
    cout << endl;
}

int find_alive(vector<int> &v, int pos)
{
    do
    {
        pos = (pos + 1) % v.size();
    } while (v[pos] == false);
    return pos;
}

int main()
{
    int size{}, sword{};
    cin >> size >> sword;
    vector<int> vet(size, true);
    sword -= 1;
    int qtd = vet.size();
    do
    {
        show_vet(vet, sword);
        sword = find_alive(vet, sword);
        vet[sword] = false;
        sword = find_alive(vet, sword);
    } while (qtd--);
}