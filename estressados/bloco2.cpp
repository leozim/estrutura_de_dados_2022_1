#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Filter - Operações de Filtragem: 4 funções

vector<int> clonar(const vector<int>& v) {
    vector<int> copia;
    for(int i = 0, max = v.size(); i < max; i++)
        copia.push_back(v[i]);
    return copia;
}

vector<int> pegar_homens(const vector<int>& v) {
    vector<int> copia;
    for(int i = 0, max = v.size(); i < max; i++)
        if(v[i] > 0)
            copia.push_back(v[i]);
    return copia;
}

vector<int> pegar_calmos(const vector<int>& v) {
    vector<int> copia;
    for(int i = 0, max = v.size(); i < max; i++)
        if(abs(v[i]) < 10)
            copia.push_back(v[i]);
    return copia;
}

vector<int> pegar_mulheres_calmas(const vector<int>& v) {
    vector<int> copia;
    for(int i = 0, max = v.size(); i < max; i++)
        if(v[i] < 0 && abs(v[i]) < 10)
            copia.push_back(v[i]);
    return copia;
}

// Acesso: 5 funções

vector<int> inverter_com_copia(const vector<int>& v) {
    vector<int> copia;
    for(int i = v.size() - 1; i > 0; i--)
        copia.push_back(v[i]);
    return copia;
}

void inverter_inplace(vector<int>& v) {
    int metade = v.size() / 2;
    int end = v.size() - 1;
    int begin = 0;

    for(int i = begin; i < metade; i++){
        int aux;
        aux = v[i];
        v[i] = v[end - i];
        v[end - i] = aux;
    }
}

int sortear(const vector<int>& v) {
    int randIndex = rand() % v.size();
    return v[randIndex];
}

void embaralhar(vector<int>& v) {
    for(int i = 0, max = v.size(); i < max; i++) {
        int randIndex = rand() % max;

        int aux = v[i];
        v[i] = v[randIndex];
        v[randIndex] = aux;
    }
}

void ordenar(vector<int>& v) {
    for(int i = 0, max = v.size(); i < max; i++) {
        for(int k = 0; k < max; k++) {
            if(v[i] > v[k]) {
                int aux = v[i];
                v[i] = v[k];
                v[k] = aux;
            }
        }
    }
}

// Conjuntos: 3 funções

void exclusivos(vector<int>& v) {
    v.erase( unique( v.begin(), v.end() ), v.end() );
}

void diferentes(vector<int>& v) {
    exclusivos(v);
}

void abandonados(vector<int>& v) {
    exclusivos(v);
}

void show(vector<int>& v) {
    for(int element : v)
        cout << element << " ";
}

int main() {
    
    vector<int> vec = {1, 8, -10, -10, -5, -5, -2, -2, 135, 135};
    diferentes(vec);
    show(vec);
}