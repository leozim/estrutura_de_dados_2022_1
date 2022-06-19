#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void mostrar_vetor(list<int>& lista, int espada){
    cout << "[ ";
    for(auto it = lista.begin(); it != lista.end(); it++)
    {
        if (*it > 0 && *it == espada)
            cout << *it << ">" << " ";
        else if (*it < 0 && *it == (-espada))
            cout << "<" << *it << " ";
        else
            cout << *it << " ";
    }
    cout << "]" << endl;
}

void matar(list<int> &lista, int espada){
    auto it = lista.begin();

    while (*it != espada) it++;

    if (it == lista.end() && *it > 0) lista.pop_front();
    else if (it == lista.begin() && *it < 0) lista.pop_back();
    else if (*it > 0) lista.remove(*next(it));
    else if (*it < 0) lista.remove(*prev(it));

}

void preencher(list<int> &lista, int size, int sinal){
    for(int i = 0; i < size; i++){
        lista.push_back((i + 1) * sinal);
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

    list<int> lista;

    preencher(lista, size, sinal);
    mostrar_vetor(lista, espada);

    while(lista.size() > 1){
        matar(lista, espada);
        espada = (espada + 1) % lista.size();
        mostrar_vetor(lista, espada);
    }

    return 0;
}