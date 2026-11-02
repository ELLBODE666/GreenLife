#ifndef FUNCTIONS_LOAD_HPP
#define FUNCTIONS_LOAD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <filesystem>

#include "../../classes_objects/headers/global_objects.hpp"
#include "../../classes_objects/headers/classes.hpp"

namespace funcFile
{
    void verificarPastaData();

    void salvarQuadro(vector<Planta>&, bool&, int&);

    void carregarQuadro(vector<Planta>&, bool&, int&);

    void salvarListaClientes(vector<Cliente>&, bool&, int&);

    void salvarVendas(vector<Cliente>&, bool&, bool&);

    void carregarListaClientes(vector<Cliente>&, bool&, int&);

    void carregarVendas(vector<Cliente>&, bool&, bool&);
}

#endif