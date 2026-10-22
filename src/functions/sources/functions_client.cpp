#include "../../classes_objects/headers/classes.hpp"
#include "../headers/functions_client.hpp"
#include "../headers/functions_main.hpp"
#include "../headers/functions_load.hpp"

using namespace std;
using namespace funcMain;
using namespace funcFile;

namespace funcClient
{
    void mostrarClientesContatos(vector<Cliente>& clientes, bool& registClient, int& numeroDeClientes,
                                 void(registrarCliente)(vector<Cliente>&, bool&, int&))
    {   
        int op1, op2;

        system("cls");

        if(!registClient)
        {
            cout << "Nenhum cliente registrado. Deseja registrar um novo cliente?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op1;

            if(op1 == 1)
            {
                system("cls");
                registrarCliente(clientes, registClient, numeroDeClientes);
            }
            else
            {
                cout << endl;
                pressEnter();

                system("cls");

                return;
            } 
        }

        system("cls");

        if(registClient)
        {
            cout << clainUnderlineBar();

            for(int i = 0; i < clientes.size(); i++)
            {
                cout << "Nome: " << clientes[i].nome << endl
                     << "Contato: " << clientes[i].contato << endl
                     << endl;
            }
        }

        cout << clainUnderlineBar();
        pressEnter();

        system("cls");
    }


    void registrarCliente(vector<Cliente>& clientes, bool& regist, int& numeroDeClientes)
    {
        int op;
        int novoDDD;
        int novoNumero;
        Cliente novoCliente("","");

        system("cls");

        cout << clainUnderlineBar()
             << "Digite o nome do cliente (Ou digite '0' para cancelar): ";
            getline(cin >> ws, novoCliente.nome);
        
        if(novoCliente.nome != "0")
        {
            while(true)
            {
                cout << endl
                     << clainUnderlineBar();
                wcout << L"Digite o número do DDD de contato: ";
                cin >> novoDDD;

                if(novoDDD > 99 || novoDDD < 11)
                {
                    wcout << "DDD " << novoDDD << L" Inválido!";
                }
                else break;
            }

            wcout << endl
                  << L"Número de contato: ";
            cin >> novoNumero;

            contactConversor(novoCliente.contato, novoDDD, novoNumero);
            clientes.push_back(novoCliente);
            regist = true;
            numeroDeClientes += 1;

            system("cls");

            cout << clainUnderlineBar()
                 << "Cliente " << clientes.back().nome << " registrado com sucesso!" << endl
                 << endl;
        }

        salvarListaClientes(clientes, registClient, numeroDeClientes);
        pressEnter();
    
        system("cls");
    }


