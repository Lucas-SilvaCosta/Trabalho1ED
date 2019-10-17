//#include <pilhaG.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
//ArrayStack<char *> plh = ArrayStack(99);

int main(int argc, char** argv){
  /*
  if(argc != 2){
    printf("YO! the fuck u doing??\n");
    return 1;
  }
  //printf("argc: %d\n", argc);
  char* arquiveName = argv[1];
  printf("Nome do arquivo: %s\n", arquiveName);
  ofstream myfile;
  myfile.open (arquiveName);
  myfile << "aaaaa";
  */
  string line;
  //ofstream myf ("example.txt");
  //myf << "aaaaa\n";
  //myf << "bbbbb\n";
  //myf.close();
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) ){
      char lineChar[line.size()];
      strcpy(lineChar, line.c_str());
      bool inTag = false;
      bool endTag = false;
      string toStack = "";
      for(int i = 0; i<line.size(); i++){
        //cout << lineChar[i];
        if(inTag && lineChar[i] != "\\"){
          toStack = toStack + lineChar[i];
        }
        if(lineChar[i] == "<")
          inTag = true;
        if(lineChar[i] == "\\" && inTag == true)
          endTag = true;
        if(lineChar[i] == ">"){
          if(endTag)
          inTag == false;
          endTag == false;
        }
      }
      cout << "\n";
    }
    myfile.close();
  }else cout << "Unable to open file";
  return 0;
}

bool verificarArquivo(){

}
