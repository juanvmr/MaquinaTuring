/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: comp1
 *
 * Created on 6 de Junho de 2018, 20:06
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct itemtabela{
    char estadoatual;
    char simboloatual;
    char estadoproximo;
    char simboloproximo;
    int direcaofita;
};

int main(int argc, char** argv) {
    itemtabela itens[128];
    char fita[256];
    FILE *arquivotabela;
    FILE *arquivofita;
    
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
    
    fclose(arquivotabela);
    return (EXIT_SUCCESS);
}

void getTabelaArquivo(FILE *arquivo, itemtabela *item){
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
    char charac;
    int posicao;
    
    while(charac != EOF){
        charac = getc(arquivo);
        if(charac != NULL){
            fita[posicao] = charac;
        }
    }
}

void processar(itemtabela *item, char *fita){
    int tabelaPos = 0;
    int fitaPos = 0;
    char estadoAtual = '0';
    
    while(tabelaPos < (sizeof(item)/sizeof(item[0]))){
        
    }
}
