#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// Busca: 4 funções

bool existe(vector<int> fila, int x) {
    return find(fila.begin(), fila.end(), x) != fila.end();
}

int contar(vector<int> fila, int x) {
    int count = 0;
    for(int element : fila)
        if(element == x)
            count++;
    return count;
}

int procurar(vector<int> fila, int x) {
    int pos = -1;
    for(int i = 0, max = fila.size(); i < max; i++) {
        pos = fila[i] == x ? i : -1;
        break;
    }
    return pos;
}

int procurar_valor(vector<int> fila, int x, int inicio) {
    if (inicio >= fila.size()) {
        cout << "posicao inicial invalida" << endl;
        return -1;
    }

    for(int i = inicio; i < fila.size(); i++)
        return fila[i] == x ? x : -1;
    
}

// Melhor caso: 4 funções

int procurar_menor(vector<int> fila) {
    int MIN = INT_MAX;
    for(int element : fila)
        if(element < MIN)
            MIN = element;
    return MIN;
}

int procurar_pos_menor(vector<int> fila) {
    int MIN = INT_MAX;
    int pos = -1;
    for(int i = 0, max = fila.size(); i < max; i++)
        if(fila[i] < MIN) {
            MIN = fila[i];
            pos = i;
        }
    return pos;
}

int procurar_pos_menor_apartir(vector<int> fila, int inicio) {
    if (inicio >= fila.size()) {
        cout << "posicao inicial invalida" << endl;
        return -1;
    }

    int MIN = INT_MAX;
    int pos = -1;
    for(int i = 0, max = fila.size(); i < max; i++)
        if(fila[i] < MIN) {
            MIN = fila[i];
            pos = i;
        }
    return pos;
}

int procurar_melhor_pos_se(vector<int> fila) {
    int MIN = INT_MAX;
    int pos = -1;
    for(int i = 0, max = fila.size(); i < max; i++)
        if(fila[i] < MIN && fila[i] > 0) {
            MIN = fila[i];
            pos = i;
        }
    return pos;
}

// Contagem: 4 funções

float calcular_stress_medio(vector<int> fila) {
    int total = 0;

    for(int i = 0, max = fila.size(); i < max; i++)
        total += abs(fila[i]);

    return (total / fila.size());
}

string mais_homens_ou_mulheres(vector<int> fila) {
    int totalHomens = 0;
    int totalMulheres = 0;

    for(int i = 0, max = fila.size(); i < max; i++) {
        if(fila[i] > 0)
            totalHomens++;
        else
            totalMulheres++;
    }

    return totalHomens > totalMulheres ? "Homens" : "Mulheres";
}

string qual_metade_eh_mais_estressada(vector<int> fila) {
    int primeiraMetade = (fila.size() / 2);
    int segundaMetade = (fila.size() - primeiraMetade);

    int stressPrimeiraMetade = 0;
    int stressSegundaMetade = 0;

    for(int i = 0; i < primeiraMetade; i++)
        stressPrimeiraMetade += (abs(fila[i]));

    for(int i = 0, max = fila.size(); i < max; i++)
        stressSegundaMetade += (abs(fila[i]));

    return stressPrimeiraMetade > stressSegundaMetade 
                                ? "Primeira metade"
                                : "Segunda metade";
}

string homens_sao_mais_estressados_que_mulheres(vector<int> fila) {
    int totalHomens = 0;
    int totalMulheres = 0;

    for(int i = 0, max = fila.size(); i < max; i++) {
        if(fila[i] > 0)
            totalHomens += fila[i];
        else
            totalMulheres += (abs(fila[i]));
    }

    return totalHomens > totalMulheres ? "Homens" : "Mulheres";
}

int main() {

    vector<int> vec = {1, 8, 7, -10, -5, 4, -3, -2};
    bool deuBom = existe(vec, 8);
    cout << deuBom;

}