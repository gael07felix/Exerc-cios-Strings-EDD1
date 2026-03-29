#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    ifstream arq("nomes.txt");

    if (arq.is_open())
    {
        string linha;

        while (getline(arq, linha))
        {
            int pos = linha.rfind(" ");

            if (pos != string::npos)
            {
                string sobrenome = linha.substr(pos + 1);
                string restante = linha.substr(0, pos);

                cout << sobrenome << ", " << restante << endl;
            }
            else
            {
                cout << linha << endl;
            }
        }

        arq.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    return 0;
}