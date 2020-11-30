#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "Functions.h"

void eliminardados(int n, int r)
{produts t;
 FILE *file;
 FILE *arq;
 file=fopen("grafs.txt", "r");
 arq=fopen("auxiliar.txt", "a+");
 int i;
 char c[]="\n";
 for (i=1;i<=n;i++){
     fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
     if(i!=r){
         fprintf(arq,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
         fprintf(arq, "%s", c);
         }
     }
 fclose(file);
 fclose(arq);
 limpar_txt("grafs.txt");
 voltagrafstxt(n-1);
 limpar_txt("auxiliar.txt");
}

void voltagrafstxt(int u)
{FILE *file;
 FILE *arq;
 file=fopen("grafs.txt", "a+");
 arq=fopen("auxiliar.txt", "r");
 char li[100];
 int i;
 for (i=0;i<u;i++){
     fgets(li, 100, arq);
     fprintf(file, "%s", li);
     }
 fclose(file);
 fclose(arq);
}

void voltaprodutostxt(int n)
{produts t;
 FILE *aux;
 FILE *file;
 aux = fopen("auxiliar.txt", "r");
 file = fopen("produtos.txt", "a+");
 int i;
 for(i=1; i<=n;i++){
     while (fgets(t.nomeprod, 50, aux)!=NULL)
         fprintf(file, "%s", t.nomeprod);
     }
limpar_txt("auxiliar.txt");
}

int posicaostring(char *nome){
 produts t;
 FILE *file;
 FILE *arq;
 file = fopen("produtos.txt", "r");
 arq = fopen("grafs.txt", "r");
 char aux[]="\0";
 strcat(nome, aux);
 int i,rt,linhas=contarelementos();
 for(i=1;i<=linhas;i++){
     fscanf(file,"%s",t.nomeprod);
     rt=strcmp(nome,t.nomeprod);
     if(rt==0)
        return i;
     }
return 0;}

int numero_produtos(){
    FILE *aux1;
    aux1 = fopen("grafs.txt","r");
    int count=0;
    char c[100];
    while (fgets(c, 100, aux1)!=NULL)
        count=count+1;
    fclose(aux1);
    return count;
}
int ultimocodigo()
{FILE *arq;
 produts t;
 arq = fopen("grafs.txt","r");
 int i,n=numero_produtos();
 int maior=0;
 for(i=0;i<=n;i++){
     fscanf(arq,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
     if(t.codepro>maior)
        maior=t.codepro;
     }
 fclose(arq);
return maior;
}

int quantidade_stock(int linha)
{produts t;
 FILE *arq;
 arq=fopen("grafs.txt", "r");
 int i;
 for (i=0; i<linha; i++)
     fscanf(arq,"%i %i %i %i %i %i %i %i",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
return t.sctokcorr;}

int preco_produto(int c)
{produts t;
    FILE *arq;
    arq=fopen("grafs.txt", "r");
    int i;
    for (i=0; i<c; i++)
        fscanf(arq,"%i %i %i %i %i %i %i %i",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
return t.price;}

void criar_conta(conta p)
{FILE *abrir;
 char c[]="\n";
 abrir=fopen("conta.txt","a+");
 fprintf(abrir,"%d %d %d %d",p.codigo,p.preco_unit,p.quant_vendida,p.preco_tot);
 fprintf(abrir,c);
 fclose(abrir);
}

void apresentar_conta(vendas)
{setlocale(LC_ALL, "Portuguese");
 FILE *abrir;
 conta c2;
 int total=0;
 abrir=fopen("conta.txt","r");
 for(;vendas>0;vendas--){
    fscanf(abrir,"%i %i %i %i",&c2.codigo,&c2.preco_unit,&c2.quant_vendida,&c2.preco_tot);
    printf("Codigo: %d| Preço por unidade: %d|Quantidade vendida: %d| Preço total: %d\n",c2.codigo,c2.preco_unit,c2.quant_vendida,c2.preco_tot);
    total=total+c2.preco_tot;
    }
 printf("Total: %d\n",total);
 fclose(abrir);
}

// inicio das funçoes para reduzir uma quantidade de produtos comprados
void limpar_txt(char *p)
{FILE *fl;
 fl = fopen(p, "w");
 fclose(fl);
}

void volta(int n)
{produts t; int f;
 char c[]="\n";
 FILE *aux;
 FILE *file1;
 aux = fopen("auxiliar.txt", "r");
 file1 = fopen("grafs.txt", "a+");
 for(f=1; f<=n; f++){
        fscanf(aux,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
        fprintf(file1,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
        fprintf(file1, "%s", c);
        }
 limpar_txt("auxiliar.txt");
 fclose(aux);
 fclose(file1);
 }

void reduzir_quant(int cod,int qt)
{int i;
 produts t;
 FILE *file;
 FILE *arq;
 file = fopen("grafs.txt", "r");
 arq = fopen("auxiliar.txt", "a+");
 char c[]="\n";
 int ct=contarelementos();
 for(i=1; i<= ct;i++){
      fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
      if(t.codepro==cod)
          t.sctokcorr=t.sctokcorr-qt;
      fprintf(arq,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
      fprintf(arq, "%s", c);
      }
  fclose(file);
  fclose(arq);
  limpar_txt("grafs.txt");
  volta(ct);
}

void aumentar_quant(int cod,int qt)
{int i;
 produts t;
 FILE *file;
 FILE *arq;
 file = fopen("grafs.txt", "r");
 arq = fopen("auxiliar.txt", "a+");
 char c[]="\n";
 int ct=contarelementos();
 for(i=1; i<= ct;i++){
      fscanf(file,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
      if(t.codepro==cod)
          t.sctokcorr=t.sctokcorr+qt;
      fprintf(arq,"%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax,t.sctokcorr);
      fprintf(arq, "%s", c);
      }
  fclose(file);
  fclose(arq);
  limpar_txt("grafs.txt");
  volta(ct);
}

int procuCodigo()
{setlocale(LC_ALL,"Portuguese");
 int forncode;
 int telef, val=0;
 int count=1;
 char nomeforn[100];
 char morada[100];
 FILE *file;
 FILE *aux;
 file=fopen("fornecedor.txt", "r");
 aux=fopen("fornecedor.txt", "r");
 char nome[50];
 char aux1[]="\0";
 char aux2[200];
 printf("\nDigite o nome do fornecedor: ");
 do{
     count=1;
     scanf("%s", nome);
     strcat(nome, aux1);
     while (fgets(aux2, 200, aux)!=NULL){
          fscanf(file, "%d %s %s %d", &forncode, nomeforn, morada, &telef);
          if(comparar(nome, nomeforn)==0){
              val=1;
              break;
              }
          count=count+1;
          val=0;
          }
     if(val==0)
          printf("\nErro: Fornecedor inexistente.\nTente novamente: ");
     }while(val!=1);
 fclose(file);
 fclose(aux);
return count;}

void recriartxt(char *txtorigem,char *txtdestino)
{FILE *file;
 FILE *aux;
 FILE *percorr;
 char max[100];
 char linha[50];
 percorr=fopen(txtorigem,"r");
 file=fopen(txtorigem, "r");
 aux=fopen(txtdestino, "w");
 while(fgets(max,100,percorr)!=NULL){
   fscanf(file,"%s",linha);
   fprintf(aux,"%s",linha);
   fprintf(aux,"%s","\n");
   }
 fclose(file);
 fclose(aux);
 fclose(percorr);
}

void recriartxt2(char *txtorigem,char *txtdestino)
{produts t;
 FILE *file;
 FILE *aux;
 FILE *percorr;
 char max[100];
 percorr=fopen(txtorigem,"r");
 file=fopen(txtorigem, "r");
 aux=fopen(txtdestino, "w");
 while(fgets(max,100,percorr)!=NULL){
   fscanf(file,"%i %i %i %i %i %i %i %i",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
   fprintf(aux,"%d %d %d %d %d %d %d %d",t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
   fprintf(aux,"%s","\n");
   }
 fclose(file);
 fclose(aux);
 fclose(percorr);
}

int LINHA_DO_PRODUTO(int c)
{produts t;
 FILE *file;
 int linhas=contarelementos();
 int i;
 file=fopen("grafs.txt", "r");
 for(i=1;i<linhas;i++){
   fscanf(file,"%i %i %i %i %i %i %i %i",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
   if (c==t.codepro)
      break;
   }
 fclose(file);
return i;}
