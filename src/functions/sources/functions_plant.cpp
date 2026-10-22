#include "../headers/functions_plant.hpp"
#include "../headers/functions_main.hpp"
#include "../headers/functions_load.hpp"

using namespace std;
using namespace funcMain;
using namespace funcFile;

namespace funcPlant
{
     void registrarQuadro(vector<Planta>& plantas, bool& registPlant)
     {
          int op;
          Adubo novaAdubagem;
          Planta novoQuadro;
          Data novaData;

          
          system("cls");

          cout << clainUnderlineBar();
          wcout << L"Dê um nome para identificação do novo quadro: ";
          getline(cin >> ws, novoQuadro.nome);
  
          cout << endl
               << clainUnderlineBar() 
               << "Insira o nome do tipo de planta do quadro a ser registrado: ";
          getline(cin >> ws,novoQuadro.tipo);
  
          cout << endl
               << clainUnderlineBar()
               << "Insira a data de plantio" << endl
               << endl
               << "Dia: ";
          cin >> novaData.dia;
          wcout << L"Mês: ";
          cin >> novaData.mes;
          cout << "Ano: ";
          cin >> novaData.ano;
          
          dataConversor(novoQuadro.fullData, novaData);

          cout << endl
               << clainUnderlineBar()
               << "Insira a quantidade de plantas neste quadro: ";
          cin >> novoQuadro.quantidade;
  
          plantas.push_back(novoQuadro);
  
          system("cls");
          cout << clainUnderlineBar()
               << "Quadro " << novoQuadro.nome << " registrado com sucesso!" << endl
               << endl;

          if(!registPlant)
          {registPlant = true;}

          pressEnter();

          salvarQuadro(plantas, registPlant, numeroDeQuadros);
          system("cls");
    }