    void editarRegistroCliente(vector<Cliente>& clientes, bool& RegistClient, int& numeroDeClientes,
                          void(registrarCliente)(vector<Cliente>&, bool&, int&))
    {   
        int op1, op2, novoDDD, novoNumero;

        system("cls");

        if(!RegistClient)
        {
            cout << "Nenhum cliente registrado. Deseja registrar um novo cliente?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op1;

            if(op1 == 1)
            {
                system("cls");
                registrarCliente(clientes, registClient, numeroDeClientes);
            }
            else
            {
                cout << endl;
                pressEnter();

                system("cls");

                return;
            } 
        }

        system("cls");

        if(registClient)
        { 
            while(true)
            {
                cout << clainUnderlineBar()
                     << "Selecione um cliente para editar os dados:" << endl
                     << clainUnderlineBar();

                Cliente::mostrarListaClientes(clientes);

                wcout << "[0] - Cancelar" << endl
                      << endl
                      << L"Escolha uma opção: ";
                cin >> op1;

                if(op1 < 0 || op1 > numeroDeClientes)
                {
                    system("cls");

                    wcout << L"Opção inválida!" << endl;
                }
                else if(op1 == 0)
                {
                    system("cls");
                    cout << "Retornando..." << endl
                         << endl;
                    pressEnter();
                    return;
                }
                else
                {
                    op1--;
                    break;
                }
            }

            system("cls");

            cout << "Editando dados do cliente " << clientes[op1].nome << endl
                 << endl
                 << "Escolha um dado para ser alterado:" << endl
                 << endl
                 << "[1] - Nome: " << clientes[op1].nome << endl
                 << "[2] - Contato: " << clientes[op1].contato << endl
                 << endl;
            wcout << L"Selecione uma opção: ";
            cin >> op2;

            system("cls");

            switch(op2)
            {
                case 1:
                    cout << "Editando o nome do cliente " << clientes[op1].nome << endl
                         << endl
                         << "Insira um novo nome: ";
                    cin >> clientes[op1].nome;

                    system("cls");

                    cout << "Nome do cliente " << clientes[op1].nome << " alterado com sucesso!" << endl
                         << endl;
                break;

                case 2:
                    while(true)
                    {
                        cout << "Editando o contato do cliente " << clientes[op1].contato << endl
                             << endl;
                        wcout << L"Digite o número do DDD de contato: ";
                        cin >> novoDDD;

                        if(novoDDD > 99 || novoDDD < 11)
                        {
                            wcout << "DDD " << novoDDD << L" Inválido!";
                        }
                        else break;
                    }

                    wcout << endl
                          << L"Número de contato: ";
                    cin >> novoNumero;

                    contactConversor(clientes[op1].contato, novoDDD, novoNumero);

                    system("cls");

                    cout << "Contato do cliente " << clientes[op1].nome << " alterado com sucesso:" << endl;
                break;

                default:
                    wcout << L"Opção inválida!" << endl;
                break;
            }
        }

        salvarListaClientes(clientes, registClient, numeroDeClientes);
        pressEnter();

        system("cls");
    }


    void excluirCliente(vector<Cliente>& clientes, bool& registClient, int& numeroDeClientes)
    {
        system("cls");

        int op1, op2;

        if(!registClient)
        {
            cout << clainUnderlineBar()
                 << L"Nenhum registro de clientes foi encontrado!" << endl
                 << endl;
        }
        else
        {
            cout << clainUnderlineBar();
            wcout << L"Selecione um cliente para exclusão: " << endl;
            cout << clainUnderlineBar();

            for(int i = 0; i < clientes.size(); i++)
            {
                cout << "[" << i+1 << "] - " << clientes[i].nome << endl
                     << "      " << clientes[i].contato << endl
                     << endl;
            }

            cout << "[0] - Cancelar" << endl
                 << endl
                 << clainUnderlineBar();
            wcout << L"Selecione uma opção: ";

            cin >> op1;

            if(op1 > 0 && op1 <= clientes.size())
            {
                system("cls");
                op1--;

                cout << clainUnderlineBar();
                wcout << L"Tem certeza que deseja excluír o cliente "; cout << clientes[op1].nome << " e todos seus registros de vendas?" << endl
                      << "[1] - Sim" << endl;
                wcout << L"[2] - Não" << endl
                      << endl
                      << L"Selecione uma opção: ";
                cin >> op2;

                if(op2 == 1)
                {
                    string clienteDelNome = clientes[op1].nome;

                    clientes.erase(clientes.begin() + op1);
                    numeroDeClientes--;

                    Cliente::verificarVendas(clientes);
                    salvarListaClientes(clientes, registClient, numeroDeClientes);
                    salvarVendas(clientes, registClient, registSell);

                    system("cls");

                    cout << "Registros do cliente " << clienteDelNome << " Deletados com sucesso!" << endl
                         << endl;
                }
            }
            else if(op1 == 0)
            {
                system("cls");
                    
                wcout << L"Cancelando operação..." << endl
                      << endl;
            }
            else
            {
                wcout << L"Opção inválida!" << endl
                      <<  "Retornando..." << endl
                      << endl;
            }
        }

        pressEnter();

        system("cls");
    }
}