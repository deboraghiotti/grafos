#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Vertice{

    public:
    char vertice;
    vector <char> adja;
    int visitado;

    Vertice(){}
    Vertice(char _vertice){
        this->vertice = _vertice;
        this->visitado = 0;
    }

    void Inserir_Adja(char _adja){
        this->adja.push_back(_adja);
    }

    void imprime(){
        cout << "Vertice: " << this->vertice << endl;
        cout << "Lista de Adjacência: ";
        for (int i = 0; i < this->adja.size(); i++ ){
            cout << this->adja[i] << " ";
        }
        cout << endl;
    }

};

class Grafo{

    public:
    int nVertice;
    int nAresta;

    vector <Vertice*> grafo;

    Grafo(){}
    Grafo(int _nVertice, int _nAresta){

        this->nVertice = _nVertice;
        this->nAresta = _nAresta;
        char v = 'a';

        for(int i = 0; i < nVertice; i++){ 

            Vertice *_vertice;
            _vertice = new Vertice(v);
            this->grafo.push_back(_vertice);
            v++;
        }
    }

    int Busca(char _v){
        for(int i = 0; i < nVertice; i++){
            if(this->grafo[i]->vertice == _v){
                return i;
            }
        }
    }

    void Inserir_Adja(int pos, char _adja){
        this->grafo[pos]->Inserir_Adja(_adja);
        return;
    }

    void imprime(){
        for(int i = 0; i < this->grafo.size();i++){
            this->grafo[i]->imprime();
        }
    }

    void Conexidade(char v){
        int pos = this->Busca(v);

        if(this->grafo[pos]->visitado == 1){
            return;
        }

        cout << v << ", ";

        this->grafo[pos]->visitado = 1;

        for(int i = 0; i < this->grafo[pos]->adja.size();i++){
            Conexidade(this->grafo[pos]->adja[i]);
            cout << endl;
        }
    }

};


int main(int argc, char *argv[]){

    if(argc != 2){
        cout << "Erro de I/O" << endl;
        exit(0);
    }

    ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        cerr << "Erro ao abrir o arquivo, o mesmo nao existe!" << endl;
        exit(1);
    }

    int cases;

    infile >> cases;

    for(int i = 0; i < cases; i++ ){ 

        cout << "Case" << i << endl;

        int nVertice;
        int nAresta;

        infile >> nVertice;
        infile >> nAresta;

        Grafo *_grafo;
        _grafo = new Grafo(nVertice,nAresta);

        for(int i = 0; i < nAresta; i++){
            char vertice;
            char adja;

            infile >> vertice;
            infile >> adja;

            int pos = _grafo->Busca(vertice);
            _grafo->Inserir_Adja(pos,adja);

            char aux = 'a';

            for(int i= 0; i < nVertice; i++){ 
                _grafo->Conexidade(aux);
                aux++;
            }

            pos = _grafo->Busca(adja);
            _grafo->Inserir_Adja(pos,vertice);
        }

       // _grafo->imprime();
        cout << "---------------------------------------------" << endl << endl;
    }


    infile.close();
    return 0;
}
