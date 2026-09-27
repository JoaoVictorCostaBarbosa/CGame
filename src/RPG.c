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
};

typedef struct inventario{
   int facao; //1 se tiver, 0 se nao
   int pistola;
   int municao;
   int lanterna;
   int ataduras;
   int ouro;
   int diamante;
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
    mudar_cor(15);
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
    printf("\n Pistola (10 dano): %s (Municao: %d)\n" , p.inv.pistola ? "Sim" : "Nao" , p.inv.municao);
    printf("\n Lanterna:  %s\n" , p.inv.lanterna ? "Sim" : "Nao");
    printf("\n Atadura: (Cura/Sangramento) %d\n" , p.inv.ataduras);
    mudar_cor(7);
    
};





void imprimir_palavra(char *s , int cor){
    mudar_cor(cor); //Aplicar cor antes de começar. O fellas do gcc n tem suporte a conio.h
    for(int i = 0 ; i < strlen(s) ; i++){
        cprintf("%c" , s[i]);
        Sleep(200);
    };      
    mudar_cor(7);
};

void escolher_itens(Personagem *p) {
    int escolha1, escolha2;

    mudar_cor(14); // Amarelo
    printf("\n[PROLOGUE] Voce esta preparando sua mochila para desembarcar na ilha.\n");
    printf("Escolha 2 itens iniciais:\n");
    printf("1 - Facao (Corte rapido e silencioso - 6 de dano)\n");
    printf("2 - Pistola com 6 municoes (Alto poder de fogo - 10 de dano por tiro)\n");
    printf("3 - Lanterna (Essencial para lugares escuros)\n");
    printf("4 - 2 Ataduras (Recuperam vida e param sangramentos)\n");
    mudar_cor(7);

int main(){
    scanf()
    imprimir_palavra("meu ovo" , 12);
    //historia 2
    imprimir_palavra("vc entra dentro desta estrutura e decide analisar o interior dela, em busca de algo para pagar sua divida claro... ", 15);
    if (p.inv.lanterna == 1){
        imprimir_palavra("Graças a sua lanterna, voce encontra 3 barras de ouro!" , 12);
        p.inv.ouro += 3;
    }else{
        imprimir_palavra("Voce encontra 2 barras de ouro!" , 12);
        p.inv.ouro +=2;
    };
    

};
    printf("\nDigite o numero do 1o item: ");
    scanf("%d", &escolha1);
    printf("Digite o numero do 2o item: ");
    scanf("%d", &escolha2);

    // Zerando o inventário primeiro
    p->inv.facao = 0;
    p->inv.pistola = 0;
    p->inv.municao = 0;
    p->inv.lanterna = 0;
    p->inv.ataduras = 0;

    // Processa a escolha 1
    if (escolha1 == 1) p->inv.facao = 1;
    else if (escolha1 == 2) { p->inv.pistola = 1; p->inv.municao = 6; }
    else if (escolha1 == 3) p->inv.lanterna = 1;
    else if (escolha1 == 4) p->inv.ataduras = 2;

    // Processa a escolha 2
    if (escolha2 == 1) p->inv.facao = 1;
    else if (escolha2 == 2) { p->inv.pistola = 1; p->inv.municao = 6; }
    else if (escolha2 == 3) p->inv.lanterna = 1;
    else if (escolha2 == 4) p->inv.ataduras += 2; // Se escolheu atadura de novo, acumula
}

int main() {
    Personagem jogador;
    
    jogador.vida_maxima = 100;
    jogador.vida = 100;

    mudar_cor(10);
    imprimir_palavra("=== BEM - VINDO A ILHA PERDIDA ===\n" , 4);
    mudar_cor(7);
    
    printf("Digite o nome do seu explorador: ");
    scanf(" %[^\n]", jogador.nome); // Isso aqui é caso o caba queira dar dois nomes , ai le os espaços
    imprimir_palavra("você é %s, um(a) explorador(a) que estava desesperadamente precisando de dinheiro para pagar uma dívida. Você ouve boatos de que uma ilha não tão distante do litoral guarda tesouros que podem quitar esta dívida, então você decide para lá em busca destes tesouros. Com isso, você vai em uma loja clandestina para comprar um pequeno barco e como o dinheiro só permite que você compre mais 2 itens para levar você terá de escolher entre: " , jogador.nome);
    // Chama a função de escolha de itens
    escolher_itens(&jogador);
    printf("Carregando...");
    Sleep(1000);
    // Mostra como ficou o personagem
    mostrar_status(jogador);

    mudar_cor(12);
    imprimir_palavra("Sua aventura comeca agora...\n" , 4);
    mudar_cor(7);

    return 0;
}
