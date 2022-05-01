#include <iostream>
#include <sstream>

int ler_inteiro()
{
    while(true)
    {
        std::cout << "Digite um inteiro: " << std::endl;
        std::string line;

        getline(std::cin, line);
        std::stringstream ss(line);

        int inteiro {};
        if(ss >> inteiro)
            return inteiro;
    }
}

std::string ler_nome()
{
    std::string nome {};
    std::cout << "Digite seu nome: " << std::endl;
    if(getline(std::cin, nome, '\n'))
        return nome;
    return "";
}

void buffer_converter_tipos(int &inteiro, float &medida, std::string &fruta)
{
    std::stringstream ss("6 6.5 banana");
    ss >> inteiro >> medida >> fruta;
}

int main()
{
    int inteiro { ler_inteiro() };
    std::cout << "Seu inteiro eh: " << inteiro << std::endl;

    std::string nome { ler_nome() };
    std::cout << "Seja bem-vindo: " << nome << std::endl;

    int num {};
    float medida {};
    std::string fruta {};

    buffer_converter_tipos(num, medida, fruta);
    std::cout << num << medida << fruta << std::endl;

    // std::string nome {};
    // while(getline(std::cin, nome))
        // std::cout << "Seja bem-vindo: " << nome << std::endl;
}