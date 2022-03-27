#include <iostream>
using namespace std;

const int MORTO = 0;

int achar_vivo(int vet[], int size, int inicio){
    int pos = (inicio + 1) % size;
    while(vet[pos] == MORTO)
        pos = (pos + 1) % size;
    return pos;
}

void mostrar_vetor(int vet[], int size, int espada){
    cout << "[";

    for(int i = 0; i < size; i++){
        if(vet[i] != MORTO)
            printf(" %d", vet[i]);
        if(i == espada)
            printf(">");
    }
    cout << " ]" << endl;
}

int main(){
    int size = 0;
    int espada = 0;

    cin >> size;
    cin >> espada;

    int vet[size];

    for(int i = 0; i < size; i++)
        vet[i] = i + 1;

    espada = espada - 1;
    mostrar_vetor(vet, size, espada);

    int qtd = size - 1;
    while(qtd--){
        int vai_morrer = achar_vivo(vet, size, espada);
        vet[vai_morrer] = MORTO;
        espada = achar_vivo(vet, size, vai_morrer);
        mostrar_vetor(vet, size, espada);
    }
}