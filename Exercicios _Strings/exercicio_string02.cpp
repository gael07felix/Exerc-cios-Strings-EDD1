#include <iostream>
#include <locale.h>
#include <cctype>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    string msg, msgSemEspaco = "", msgInvertida = "";

    cout << "Digite uma mensagem: ";
    getline(cin, msg);

   
    for (int i = 0; i < msg.size(); i++)
    {
        char c = msg[i];

        if (c != ' ')
        {
            msgSemEspaco += toupper(c);
        }
    }

    
    for (int i = (int)msgSemEspaco.size() - 1; i >= 0; i--)
    {
        msgInvertida += msgSemEspaco[i];
    }

    
    if (msgSemEspaco.compare(msgInvertida) == 0)
    {
        cout << "Eh um palindromo!" << endl;
    }
    else
    {
        cout << "Nao eh um palindromo!" << endl;
    }

    return 0;
}