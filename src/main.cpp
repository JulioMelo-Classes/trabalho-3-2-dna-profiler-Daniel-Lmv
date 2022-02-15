#include <iostream>
#include "../include/interface.hpp"
#include "../include/dados.hpp"
#include "../include/perfil.hpp"

int main(int argc, char *argv[]){
  //Construtores.
  Interface inter;  
  Dados dados;
  Perfil perfil;

  //Variáveis auxiliares.
  std::vector<std::string*> p;
  std::vector<std::string> p2;
  std::pair<int,std::string> resultado;
  std::vector<int> posicoes;
  std::string sequencia;
  
  //Começo do programa.
  inter.inicio();

  //Validação da entrada, se não for validado, sai do programa.
  int aux= inter.validar_entrada1(argc);
  if(aux==0){
    return 0;
  }
  aux = inter.validar_entrada2(argv[1], argv[3]);
  if(aux==0){
    return 0;
  }
  
  //Texto com o nome dos arquivos a serem carregados.
  inter.carregar_dados(argv[2],argv[4]);
  
  //Carregamento da base de dados.
  dados.carregar_base(argv[2]);
  
  //Carregamento do DNA.
  perfil.carregar_sequencia(argv[4]);
  
  //Texto concluindo o carregamento.
  inter.concluir_carregar_dados();
  
  //Passando a sequência de STRS para um ponteiro.
  p = dados.get_sequencias();
  
  //Função para calcular qual a maior sequência dos STRS.
  p2 = perfil.calcular(p);
  
  //Função para procurar o perfil do DNA na base de dados.
  resultado=dados.procurar_na_base(p2);
  
  //Função para pegar as posições para printar os caracteres especiais.
  posicoes=perfil.getvetorposicoes();
  
  //Função pegando a sequência de STRS.
  sequencia=perfil.getsequencia();
  
  //Função printando se houve match ou não.
  inter.match(resultado,posicoes,sequencia);

  //Fim do programa.
  return 0;
}