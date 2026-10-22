#ifndef FUNCTIONS_PLANT_HPP
#define FUNCTIONS_PLANT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "../../classes_objects/headers/global_objects.hpp"
#include "../../classes_objects/headers/classes.hpp"

using namespace std;

namespace funcPlant
{
     void registrarQuadro(vector<Planta>&, bool&);

     void editarQuadro(vector<Planta>&, bool&, int);
     
     void registrarAdubagem(vector<Planta>&, bool&, int);
     
     void mostrarQuadro(vector<Planta>&, bool&, int);

     void excluirQuadro(vector<Planta>&, int&, bool&);
}

#endif