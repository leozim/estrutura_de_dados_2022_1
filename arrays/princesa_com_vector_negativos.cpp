#include <iostream>
#include <vector>
using namespace std;

void mostrar_vetor(vector<int> vec, int espada){
    cout << "[";
    bool eh_o_primeiro = true;

    for(int i = 0; i < vec.size(); i++){
            if(eh_o_primeiro)
                eh_o_primeiro = false;
            
            else
                cout << " ";
            
            if(vec[i] == espada)
               cout << vec[i] << ">";

            else
                cout << vec[i];
              
    }
    cout << "]" << endl;
}

void matar(vector<int> &vec, int espada){
    if (vec[espada - 1] < 0)
        espada *= -1;
    vec.erase(vec.begin() + espada);
}

int proximoComEspada(vector<int> &vec, int vivo){
    return *vec.begin() + 1;
}

void preencher(vector<int> &vec, int size, int sinal){
    for(int i = 0; i < size; i++){
        vec.push_back((i + 1) * sinal);
        sinal *= -1;
    }
}

int main(void)
{
    int size = 0;
    int espada = 0;
    int sinal {};

    cin >> size;
    cin >> espada;
    cin >> sinal;

    vector<int> vec;

    preencher(vec, size, sinal);
    mostrar_vetor(vec, espada);

    while(vec.size() > 1){
        matar(vec, espada);
        espada = (espada + 1) % vec.size();
        mostrar_vetor(vec, espada);
    }

    return 0;
}