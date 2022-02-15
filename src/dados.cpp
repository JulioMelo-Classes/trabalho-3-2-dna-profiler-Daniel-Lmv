#include "../include/dados.hpp"

/* Implementação da classe Dados */
Dados::Dados(){};

//Função que carrega o primeiro arquivo e o armazena na base.
void Dados::carregar_base(char* arquivo){
  std::ifstream arq1;
  std::string line;
  std::string delimiter = ",";
  size_t pos = 0;
  int aux = 0;

  arq1.open(arquivo,std::ios::in);
  while(! arq1.eof()){
    getline(arq1,line);
    //separar a string quando achar vírgulas.
    while((pos = line.find(delimiter))!=std::string::npos){
      base.push_back(line.substr(0, pos));
      line.erase(0, pos + delimiter.length());
      if(aux==0){
        qnt_da_linha++;
      }
    }
    base.push_back(line);
    if(aux==0){
      qnt_da_linha++;
    }
    aux=1;
  }
  arq1.close();
}

//Função que retorna as sequências de STRS.
std::vector<std::string*> Dados::get_sequencias(){
  for(int i=1;i<qnt_da_linha;i++){
    sequencias.push_back(&base[i]);
  } 
  return sequencias;
}

//Função que procura o perfil do DNA na base de dados.
std::pair<int,std::string> Dados::procurar_na_base(std::vector<std::string> a){
  int booleano=1;
  
  for(int i=0;i<base.size();i++){
    if(a[0][0]==base[i][0]){
      for(int j=1;j<a.size();j++){
        if(a[j][0]!=base[i+j][0]){
          booleano=0;
        }
      }
      if(booleano==1){
        return{1,base[i-1]};
      }
    }
  }
  return{0,""};
}