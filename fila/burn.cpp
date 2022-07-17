#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;
using matrix = vector<string>;

const char TREE = '#';
const char FIRE = 'o';
const char BURNED = 'x';
const char EMPTY = '.';

struct Pos
{
    int linha;
    int coluna;

    Pos(int l = 0, int c = 0) : linha(l), coluna(c)
    { }
};

vector<Pos> get_neib(Pos p)
{
    int l = p.linha;
    int c = p.coluna;

    return { {l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c} };
}

void show(matrix& mat)
{
    for (auto line : mat)
        cout << line << '\n';
    getchar();
}

void queimar(matrix& mat, Pos pos)
{
    int nl = mat.size();
    int nc = mat[0].size();

    stack<Pos> burn;
    burn.push(pos);
    
    while (!burn.empty())
    {   
        for (auto tree : get_neib(burn.top()))
        {
            if (pos.linha < nl || pos.linha >= nl || pos.coluna < nc || pos.coluna >= nc) continue;
            else if (mat[tree.linha][tree.coluna] == TREE) burn.push(tree);
        }

        Pos toBurn = burn.top();
        mat[toBurn.linha][toBurn.coluna] = FIRE;
        burn.pop();
    }
    
}

int main()
{
    ifstream burn("burn.txt");
    int linhas { 0 };
    int colunas { 0 };
    Pos pos;

    burn >> linhas >> colunas >> pos.linha >> pos.coluna;

    matrix mat;

    for (int i = 0; i < linhas; i++)
    {
        string line;
        burn >> line;
        mat.push_back(line);
    }

    queimar(mat, pos);
    show(mat);

    return 0;
}