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

    Pos(int l, int c) : linha(l), coluna(c)
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

void path(matrix& mat, Pos start, Pos end)
{
    for (int i = 0, size = mat.size(); i < size; i++)
        for (int k = 0, kSize = mat[0].size(); k < kSize; k++)
        {
            if (mat[i][k] == 'I')
            {
                mat[i][k] = DRILLED;
                start = Pos(i, k);
            }

            if (mat[i][k] == 'F')
            {
                mat[i][k] == DRILLED;
                end = Pos(i, k);
            }

        }

}

void furar(matrix& mat, Pos pos, Pos end)
{
    int l = pos.linha;
    int c = pos.coluna;

    if (l < 0 || l >= mat.size() || c < 0 || c >= mat[0].size())
        return;
    else if (mat[l][c] == WALL || mat[l][c] == PATH)
        return;

    mat[l][c] = PATH;

    furar(mat, Pos(l, c - 1), end);
    furar(mat, Pos(l - 1, c), end);
    furar(mat, Pos(l, c + 1), end);
    furar(mat, Pos(l + 1, c), end);

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
    path(mat, Pos(5, 3), Pos(9, 5));
    furar(mat, Pos(1, 1), Pos(9, 5));
    show(mat);

}
