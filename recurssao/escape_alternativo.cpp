#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;
using matrix = vector<string>;

const char WALL = '#';
const char TODRILL = 'o';

struct Pos
{
    int linha;
    int coluna;

    Pos(int l, int c) : linha(l), coluna(c)
    { }

};

void show(matrix& mat)
{
    for (auto line : mat)
        cout << line << '\n';
    getchar();
}

vector<Pos> get_neib(Pos p)
{
    int l = p.linha;
    int c = p.coluna;
    return { {l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c} };
}


vector<Pos> shuffle(vector<Pos> vet)
{
    random_shuffle(begin(vet), end(vet));
    return vet;
}

bool pode_furar(matrix& mat, Pos posicao)
{
    int numeroLinha = mat.size();
    int numeroColuna = mat[0].size();

    int linha = posicao.linha;
    int coluna = posicao.coluna;

    {
        if (linha < 0 || linha >= numeroLinha || coluna < 0 || coluna >= numeroColuna)
            return false;

        if (mat[linha][coluna] != WALL)
            return false;
    }

    int cont { 0 };
    for (auto vizinho : get_neib(posicao))
    {
        int l = vizinho.linha;
        int c = vizinho.coluna;
        if (l < 0 || l >= numeroLinha || c < 0 || c >= numeroColuna)
            continue;
        if (mat[vizinho.linha][vizinho.coluna] == WALL)
            cont++;
    }

    return cont >= 3;

}

void furar(matrix& mat, Pos posicao)
{   
    int l = posicao.linha;
    int c = posicao.coluna;

    if (!pode_furar(mat, posicao)) return;

    mat[l][c] = TODRILL;
    show(mat);
    for (auto vizinho : shuffle(get_neib(posicao)))
        furar(mat, vizinho);
}

int main(void)
{
    ifstream file("inputEscape.txt");
    int nl { 0 };
    int nc { 0 };
    matrix mat;

    file >> nl >> nc;

    for (int i = 0; i < nl; i++)
    {
        string line;
        file >> line;
        mat.push_back(line);
    }

    furar(mat, Pos(1, 1));

}
