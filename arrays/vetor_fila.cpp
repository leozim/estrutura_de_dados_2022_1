#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> data)
{
    cout << "[ ";
    for (int element : data)
        cout << element << " ";
    cout << "]" << endl;
}

void showResult(vector<int> data)
{
    cout << "RESULTADO: ";
    show(data);
}

void readInput(vector<int>& queue, vector<int>& toLeave)
{
    int sizeQueue {};
    int sizeToLeave {};
    int id {};

    cout << "insira o tamanho do vetor: ";
    cin >> sizeQueue;

    sizeToLeave = sizeQueue;

    cout << "insira os identificadores da fila: ";
    while (sizeQueue-- > 0)
    {
        cin >> id;
        queue.push_back(id);
    }

    cout << "informe quem sairar da fila: ";
    while (cin >> id)
    {
        toLeave.push_back(id);
    }
    
}

void leaveQueue(vector<int>& queue, vector<int> toLeave)
{
    for (auto element : toLeave)
    {
        for (int i = 0, size = queue.size(); i < size; i++)
        {
            if(element == queue[i])
                queue.erase(queue.begin() + i);
        }
    }
}

int main()
{
    vector<int> queue {};
    vector<int> toLeave {};

    readInput(queue, toLeave);

    cout << "FILA: ";
    show(queue);
    cout << "SAIRAO: ";
    show(toLeave);
    leaveQueue(queue, toLeave);

    showResult(queue);

    return 0;
}