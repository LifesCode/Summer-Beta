#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Functions.h"

int main()
{int escolha_acao;
 setlocale(LC_ALL, "Portuguese");
 do{
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||      MENU      ||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" 1-> Venda;\n 2-> Compra;\n 3-> Inventario;\n 4-> Estatisticas por fornecedor;\n 5-> Fatura�ao;\n 6-> Editar lista de Produtos;\n 7-> Ordenar Lista de Produtos;\n 8-> Sair;\n");
    printf("O que pretende realizar? \n");
    scanf("%d",&escolha_acao);
    switch(escolha_acao){
      case 1 :
        venda();
        system("CLS");
        break;
      case 2 :
        compra();
        system("CLS");
        break;
      case 3 :
        system("CLS");
        inventario();
        break;
      case 4 :
        system("CLS");
         fornecedor();
        break;
      case 5 :
        faturacao();
        system("CLS");
        break;
      case 6 :
        editar_produto();
        system("CLS");
        break;
      case 7 :
        ordenar();
        system("CLS");
        break;
      case 8 :
        escolha_acao=sair(escolha_acao);
        break;
      default:
        system("CLS");
        escolha_acao=1;
     }
  }while(escolha_acao);
return 0;
}