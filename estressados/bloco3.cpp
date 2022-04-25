#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Map - Manipulação: 3 funções

vector<int> sozinhos(const vector<int>& v) {
    vector<int> repetidos;

    for(int i = 0, max = v.size(); i < max - 1; i++) {
        for(int k = i + 1; k < max; k++) {
            if(v[i] == v[k])
                repetidos.push_back(i);
        }
    }
    
}

// Proximidade: 2 funções

int briga(const vector<int>& v);

vector<int> apaziguados(const vector<int>& v);

// Sequências: 3 funções

int quantos_times(const vector<int>& v);

vector<int> maior_time(const vector<int>& v);

int sem_time(vector<int> vet);

int main() {
    
    vector<int> vec = {1, 8, 7, -10, -5, 4, -3, -2};

}
