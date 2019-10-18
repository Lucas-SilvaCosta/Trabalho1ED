#include "pilhaG.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//#include "xml/dataset01.xml";

using namespace std;
//ArrayStack<char *> plh = ArrayStack(99);

bool verificarArquivo(string arq){
  string line;
  ifstream myfile ("xml/"+arq+".xml");
  if (myfile.is_open())
  {
    //printf("==========entrou\n");
    structures::ArrayStack<std::string> plh(45);
    bool inTag = false;
    bool endTag = false;
    string toStack = "";
    while ( getline (myfile,line) ){
      //printf("==========entrou while");
      char lineChar[line.size()];
      strcpy(lineChar, line.c_str());
      for(int i = 0; i<line.size(); i++){
        //cout << "inTag: " << inTag << "; ";
        //cout << "endTag: " << endTag << "\n";
        //cout << toStack << " + " << lineChar[i] << "\n";
        //cout << lineChar[i];
        //printf("==========entrou for");
        //printf("%c == <?   ", lineChar[i]);
        //cout << (lineChar[i] == '<') << "\n";
        //cout << "inTag: " << inTag << "\n";
        if(inTag && lineChar[i] != '/' && lineChar[i] != '>' && lineChar[i] != '<'){
          //cout << "inTag: " << inTag << "\n";
          //printf("%s + ", toStack);

          toStack = toStack + lineChar[i];
        }
        if(lineChar[i] == '<'){
          //printf("==========inTag: true\n");
          inTag = true;
        }
        if(lineChar[i] == '/' && inTag == true){
          //printf("==========endTag: true\n");
          endTag = true;
        }
        //printf("%c == >?   ", lineChar[i]);
        //cout << (lineChar[i] == '>') << "\n";
        if(lineChar[i] == '>'){
          //printf("char = >\n");
          //char test[toStack.size()];
          //strcpy(test, toStack.c_str());
          if(endTag){
            //printf("tirando: %*s\n", 15, test);
            //cout << "tirando:   " << toStack << "\n";
            if(toStack == plh.top()){
              cout << "tirei:   " << plh.pop() << "\n";
            }else{
              return false;
            }
          }else{
            //printf("colocando: %*s\n", 13, test);
            //cout << "colocando: " << toStack << "\n";
            plh.push(toStack);
            cout << "coloquei: " << plh.top() << "\n";
          }
          toStack = "";
          inTag = false;
          //cout << "Passei pelo inTag: " << inTag << "\n";
          endTag = false;
        }
      }
    }
    if(plh.empty()){
      return true;
    }else{
      return false;
    }
    myfile.close();
  }else cout << "Não foi possível abrir o arquivo";
}

int main(int argc, char** argv){
  if(argc != 2){
    printf("YO! the fuck u doing??\n");
    return 1;
  }
  //string arq = "xml/datasetTeste.xml";
  string arq = argv[1];
  if(verificarArquivo(arq)){
    printf("Arquivo válido\n");
  }else{
    printf("Arquivo inválido\n");
  }

  return 0;
}
