#include <iostream>

int main()
{
    /* INICIALIZAÇÃO DE VARIÁVEIS */

    // copy assign
    int x = 0;

    // constructor inicialization
    int y(5);

    // braces inicialization - recommended
    int z { 5 };
    int zz {};

    std::cout << "Hello, World! " << zz;
}