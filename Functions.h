#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct n{
    char nomeprod[30];
    int codepro;
    char marca[30];
    int codetype;
    int price;
    int aquiprice;
    int forncode;
    int sctokmim;
    int sctokmax;
    int sctokcorr;
}n;
typedef struct n produts;

typedef struct{
 int  codigo;
 int  preco_unit;
 int  quant_vendida;
 int  preco_tot;
}conta;

typedef struct t{
    int forncode;
    char nomeforn[50];
    char morada[50];
    int telef;
}t;
typedef struct t forn;
typedef struct o{
    char data[11];
    int quant;
}o;
typedef struct o enco;

int sair(int);
void compra();
void imprimir();
void procura(produts);
void editar(produts);
void inventario();
void venda();
void editar_produto();
int ultimocodigo();
int quantidade_stock(int);
int preco_produto(int);
void apresentar_conta();
void criar_conta(conta);
void reduzir_quant(int,int);
void limpar_txt(char*);
int posicaostring(char *);
int inserir_mais();
void eliminarprod();
void voltaprodutostxt(int );
void eliminardados(int,int);
void voltagrafstxt(int);
int procuCodigo();
void aumentar_quant(int,int);
void recriartxt(char *,char *);
void recriartxt2(char *,char *);
int comparar(char *, char *);
void  fornecedor();
int LINHA_DO_PRODUTO(int);
#endif // SUMMER_FONCTION_H_INCLUDED

