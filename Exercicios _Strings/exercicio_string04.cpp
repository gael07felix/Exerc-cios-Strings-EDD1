#include <iostream>
#include <fstream>
#include <locale.h>
#include <cctype>
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
            string palavras[20];
            int qtd = 0;
            string temp = "";

            for (int i = 0; i < linha.size(); i++)
            {
                if (linha[i] != ' ')
                {
                    temp += linha[i];
                }
                else
                {
                    palavras[qtd++] = temp;
                    temp = "";
                }
            }
            palavras[qtd++] = temp;
            string sobrenome = palavras[qtd - 1];

            for (int i = 0; i < sobrenome.size(); i++)
            {
                sobrenome[i] = toupper(sobrenome[i]);
            }
            
            string nome = palavras[0];

            cout << sobrenome << ", " << nome;

            for (int i = 1; i < qtd - 1; i++)
            {
                cout << " " << (char)toupper(palavras[i][0]) << ".";
            }

            cout << endl;
        }

        arq.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    return 0;
}