#include <iostream>
#include <vector>
#include <ctime>   
#include "forca.hpp"

int main()
{
    int continuar = 0;
    srand(time(nullptr));
    while(continuar != -1)
    {
       std::vector<std::string> palavras = lerArquivo();
       jogoForca myGame(palavras);
       palpites(myGame);
       std::cout << "Quer repetir? 1 para sim e -1 para nao\n";
       std::cin >> continuar;
       getchar();
    }
    getchar();
}