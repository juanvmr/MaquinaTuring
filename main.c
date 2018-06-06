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
    FILE *arquivotabela;
    arquivotabela = fopen("arquivotabela.txt", "r");
    if(arquivotabela == NULL){
        arquivotabela = fopen("arquivotabela.txt", "w");
    }
    
    
    fclose(arquivotabela);
    return (EXIT_SUCCESS);
}

itemtabela getTabelaArquivo(FILE *arquivo){
    
}
