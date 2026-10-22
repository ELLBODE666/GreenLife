#include "../headers/functions_sell.hpp"
#include "../headers/functions_main.hpp"
#include "../headers/functions_client.hpp"
#include "../headers/functions_load.hpp"

using namespace std;
using namespace funcMain;
using namespace funcClient;
using namespace funcFile;

namespace funcSell
{
    void mostrarVendas(vector<Cliente>& clientes, int& numeroDeClientes, bool& RegistClient, bool& registSell,
                       void(registrarCliente)(vector<Cliente>&, bool&, int&),
                       void(registrarVenda)(vector<Cliente>&, bool&, bool&, int&, void(registrarCliente)(vector<Cliente>&, bool&, int&)))
    {
        int op1, op2;
        bool registrosConcluidos = RegistClient && registSell;

        system("cls");

        if(RegistClient == false)
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
                if(registClient)
                {
                registrarVenda(clientes, RegistClient, registSell, numeroDeClientes, registrarCliente);
                }
            }
        }
        else if(registSell == false)
        {
            cout << "Nenhum registro de vendas encontrado. Deseja registrar uma nova venda?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op1;

            if(op1 == 1)
            {
                system("cls");
                registrarVenda(clientes, RegistClient, registSell, numeroDeClientes, registrarCliente);
            }

        }

        if(registrosConcluidos)
        {
            cout << "Selecione um cliente para ver os registros de vendas: " << endl;

            Cliente::mostrarListaClientes(clientes);
            
          wcout << endl
                << L"Selecione uma opção: ";
            
          cin >> op1;
          op1--;

            if(op1 < 0 || op1 >= numeroDeClientes)
            {
              wcout << endl
                    << L"Opção inválida!" << endl
                    << "Retornando..." << endl
                    << endl;
                pressEnter();
                system("cls");
                return;
            }

            system("cls");

            cout << "Selecione uma das vendas de " << clientes[op1].nome << " Para visualizar: " << endl;

            for(int i = 0; i < clientes[op1].vendas.size(); i++)
            {
                cout << "[" << i+1 << "] - " << clientes[op1].vendas[i].fullData << endl
                     << "Plantas: ";

                for(int j = 0; j < clientes[op1].vendas[i].plantasVendidas.size(); j++)
                {
                    cout << clientes[op1].vendas[i].plantasVendidas[j].nome;
                    if(j < clientes[op1].vendas[i].plantasVendidas.size() - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << endl
                     << endl;
            }
            wcout << L"Selecione uma opção: ";
            cin >> op2;
            op2--;

            if(op2 < 0 || op2 >= clientes[op1].vendas.size())
            {
                wcout << endl
                    << L"Opção inválida!" << endl
                    << "Retornando..." << endl
                    << endl;
                pressEnter();
                system("cls");
                return;
            }

            system("cls");

            cout << clainUnderlineBar()
                 << "Cliente: " << clientes[op1].nome << endl
                 << "Data da venda: " << clientes[op1].vendas[op2].fullData << endl
                 << "Plantas vendidas: ";

            for(int i = 0; i < clientes[op1].vendas[op2].plantasVendidas.size(); i++)
            {
                cout << clientes[op1].vendas[op2].plantasVendidas[i].nome;
                if(i < clientes[op1].vendas[op2].plantasVendidas.size() - 1)
                    {
                        cout << ", ";
                    }
            }
            cout << endl
                 << endl
                 << clainUnderlineBar();

            for(int i = 0; i < clientes[op1].vendas[op2].plantasVendidas.size(); i++)
            {
                cout << i+1 << " - " << clientes[op1].vendas[op2].plantasVendidas[i].nome << endl
                     << "Pote usado: " << clientes[op1].vendas[op2].plantasVendidas[i].poteUsado << endl
                     << "Quantidade vendida: " << clientes[op1].vendas[op2].plantasVendidas[i].quantidade << endl
                     << "Valor por unidade: R$" << clientes[op1].vendas[op2].plantasVendidas[i].valor << endl
                     << endl;
            }
            cout << clainUnderlineBar()
                 << "Valor total da venda: R$" << clientes[op1].vendas[op2].valorGeral << endl
                 << "Valor pago: R$" << clientes[op1].vendas[op2].valorPago << endl
                 << "Saldo devedor desta venda: R$" << clientes[op1].vendas[op2].saldoDevedor  << endl;
          wcout << L"Dívida total do cliente: R$" << clientes[op1].divida << endl
                << L"Observação: "; cout << clientes[op1].vendas[op2].observacao << endl
                 << clainUnderlineBar();

                 pressEnter();
        }
   
        system("cls");
    }
    
    
    void editarRegistroVenda(vector<Cliente>& clientes, int& numeroDeClientes, bool& registClient, bool& registSell,
                        void(registrarCliente)(vector<Cliente>&, bool&, int&),
                        void(registrarVenda)(vector<Cliente>&, bool&, bool&, int&, void(registrarCliente)(vector<Cliente>&, bool&, int&)))
    {
        int op1, op2, op3, index;
        bool registrosConcluidos = registClient && registSell;
        Data novaData;

        system("cls");

        if(registClient == false)
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

                if(registClient)
                {
                    registrarVenda(clientes, registClient, registSell, numeroDeClientes, registrarCliente);
                }
            }
        }
        else if(registSell == false)
        {
            cout << "Nenhum registro de vendas encontrado. Deseja registrar uma nova venda?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op1;

            if(op1 == 1)
            {
                system("cls");
                registrarVenda(clientes, registClient, registSell, numeroDeClientes, registrarCliente);
            }

        }

        if(registrosConcluidos)
        {
            system("cls");

            cout << clainUnderlineBar();
            wcout << L"Selecione um cliente para edição do registro de vendas:" << endl;
            cout << clainUnderlineBar();
            Cliente::mostrarListaClientes(clientes);
            
            wcout << "[0] - Cancelar" << endl
                  << endl
                  << L"Escolha uma opção: ";
            cin >> op1;
            
            if(op1 == 0)
            {
                system("cls");

                cout << clainUnderlineBar();
                wcout << L"Cancelando operação..." << endl
                      << endl;
                pressEnter();
                return;
            } 
            else if(op1 < 0 || op1 > clientes.size())
            {
                system("cls");
                cout << clainUnderlineBar();
                wcout << L"Opção inválida!" << endl
                      << "Retornando..." << endl
                      << endl;
                pressEnter();
                return;
            }
            else op1--;

            system("cls");

            while(true)
            {
                cout << clainUnderlineBar()
                     << "Selecione uma das vendas de " << clientes[op1].nome << " Para editar:" << endl
                     << clainUnderlineBar();

                for(int i = 0; i < clientes[op1].vendas.size(); i++)
                {
                    cout << "[" << i+1 << "] - " << clientes[op1].vendas[i].fullData << endl
                         << "Plantas: ";

                    for(int j = 0; j < clientes[op1].vendas[i].plantasVendidas.size(); j++)
                    {
                        cout << clientes[op1].vendas[i].plantasVendidas[j].nome;
                        if(j < clientes[op1].vendas[i].plantasVendidas.size() - 1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl
                         << endl;
                }
                wcout << "[0] - Cancelar" << endl
                      << L"Escolha uma opção: ";
                cin >> op2;

                if(op2 == 0)
                {
                    system("cls");

                    cout << clainUnderlineBar();
                    wcout << L"Cancelando operação..." << endl
                          << endl;
                    pressEnter();
                    return;
                }
                else if(op2 < 0 || op2 > clientes[op1].vendas.size())
                {
                    system("cls");
                    cout << clainUnderlineBar();
                    wcout << L"Opção inválida!" << endl
                          << endl;
                    pressEnter();
                }
                else
                {
                    op2--;
                    break;
                }
            }

            system("cls");

            cout << clainUnderlineBar()
            << "Editando venda -> Data: " << clientes[op1].vendas[op2].fullData << endl
            << "Feita para " << clientes[op1].nome << endl
            << endl
            << endl
            << "[1] - Data da venda: " << clientes[op1].vendas[op2].fullData << endl
            << "[2] - Plantas vendidas: ";

            for(int i = 0; i < clientes[op1].vendas[op2].plantasVendidas.size(); i++)
            {
                cout << clientes[op1].vendas[op2].plantasVendidas[i].nome;
                if(i < clientes[op1].vendas[op2].plantasVendidas.size() -1)
                {
                    cout << ", ";
                }
            }
            wcout << endl
                  << endl
                  << L"Escolha uma opção: ";
            cin >> op3;

            system("cls");

            switch(op3)
            {
                case 1:
                    cout << "Editando a data '" << clientes[op1].vendas[op2].fullData << "' da venda feita para " << clientes[op1].nome << endl
                         << endl
                         << "Insira uma nova data" << endl
                         << endl
                         << "Dia: ";
                    cin >> novaData.dia;
                    wcout << L"Mês: ";
                    cin >> novaData.mes;
                    cout << "Ano: ";
                    cin >> novaData.ano;

                    dataConversor(clientes[op1].vendas[op2].fullData, novaData);

                    system("cls");                 

                    cout << clainUnderlineBar();
                    wcout << L"Edição concluída com sucesso!" << endl
                          << endl;
                break;

                case 2:
                    clientes[op1].divida -= clientes[op1].vendas[op2].saldoDevedor;    
                    clientes[op1].vendas[op2].valorGeral = 0;               

                    cout << clainUnderlineBar()
                         << "Insira a quantidade de tipos de plantas vendidas: ";
                     cin >> index;

                    while (index > 10 || index <= 0)
                    {
                        cout << endl
                             << "Valor Incorreto! (Min: 0, Max: 10)" << endl
                             << "Insira a quantidade de tipos de plantas vendidas: ";
                        cin >> index;
                        cout << endl;
                    }

                    clientes[op1].vendas[op2].plantasVendidas.clear();
                    clientes[op1].vendas[op2].plantasVendidas.resize(index);
                    system("cls");

                    for(int i = 0; i < index; i++)
                    {
                        cout << clainUnderlineBar();
                        wcout << L"Registrando planta número " << i+1 << endl
                              << endl
                              << "Digite o nome do tipo da planta: ";
                        getline(cin >> ws, clientes[op1].vendas[op2].plantasVendidas[i].nome);   
                        cout << endl;

                        bool valido = false;
                        while (!valido)
                        {
                            cout << "Selecione o tipo de pote ou saco usado na planta:" << endl
                                 << "[1] - Pote" << endl
                                 << "[2] - Saco" << endl;
                          wcout << L"[3] - Torrão" << endl
                                << endl
                                << L"Selecione uma opção: ";
                            cin >> op3;
                        
                            switch(op3)
                            {
                                case 1:
                                    cout << endl
                                         << clainUnderlineBar()
                                         << "Insira o tamanho do pote usado: ";
                                    getline(cin >> ws, clientes[op1].vendas[op2].plantasVendidas[i].poteUsado);
                                    {
                                        string temp;
                                        temp = "Pote " + clientes[op1].vendas[op2].plantasVendidas[i].poteUsado;
                                        clientes[op1].vendas[op2].plantasVendidas[i].poteUsado = temp;
                                    }     
                                    valido = true;
                                break;
                                
                                case 2:
                                    clientes[op1].vendas[op2].plantasVendidas[i].poteUsado = "Saco";
                                    valido = true;
                                break;
                                
                                case 3:
                                    clientes[op1].vendas[op2].plantasVendidas[i].poteUsado = "Torrão";
                                    valido = true;
                                break;
                                
                                default:
                                    wcout << endl
                                          << L"Opção inválida!" << endl
                                          << endl;    
                            }
                        }
                    
                        cout << endl
                             << clainUnderlineBar()
                             << "Insira a quantidade de plantas vendidas: ";
                        cin >> clientes[op1].vendas[op2].plantasVendidas[i].quantidade;
                    
                        cout << endl
                             << clainUnderlineBar();
                        wcout << "Insira o valor por cada planta" << endl
                              << L"Use um '.'(ponto) ao invés de ','(Vírgula): R$";
                        cin >> clientes[op1].vendas[op2].plantasVendidas[i].valor;
                        cout << endl;

                        clientes[op1].vendas[op2].valorGeral += (clientes[op1].vendas[op2].plantasVendidas[i].valor * clientes[op1].vendas[op2].plantasVendidas[i].quantidade);
                    }
                    cout << endl;

                    while(true)
                    {
                        cout << clainUnderlineBar()
                             << "Valor geral da venda: " << clientes[op1].vendas[op2].valorGeral << endl
                             << "Deseja aplicar algum desconto?" << endl
                             << "[1] - Sim" << endl;
                      wcout << L"[2] - Não" << endl
                            << endl
                            << L"Escolha uma opção: ";
                        cin >> op3;
                    
                        if(op3 == 1)
                        {
                            cout << endl;
                            clientes[op1].vendas[op2].aplicarDesconto();

                            cout << endl
                                 << "Desconto de R$" << clientes[op1].vendas[op2].desconto << " aplicado com sucesso!" << endl
                                 << "Novo valor geral: R$" << clientes[op1].vendas[op2].valorGeral << endl;
                            break;
                        }
                        else if(op3 == 2)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");

                            wcout << L"Opção inválida!" << endl;
                        }
                    }
                    
                    cout << endl
                         << clainUnderlineBar()
                         << "Insira o valor pago na venda: R$";
                    cin >> clientes[op1].vendas[op2].valorPago;

                    clientes[op1].vendas[op2].saldoDevedor = clientes[op1].vendas[op2].valorGeral - clientes[op1].vendas[op2].valorPago;
                    clientes[op1].divida += clientes[op1].vendas[op2].saldoDevedor;

                    cout << endl
                         << clainUnderlineBar();
                    wcout << L"Digite alguma observação nessa venda (Desconto dado, quadro retirado, etc...): " << endl
                         << "  ";
                    getline(cin >> ws, clientes[op1].vendas[op2].observacao);

                    system("cls");

                    wcout << L"Edição da venda de "; cout << clientes[op1].nome << " feita com sucesso!" << endl
                         << endl;
                break;

                default:
                    wcout << L"Opção inválida!" << endl;
                break;
            }

            Cliente::verificarVendas(clientes);
        }

        salvarListaClientes(clientes, registClient, numeroDeClientes);
        salvarVendas(clientes, registClient, registSell);
        pressEnter();

        system("cls");
    }
    

    void RegistrarVenda(vector<Cliente>& clientes, bool& registClient, bool& registSell, int& numeroDeClientes,
                        void registrarCliente(vector<Cliente>&, bool&, int&))
    {
        Venda novaVenda;
        PlantaVendida novaPlanta;
        Data novaData;
        int op1, op2, index;

        while(true)
        {
            if(registClient == false)
            {
                system("cls");
                registrarCliente(clientes, registClient, numeroDeClientes);
                op1 = 0;
            }
            else
            {
                system("cls");
                cout << "Selecione um cliente para registrar a venda:" << endl;

                cout << clainUnderlineBar();
                Cliente::mostrarListaClientes(clientes);
                cout << "[" << numeroDeClientes + 1 << "] - Registrar novo cliente" << endl
                     << "[0] - Cancelar" << endl
                     << endl
                     << clainUnderlineBar();

                wcout << L"Selecione uma opção: ";
                cin >> op1;

                if (op1 == clientes.size()+1)
                {
                    op1--;
                    registrarCliente(clientes, registClient, numeroDeClientes);
                }
                else if(op1 == 0)
                {
                    system("cls");
                    cout << clainUnderlineBar();
                    wcout << L"Cancelando operação..." << endl
                          << endl;
                    pressEnter();
                    break;
                } 
                else if(op1 < 0 || op1 > clientes.size()+1)
                {
                    system("cls");
                    cout << clainUnderlineBar();
                    wcout << L"Opção inválida!" << endl
                          << "Retornando..." << endl
                          << endl;
                    pressEnter();
                    break;
                }
                else op1 --;  

                system("cls");
            }

            cout << clainUnderlineBar()
                 << "Registrando venda para " << clientes[op1].nome << endl
                 << endl
                 << "Insira a data da venda" << endl
                 << endl
                 << "Dia: ";
            cin >> novaData.dia;
            wcout << L"Mês: ";
            cin >> novaData.mes;
            cout << "Ano: ";
            cin >> novaData.ano;

            dataConversor(novaVenda.fullData, novaData);
      
            cout << endl
                 << clainUnderlineBar()
                 << "Insira a quantidade de tipos de plantas vendidas: ";
            cin >> index;

            while (index > 10 || index <= 0)
            {
                cout << endl
                     << "Valor Incorreto! (Min: 0, Max: 10)" << endl
                     << "Insira a quantidade de tipos de plantas vendidas: ";
                cin >> index;
                cout << endl;
            }

            novaVenda.plantasVendidas.resize(index);
            novaVenda.numPlantas = index;
            system("cls");

            for(int i = 0; i < index; i++)
            {
                cout << clainUnderlineBar();
                wcout << L"Registrando planta número " << i+1 << endl
                      << endl
                      << "Digite o nome do tipo da planta: ";
                getline(cin >> ws, novaVenda.plantasVendidas[i].nome);

                cout << endl;

                bool valido = false;
                while (!valido)
                {
                    cout << "Selecione o tipo de pote ou saco usado na planta:" << endl
                         << "[1] - Pote" << endl
                         << "[2] - Saco" << endl;
                  wcout << L"[3] - Torrão" << endl
                        << endl
                        << L"Selecione uma opção: ";
                    cin >> op2;

                    switch(op2)
                    {
                        case 1:
                            cout << endl
                                 << clainUnderlineBar()
                                 << "Insira o tamanho do pote usado: ";
                            getline(cin >> ws, novaVenda.plantasVendidas[i].poteUsado);
                            {
                                string temp;
                                temp = "Pote " + novaVenda.plantasVendidas[i].poteUsado;
                                novaVenda.plantasVendidas[i].poteUsado = temp;
                            }     
                            valido = true;
                        break;

                        case 2:
                            novaVenda.plantasVendidas[i].poteUsado = "Saco";
                            valido = true;
                        break;

                        case 3:
                            novaVenda.plantasVendidas[i].poteUsado = "Torrao";
                            valido = true;
                        break;

                        default:
                            wcout << endl
                                  << L"Opção inválida!" << endl
                                  << endl;    
                    }
                }

                cout << endl
                     << clainUnderlineBar()
                     << "Insira a quantidade de plantas vendidas: ";
                cin >> novaVenda.plantasVendidas[i].quantidade;

                cout << endl
                     << clainUnderlineBar();
                wcout << "Insira o valor por cada planta" << endl
                      << L"Use um '.'(ponto) ao invés de ','(Vírgula): R$";
                cin >> novaVenda.plantasVendidas[i].valor;
                cout << endl;

                novaVenda.valorGeral += (novaVenda.plantasVendidas[i].valor * novaVenda.plantasVendidas[i].quantidade);
            }
            cout << endl;

            while(true)
            {
                cout << clainUnderlineBar()
                     << "Valor geral da venda: " << novaVenda.valorGeral << endl
                     << "Deseja aplicar algum desconto?" << endl
                     << "[1] - Sim" << endl;
              wcout << L"[2] - Não" << endl
                    << endl
                    << L"Escolha uma opção: ";
                cin >> op2;

                if(op2 == 1)
                {
                    cout << endl;
                    novaVenda.aplicarDesconto();
                    
                    cout << endl
                         << "Desconto de R$" << novaVenda.desconto << " aplicado com sucesso!" << endl
                         << "Novo valor geral: R$" << novaVenda.valorGeral << endl;
                    break;
                }
                else if(op2 == 2)
                {
                    break;
                }
                else
                {
                    system("cls");
                    
                    wcout << L"Opção inválida!" << endl;
                }
            }

            cout << endl
                 << clainUnderlineBar()
                 << "Insira o valor pago na venda: R$";
            cin >> novaVenda.valorPago;

            novaVenda.saldoDevedor = novaVenda.valorGeral - novaVenda.valorPago;
            clientes[op1].divida += novaVenda.saldoDevedor;

            cout << endl
                 << clainUnderlineBar();
            wcout << L"Digite alguma observação nessa venda (Desconto dado, quadro retirado, etc...): " << endl
                 << "  ";
            getline(cin >> ws, novaVenda.observacao);

            clientes[op1].vendas.push_back(novaVenda);
            clientes[op1].numVendas ++;

            system("cls");
            cout << "Venda para o cliente " << clientes[op1].nome << " registrado com sucesso!" << endl
                 << endl;

            Cliente::verificarVendas(clientes);
            salvarListaClientes(clientes, registClient, numeroDeClientes);
            salvarVendas(clientes, registClient, registSell);
            pressEnter();

            system("cls");
            break;
        }
    }

    
    void ExcluirVenda(vector<Cliente>& clientes, bool& registClient, bool& registSell, int& numeroDeQuadros,
                      void(registrarCliente)(vector<Cliente>&, bool&, int&),
                      void(registrarVenda)(vector<Cliente>&, bool&, bool&, int&, void(registrarCliente)(vector<Cliente>&, bool&, int&)))
    {
        int op1, op2, op3;
        bool registrosConcluidos = registClient && registSell;

        system("cls");

        if(registClient == false)
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
                if(registClient)
                {
                registrarVenda(clientes, registClient, registSell, numeroDeClientes, funcClient::registrarCliente);
                }
            }
        }
        else if(registSell == false)
        {
            cout << "Nenhum registro de vendas encontrado. Deseja registrar uma nova venda?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op1;

            if(op1 == 1)
            {
                system("cls");
                registrarVenda(clientes, registClient, registSell, numeroDeClientes, registrarCliente);
            }

        }

        if(registrosConcluidos)
        {
            cout << clainUnderlineBar()
                 << "Selecione um dos clientes para excluir uma venda: " << endl
                 << endl;

            Cliente::mostrarListaClientes(clientes);
            cout << "[0] - Cancelar" << endl
                 << endl;

                wcout << L"Selecione uma opção: ";
                cin >> op1;

            if(op1 == 0)
            {
                system("cls");
                cout << clainUnderlineBar();
                wcout << L"Cancelando operação..." << endl
                      << endl;
                pressEnter();
                return;
            } 
            else if(op1 < 0 || op1 > clientes.size()+1)
            {
                system("cls");
                cout << clainUnderlineBar();
                wcout << L"Opção inválida!" << endl
                      << "Retornando..." << endl
                      << endl;
                pressEnter();
                return;
            }
            else op1 --;  

            system("cls");

            while(true)
            {
                cout << "Selecione uma das vendas de " << clientes[op1].nome;
                wcout << L" para exclusão:" << endl;
                cout << clainUnderlineBar();

                for(int i = 0; i < clientes[op1].vendas.size(); i++)
                {
                    cout << "[" << i+1 << "] - " << clientes[op1].vendas[i].fullData << endl
                         << "Plantas: ";

                    for(int j = 0; j < clientes[op1].vendas[i].plantasVendidas.size(); j++)
                    {
                        cout << clientes[op1].vendas[i].plantasVendidas[j].nome;
                        if(j < clientes[op1].vendas[i].plantasVendidas.size() - 1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl
                         << endl;
                }

                wcout << "[0] - Cancelar" << endl
                      << L"Escolha uma opção: ";
                cin >> op2;

                if(op2 == 0)
                {
                    system("cls");

                    cout << clainUnderlineBar();
                    wcout << L"Cancelando operação..." << endl
                          << endl;
                    pressEnter();
                    return;
                }
                else if(op2 < 0 || op2 > clientes[op1].vendas.size())
                {
                    system("cls");
                    cout << clainUnderlineBar();
                    wcout << L"Opção inválida!" << endl
                          << endl;
                    pressEnter();
                }
                else
                {
                    op2--;
                    break;
                }
            }

            system("cls");

            cout << clainUnderlineBar();
            cout << "Tem certeza que deseja excluir os registros da venda de: ";

            for(int i = 0; i < clientes[op1].vendas[op2].plantasVendidas.size(); i++)
            {
                cout << clientes[op1].vendas[op2].plantasVendidas[i].nome;
                if(i < clientes[op1].vendas[op2].plantasVendidas.size() - 1)
                {
                    cout << ", ";
                }
            }

            cout << endl
                 << "Feitas para o cliente " << clientes[op1].nome << " no dia " << clientes[op1].vendas[op2].fullData << "?" << endl
                 << "[1] - Sim" << endl;
          wcout << L"[2] - Não" << endl
                << endl
                << L"Escolha uma opção: ";
            cin >> op3;

            if(op3 == 1)
            {
                string temp = clientes[op1].vendas[op2].fullData;

                if(clientes[op1].vendas[op2].saldoDevedor > 0)
                {
                    clientes[op1].divida -= clientes[op1].vendas[op2].saldoDevedor;
                }

                Venda::excluirVenda(clientes[op1].vendas, op2);
                clientes[op1].numVendas --;

                cout << "Venda feita para o cliente " << clientes[op1].nome << " no dia " << temp << endl;
              wcout << L"Excluída com sucesso!" << endl
                     << endl;
            }
            else
            {
                wcout << L"Cancelando operação..." << endl
                     << endl;
            }

            Cliente::verificarVendas(clientes);
            salvarListaClientes(clientes, registClient, numeroDeClientes);
            salvarVendas(clientes, registClient, registSell);
        }    
        pressEnter();

        system("cls");
    }
}