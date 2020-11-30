#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Functions.h"

int sair_completo(int esc)
{setlocale(LC_ALL, "Portuguese");
 do{
    system("CLS");
    printf("Tem certeza que quer abandonar o programa?\n 1-> Sim \n 2-> Nao\n");
    scanf("%d",&esc);
    if(esc==1){
        system("CLS");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||    Obrigado por utilizar este programa! Até a proxima!   ||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        exit(0);
        }
    else if(esc==2){
        system("CLS");
        return 1;
        }
    else{
        printf("Resposta invalida!Tente novamente.");
        system("CLS");
        }
    }while(esc!=2 || esc!=1);
}

int sair_parcial(int esc)
{do{
    printf("Desejas continuar ou voltar ao Menu?\n 1- Continuar \n 2- Voltar ao Menu\n");
    scanf("%d",&esc);
    if (esc==1){
       system("CLS");
       return 1;
       }
    else if(esc==2){
       system("CLS");
       main();
       }
    else{
        printf("Resposta invalida! Tente novamente.");
        system("CLS");
        }
   }while(esc!=1 || esc!=2);
}

int sair(int esc)
{if(esc==8)
    sair_completo(esc);
 else
    esc=sair_parcial(esc);
return esc;}
