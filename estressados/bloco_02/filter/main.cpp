#include <iostream>
#include <vector>

using namespace std;

int clone(const std::vector<int>& v){
    vector<int> vCopy;
   for (int i=0; i<v.size(); i++)
        vCopy.push_back(v[i]);
    
    for(int i=0; i<vCopy.size(); i++)
        cout << vCopy[i] << endl;
    return 0;
}

int pegar_homens(const std::vector<int>& v){
    vector<int> vCopy;
   for (int i=0; i<v.size(); i++)
        if(v[i] > 0)
            vCopy.push_back(v[i]);
    
    for(int i=0; i<vCopy.size(); i++)
        cout << vCopy[i] << endl;
    return 0;
}

int pegar_calmos(const std::vector<int>& v){
    vector<int> vCopy;
   for (int i=0; i<v.size(); i++)
        if(v[i] < 10)
            vCopy.push_back(v[i]);
    
    for(int i=0; i<vCopy.size(); i++)
        cout << vCopy[i] << endl;
    return 0;
}

int pegar_mulheres_calma(const std::vector<int>& v){
    vector<int> vCopy;
   for (int i=0; i<v.size(); i++)
        if(v[i] < 0 && v[i] > -10)
            vCopy.push_back(v[i]);
    
    for(int i=0; i<vCopy.size(); i++)
        cout << vCopy[i] << endl;
    return 0;
}

int main()
{
    vector<int> vet{ -110,110, -4, 1, 3, 50, -9};
    //clone(vet);
    //pegar_homens(vet);
    //pegar_calmos(vet);
    pegar_mulheres_calma(vet);
}