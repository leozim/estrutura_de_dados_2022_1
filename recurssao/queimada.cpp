#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>

using namespace std;

const char TREE = '#';
const char FIRE = 'o';
const char BURNED = 'x';
const char EMPTY = '.';

void mostrarDoArquivo(vector<string> mapa) {
    for(auto line : mapa) cout << line << '\n';
    getchar();
}

void mostrar(vector<string> mapa) {
    for(auto line : mapa) cout << line << '\n';
}

void queimar(vector<string> mapa, int posLinha, int posColuna) {
    int nl = mapa.size();
    int nc = mapa[0].size();

    if(posLinha < nl || posLinha >= nl || posColuna < nc || posColuna >= nc) return;

    if(mapa[posLinha][posColuna] != TREE) return;

    mapa[posLinha][posColuna] = FIRE;
    mostrarDoArquivo(mapa);

    queimar(mapa, posLinha, posColuna - 1);
    queimar(mapa, posLinha - 1, posColuna);
    queimar(mapa, posLinha, posColuna + 1);
    queimar(mapa, posLinha + 1, posColuna);

    mapa[posLinha][posColuna] = BURNED;
    mostrar(mapa);

}

// MAIN LENDO DO ARQUIVO INPUT.TXT
int main(void) {

    ifstream arquivo("input.txt");

    vector<string> mapa;
    int numeroLinhas {};
    int numeroColunas {};
    int linhaParaQueimar {};
    int colunaParaQueimar {};
    arquivo >> numeroLinhas >> numeroColunas >> linhaParaQueimar >> colunaParaQueimar;

    for(int i = 0; i < numeroLinhas; i++) {
        string line;
        arquivo >> line;
        mapa.push_back(line);
    }

    mostrarDoArquivo(mapa);
    queimar(mapa, linhaParaQueimar, colunaParaQueimar);

    return 0;
}

/*
// MAIN LENDO DO CONSOLE
int main(void) {

    vector<string> map;

    int numeroLinhas {};
    int numeroColunas {};
    cin >> numeroLinhas >> numeroColunas;

    int linhaParaQueimar {};
    int colunaParaQueimar {};
    cin >> linhaParaQueimar >> colunaParaQueimar;

    for(int i = 0; i < numero_linhas; i++) {
        string line;
        cin >> line;
        map.push_back(line);
    }

    mostrar(mapa);
    queimar(map, linhaParaQueimar, colunaParaQueimar);

    return 0;
}
*/
