#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <synchapi.h>
#include <windows.h>
#include <conio.h>
#include <wingdi.h>

void mudar_cor(int cor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

typedef struct inventario{
   int facao; //1 se tiver, 0 se nao
   int pistola;
   int municao;
   int lanterna;
   int ataduras;
}Inventario;

typedef struct Personagem{
    char nome[50];
    int vida;
    int vida_maxima;
    Inventario inv;
}Personagem ;

typedef struct Monstro{
    char nome[50];
    int vida;
    int vida_maxima;
    int ataque;
}Monstro;

void mostrar_status(Personagem p){
    //Impressao do explorador que vai acabar morrendo no meio da historia tenho certeza ;-;
    printf("\n =============================================== \n");
    printf("\n                STATUS DO PERSONAGEM             \n");
    printf("\n =============================================== \n");
    printf("Nome do explorador: %s\n" , p.nome);
    printf("Vida do explorador: %d , Vida maxima: %d \n" , p.vida , p.vida_maxima);

    //Inventario do caba bom

    printf("\n =============================================== \n");
    printf("\n                INVENTARIO                       \n");
    printf("\n =============================================== \n");
    printf("\n Facao (6 Dano):   %s\n" , p.inv.facao ? "Sim" : "Nao");
    printf("\n Pistola (10 dano): %s (Municao: %d)\n" , p);
    
}





void imprimir_palavra(char *s , int cor){
    mudar_cor(cor); //Aplicar cor antes de começar. O fellas do gcc n tem suporte a conio.h
    for(int i = 0 ; i < strlen(s) ; i++){
        cprintf("%c" , s[i]);
        Sleep(200);
    }      
    mudar_cor(7);
}



int main(){
    imprimir_palavra("meu ovo" , 12);
}