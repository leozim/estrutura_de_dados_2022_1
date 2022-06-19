#include <iostream>

using namespace std;

void vet(int vec[], int size, int index = 0)
{
    if (size <= 0)
        return;
    cout << vec[index] << " ";
    size--;
    vet(vec, size, ++index);
}

void rvet(int vec[], int size,int begin = 0)
{
    int aux {0};
    if (begin < size)
    {
        aux = vec[begin];
        vec[begin] = vec[size - 1];
        vec[size - 1] = aux;
        rvet(vec, size - 1, begin++);
    }
}

int soma(int vec[], int size)
{
    if (size == 0)
        return vec[0];

    return vec[size - 1] + soma(vec, size--);
}

int mult(int vec[], int size)
{
    if (size == 0)
        return vec[0];

    return vec[size - 1] * soma(vec, size--);
}

int min(int vec[], int size)
{
    int menor = vec[0];
    int index {0};

    if (size <= 0)
        return menor;

    if (vec[index] < menor)
        menor = vec[index];

    return min(vec, size--);
    
}

void inv(int vec[], int size)
{
    rvet(vec, size);
    vet(vec, size);
}

int main()
{
    int size {0};
    cin >> size;

    int vec[size];

    for(int i = 1; i <= size; i++)
        vec[i - 1] = i;

    cout << "[ ";
    vet(vec, size);
    cout << "]";

    return 0;
}