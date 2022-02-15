#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

class Dados{
  private:

    std::vector<std::string> base;//<! vetor de strings com a base a ser lida.

    std::vector<std::string*> sequencias;//<! vetor de ponteiro para strings para guardar as STRS.

    int qnt_da_linha = 0;//<! inteiro para guardar a quantidade de itens lidos na primeira linha.

  public:  
    
    /**
     * Constructor de um novo objeto Dados.
     */
    Dados();

    /**
     * Função para ler a base de dados.
     * 
     * @param arquivo nome do arquivo a ser lido.
     */
    void carregar_base(char* arquivo);

    /**
     * Função para pegar a sequência de STRS.
     * 
     * @return std::vector<std::string*> vetor de ponteiros para strings com a sequência de STRS.
     */
    std::vector<std::string*> get_sequencias();

    /**
     * Função para procurar o perfil do DNA na base de dados.
     * 
     * @param a vetor de strings a ser recebido.
     * @return std::pair<int,std::string> par contendo um inteiro e uma string.
     */
    std::pair<int,std::string> procurar_na_base(std::vector<std::string> a);
};
#endif