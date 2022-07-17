#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct fila
{
    stack<int> deposito;
    stack<int> prateleira;
    string saida;

    void queue(int x)
    {
        this->deposito.push(x);
    }

    void stackUp()
    {
        if (this->prateleira.empty())
            while (!this->deposito.empty())
            {
                this->prateleira.push(this->deposito.top());
                this->deposito.pop();
            }
    }

    void output()
    {
        stackUp();
        this->saida += to_string(this->prateleira.top()) + '\n';
    }

    void dequeue()
    {
        stackUp();
        this->prateleira.pop();
    }

};


int main()
{
    int query { 0 };
    cin >> query;

    fila fila;

    pair<int, int> commands { 0, 0 };
    while (query-- != 0)
    {
        cin >> commands.first;
        switch (commands.first)
        {
        case 1 :
            cin >> commands.second;
            fila.queue(commands.second);
            break;
        
        case 2 :
            fila.dequeue();
            break;

        case 3 :
            fila.output();
            break;

        default:
            break;
        }
    }

    cout << fila.saida;

    return 0;
}