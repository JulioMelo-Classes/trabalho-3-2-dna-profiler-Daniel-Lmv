#include "../include/perfil.hpp"

/* Implementação da classe Perfil */

Perfil::Perfil(){};

//Função para carregar a sequência de DNA.
void Perfil::carregar_sequencia(char* arquivo){
  std::ifstream arq1;
  
  arq1.open(arquivo,std::ios::in);
  getline(arq1,sequencia);

  arq1.close();
}

//Função para calcular a maior sequência de STRS.
std::vector<std::string> Perfil::calcular(std::vector<std::string*> a){  
  std::string chave;
  int maior=0;
  int aux=0;
  int pos=0;

  for(int i=0;i<a.size();i++){
    chave = *a[i];
    for(int j=0;j<sequencia.size()-3;j++){
      if(chave[0]==sequencia[j] && chave[1]==sequencia[j+1] && chave[2]==sequencia[j+2] && chave[3]==sequencia[j+3]){
        aux++;
        j=j+3;
        if(aux>maior){
          maior=aux;
          pos=j;
        }
      }else{
        aux=0;
      }
    }
    std::string m = std::to_string(maior);
    user.push_back(m);
    user_pos.push_back(pos);
    user_pos.push_back(maior);
    maior=0;
  }    

  for(int i=0;i<user_pos.size()-1;i=i+2){
    int aux=user_pos[i+1];
    aux = aux*4;
    aux = user_pos[i]-aux;
    user_pos[i+1]= aux;
  }
  return user;
}

//Função que retorna um vetor com as posições para a impressão dos caracteres especiais.
std::vector<int> Perfil::getvetorposicoes(){
  return user_pos;
}

//Função que retorna um ponteiro para a localização da sequência de DNA.
std::string Perfil::getsequencia(){
  return sequencia;
}