     void editarQuadro(vector<Planta>& plantas, bool& registPlant, int numeroDeQuadros)
     {
          int op1, op2, op3;
          Adubo novaAdubagem;
          Data novaData;

          if(!registPlant)
          {
               cout   << "Nenhum quadro de plantas registrado. Deseja registrar um novo quadro?" << endl
                      << "[1] - Sim" << endl;
               wcout << L"[2] - Não" << endl
                     << endl
                     << L"Selecione uma opção: ";
               cin >> op1;

               if(op1 == 1)
               {
                    registrarQuadro(plantas, registPlant);
               }
               else if(op1 == 2)
               {
                    cout << "Retornando..." << endl
                         << endl;
               }
               else
               {
                    wcout << L"Opção inválida!" << endl
                          << "Retornando..." << endl;
               }
          }
          else
          {
               system("cls");

               cout << clainUnderlineBar()
                    << "Selecione um dos quadros registrados para editar seus dados:" << endl
                    << clainUnderlineBar();

               Planta::mostrarListaQuadros(plantas);

               wcout << "[0] - Cancelar" << endl
                     << endl
                     << L"Escolha uma opção: ";
               cin >> op1;

               if(op1 == 0)
               {
                    system("cls");

                    wcout << L"Cancelando operação." << endl
                          << "Retornando..." << endl
                          << endl;
               }
               else if(op1 < 0 || op1 > plantas.size())
               {
                    wcout << L"Opção inválida!" << endl
                          << "retornando..." << endl
                          << endl;
               }
               else
               {
                    op1--;

                    system("cls");

                    cout << clainUnderlineBar()
                         << "Editando os dados do quadro '" << plantas[op1].nome << "'" << endl
                         << "Selecione um dado para ser alterado: " << endl
                         << endl
                         << "[1] - Nome: " << plantas[op1].nome << endl
                         << "[2] - Tipo de planta: " << plantas[op1].tipo << endl
                         << "[3] - Data de plantio: " << plantas[op1].fullData << endl
                         << "[4] - Quantidade plantada: " << plantas[op1].quantidade << endl
                         << "[5] - Adubagens feitas " << endl
                         << endl;

                    wcout << L"Escolha uma opção: ";
                    cin >> op2;
                    system("cls");

                    switch(op2)
                    {
                         case 1:
                              cout << "Editando o nome de " << plantas[op1].nome << endl
                                   << endl
                                   << "Digite um novo nome: ";
                              getline(cin >> ws, plantas[op1].nome);

                              wcout << endl
                                    << L"Edição concluída com sucesso!" << endl
                                    << endl;
                         break;

                         case 2:
                              cout << "Editando o tipo de " << plantas[op1].nome << endl
                                   << endl
                                   << "Digite um novo tipo: ";
                              getline(cin >> ws, plantas[op1].tipo);

                              wcout << endl
                                    << L"Edição concluída com sucesso!" << endl
                                    << endl;
                         break;

                         case 3:
                              cout << "Editando a data de plantio de " << plantas[op1].nome << endl
                                   << endl
                                   << "Insira uma nova data de plantio" << endl
                                   << endl
                                   << "Dia: ";
                              cin >> novaData.dia;
                              wcout << L"Mês: ";
                              cin >> novaData.mes;
                              cout << "Ano: ";
                              cin >> novaData.ano;

                              dataConversor(plantas[op1].fullData, novaData);

                              wcout << endl
                                    << L"Edição concluída com sucesso!" << endl
                                    << endl;
                         break;

                         case 4:
                              cout << "Editando a quantidade plantada de " << plantas[op1].nome << endl
                                   << endl
                                   << "Digite uma nova quantidade:  ";
                              cin >> plantas[op1].quantidade;

                              system("cls");
                              cout << clainUnderlineBar();
                              wcout << L"Edição concluída com sucesso!" << endl
                                    << endl;
                         break;

                         case 5:
                              if(plantas[op1].qntAdubadas == 0)
                              {
                                   cout << "Nenhuma adubagem no quadro " << plantas[op1].nome << " Registrado!" << endl
                                        << "Deseja registrar uma nova adubagem?    1 -> Sim" << endl;
                                 wcout << L"                                       2 -> Não" << endl
                                       << endl
                                       << L"Escolha uma opção: ";

                                   cin >> op2;

                                   switch(op2)
                                   {
                                        case 1:
                                             cout << endl
                                             << clainUnderlineBar()
                                             << "Registrando uma adubagem no quadro " << plantas[op1].nome << endl
                                             << endl
                                             << "Selecione o tipo de adubo usado: ";
                                   
                                             getline(cin >> ws, novaAdubagem.tipoDeAdubo);
                                   
                                             cout << endl
                                                  << "Selecione a data de adubagem " << endl
                                                  << "Dia: ";
                                             cin >> novaData.dia;
                                             wcout << L"Mês: ";
                                             cin >> novaData.mes;
                                             cout << "Ano: ";
                                             cin >> novaData.ano;
                                   
                                             dataConversor(novaAdubagem.dataDeAdubagem, novaData);                                                      
                                   
                                             plantas[op1].qntAdubadas += 1;
                                             plantas[op1].adubagens.push_back(novaAdubagem);
                                   
                                              cout << endl
                                                   << "Adubagem registrada com sucesso!" << endl;
                                   
                                             salvarQuadro(plantas, registPlant, numeroDeQuadros);
                                        break;

                                        case 2:
                                        cout << endl
                                             << "Retornando..." << endl
                                             << endl;
                                        break;

                                        default:
                                             wcout << "Opção inválida!" << endl
                                                   << "Retornando..." << endl;
                                        break;
                                   }
                              }
                              else
                              {
                                   while(true)
                                   {
                                        cout << "selecione uma das adubagens para editar:    "
                                             << "[1] - " << plantas[op1].adubagens[0].tipoDeAdubo << " - "
                                             << plantas[op1].adubagens[0].dataDeAdubagem << endl;
                                        for(int i = 1; i < plantas[op1].qntAdubadas-1; i++)
                                        {
                                             cout << "                                            "
                                                  << "[" << i+1 << "] - " << plantas[op1].adubagens[i].tipoDeAdubo << " - "
                                                  << plantas[op1].adubagens[i].dataDeAdubagem << endl;
                                        }
                                   
                                        wcout << endl
                                              << L"Escolha uma opção: ";
                                        cin >> op2;
                                        op2--;

                                        if(op2 >= 0 && op2 < plantas[op1].qntAdubadas)
                                        {
                                             system("cls");

                                             cout << "Deseja editar ou excluir essa adubagem?    1 -> Editar" << endl
                                                  << "                                           2 -> Excluir" << endl
                                                  << endl;
                                             wcout << L"Escolha uma opção: ";

                                             cin >> op3;

                                             if(op3 == 1)
                                             {
                                                  system("cls");
                                                  clainUnderlineBar();

                                                  cout << "Alterando o tipo de adubo para a adubagem " << op2+1 << " do quadro " <<plantas[op1].nome << endl
                                                       << endl
                                                       << "Insira um novo tipo de adubo: ";
                                                  getline(cin >> ws, novaAdubagem.tipoDeAdubo);

                                                  cout << endl
                                                       << "Insira uma nova data: " << endl
                                                       << endl
                                                       << "Dia: ";
                                                  cin >> novaData.dia;
                                                  wcout << L"Mês: ";
                                                  cin >> novaData.mes;
                                                  cout << "Ano: ";
                                                  cin >> novaData.ano;

                                                  dataConversor(novaAdubagem.dataDeAdubagem, novaData);
                                                  plantas[op1].adubagens[op2] = novaAdubagem;

                                                  cout << "Adubagem editada com sucesso!" << endl;
                                                  break;                   
                                             }
                                             else if(op3 == 2)
                                             {
                                                  plantas[op1].adubagens.erase(plantas[op1].adubagens.begin() + op2);
                                                  plantas[op1].qntAdubadas --;
                                             
                                                  wcout << L"Adubagem excluída com sucesso!" << endl;
                                                  break;
                                             }
                                             else
                                             {
                                                  wcout << L"Opção inválida!" << endl
                                                        << "Retornando..." << endl;
                                             }
                                        }
                                        else
                                        {
                                             wcout << L"Opção inválida!" << endl
                                                   << "Retornando..." << endl;
                                                   break;
                                        }
                                   }
                              }
                         break;

                         default:
                              wcout << L"Opção inválida!" << endl
                                    << endl;
                         break;
                    }
               }
          }

          pressEnter();                
          salvarQuadro(plantas, registPlant, numeroDeQuadros);
          system("cls");
     }

     
     void registrarAdubagem(vector<Planta>& plantas, bool& registPlant, int numeroDeQuadros)
     {
          system("cls");

          int op;
          Adubo novaAdubagem;
          Data novaData;

          if(registPlant == false)
          {
               cout   << "Nenhum quadro de plantas registrado. Deseja registrar um novo quadro?" << endl
                      << "                                                      1 -> Sim" << endl;
               wcout << L"                                                      2 -> Não" << endl
                     << L"Escolha uma opção: ";
               cin >> op;

               if(op == 1)
               {
                    registrarQuadro(plantas, registPlant);
                    return;
               }
               else pressEnter(); return;
          }
          else
          {
               cout << "Selecione um dos quadros para registrar uma nova adubagem: " << endl
                    << endl;

               for(int i = 0; i < numeroDeQuadros; i++)
               {
                    cout << i+1 << " -> " << plantas[i].nome << endl;
               }

               wcout << endl
                     << L"Selecione uma opção: ";

               cin >> op;
               op--;

               system("cls");

               cout << clainUnderlineBar()
                    << "Registrando uma adubagem no quadro " << plantas[op].nome << endl
                    << endl
                    << "Selecione o tipo de adubo usado: ";

               getline(cin >> ws, novaAdubagem.tipoDeAdubo);

               cout << endl
                    << "Selecione a data de adubagem " << endl
                    << "Dia: ";
               cin >> novaData.dia;
               wcout << L"Mês: ";
               cin >> novaData.mes;
               cout << "Ano: ";
               cin >> novaData.ano;
     
               dataConversor(novaAdubagem.dataDeAdubagem, novaData);

               plantas[op].qntAdubadas += 1;
               plantas[op].adubagens.push_back(novaAdubagem);

               cout << endl
                    << "Adubagem registrada com sucesso!" << endl;
          }

          pressEnter();
          salvarQuadro(plantas, registPlant, numeroDeQuadros);
          system("cls");
     }
     

