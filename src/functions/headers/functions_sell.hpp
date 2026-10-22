#ifndef FUNCTIONS_SELL_HPP
#define FUNCTIONS_SELL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include "../../classes_objects/headers/global_objects.hpp"
#include "../../classes_objects/headers/classes.hpp"

namespace funcSell
{
    void mostrarVendas(vector<Cliente>&, int&, bool&, bool&,
                       void(vector<Cliente>&, bool&, int&),
                       void(vector<Cliente>&, bool&, bool&, int&, void(vector<Cliente>&, bool&, int&)));
  
    void editarRegistroVenda(vector<Cliente>&, int&, bool&, bool&,
                             void(vector<Cliente>&, bool&, int&),
                             void(vector<Cliente>&, bool&, bool&, int&, void(vector<Cliente>&, bool&, int&)));
  
    void RegistrarVenda(vector<Cliente>&, bool&, bool&, int&,
                        void(vector<Cliente>&, bool&, int&));
 
    void ExcluirVenda(vector<Cliente>&, bool&, bool&, int&,
                      void(vector<Cliente>&, bool&, int&),
                      void(vector<Cliente>&, bool&, bool&, int&, void(vector<Cliente>&, bool&, int&)));

}

#endif