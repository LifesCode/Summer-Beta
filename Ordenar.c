#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Functions.h"

int ordem()
{produts t,t1;
 FILE *file;
 FILE *arq;
 FILE *file2;
 FILE *arq2;
 FILE *percorrer;
 char aux1[100];
 int shift=0,parar;//para apanhar so um nome e continuar
 char nome1[30];//guardar o nome para comparar
 char nome2[30];//guardar o nome depois da comparacao
 file = fopen("produtos.txt", "r");
 arq = fopen("grafs.txt", "r");
 file2 = fopen("auxiliar.txt", "a+");//nomes
 arq2 = fopen("conta.txt", "a+");//dados
 percorrer=fopen("produtos.txt","r");
 while(fgets(aux1,100,percorrer)!=NULL){
    //parar=0;
    if(shift==0){
        fscanf(file,"%s",nome1);
        fscanf(arq,"%d %d %d %d %d %d %d %d",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
        shift=1;
        }
    else{
        fscanf(file,"%s",nome2);
        fscanf(arq,"%d %d %d %d %d %d %d %d",&t1.codepro, &t1.codetype, &t1.price, &t1.aquiprice, &t1.forncode, &t1.sctokmim, &t1.sctokmax, &t1.sctokcorr);
        if(strcmp(nome1,nome2)==-1){
            fprintf(file2,"%s",nome1);
            fprintf(file2,"%s","\n");
            fprintf(arq2,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
            fprintf(arq2,"%s","\n");
            strcpy(nome1,nome2);
            t.codepro=t1.codepro;t.codetype=t1.codetype;t.price=t1.price;t.aquiprice=t1.aquiprice;t.forncode=t1.forncode;t.sctokmim=t1.sctokmim;t.sctokmax=t1.sctokmax;t.sctokcorr=t1.sctokcorr;
            //parar=1;
            }
        else if(strcmp(nome1,nome2)==1){
            fprintf(file2,"%s",nome2);
            fprintf(file2,"%s","\n");
            fprintf(arq2,"%d %d %d %d %d %d %d %d", t1.codepro, t1.codetype, t1.price, t1.aquiprice, t1.forncode, t1.sctokmim, t1.sctokmax, t1.sctokcorr);
            fprintf(arq2,"%s","\n");
            //parar=1;
            }
        }
    }
 fprintf(file2,"%s",nome1);
 fprintf(arq2,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
 fclose(file);
 fclose(arq);
 fclose(file2);
 fclose(arq2);
 fclose(percorrer);
 recriartxt("auxiliar.txt","produtos.txt");
 recriartxt2("conta.txt","grafs.txt");
 limpar_txt("auxiliar.txt");
 limpar_txt("conta.txt");
return 0;}

void ordenar()
{int opc,parar;
 do{int i=0;
    system("CLS");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||   ORDENAR   |||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n 1-> Ordenar;\n 2-> Voltar ao Menu;\nO que pretendes fazer?");
    scanf("%d",&opc);
    switch(opc){
        case 1 :do{
                parar=ordem();
                i++;
                }while(i<80);
                 FILE *file;
                 FILE *arq;
                 file=fopen("produtos.txt","r");
                 arq=fopen("produtos.txt","r");
                 fprintf(arq,"%s","\b");
                 fprintf(file,"%s","\b");
                 fclose(file);
                 fclose(arq);
                printf("Produtos ordenados com sucesso!");
                break;
        case 2 :
                system("CLS");
                main();
                break;
        default:
                system("CLS");
                printf("Resposta invalida!");
        }
    }while(sair(0));
}
