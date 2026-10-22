#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

#include "global_objects.hpp"

struct Data{int dia; int mes; int ano;};
struct Adubo{string tipoDeAdubo; string dataDeAdubagem;};
struct PlantaVendida{string nome; string poteUsado; int quantidade; double valor;};

class Planta
{
    public:
        string nome;
        string tipo; 
        string fullData; 
        int quantidade = 0; 
        int qntAdubadas = 0; 
        vector <Adubo> adubagens;

        void mostrarQuadro() const;
        static void mostrarListaQuadros(vector<Planta>&);
};

class Venda
{    
    private:

    public:
        vector<PlantaVendida> plantasVendidas;
        string fullData;
        string observacao;
        double valorGeral = 0.0;
        double desconto = 0.0;
        double valorPago = 0.0;
        double saldoDevedor = 0.0;
        int numPlantas = 0;

        double aplicarDesconto();
        static void excluirVenda(vector<Venda>&, int);
};


class Cliente
{
    public:
        string nome;
        string contato;
        vector <Venda> vendas;
        double divida = 0;
        int numVendas = 0;  

    Cliente(string nm = "Nome", string cnt = "[**]*********", double dvd = 0.0, int nv = 0) : nome(nm), contato(cnt), divida(dvd), numVendas(nv) {}

    void mostrarCliente() const;

    static void mostrarListaClientes(vector<Cliente>&);
    
    static bool verificarVendas(vector<Cliente>&);
};

#endif