    void mostrarQuadro(vector<Planta>& plantas, bool& registPlant, int numeroDeQuadros)
    {
          int op;

          if(registPlant == false)
          {
               cout   << "Nenhum quadro de plantas registrado. Deseja registrar um novo quadro?" << endl
                      << "[1] - Sim" << endl;
               wcout << L"[2] - Não" << endl
                     << endl
                     << L"Escolha uma opção: ";
               cin >> op;

               if(op == 1)
               {
                    registrarQuadro(plantas, registPlant);
                    return;
               }
               else pressEnter(); return;
          }
          else
          {
               system("cls");
               cout << clainUnderlineBar()
                    << "Selecione um dos quadros registrados para exibir seus dados" << endl
                    << clainUnderlineBar();

               for(int i = 0; i < numeroDeQuadros; i++)
               {
                    cout << i + 1 << " -> " << plantas[i].nome << endl;
               }
               cout << endl;
              wcout << L"Escolha uma opção: ";
               cin >> op;
               op--;

               if(op < 0 || op >= numeroDeQuadros)
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
                    << "Nome do quadro: " << plantas[op].nome << endl
                    << "Tipo de planta: " << plantas[op].tipo << endl
                    << "Data de plantio: " << plantas[op].fullData << endl
                    << "Quantidade plantada: " << plantas[op].quantidade << endl
                    << "Adubagens feitas: " << plantas[op].qntAdubadas << endl;

               if(plantas[op].qntAdubadas != 0)
               {              
                    for(int i = 0; i < plantas[op].qntAdubadas; i++)
                    {
                         cout << "Adubagem " << i+1 << " -> Adubo usado: " << plantas[op].adubagens[i].tipoDeAdubo 
                              << ", Data: " << plantas[op].adubagens[i].dataDeAdubagem << endl;
                    }
               }

               cout << clainUnderlineBar();

               pressEnter();
          }  

     system("cls");
    }


