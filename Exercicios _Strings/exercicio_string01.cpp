#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;

void gotoxy(short x, short y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    setlocale(LC_ALL, "");

    string msg;

    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    int larguraTela = 80;
    int linhaInicial = 5;
    int linhaFinal = 20;

    int colunaInicial = (larguraTela - msg.size()) / 2;

    gotoxy(colunaInicial, linhaInicial);
    cout << msg;

    Sleep(1000); 

    for (int i = 0; i < msg.size(); i++)
    {
        for (int linha = linhaInicial; linha <= linhaFinal; linha++)
        {
            gotoxy(colunaInicial + i, linha - 1);
            cout << " ";

            gotoxy(colunaInicial + i, linha);
            cout << msg[i];

            Sleep(50);
        }
    }

    gotoxy(colunaInicial, linhaFinal);
    cout << msg;

    cout << endl;
    return 0;
}