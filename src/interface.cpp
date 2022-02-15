#include "../include/interface.hpp"


/* Implementação da classe Interface */

Interface::Interface(){};

//Texto com o cabeçalho do programa.
void Interface::inicio(){
  std::cout<<"\n=================================================="<<std::endl;
  std::cout<<"  Welcome to the Basic DNA Profiler, v1.0"<<std::endl;
  std::cout<<"  Copyright (C) 2021, Selan R. dos Santos"<<std::endl;
  std::cout<<"=================================================="<<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"\x1B[34mThis program loads a DNA database and a unknown\nDNA sequence and tries  to find a match between\nthe input DNA sequence and the DNA database.\033[0m"<<std::endl;
}

//Função validando a quantidade de argumentos passados.
int Interface::validar_entrada1(int a){
  int boleano=1;
  
  if(a<5){
    boleano=0;
  }
  if(boleano==0){
    std::cout<<"\n\x1B[31m[+] Argumentos de entrada passados incorretamente! Faltando Argumentos!\033[0m"<<std::endl;
    std::cout<<"\x1B[31m[+] Usage: dna_profiler -d <database_file> -s <dna_sequence_file>\033[0m"<<std::endl;
  }
  return boleano;
}

//Função validando se os argumentos de entrada foram passados corretamente.
int Interface::validar_entrada2(char* b, char* c){
  int boleano=1;
  char* aux2;
  aux2= strstr(b,"-d");
  
  if(aux2==NULL){
    boleano=0;
    std::cout<<"\n\x1B[31m[+] Argumentos de entrada passados incorretamente! Use '-d' para o primeiro argumento\033[0m"<<std::endl;
    std::cout<<"\x1B[31m[+] Usage: dna_profiler -d <database_file> -s <dna_sequence_file>\033[0m"<<std::endl;
  }
  
  aux2=strstr(c,"-s");
  if(aux2==NULL){
    boleano=0;
    std::cout<<"\n\x1B[31m[+] Argumentos de entrada passados incorretamente! Use '-s' para o segundo argumento\033[0m"<<std::endl;
    std::cout<<"\x1B[31m[+] Usage: dna_profiler -d <database_file> -s <dna_sequence_file>\033[0m"<<std::endl;
  }
  return boleano; 
}

//Texto iniciando o carregamento de dados.
void Interface::carregar_dados(char* b, char* c){
  std::cout<<"\n[+] Preparing to read the DNA Database file [\x1B[31m"<<b<<"\033[0m]"<<std::endl;
  std::cout<<"\[+] Preparing to read the unknown DNA sequence file [\x1B[31m"<<c<<"\033[0m]"<<std::endl;
  std::cout<<"[+] Processing data, please wait."<<std::endl;
}

//Texto concluindo o carregamento de dados.
void Interface::concluir_carregar_dados(){
  std::cout<<"\n[+] Input files sucessfully read."<<std::endl;
  std::cout<<"[+] Searching the database for a match... please wait."<<std::endl;
}

//Função para imprimir o match.
void Interface::match(std::pair<int,std::string> a, std::vector<int> b, std::string d){
  if(a.first==0){
    //Printa se não houver match.
    std::cout<<"\n\n>>> Sorry, no match in our database."<<std::endl;
  }else{
    //Printa o nome de quem deu match.
    std::cout<<"\n\nMatch ID(99.9%): "<<a.second<<std::endl;
    std::cout<<"DNA Profile:"<<std::endl;
    
    //Ordena o vetor com as posições para printar os caracteres especiais.
    int aux=0;
    for(int i=0;i<b.size();i++){
      for(int j=0;j<b.size();j++){
        if(b[i]<b[j]){
          aux = b[i];
          b[i] = b[j];
          b[j] = aux;
        }
      }
    }
    //Adiciona um a posição por conta do "[" que vai ser printado embaixo.
    for(int i=0;i<b.size();i++){
      b[i]=b[i]+1;
    }
    //Printa a sequência e a quantidade de repetições na primeira linha.
    for(int i=0;i<d.size();i++){
      for(int j=0;j<b.size();j=j+2){
        if(i==b[j]){
          int aux = b[j+1]- b[j];
          aux = aux/4;
          std::cout<<" "<<d[i]<<d[i+1]<<d[i+2]<<d[i+3]<<" [x"<<aux<<"]"; 
          i=i+10; 
        }
      }  
      std::cout<<" ";
    }
    std::cout<<"\n";
    //Printa as setinhas alinhadas com a sequência encontrada no DNA.
    for(int i=0;i<d.size();i++){
      for(int j=0;j<b.size();j=j+2){
        while(i>b[j] &&i<=b[j+1]){
          std::cout<<"v"; 
          i++; 
        }
      }  
      std::cout<<" ";
    }
    std::cout<<"\n";
    //Printa a sequência encontrada no DNA colocando as letras em verde.
    std::cout<<"[";
    for(int i=0;i<d.size();i++){
      for(int j=0;j<b.size();j=j+2){
        while(i>=b[j] &&i<b[j+1]){
          std::cout<<"\x1b[032m"<<d[i]<<"\033[0m"; 
          i++; 
        }
      }  
      std::cout<<d[i];
    }
    std::cout<<"]";
    std::cout<<"\n";
  } 
}