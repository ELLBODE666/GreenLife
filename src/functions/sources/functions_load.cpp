#include "../headers/functions_load.hpp"

using namespace std;
namespace fs = filesystem;

namespace funcFile
{
    void verificarPastaData()
    {
        fs::path caminhoData = fs::current_path().parent_path() / "data";

        if(!fs::exists(caminhoData))
        {
            fs::create_directories(caminhoData);
                
        }
    }


    void salvarQuadro(vector<Planta>& plantas, bool& regist, int& numeroDeQuadros)
    {
        verificarPastaData();

        numeroDeQuadros = plantas.size();
        ofstream outfile("../data/plants_data.txt");

        if(outfile.is_open())
        {
            outfile << regist << endl;
            outfile << numeroDeQuadros << endl
                    << endl;

            for(int i = 0; i < numeroDeQuadros; i++)
            {
                outfile << plantas[i].nome << endl;
                outfile << plantas[i].tipo << endl;
                outfile << plantas[i].fullData << endl;
                outfile << plantas[i].quantidade << endl;
                outfile << plantas[i].qntAdubadas << endl;
                
                for(int j = 0; j < plantas[i].qntAdubadas; j++)
                {
                    outfile << plantas[i].adubagens[j].tipoDeAdubo << endl;
                    outfile << plantas[i].adubagens[j].dataDeAdubagem << endl;
                }
                
                outfile << endl;
            }
            outfile.close();
        }
        else cout << "Erro ao abrir arquivos de salvamento!" << endl;
    }


    void carregarQuadro(vector<Planta>& plantas, bool& regist, int& numeroDeQuadros)
    {
        verificarPastaData();

        ifstream infile("../data/plants_data.txt");

        if(infile.is_open())
        {
            infile >> regist;
            infile >> numeroDeQuadros;
            infile.ignore();

            string linhaVazia;
            getline(infile, linhaVazia);
            
            for(int i = 0; i < numeroDeQuadros; i++)
            {
                Planta novoQuadro;

                getline(infile, novoQuadro.nome);
                getline(infile, novoQuadro.tipo);
                getline(infile, novoQuadro.fullData);
                infile >> novoQuadro.quantidade;
                infile >> novoQuadro.qntAdubadas;
                infile.ignore();

                for(int j = 0; j < novoQuadro.qntAdubadas; j++)
                {
                    Adubo adubo;
                    getline(infile, adubo.tipoDeAdubo);
                    getline(infile, adubo.dataDeAdubagem);
                    novoQuadro.adubagens.push_back(adubo);
                }

                plantas.push_back(novoQuadro);
                getline(infile, linhaVazia);

                if (i > numeroDeQuadros - 1)
                {
                    getline(infile, linhaVazia);
                }
            }
            infile.close();
        }
        else
        {
            wcout << L"Não há registros de quadros. Criando um novo arquivo de registros" << endl
                  << endl;
        };
    }


    void salvarListaClientes(vector<Cliente>& clientes, bool& registClient, int& numeroDeClientes)
    {
        verificarPastaData();

        numeroDeClientes = clientes.size();

        ofstream outfile("../data/clients_data.txt");

        if(outfile.is_open())
        {
            outfile << registClient << endl
                    << numeroDeClientes << endl
                    << endl;

            for(int i = 0; i < numeroDeClientes; i++)
            {
                outfile << clientes[i].nome << endl
                        << clientes[i].contato << endl
                        << clientes[i].divida << endl
                        << clientes[i].numVendas << endl;

                if(i < numeroDeClientes -1)
                {
                    outfile << endl;
                }
            }

            outfile.close();
        }
        else
        {
            cout << "Erro ao abrir arquivos de salvamento!" << endl;
        }
    }


    void salvarVendas(vector<Cliente>& clientes, bool& registClient, bool& registSell)
    {
        verificarPastaData();

        if(registClient)
        {
            ofstream outfile("../data/vendas_data.txt");

            if(outfile.is_open())
            {
                outfile << registSell << endl
                        << endl;

                for(int i = 0; i < clientes.size(); i++)
                {
                    for(auto venda : clientes[i].vendas)
                    {
                        outfile << venda.fullData << endl
                                << venda.observacao << endl
                                << venda.valorGeral << endl
                                << venda.desconto << endl
                                << venda.valorPago << endl
                                << venda.saldoDevedor << endl
                                << venda.numPlantas << endl
                                << endl;

                        for(auto planta : venda.plantasVendidas)
                        {
                            outfile << planta.nome << endl
                                    << planta.poteUsado << endl
                                    << planta.quantidade << endl
                                    << planta.valor << endl
                                    << endl;
                        }                    
                    }
                }
                
                outfile.close();
            }
        }
    }


    void carregarListaClientes(vector<Cliente>& clientes, bool& registClient, int& numeroDeClientes)
    {
        verificarPastaData();

        ifstream infile("../data/clients_data.txt");

        if(infile.is_open())
        {
            string linhaVazia;

            infile >> registClient;
            infile >> numeroDeClientes;
            infile.ignore();

            getline(infile, linhaVazia);

            clientes.resize(numeroDeClientes);

            for(int i = 0; i < numeroDeClientes; i++)
            {
                getline(infile, clientes[i].nome);
                getline(infile, clientes[i].contato);
                infile >> clientes[i].divida;
                infile >> clientes[i].numVendas;
                infile.ignore();
                
                if(i < numeroDeClientes -1)
                {
                    getline(infile, linhaVazia);
                }
            }

            infile.close();
        }
        else
        {
            wcout << L"Não há registros de clientes, criando novo registro." << endl
                  << endl;
        }
    }


    void carregarVendas(vector<Cliente>& clientes, bool& registClient, bool& registSell)
    {
        verificarPastaData();
               
        ifstream infile("../data/vendas_data.txt");

        if(registClient)
        {
            if(infile.is_open())
            {
                string linhaVazia;

                infile >> registSell;
                infile.ignore();
                getline(infile, linhaVazia);

                for(int i = 0; i < clientes.size(); i++)
                {
                    for(int j = 0; j < clientes[i].numVendas; j++)
                    {
                        clientes[i].vendas.resize(clientes[i].numVendas);

                        getline(infile, clientes[i].vendas[j].fullData);
                        getline(infile, clientes[i].vendas[j].observacao);
                        infile >> clientes[i].vendas[j].valorGeral;
                        infile >> clientes[i].vendas[j].desconto;
                        infile >> clientes[i].vendas[j].valorPago;
                        infile >> clientes[i].vendas[j].saldoDevedor;
                        infile >> clientes[i].vendas[j].numPlantas;
                        infile.ignore();
                        getline(infile, linhaVazia);

                        for(int k = 0; k < clientes[i].vendas[j].numPlantas; k++)
                        {
                            clientes[i].vendas[j].plantasVendidas.resize(clientes[i].vendas[j].numPlantas);

                            getline(infile, clientes[i].vendas[j].plantasVendidas[k].nome);
                            getline(infile, clientes[i].vendas[j].plantasVendidas[k].poteUsado);
                            infile >> clientes[i].vendas[j].plantasVendidas[k].quantidade;
                            infile >> clientes[i].vendas[j].plantasVendidas[k].valor;
                            infile.ignore();
                            getline(infile, linhaVazia);
                        }
                    }
                }

                infile.close();
            }
            else
            {
                wcout << L"Não há registros de vendas, criando novo registro." << endl
                  << endl;
            }
        }
    }
}