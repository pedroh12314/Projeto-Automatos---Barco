#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

void imprime_e_recebe_entrada();
void runAutomato();
bool lerEntrada();
void entradaInvalida();
void pressEnter();

/*
###### CONSIDERACOES ######

- ENTRADAS
H
HM
HG
HR

- TRASICAO: ESTADO + ENTRADA

             -> 4 -> 5 -
1 -> 2 -> 3 -           -> 8 -> 9 -> 10
             -> 6 -> 7 -


- ESTADOS
       ME     MD
1:    HMRG |  []
2:    RM   |  HG
3:    HRM  |  G
4:    R    |  HMG
5:    HGR  |  M
6:    M    |  HRG
7:    HGM  |  R
8:    G    |  HRM
9:    HG   |  RM
10:   []   |  HRMG

- ESTADO INICIAL: 1
- ESTADO FINAL:   10

*/

// CODIGO PRINCIPAL
int main()
{
     system("CLS");
     cout << "ENUNCIADO" << endl;
     cout << endl;

     // SOLICITA CONFIRMACAO PARA PROSSEGUIR
     pressEnter();

     // RODA O AUTOMATO
     runAutomato();

     return 0;
}

// VARIAVEIS GLOBAIS
string entrada;
int estadoAutomato = 1;

// SOLICITA ENTRADA E REALIZA LEITURA
void imprime_e_recebe_entrada()
{
     system("cls");
     cout << "ESTADO ATUAL: " << estadoAutomato << endl;
     cout << "Escreva uma entrada: H, HG, HM, HR\n\n" << endl;
     cin >> entrada;
}

// MAQUINA DE ESTADO DO AUTOMATO
void runAutomato()
{
     while (estadoAutomato <= 10)
     {
          switch (estadoAutomato)
          {
          case 1:
               // solicita entrada e salva em uma variavel entrada
               imprime_e_recebe_entrada();

               // Verifica se a entrada e valida para o estado atual
               if (entrada.compare("HG") == 0)
                    estadoAutomato = 2;
               else
                    entradaInvalida(); // Avisa usuario entrada invalida

               break;
          case 2:
               imprime_e_recebe_entrada();

               if (entrada.compare("H") == 0)
                    estadoAutomato = 3;
               else if (entrada.compare("HG") == 0)
                    estadoAutomato = 1;
               else
                    entradaInvalida();

               break;
          case 3:
               imprime_e_recebe_entrada();

               if (entrada.compare("HM") == 0)
                    estadoAutomato = 4;
               else if (entrada.compare("HR") == 0)
                    estadoAutomato = 6;
               else if (entrada.compare("H") == 0)
                    estadoAutomato = 2;
               else
                    entradaInvalida();

               break;
          case 4:
               imprime_e_recebe_entrada();

               if (entrada.compare("HG") == 0)
                    estadoAutomato = 5;
               else if (entrada.compare("HM") == 0)
                    estadoAutomato = 3;
               else
                    entradaInvalida();
               break;
          case 5:
               imprime_e_recebe_entrada();

               if (entrada.compare("HR") == 0)
                    estadoAutomato = 8;
               else if (entrada.compare("HG") == 0)
                    estadoAutomato = 4;
               else
                    entradaInvalida();
               break;
          case 6:
               imprime_e_recebe_entrada();

               if (entrada.compare("HG") == 0)
                    estadoAutomato = 7;
               else if (entrada.compare("HR") == 0)
                    estadoAutomato = 3;
               else
                    entradaInvalida();
               break;
          case 7:
               imprime_e_recebe_entrada();

               if (entrada.compare("HM") == 0)
                    estadoAutomato = 8;
               else if (entrada.compare("HG") == 0)
                    estadoAutomato = 6;
               else
                    entradaInvalida();
               break;
          case 8:
               imprime_e_recebe_entrada();

               if (entrada.compare("H") == 0)
                    estadoAutomato = 9;
               else if (entrada.compare("HM") == 0)
                    estadoAutomato = 7;
               else if (entrada.compare("HR") == 0)
                    estadoAutomato = 5;
               else
                    entradaInvalida();
               break;

          case 9:
               imprime_e_recebe_entrada();

               if (entrada.compare("HG") == 0)
                    estadoAutomato = 10;
               else if (entrada.compare("H") == 0)
                    estadoAutomato = 8;
               else
                    entradaInvalida();
               break;
          case 10:
               system("cls");
               cout << "ESTADO ATUAL: " << estadoAutomato << endl;
               cout << "\n\nEstado Final atingido!!!!\n\n";
               pressEnter();
               estadoAutomato = 11;

               break;
          default:
               system("cls");
               cout << "\n\ninesperado default estadoAutomato()\n\n";
               break;
          }
     }
}



// AVISA USUARIO QUE ENTRADA E INVALIDA
void entradaInvalida()
{
     system("CLS");
     cout << "\nEntrada invalida!\n";
     pressEnter();
}

// AGUARDA O USUARIO PRESSINAR ENTER
void pressEnter()
{
     do
     {
     cout << "\nPressione ENTRER para continuar...\n";
     } while (lerEntrada() != true);
}

// Verifica se o enter 
bool lerEntrada()
{
     cin.clear();
     fflush(stdin);
     if(_getch() == '\r')
          return true;
     return false;   
}
