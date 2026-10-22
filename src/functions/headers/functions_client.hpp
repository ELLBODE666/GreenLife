#ifndef FUNCTIONS_CLIENT_HPP
#define FUNCTIONS_CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include "../../classes_objects/headers/global_objects.hpp"
#include "../../classes_objects/headers/classes.hpp"


namespace funcClient
{
    void mostrarClientesContatos(vector<Cliente>&, bool&, int&, void(vector<Cliente>&, bool&, int&));

    void registrarCliente(vector<Cliente>&, bool&, int&);
    
    void editarRegistroCliente(vector<Cliente>&, bool&, int&, void(vector<Cliente>&, bool&, int&));

    void excluirCliente(vector<Cliente>&, bool&, int&);
}

#endif