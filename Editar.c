#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Functions.h"

void eliminarprod()
{char prod[30];
 produts t;
 printf("\nEscreve o nome do produto que deseja eliminar: ");
 scanf("%s", prod);
 FILE *aux;
 FILE *file;
 aux = fopen("auxiliar.txt", "a+");
 file = fopen("produtos.txt", "r");
 int nt=numero_produtos("produtos.txt");//atençao duvida aqui
 int ct=posicaostring(prod)-1;
 int i;
 for(i=1; i<=nt;i++){
     fgets(t.nomeprod, 50, file);
     if(i!=ct)
         fprintf(aux,"%s", t.nomeprod);
     }
 fclose(aux);
 fclose(file);
 limpar_txt("produtos.txt");
 voltaprodutostxt(nt);
 limpar_txt("auxiliar.txt");
 eliminardados(nt, ct);
}

int inserir_mais()
{int esc;
    do{
    printf("Desejas adicionar mais algum produto?\n 1- Continuar; \n 2- Voltar ao Menu de Editagem;\n");
    scanf("%d",&esc);
    if (esc==1)
       return 1;
    else if(esc==2)
       return 0;
    else{
        printf("Resposta invalida! Tente novamente.");
        system("CLS");
        }
   }while(esc!=1 || esc!=2);
}

void imprimir()
{setlocale(LC_ALL, "Portuguese");
 produts t;
 FILE *file;
 FILE *arq;
 file = fopen("produtos.txt","r");
 arq = fopen("grafs.txt","r");
 printf("\n==============================================================================================================================================\n");
 while((fgets(t.nomeprod, 30, file)) != NULL){
     fscanf(arq,"%i %i %i %i %i %i %i %i", &t.codepro, &t.codetype, &t.price, &t.aquiprice, &t.forncode, &t.sctokmim, &t.sctokmax, &t.sctokcorr);
     printf("\nNome produto: %s \n|Codigo: %i |Codigo tipo: %i |Preço: %i |Preço aquisicao: %i |Codigo fornecedor: %i |Stock min.: %i |Stock max.: %i |Stock corrente: %i |",t.nomeprod, t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
     printf("\n---------------------------------------------------------------------------------------------------------------------------------------------");
     }
 printf("\n\n");
 fclose(file);
 fclose(arq);
}

void inserir(int cod_forn)
{do{produts t;
    setlocale(LC_ALL, "Poruguese");
    FILE *file;
    FILE *arq;
    arq = fopen("grafs.txt", "a+");
    file = fopen("produtos.txt", "a+");
    char nome[30];
    char c[]="\n";
    printf("\nDigite o nome do produto: ");
    scanf("%s", nome);
    fprintf(file, c);
    fprintf(file, nome);
    t.codepro=ultimocodigo()+1;
    printf("Digite o codigo tipo de produto: ");
    scanf("%d", &t.codetype);
    printf("Digite o preço do produto: ");
    scanf("%d", &t.price);
    printf("Digite o preço de aquisição do produto: ");
    scanf("%d", &t.aquiprice);
    if (cod_forn==0){
       printf("Digite o codigo de fornecedor: ");
       scanf("%d", &t.forncode);
       }
    else{
       t.forncode=cod_forn;
       }
    printf("Digite o stock minimo do produto: ");
    scanf("%d", &t.sctokmim);
    printf("Digite o stock maximo do produto: ");
    scanf("%d", &t.sctokmax);
    printf("Digite o stock corrente do produto: ");
    scanf("%d", &t.sctokcorr);
    fprintf(arq, "\n%d %d %d %d %d %d %d %d", t.codepro, t.codetype, t.price, t.aquiprice, t.forncode, t.sctokmim, t.sctokmax, t.sctokcorr);
    fclose(file);
    fclose(arq);
    }while(sair(0));
}

void editar_produto()
{int op,op2;
 do{
    system("CLS");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||    EDITAR    ||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n 1-> Inserir novo Produto;\n 2-> Remover Produto existente;\n 3-> Listar todos os produtos;\n 4-> Voltar ao Menu;");
    printf("\nO que pretendes fazer?");
    scanf("%d", &op);
    switch (op){
        case 1 :
            do{
               system("CLS");
               inserir(0);
               op2=inserir_mais();
              }while(op2);
            editar_produto();
            break;
        case 2 :
            system("CLS");
            eliminarprod();
            break;
        case 3 :
            system("CLS");
            imprimir();
            break;
        case 4 :
            system("CLS");
            main();
            break;
        default :
            system("CLS");
            printf("Resposta invalida!");
        }
    }while(sair(0));
}