    void excluirQuadro(vector<Planta>& plantas, int& numeroDeQuadros, bool& registPlant)
    {
          system("cls");

          int op1, op2;

          if(!registPlant)
          {
               cout << "Nenhum registro de quadro de plantas foi encontrado." << endl
                    << endl;
          }
          else
          {
               cout << clainUnderlineBar();
               wcout << L"Selecione um quadro para exclusão:" << endl;
               cout << clainUnderlineBar();

               for(int i = 0; i < numeroDeQuadros; i++)
               {
                    cout << "[" << i+1 << "] - " << plantas[i].nome << endl;
               }

               cout << "[0] - Cancelar" << endl
                    << clainUnderlineBar();

               wcout << L"Escolha uma opção: ";
               cin >> op1;

               if(op1 > 0 && op1 <= numeroDeQuadros)
               {
                    system("cls");
                    op1--;

                    cout << clainUnderlineBar();    
                  wcout << L"Tem certeza que deseja excluír o quadro "; cout << plantas[op1].nome << "?" << endl
                        << "[1] - Sim" << endl;
                  wcout << L"[2] - Não" << endl
                        << endl
                        << L"Escolha uma opção: ";
                    cin >> op2;

                    if(op2 == 1)
                    {
                         string quadroDelNome = plantas[op1].nome;
                         plantas.erase(plantas.begin() + op1);
                         salvarQuadro(plantas, registPlant, numeroDeQuadros);
                         numeroDeQuadros --;

                         if(numeroDeQuadros == 0)
                         {
                              registPlant = false;
                         }

                         system("cls");

                         cout << "Quadro " << quadroDelNome << " deletado com sucesso!" << endl
                              << endl;
                    }
                    else if(op2 == 2)
                    {
                         wcout << endl
                               << L"Cancelando operação..." << endl
                               << endl;
                    }
                    else
                    {
                         wcout << L"Opção inválida!" << endl
                          <<  "Retornando..." << endl
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