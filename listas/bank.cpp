#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

struct Cliente
{
    string nome;
    int documentos;
    int paciencia;

    Cliente(string id = " ", int documentos = 0, int paciencia = 0) : 
    nome(id), documentos(documentos), paciencia(paciencia)
    { }

    string str()
    {
        return nome + ":" + to_string(documentos) + ":" + to_string(paciencia);
    }

};

struct Banco
{
    vector<Cliente*> caixas;
    list<Cliente*> filaEntrada;
    list<Cliente*> filaSaida;
    int documentosRecebidos {0};
    int documentosPerdidos {0};
    int tics {0};

    Banco(int caixas) {
       this->caixas = vector<Cliente*>(caixas);
    }
    
    void insert(Cliente* clientePtr)
    {
        this->filaEntrada.push_front(clientePtr);
    }

    bool isEmpty()
    {
        return caixas.size() > 0;
    }

    void tic()
    {
        /*
        para todos os clientes na fila de saida
            remova cliente da fila

        para todos os caixas
            se existe um cliente nesse caixa
                se o cliente documentos a serem processados
                    processe um documento desse cliente
                se não
                    mova cliente para fila de saída
            se não
                se houver cliente na fila de entrada
                    pegue um cliente da fila de entrada e coloque no caixa

        para cada cliente da fila de entrada
            se a paciencia desse cliente for maior que zero
                decremente um na paciencia
            se não
                ponha esse cliente na fila de saída
        */
    }

    void show()
    {
        for (auto cliente: this->caixas)
            cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";

        cout << "\nna fila de entrada :{ ";
        for (auto fila: this->filaEntrada)
            cout << fila->str() << " ";

        cout << "\nna fila de saida :{ ";
        for (auto fila : this->filaSaida)
            cout << fila->str() << " ";
        
        cout << "}\n";

    }

};


int main()
{
    Banco banco(2);

    while (true)
    {
        string linha, comando;
        getline(cin, linha);
        cout << "$" << linha << endl;

        stringstream ss(linha);
        ss >> comando;

        if (comando == "end") break;

        if (comando == "show")
            banco.show();

        else if (comando == "in")
        {
            string nome;
            int quantidadeDocumentos {0};
            int paciencia {0};
            ss >> nome >> quantidadeDocumentos >> paciencia;
            banco.insert(new Cliente(nome, quantidadeDocumentos, paciencia));
        }

        else if (comando == "init")
        {
            int quantidadeCaixas {0};
            ss >> quantidadeCaixas;
            banco = Banco(quantidadeCaixas);
        }

        else if (comando == "tic")
        {
            banco.tic();
        }

        else if (comando == "finish")
        {
            while(!banco.isEmpty())
                banco.tic();
            
            cout << "recebido: " << banco.documentosRecebidos << endl;
            cout << "perdidos: " << banco.documentosPerdidos - 1 << endl;
            cout << "tics: " << banco.tics << endl;
        }

        else cout << "fail: comando invalido" << endl;

    }
    
    return 0;
}