#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> data)
{
    cout << "[ ";
    for (auto row : data)
        cout << row << " ";
    cout << "]" << endl;
}

void showResult(vector<int> data)
{
    show(data);
}

void readInput(vector<int>& data, int& moves)
{
    int size {};
    int element {};
    
    cout << "insira o tamanho do vetor e quantidade de rotacao: ";
    cin >> size >> moves;

    cout << "insira os elementos do vetor: ";

    while(size-- > 0)
    {
        cin >> element;
        data.push_back(element);
    }
}

void moveToRight(vector<int>& data, int moves)
{   
    if (moves <= 0) return ;

    int size = data.size() - 1;
    int first = data[size];
    for (int i = size; i >= 0; i--)
        data[i] = data[i - 1];

    data[0] = first;
    moveToRight(data, moves - 1);
}

int main()
{
    int moves {};
    vector<int> data{};

    readInput(data, moves);
    show(data);
    moveToRight(data, moves);
    showResult(data);

    return 0;
}