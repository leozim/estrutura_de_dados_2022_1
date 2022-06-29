#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;
using matrix = vector<string>;

const char WALL = '#';
const char PATH = '.';
const char DRILLED = '_';

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

pair<Pos, Pos> path(matrix& mat)
{
    Pos start;
    Pos end;
    for (int i = 0, size = mat.size(); i < size; i++)
        for (int k = 0, kSize = mat[0].size(); k < kSize; k++)
        {
            if (mat[i][k] == 'I')
            {
                start = Pos(i, k);
            }

            if (mat[i][k] == 'F')
            {
                end = Pos(i, k);
            }

        }

    return make_pair(start, end);

}

bool furar(matrix& mat, Pos pos, Pos end)
{
    int l = pos.linha;
    int c = pos.coluna;

    if (mat[l][c] != DRILLED)
        return false;
    if (l == end.linha && c == end.coluna)
    {
        mat[l][c] = PATH;
        return true;
    }

    mat[l][c] = PATH;
    for (auto neighbor : get_neib(pos))
    {
        if (furar(mat, neighbor, end))
            return true;
    }

    mat[l][c] = DRILLED;
    return false;

}

void escape(matrix& mat)
{
    pair<Pos, Pos> par = path(mat);
    furar(mat, par.first, par.second);
}

int main()
{
    ifstream file("inputEscape.txt");
    int nl {0};
    int nc {0};
    matrix mat;

    file >> nl >> nc;

    for (int i = 0; i < nl; i++)
    {
        string line;
        file >> line;
        mat.push_back(line);
    }

    show(mat);
    cout << endl;
    escape(mat);
    show(mat);

}
