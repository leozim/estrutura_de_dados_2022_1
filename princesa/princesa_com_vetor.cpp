#include <iostream>
using namespace std;

void mostrar_vetor(int vet[], int size, int espada){
    cout << "[";
    bool eh_o_primeiro = true;

    for(int i = 0; i < size; i++){
            if(eh_o_primeiro)
                eh_o_primeiro = false;
            
            else
                cout << " ";
            
            if(vet[i] == (espada))
               cout << vet[i] << ">";

            else
                cout << vet[i];
              
    }
    cout << endl;
}

int girar_vetor(int v[], int size){
    int primeiro = v[0];
    
    for(int i = 1; i < size; i++){
        v[i - 1] = v[i];
    }

    v[size - 1] = primeiro;
    return primeiro;
}

int main(void)
{
    int size = 0;
    int espada = 0;

    cin >> size;
    cin >> espada;

    int v[size];

    for(int i = 0; i < size; i++){
        v[i] = i + 1;
    }

    mostrar_vetor(v, size, espada);

    while(v[0] != espada){
        girar_vetor(v, size);
    }

    while(size > 1){
        girar_vetor(v, size);
        girar_vetor(v, size);

        size--;
        espada = v[0];
        mostrar_vetor(v, size, espada);
    }

    return 0;
}