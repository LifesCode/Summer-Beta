#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Functions.h"

void monstrarprod(int ct)
{setlocale(LC_ALL, "Portuguese");
 produts t;
 forn f;
 int count=0;
 char aux1[100];
 FILE*file;
 file=fopen("grafs.txt", "r+");
 FILE*arq;
 arq=fopen("grafs.txt", "r+");
 FILE*arq1;
 arq1=fopen("produtos.txt", "r+");
 char c[100];
 printf("\nOs produtos com origem nesse fornecedor são: ");
 while (fgets(aux1, 100, file)!=NULL){
     fgets(t.nomeprod,100, arq1);
     fscanf(arq,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
     if (ct==t.forncode){
         printf("\n\n----------------------------------------------------------------------------------------------------------");
         printf("\nProduto: %s \nPreço de aquisição: %d \nCusto de venda: %d \nDiferença de preço: %d\n",  t.nomeprod, t.aquiprice, t.price, t.price-t.aquiprice);
         }
     count=count+1;
     }
 printf("\n\n");
 fclose(file);
 fclose(arq);
 fclose(arq1);
}

int contarForn(){
    int count=0;
    FILE *file;
    file=fopen("fornecedor.txt", "r");
    char c[100];
    while (fgets(c, 100, file)!=NULL){
        count=count+1;
    }
    fclose(file);
    return count;
}

int procuCodigo2()
{setlocale(LC_ALL,"Portuguese");
 int forncode;
 int i,val,telef,count=1,linhas=contarelementos();
 char nomeforn[100];
 char morada[50];
 char aux1[]="\0";
 printf("\nDigite o nome do fornecedor: ");
 do{FILE *file;
    file=fopen("fornecedor.txt", "r");
    val=1;
    char nome[50];
    count=1;
    scanf("%s", nome);
    strcat(nome, aux1);
    for (i=0;i<=linhas;i++){
         fscanf(file, "%d %s %s %d", &forncode, nomeforn, morada, &telef);
         count=count+1;
         if(comparar(nome, nomeforn)==0){
             val=0;
             break;
             }
         }
     if(val==1)
         printf("\nErro fornecedor nao existe.\nTente novamente: ");
     fclose(file);
    }while(val!=0);
return count;}

void por_nomeforn()
{int ct=procuCodigo2();
 monstrarprod(ct-1);
}

void por_codigoforn()
{setlocale(LC_ALL, "Portugues");
 printf("\nInsira o codigo do fornecedor que desejas pesquisar: ");
 int ct, t=contarForn();
 do{
    scanf("%d", &ct);
    if (ct>contarForn())
        printf("Digite o codigo novamente por esse codigo nao existe: ");
   }while(ct>t);
 printf("\n%d", ct);
 monstrarprod(ct);
}

void fornecedor()
{int opc=0;
 setlocale(LC_ALL, "Portugues");
 do{printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||     ESTATISTICAS POR FORNECEDOR     |||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n\n  Pesquisa de Produto de um determinado fornecedor:\n      1-> Por Nome do Fornecedor;\n      2-> Por Codigo do Fornecedor;\n  3-> Voltar ao Menu;\n");
    printf("\nEscolha opçãoo: ");
    scanf("%d", &opc);
    switch (opc){
        case 1 :
           system("CLS");
           por_nomeforn();
           break;
        case 2 :
           system("CLS");
           por_codigoforn();
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
