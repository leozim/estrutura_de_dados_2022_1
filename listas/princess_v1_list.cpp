#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

void mostrar_lista(list<int>& lista, int espada){
    cout << "[ ";
    for(auto it = lista.begin(); it != lista.end(); it++)
    {
        if (*it == espada)
            cout << *it << ">" << " ";
        else
            cout << *it << " ";
    }
    cout << "]" << endl;
}

void matar(list<int> &lista, int espada){
    auto it = lista.begin();

    while (*it != espada) it++;

    if (it == lista.end()) lista.front();
        
    else lista.remove(*next(it));

}

int main(void)
{
    int size = 0;
    int espada = 0;

    cin >> size;
    cin >> espada;

    list<int> lista;

    for(int i = 0; i < size; i++){
        lista.push_back(i + 1);
    }

    int aux = lista.size();
    while(aux > 1){
        mostrar_lista(lista, espada);
        matar(lista, espada);
        espada = (espada + 1) % size;
        aux--;
    }

    mostrar_lista(lista, espada);

    return 0;
}