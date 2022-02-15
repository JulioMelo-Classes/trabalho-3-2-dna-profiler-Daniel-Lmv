#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

class Perfil{
  private:
    std::string sequencia;//<! string com a sequência de STRS.

    std::vector<std::string> user;//<! vetor de string contendo a quantidade de STRS do perfil.

    std::vector<int> user_pos;//<! vetor contendo a posição de onde será impresso os caracteres especiais.

  public:
    
    /**
     * Construtor de um novo objeto Perfil.
     */
    Perfil();

    /**
     * Função para carregar a sequência de DNA.
     * 
     * @param arquivo nome do arquivo a ser lido.
     */
    void carregar_sequencia(char* arquivo);

    /**
     * Função para calcular a maior sequência de STRS.
     * 
     * @param a vetor de ponteiros indicando quais STRS serão calculados.
     * @return std::vector<std::string> vetor com a quantidade de STRS do perfil.
     */
    std::vector<std::string> calcular(std::vector<std::string*> a);

    /**
     * Função para pegar o vetor com as posições para a impressão dos caracteres especiais.
     * 
     * @return std::vector<int> vetor com inteiro indicando as posições.
     */
    std::vector<int> getvetorposicoes();

    /**
     * Função para pegar a sequência de DNA.
     * 
     * @return std::string string contendo a sequência de DNA. 
     */
    std::string getsequencia();

};
#endif