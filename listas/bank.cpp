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

    bool hasDocuments()
    {
        return documentos > 0;
    }

    bool hasPaciencia()
    {
        return paciencia > 0;
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

    bool caixaIsEmpty()
    {
        return caixas.size() > 0;
    }

    bool filaEntradaIsEmpty()
    {
        return filaEntrada.size() > 0;
    }

    bool filaSaidaIsEmpty()
    {
        return filaSaida.size() > 0;
    }

    void tic()
    {
        if ( !filaSaidaIsEmpty() )
        {
            for (auto it = this->filaSaida.begin(), end = this->filaSaida.end(); it != end; it++)
            {
                this->filaSaida.erase(it);
            }
        }

        if ( !caixaIsEmpty() )
        {
            for (auto it = this->caixas.begin(), end = this->caixas.end(); it != end; it++)
            {
                Cliente *cliente = *it;
                if (cliente->hasDocuments())
                    documentosRecebidos = cliente->documentos;
                else
                {
                    this->filaSaida.push_back(*it);
                    this->caixas.erase(it);
                }
            }
        }

        else
        {
            if (!this->filaEntradaIsEmpty())
            {
                for (auto it = this->filaEntrada.begin(), end = this->filaEntrada.end(); it != end; it++)
                {
                    this->caixas.push_back(*it);
                }
            }
        }

        if (!this->filaEntradaIsEmpty())
        {
            for (auto it = this->filaEntrada.begin(), end = this->filaEntrada.end(); it != end; it++)
                {
                    Cliente *cliente = *it;
                    if (cliente->hasPaciencia())
                        cliente->paciencia--;
                    else
                    {
                        this->filaSaida.push_back(cliente);
                        this->filaEntrada.erase(it);
                    }
                        
                }
        }

    }

    void show()
    {
        for (auto cliente: this->caixas)
            cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";

        cout << "\nna fila de entrada :{ ";
        for (auto fila: this->filaEntrada)
            cout << fila->str() << " ";
        cout << "}";

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
            while(!banco.caixaIsEmpty())
                banco.tic();
            
            cout << "recebido: " << banco.documentosRecebidos << endl;
            cout << "perdidos: " << banco.documentosPerdidos - 1 << endl;
            cout << "tics: " << banco.tics << endl;
        }

        else cout << "fail: comando invalido" << endl;

    }
    
    return 0;
}