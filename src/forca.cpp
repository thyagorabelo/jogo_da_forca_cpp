#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "forca.hpp"

void limparBuffer() 
{
    while (std::cin.get() != '\n');
}

void jogoForca::imprimeForca(int erros)
{
    std::vector<std::string> fases = {
        R"(  +---+
  |   |
      |
      |
      |
      |
=========)",

        R"(  +---+
  |   |
  O   |
      |
      |
      |
=========)",

        R"(  +---+
  |   |
  O   |
  |   |
      |
      |
=========)",

        R"(  +---+
  |   |
  O   |
 /|   |
      |
      |
=========)",

        R"(  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========)",

        R"(  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========)",

        R"(  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========)"
    };

    std::cout << fases[erros] << '\n';
}

std::vector<std::string> lerArquivo()
{
    std::ifstream arquivo("dados/frutas.txt");
    std::vector<std::string> linhas;
    std::string palavra;
    if(arquivo.is_open())
    {
        while(std::getline(arquivo, palavra))
        {
            linhas.push_back(palavra);
        }
        arquivo.close();
    }
    return linhas;
}

int escolherLinha(int x)
{
    if(x <= 0) return -1;
    int choice = rand() % x;
    return choice;
}

jogoForca::jogoForca(const std::vector<std::string>& palavras)
{
    int i = escolherLinha(palavras.size());
    if(i != -1)
    {
        palavrasorteada = palavras[i];
    }
}

std::string jogoForca::getPalavrasorteada() const
{
    return palavrasorteada;
}

int palpites(jogoForca& x)
{
    int erros = 0;
    x.quantidade_palpites = 6;
    std::string palavra = x.getPalavrasorteada();
    std::string progresso(palavra.size(), '_');
    while (x.quantidade_palpites > 0 && progresso != palavra)
    {
       system("cls");
       std::cout << x.quantidade_palpites << " tentativas para advinhar a fruta da vez...\n\n";
       bool acertou = false;
       for(char c : progresso)
       {
           std::cout << c << ' ';
       }
       std::cout << "\n\n\n";
       x.imprimeForca(erros);
        std::cout << "\n\nDigite uma letra: ";
        std::cin >> x.palpite;
        limparBuffer();
       for(size_t i = 0; i < palavra.size(); i++)
       {
          if(palavra[i] == x.palpite) 
          {
             progresso[i] = x.palpite;
             acertou = true;
           }
        }
          if(!acertou && x.quantidade_palpites > 0)
          {
              x.quantidade_palpites--;
              std::cout << "Letra incorreta. " << x.quantidade_palpites << " tentativas restantes\n";
              erros++;
              x.imprimeForca(erros);
           }
        std::cout << '\n';
        system("pause");
     }
    if(progresso == palavra) std::cout << "Muito bom!! Acertou a palavra\n" << palavra << '\n';
    else std::cout << "Infelizmente nao deu tempo de acertar a palavra, que era: " << palavra << '\n';
     return 0;
}



    
    
    
      





