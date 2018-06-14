/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: juanvmr
 *
 * Created on 13 de Junho de 2018, 23:14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define and &&
#define not !
#define or ||

typedef struct itemtabela{
    char estadoatual;
    char simboloatual;
    char estadoproximo;
    char simboloproximo;
    int direcaofita;
};

void getTabelaArquivo(FILE *arquivo, struct itemtabela *item);
void getFita(FILE *arquivo, char *fita);
void processar(itemtabela *item, char *fita);
bool erroDirecaoFita(itemtabela *item);
void erroFitaNegativa(itemtabela *item);

int main(int argc, char** argv) {
    struct itemtabela itens[128];
    char fita[256];
    FILE *arquivotabela;
    FILE *arquivofita;

    printf("Not used: %d and %c", argc, **argv);

    arquivotabela = fopen("arquivotabela.txt", "r");
    if(arquivotabela == NULL){
        arquivotabela = fopen("arquivotabela.txt", "w");
    }
    else{
        getTabelaArquivo(arquivotabela, itens);
    }

    arquivofita = fopen("arquivofita.txt", "r");
    if(arquivofita == NULL){
        arquivofita = fopen("arquivofita.txt", "w");
    }
    else{
        getFita(arquivofita, fita);
    }

    processar(itens, fita);

    fclose(arquivotabela);
    return (EXIT_SUCCESS);
}

void getTabelaArquivo(FILE *arquivo, struct itemtabela *item){
    char charac;
    int posicao = 0;
    int entrada = 0;

    while(charac != EOF){
        charac = getc(arquivo);
        if(charac == ',' || charac == ' '){
            continue;
        }
        else{
            if(charac == NULL){
                charac = '$';
            }
            if(entrada == 0){
                item[posicao].estadoatual = charac;
            }
            else if(entrada == 1){
                item[posicao].simboloatual = charac;
            }
            else if(entrada = 2){
                item[posicao].estadoproximo = charac;
            }
            else if(entrada = 3){
                item[posicao].simboloproximo = charac;
            }
            else if(entrada = 4){
                charac == '0' ? item[posicao].direcaofita = 0 : item[posicao].direcaofita = 1;
                posicao++;
                entrada = 0;
            }
        }
    }
}

void getFita(FILE *arquivo, char *fita){
    char charac = NULL;
    int posicao = 0;

    while(charac != EOF){
        charac = getc(arquivo);
        if(charac != NULL and charac != EOF){
            fita[posicao] = charac;
            posicao++;
        }
    }
}

void processar(itemtabela *item, char *fita){
    int tabelaPos = 0;
    int fitaPos = 0;
    char estadoAtual = '0';
    bool erro = false;

    while(tabelaPos < (sizeof(item)/sizeof(item[0]))){
        if(fita[fitaPos] == item[tabelaPos].simboloatual and item[tabelaPos].estadoatual == estadoAtual){
            fita[fitaPos] = item[tabelaPos].simboloproximo;
            estadoAtual = item[tabelaPos].estadoproximo;

            if(item[tabelaPos].direcaofita == 0){
                fitaPos++;
            }
            else if(item[tabelaPos].direcaofita == 1){
                fitaPos--;
                if(fitaPos < 0){
                    erroFitaNegativa(item);
                }
            }
            else{
                erro = true;
                while(erro = true){
                    erro = erroDirecaoFita(itemtabela[tabelaPos]);
                }
            }
        }
    }
}

//Caso o valor da direÃ§Ã£o seja desconhecido,
//repete a funÃ§Ã£o atÃ© o valor ser certo.
bool erroDirecaoFita(itemtabela *item){
    printf("Direcao de fita errada. Insira uma nova: ");
    scanf("%d", item.direcaofita);

    if(item->direcaofita == 1 or item->direcaofita == 0){
        return false;
    }
    else{
        return true;
    }
}

//Caso a fita mova para uma posiÃ§Ã£o negativa,
//move-se todas as posiÃ§Ãµes uma casa a frente.
void erroFitaNegativa(itemtabela *item){
    int i;
    for(i=(sizeof(item)/sizeof(item[0])); i>-1; i--){
        if(item[i] != NULL){
            i+=2;
            continue;
        }
        if(i==0){
            item[i] = NULL;
            continue;
        }
        item[i] = item[i-1];
    }
}
