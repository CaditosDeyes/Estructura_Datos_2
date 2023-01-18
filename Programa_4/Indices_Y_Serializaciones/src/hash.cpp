#include "hash.h"

Hash::Hash() {}
bool Hash::vacia() const
{
    int suma{};
    for (int i{}; i < consola; i++)
    {
        suma += tabla[i].size();
    }
    if (!suma)
    {
        return true;
    }
    return false;
}

int Hash::hashFuncion(int llave)
{
    return llave % consola;
}

void Hash::insertar(int llave, data valor)
{
    int hashValor = hashFuncion(llave);
    auto &cell = tabla[hashValor];
    bool llave_existente = false;
    auto enumerador = cell.begin();

    do
    {
        if (!llave_existente)
        {
            cell.emplace_back(llave, valor);
            return;
        }
        else
        {
            llave_existente = true;
            enumerador++;
        }
    } while (enumerador != cell.end());
}

void Hash::eliminar(int llave)
{
    int hashValor = hashFuncion(llave);
    auto &cell = tabla[hashValor];
    auto enumerador = begin(cell);
    bool llave_existente = false;
    for (; enumerador != end(cell); enumerador++)
    {
        if (enumerador->first == llave)
        {
            llave_existente = true;
            enumerador = cell.erase(enumerador);
            cout << "libro eliminado" << endl;
            break;
        }
    }

    if (!llave_existente)
    {
        cout << "codigo no encontrado" << endl;
    }

    return;
}

void Hash::mostrar_tabla()
{
    for (int i{}; i < consola; i++)
    {
        if (tabla[i].size() == 0)
            continue;

        auto enumerador = tabla[i].begin();
        cout<<"Codigo |\tAutor |\tLibro\t\t |\tPaginas \n";
        for (; enumerador != tabla[i].end(); enumerador++)
        {
            cout << enumerador->first<<"\t"<<enumerador->second << endl;
        }
    }
    return;
}

void Hash::buscar(int llave)
{
    int hashValor = hashFuncion(llave);
    auto &cell = tabla[hashValor];
    auto enumerador = begin(cell);
    bool llave_existente = false;
    for (; enumerador != end(cell); enumerador++)
    {
        if (enumerador->first == llave)
        {
            llave_existente = true;
            cout << "libro encontrado" << endl;
            cout<<"Codigo |\tAutor |\tLibro\t |\tPaginas \n";
            cout << enumerador->first<<"\t"<<enumerador->second << endl;
            break;
        }
    }

    if (!llave_existente)
    {
        cout << "Codigo no encontrado" << endl;
    }

    return;
}

void Hash::Guardar()
{
    ofstream archivo("file01.txt", ios::out);
    if (archivo.is_open())
    {
        for (int i{}; i < consola; i++)
        {
            for (auto it = tabla[i].begin(); it != tabla[i].end(); it++)
            {
                archivo << it->first << "|"
                        << it->second.getAutor() << "|"
                        << it->second.getLibro() << "|"
                        << it->second.getPaginas() << "*"
                        << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo crear el archivo" << endl;
    }
    archivo.close();
}

void Hash::Cargar()
{
    ifstream archivo("file01.txt", ios::out);
    if (archivo.is_open())
    {
        string provisional;
        int llave;
        data d;

        while (true)
        {
            getline(archivo, provisional, '|');
            if (archivo.eof())
            {
                break;
            }
            llave = stoi(provisional);
            d.setLlave(llave);
            getline(archivo, provisional, '|');
            d.setAutor(provisional);
            getline(archivo, provisional, '|');
            d.setLibro(provisional);
            getline(archivo, provisional, '*');
            d.setPaginas(provisional);

            insertar(d.getLlave(), d);
        }
    }
    else
    {
        cout << "No se pudo acceder al archivo" << endl;
    }
    archivo.close();
}
