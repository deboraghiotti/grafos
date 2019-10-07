#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main(){

    ifstream arq1;
    arq1.open("arquivo.txt");
    if(!arq1.is_open()){
        cerr << "Erro ao abrir o arquivo, o mesmo nao existe!" << endl;
        exit(1);
    }
    return 0;
}
