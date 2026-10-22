#include "../headers/functions_main.hpp"

using namespace std;

namespace funcMain
{
    string clainUnderlineBar()
    {
        int length = 120;
    return string(length, '_') + "\n\n";
    }


    string pressEnter()
    {
        string dummy;
        cout << "Precione ENTER para continuar..." << endl;
        cin.ignore();
        getline(cin, dummy);
    return dummy;
    }


    void dataConversor(string& herData, Data data)
    {
        herData = to_string(data.dia) + "/" + 
                  to_string(data.mes) + "/" + 
                  to_string(data.ano);
    }

    void contactConversor(string& contact, int ddd, int tel)
    {
        contact = "[" + to_string(ddd) + "]" +
                        to_string(tel);
    }
}