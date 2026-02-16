#ifndef FORCA_HPP
#define FORCA_HPP
#include <string>
#include <vector>

/* Jogo da Forca
O jogo da forca consiste em adivinhar uma palavra secreta de determinado comprimento,
digitando uma letra por vez. O jogo termina se o jogador não adivinhar a palavra corretamente
dentro do número de tentativas permitido. O jogo da forca utilizará classes para armazenar a palavra secreta
e as tentativas, uma classe contendo métodos para acompanhar 
o progresso e uma classe para representar a figura da forca.
A lógica do jogo será escrita utilizando diversos recursos da linguagem de programação C++, como structs,
estruturas switch e laços de repetição.*/
class jogoForca
{
public:
    char palpite{};
    int quantidade_palpites{};
    std::string getPalavrasorteada() const;
    jogoForca(const std::vector<std::string>& palavras);
    void imprimeForca(int erros);
private:
   std::string palavrasorteada;
};

std::vector<std::string> lerArquivo();

int escolherLinha(int);

int palpites(jogoForca& x);

void limparBuffer();

#endif
