#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <limits>

using namespace std;

#include "classes_objects/headers/global_objects.hpp"
#include "classes_objects/headers/classes.hpp"

#include "functions/headers/functions_main.hpp"
#include "functions/headers/functions_load.hpp"

#include "functions/headers/functions_plant.hpp"
#include "functions/headers/functions_client.hpp"
#include "functions/headers/functions_sell.hpp"

int main(int argc, const char* argv[])
{
    vector<Planta> plantas;
    vector<Cliente> clientes;

    int opcao;

    setlocale(LC_ALL, "");

    funcFile::carregarQuadro(plantas, registPlant, numeroDeQuadros);
    funcFile::carregarListaClientes(clientes, registClient, numeroDeClientes);
    funcFile::carregarVendas(clientes, registClient, registSell);
    
    while(rec != true)
    {
        system("cls");

       wcout << "====================================================== Green Life ======================================================" << endl 
             << "__________________________________________________________Menu__________________________________________________________" << endl
             << endl
             << "                                       [1] - Registros de quadros                                                        " << endl
             << "                                       [2] - Registro de clientes                                                        " << endl
             << "                                       [3] - Registro de vendas                                                          " << endl
             << "                                       [4] - Registro de canteiros                                                       " << endl
             << "                                       [0] - Sair...                                                                     " << endl
            << L"Escolha uma opção: ";

        cin >> opcao;

        switch(opcao)
        {
            case 1:
                system("cls");

                while (opcao != 0)
                {
                    wcout << "__________________________________________________________Menu__________________________________________________________" << endl
                      << endl
                      << "                                       [1] - Mostrar quadros de plantas registrados                                      " << endl
                      << "                                       [2] - Editar status de um quadro                                                  " << endl
                      << "                                       [3] - Registrar uma nova adubagem de um quadro                                    " << endl
                      << "                                       [4] - Registrar novos quadros de plantas                                          " << endl
                     << L"                                       [5] - Excluír um quadro de plantas                                                   " << endl
                      << "                                       [0] - Retornar para Menu principal                                                " << endl
                      << endl
                     << L"Escolha uma opção: ";

                    cin >> opcao;

                    switch(opcao)
                    {
                        case 1:
                            funcPlant::mostrarQuadro(plantas, registPlant, numeroDeQuadros);
                        break;
                    
                        case 2:
                            funcPlant::editarQuadro(plantas, registPlant, numeroDeQuadros);
                        break;
                    
                        case 3:
                            funcPlant::registrarAdubagem(plantas, registPlant, numeroDeQuadros);
                        break;
                    
                        case 4:
                            funcPlant::registrarQuadro(plantas, registPlant);
                        break;

                        case 5:
                            funcPlant::excluirQuadro(plantas, numeroDeQuadros, registPlant);
                        break;

                        case 0:
                            system("cls");
                        break;
                    
                        default:
                            system("cls");
                            wcout << L"Opção inválida!" << endl
                                  << endl;
                            funcMain::pressEnter();
                            
                        break;
                    }
                }
            break;

            case 2:
                system("cls");

                while (opcao != 0)
                {
                    wcout << "__________________________________________________________Menu__________________________________________________________" << endl
                          << endl
                          << "                                          [1] - Mostrar lista de clientes                                                     " << endl
                          << "                                          [2] - Editar dados de algum cliente                                                 " << endl
                          << "                                          [3] - Registrar novo cliente                                                        " << endl
                         << L"                                          [4] - Excluír um cliente                                                            " << endl
                          << "                                          [0] - Retornar para Menu principal                                                  " << endl
                          << endl
                          << L"Escolha uma opção: ";

                    cin >> opcao;

                    switch(opcao)
                    {
                        case 1:
                            funcClient::mostrarClientesContatos(clientes, registClient, numeroDeClientes, funcClient::registrarCliente);
                        break;

                        case 2:
                            funcClient::editarRegistroCliente(clientes, registClient, numeroDeClientes, funcClient::registrarCliente);
                        break;

                        case 3:
                            funcClient::registrarCliente(clientes, registClient, numeroDeClientes);
                        break;

                        case 4:
                            funcClient::excluirCliente(clientes, registClient, numeroDeClientes);
                        break;

                        case 0:
                            system("cls");
                        break;

                        default:
                            system("cls");
                            wcout << L"Opção inválida!" << endl
                                  << endl;
                            funcMain::pressEnter();
                        break;
                    }
                }
            break;

            case 3:
                system("cls");

                while (opcao != 0)
                {
                    wcout << "__________________________________________________________Menu__________________________________________________________" << endl
                          << endl
                          << "                                       [1] - Mostrar registros de vendas                                                  " << endl
                          << "                                       [2] - Editar algum registro de vendas                                             " << endl
                          << "                                       [3] - Registrar uma nova venda                                                    " << endl
                         << L"                                       [4] - Excluír um registro de vendas                                               " << endl              
                          << "                                       [0] - Retornar para Menu principal                                                " << endl
                          << endl
                         << L"Escolha uma opção: ";

                    cin >> opcao;

                    switch(opcao)
                    {
                        case 1:
                            funcSell::mostrarVendas(clientes, numeroDeClientes, registClient, registSell, funcClient::registrarCliente, funcSell::RegistrarVenda);
                        break;

                        case 2:
                            funcSell::editarRegistroVenda(clientes, numeroDeClientes, registClient, registSell, funcClient::registrarCliente, funcSell:: RegistrarVenda);
                        break;

                        case 3:
                            funcSell::RegistrarVenda(clientes, registClient, registSell, numeroDeClientes, funcClient::registrarCliente);
                        break;

                        case 4:
                            funcSell::ExcluirVenda(clientes, registClient, registSell, numeroDeClientes, funcClient::registrarCliente, funcSell::RegistrarVenda);

                        case 0:
                            system("cls");
                        break;

                        default:
                            system("cls");
                            wcout << L"Opção inválida!" << endl
                                  << endl;
                            funcMain::pressEnter();
                        break;
                    }    
                }
            break;

            case 4:
                

            break; 
                
            case 0:
                cout << endl
                     << "Saindo..." << endl;
                rec = true;
            break;

            default:
                system("cls");
                wcout << L"Opção inválida!" << endl
                      << endl;
                funcMain::pressEnter();
            break;                  
        };
    }

system("pause");
return 0;
}