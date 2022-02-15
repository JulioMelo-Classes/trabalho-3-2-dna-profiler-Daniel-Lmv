#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

class Interface{
  public:

    /**
    * Construtor de um novo objeto Interface.
    */
    Interface();

    /**
     * Função para imprimir o cabeçalho do programa.
     */
    void inicio();

    /**
     * Função para validar se a quantidade de argumentos passados estão corretos.
     *
     * @param a quantidade de argumentos passados.
     * @return int inteiro contendo 1 ou 0.
     */
    int validar_entrada1(int a);
    
    /**
     * Função para validar se os argumentos passados estão corretos.
     *
     * @param b primeiro argumento que deve ser "-d".
     * @param c segundo argumento que deve ser "-s".
     * @return int inteiro contendo 1 ou 0.
     */
    int validar_entrada2(char* b, char* c);   
    
    /**
     * Função para imprimir o início do carregamento de dados.
     *
     * @param b nome do primeiro arquivo.
     * @param c nome do segundo arquivo.
     */
    void carregar_dados(char* b, char* c);

    /**
    * Função para imprimir a conclusão do carregamento de dados.
    */
    void concluir_carregar_dados();

    /**
     * Função para imprimir o match de DNA. 
     *
     * @param a par contendo um inteiro que não será utilizado aqui e o nome do match.
     * @param b vetor de inteiros contendo as posições para impressão especial.
     * @param d string contendo a sequência de DNA.
     */
    void match(std::pair<int,std::string> a, std::vector<int> b, std::string d);
};
#endif