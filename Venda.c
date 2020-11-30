#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Functions.h"
int verific_codigo(int codigo)
{ if ( ultimocodigo()>= codigo)
     return 0;
  else{
     printf("Nao existe um produto com o codigo %d.Tente novamente!\n",codigo);
     return 1;
     }
}

int verific_stock(int quant,int cod)
{int linha=LINHA_DO_PRODUTO(cod);
 int quant1=quantidade_stock(linha);
 if (quant1 >= quant)
    return 0;
 else{
    printf("Lamentamos informar que tem apenas %d unidades do produto desejado, no stock. Tente Novmente!\n",quant1);
    return 1;
     }
}

int vender_mais()
{int esc;
    do{
    printf("Desejas vender mais algum produto?\n 1- Continuar; \n 2- Ver Conta;\n");
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

void vender_um_produto()
{conta produto;
 do{
    printf("Digite o codigo do produto que deseja vender: ");
    scanf("%d",&produto.codigo);
    }while(verific_codigo(produto.codigo));
 do{
    printf("Digite a quantidade do produto que deseja vender: ");
    scanf("%d",&produto.quant_vendida);
    }while(verific_stock(produto.quant_vendida,produto.codigo));
 produto.preco_unit=preco_produto(produto.codigo);
 produto.preco_tot=produto.quant_vendida*produto.preco_unit;
 printf("Produto vendido com sucesso!");
 criar_conta(produto);
 reduzir_quant(produto.codigo,produto.quant_vendida);
}

void venda()
{
 do{int opc,numero_vendas=0;
    system("CLS");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||      VENDA     ||||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n 1-> Vender;\n 2-> Voltar ao Menu;\nO que pretendes fazer?");
    scanf("%d",&opc);
    switch(opc){
        case 1 :
                do{
                    vender_um_produto();
                    numero_vendas=numero_vendas+1;
                    }while(vender_mais());
                system("CLS");
                apresentar_conta(numero_vendas);
                limpar_txt("conta.txt");
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
