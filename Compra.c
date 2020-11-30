#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Functions.h"

int verificar(int c){
   produts t;
   int w=0;
   FILE *file;
   file=fopen("grafs.txt", "r");
   FILE *aux;
   aux=fopen("grafs.txt", "r");
   char aux2[200];
   while (fgets(aux2, 200, aux)!=NULL){
      fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
      if(c==t.codepro){
         w=1;
         break;
      }
   }
   return w;
}
int procaqui(int c){
   produts t;
   char help[200];
   FILE *file;
   file=fopen("grafs.txt", "r+");
   FILE *aux;
   aux=fopen("grafs.txt", "r+");
   while(fgets(help, 200, aux)!=NULL){
      fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
      if (c==t.codepro)
         break;
   }
   fclose(file);
   fclose(aux);
   return t.aquiprice;
}

void compra_por_codigo(int c)
{produts t;
 enco p;
 FILE *file;
 file=fopen("encomendas.txt", "a+");
 printf("\nInsira o codigo do produto: ");
 scanf("%d",&t.codepro);
 int val=verificar(t.codepro);
 char n[]="\n";
   if (val==1){
      printf("\nDigite a quantidade a ser comprada: ");
      scanf("%d", &p.quant);
      printf("Digite a data (no Formato aaaa-mm-dd): ");
      scanf("%s", p.data);
      fprintf(file, "%s", n);
      fprintf(file,"%s %d %d %d", p.data, t.codepro, p.quant, procaqui(t.codepro));
      aumentar_quant(c, p.quant);
      }
   else
      printf("Erro: Codigo inexistente.");
 fclose(file);
}


void por_nome_forn()
{char nome[20];
 char aux[]="\0";
 int cod=procuCodigo();
 compra_por_codigo(cod);
}

void por_cod_forn()
{int code;
 printf("\nDigite o codigo do fornecedor: ");
 scanf("%d",&code);
 compra_por_codigo(code);
}

void compra()
{setlocale(LC_ALL, "Portuguese");
 int opc=0;
 do{system("CLS");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||     COMPRA     ||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\nOpções do Compra:\n  Pesquisa de Produto:\n      1-> Por Nome do Fornecedor;\n      2-> Por Codigo do Fornecedor;\n  3-> Voltar ao Menu;\n");
    printf("\nEscolha opção: ");
    scanf("%d", &opc);
    switch (opc){
        case 1 :
           system("CLS");
           por_nome_forn();
           break;
        case 2 :
           system("CLS");
           por_cod_forn();
           break;
        case 3 :
           system("CLS");
           main();
           break;
        default :
           printf("Resposta invalida!");
           opc=0; /*para nao sair completamente ao chegar na funcao sair*/
        }
    }while(sair(0));
}
