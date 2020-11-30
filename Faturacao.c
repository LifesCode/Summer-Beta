#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Functions.h"

int procuraPre(int c)
{produts t;
 FILE * file;
 file=fopen("grafs.txt", "r");
 FILE * file1;
 file1=fopen("grafs.txt", "r");
 char aux[100];
 while(fgets(aux, 100, file)!=NULL){
         fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
         if (t.codepro==c){
             break;
             }
         }
 fclose(file);
 fclose(file1);
 return t.price;}

void faturacaoFunction()
{setlocale(LC_ALL, "Portuguese");
 int code;
 int pre;
 enco p;
 FILE * file;
 file=fopen("encomendas.txt", "r");
 FILE * arq;
 arq=fopen("encomendas.txt", "r");
 char aux[200];
 char data1[11];
 char data2[11];
 char aux1[]="\0";
 char aux2[]="\0";
 printf("\ndigite a primeira data (no Formato aaaa-mm-dd): ");
 scanf ("%s", data1);
 printf("\ndigite a segunda data (no Formato aaaa-mm-dd): ");
 scanf ("%s", data2);
 strcat(data1, aux1);
 strcat(data2, aux2);
 float totalprice=0;
 float totalaqui=0;
 float dif=0;
 while (fgets(aux, 200, arq)!=NULL){
     fscanf(file, "%s %d %d %d", p.data, &code, &p.quant, &pre);
     if ((comparar(data1, p.data)==0 || comparar(data1, p.data)==-1)){
         if((comparar(data2, p.data)==0 || comparar(data2, p.data)==1)){
             int preven=procuraPre(code);
             printf("\nCusto de aquisicao: %d $00\nCusto de venda: %d $00\nDiferenca: %d $00", pre, preven, preven-pre);
             totalprice=totalprice+preven;
             totalaqui=totalaqui+pre;
             dif=dif+(preven-pre);
             printf("\n");
             printf("\n-----------------------------------------------------------------------------------\n");
             }
        }
     }
 printf("\nCusto total de aquisicao: %f $00\nCusto total de venda: %f $00\nDiferenca total: %f $00\n", totalprice, totalaqui, dif);
 fclose(file);
}


void faturacao()
{int opc;
 do{system("CLS");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||||||||||||||||   FATURAÇÃO   ||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n 1-> Pesquisar;\n 2-> Voltar ao menu;\nO que pretendes fazer?");
    scanf("%d",&opc);
    switch(opc){
        case 1 :
                system("CLS");
                faturacaoFunction();
                break;
        case 2 :
                system("CLS");
                break;
        default:
                system("CLS");
                printf("Resposta invalida!");
        }
    }while(sair(0));
}
