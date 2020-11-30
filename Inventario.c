#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Functions.h"

void mostrar_produto()
{FILE *file;
 file = fopen("produtos.txt", "a+");
 char nome[30];
 char c[]="\n";
 printf("\nDigite o nome do produto: ");
 scanf("%s", nome);
 fprintf(file, c);
 fprintf(file, nome);
}

int comparar(char *v, char *c)
{if(strcmp(v, c) == 0)
    return 0;
 else if(strcmp(v,c) > 0)
    return 1;
 else
    return -1;
}

void pornome(char *nome, int d)
{ setlocale(LC_ALL, "Portuguese");
  FILE *dado;
  int i;
  produts t;
  dado = fopen("grafs.txt","r");
  for(i=0; i<d; i++)
      fscanf(dado,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
  printf("%s",nome);
  printf("  stock atual %i | preço venda %i | preço aquisição %i | diferença preço %i \n", t.sctokcorr, t.price, t.aquiprice, t.price-t.aquiprice);
  fclose(dado);
}
// ESTA FUNCAO é RESPONSAVEL POR CNTAR ELEMENTOS DA LISTA
int contarelementos(){
    FILE *aux1;
    aux1 = fopen("grafs.txt","r");
    int count=0;
    char c[100];
    while (fgets(c, 100, aux1)!=NULL)
        count=count+1;
    fclose(aux1);
    return count;
}
//PROCURA O ELEMENTO POR CODICO NO TXT E DEPOIS MOSTRA NO ECRA OS SEUS DADOS
void por_codigo()
{setlocale(LC_ALL, "Portuguese");
 int i,cod,linhas;
 produts t;
 produts N;
 FILE *file;
 FILE *arq;
 file = fopen("produtos.txt","r");
 arq = fopen("grafs.txt","r");
 printf("\nDigite o codigo do produto sabendo que os codigos variam de 1 á %d : ", ultimocodigo());
 scanf("%d", &cod);
 linhas=contarelementos();
 if(cod<=ultimocodigo()){
      for(i=0; i<linhas; i++){
           fscanf(file,"%s",&t.nomeprod);
           fscanf(arq,"%i %i %i %i %i %i %i %i",&t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
           if(cod==t.codepro){
              int dif=t.price-t.aquiprice;
              printf("Nome: %s| stock atual: %i|  preço venda: %i|  preço aquisição: %i|\tdiferença preço:%i\n",t.nomeprod,t.sctokcorr, t.price, t.aquiprice, dif);
              break;
              }
           }
      }
 else
      printf("\nO produto não existe.\n\n");
}
// PROCURA A POSICAO DO ELEMENTO PELO SEU NOME
void por_nome()
{int rt,ct=0;
 char nome[20];
 printf("\nDigite o nome do produto: ");
 scanf("%s", &nome);
 ct=posicaostring(nome);
 printf("\n");
 if (ct!=0)
     pornome(nome, ct);
 else
    printf("Erro: Produto Inexistente!!!");
}
// FUNCAO RESPONSAVEL POR EXECUTAR AS FUNCOES DO INVENTARIO
void inventario()
{setlocale(LC_ALL, "Portuguese");
 int opc=0;
 do{printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||   INVENTARIO    |||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\nOpções do Inventairo:\n  Pesquisa de Produto:\n      1-> Por Nome;\n      2-> Por Codigo ;\n  3-> Voltar ao Menu;\n");
    printf("\nEscolha opção: ");
    scanf("%d", &opc);
    switch (opc){
        case 1 :
           system("CLS");
           por_nome();
           break;
        case 2 :
           system("CLS");
           por_codigo();
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
