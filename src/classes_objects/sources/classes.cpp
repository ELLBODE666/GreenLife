#include "../headers/classes.hpp"

void Planta::mostrarQuadro() const
{
    cout << "Nome: " << nome << endl;
}


void Planta::mostrarListaQuadros(vector<Planta>& plantas)
{
    for(int i = 0; i < plantas.size(); i++)
    {
        cout << "[" << i+1 << "] - ";
        plantas[i].mostrarQuadro();
    }
}


double Venda::aplicarDesconto()
{
    this->desconto = 0; // Reseta o desconto caso esteja na função de edição de dados da venda.
    cout << "Insira o desconto dado na venda: R$";
    cin >> this->desconto;
    this->valorGeral -= this->desconto;
return this->valorGeral;
}


void Venda::excluirVenda(vector<Venda>& vendas, int op)
{
    vendas.erase(vendas.begin() + op);
}


void Cliente::mostrarCliente() const
{
    cout << "Nome: " << nome << endl;
}


void Cliente::mostrarListaClientes(vector<Cliente>& clientes)
{       
    for(int i = 0; i < clientes.size(); i++)
    {
        cout << "[" << i+1 << "] - ";
        clientes[i].mostrarCliente();
    }
};


bool Cliente::verificarVendas(vector<Cliente>& clientes)
{
    if (clientes.empty())
    {
        registSell = false;
        registClient = false;
        return false;
    }

    for(const auto& cliente : clientes)
    {
        if(cliente.numVendas > 0)
        {
            registSell = true;
            return true;
        }
    }

    registSell = false;
    return false;
}