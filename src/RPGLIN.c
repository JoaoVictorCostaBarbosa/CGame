#include <stdio.h>
#include<string.h>
#include <unistd.h>
// objeto de escolha
int escolha = 0;
//contador esquerda
int esquerda = 0;
//itens do inventario
int lanterna = 0;
int colar_forca = 0;
int chave_simples = 0;
int facao = 0;
int colar_hp = 0;
int ataduras = 0;
int municao = 0;
int pistola = 0;

int sangramento = 0; // status de sangramento toma 5 de dano por escolha em combate
int combate = 0; // Contador de combates
int vitoria = 1; // Vitoria = 1 Derrota = 0, usar como verificador após combate

void imprimir(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(3000);
    }
}

int main() {
    // seleção de itens iniciais
    imprimir("Você é { nome }, um(a) explorador(a) que estava desesperadamente precisando de dinheiro para pagar uma dívida. Você ouve boatos de que uma ilha não tão distante do litoral guarda tesouros que podem quitar esta dívida, então você decide para lá em busca destes tesouros. Com isso, você vai em uma loja clandestina para comprar um pequeno barco e como o dinheiro só permite que você compre mais 2 itens para levar você terá de escolher entre: \n");

    imprimir("1- Facão --> 6 de dano\n");
    imprimir("2 - Pistola com 6 munições --> 10 de dano por munição\n");
    imprimir("3 - Lanterna --> ilumina lugares escuros\n");
    imprimir("4 - 2 Ataduras --> curam x de vida e param sangramento\n");
    
    scanf("%d", &escolha);
    
    if (escolha == 1){
        imprimir("1 - Pistola com 6 munições --> 10 de dano por munição\n");
        imprimir("2 - Lanterna --> ilumina lugares escuros\n");
        imprimir("3 - 2 Ataduras --> curam x de vida e param sangramento\n");
        facao = 1;
        scanf("%d", &escolha);
        if (escolha == 1){
            pistola = 1;
            municao = 6;
        }
        if (escolha == 2){
            lanterna = 1;
        }
        if (escolha == 3){
            ataduras = 2;
        }
    }else if (escolha == 2){
        imprimir("1- Facão --> 6 de dano\n");
        imprimir("2 - Lanterna --> ilumina lugares escuros\n");
        imprimir("3 - 2 Ataduras --> curam x de vida e param sangramento\n");
        pistola = 1;
        municao = 6;
        scanf("%d", &escolha);
        if (escolha == 1){
            facao = 1;
        }
        if (escolha == 2){
            lanterna = 1;
        }
        if (escolha == 3){
            ataduras = 2;
        }
    }else if (escolha == 3){
        imprimir("1- Facão --> 6 de dano\n");
        imprimir("2 - Pistola com 6 munições --> 10 de dano por munição\n");
        imprimir("3 - 2 Ataduras --> curam x de vida e param sangramento\n");
        lanterna = 1;
        scanf("%d", &escolha);
        if (escolha == 2){
            pistola = 1;
            municao = 6;
        }
        if (escolha == 1){
            facao = 1;
        }
        if (escolha == 3){
            ataduras = 2;
        }
    }else if (escolha == 4){
        imprimir("1- Facão --> 6 de dano\n");
        imprimir("2 - Pistola com 6 munições --> 10 de dano por munição\n");
        imprimir("3 - Lanterna --> ilumina lugares escuros\n");
        ataduras = 2;
        scanf("%d", &escolha);
        if (escolha == 2){
            pistola = 1;
            municao = 6;
        }
        if (escolha == 3){
            lanterna = 1;
        }
        if (escolha == 1){
            facao = 1;
        }
    }
    imprimir("\nInventário: \n");
    if (facao == 1){
        imprimir("Facão --> 6 de dano\n");
    }
    if (lanterna == 1){
        imprimir("Lanterna --> ilumina lugares escuros\n");
    }
    if (pistola == 1){
        imprimir("Pistola com 6 munições --> 10 de dano por munição\n");
    }
    if (ataduras == 2){
        imprimir("2 Ataduras --> curam x de vida e param sangramento\n");
    }
    
    imprimir("\nUtilizando aquele pequeno barco barato que você havia comprado, você consegue chegar na ilha você caminha até que vc encontra uma bifurcação na estrada ambos os caminhos parecem que vão te levar ao mesmo lugar, qual caminho você ira escolher?\n");
    imprimir("1 - Direita\n");
    imprimir("2 - Esquerda\n");
    scanf("%d", &escolha);
// PROCESSO DE ENTRAR PELO LADO ESQUERDO
    if (escolha == 2){
        imprimir("Após seguir pelo caminho do lado esquerdo por um tempo, você percebe que você havia retornado para a mesma bifurcação que você já havia passado\n");
    imprimir("1 - Ir para a Direita\n");
    imprimir("2 - Continuar indo para a Esquerda\n");
        scanf("%d", &escolha);
        esquerda += 1;
    }
    if (escolha == 2){
        imprimir("Após seguir pelo caminho do lado esquerdo por mais tempo ainda, você percebe que você havia retornado novamente para a mesma bifurcação que você já havia passado\n");
    imprimir("1 - Ir para a Direita\n");
    imprimir("2 - Continuar indo para a Esquerda\n");
        scanf("%d", &escolha);
        esquerda += 1;
    }
    // LADO ESQUERDO
    if (esquerda == 2){
        imprimir("Após mais algumas horas caminhando pelo caminho esquerdo, você finalmente encontra um buraco na parte de tras de uma estrutura, o interior do local esta muito escuro e você pode escutar pessoas falando uma língua estranha la dentro.\n");
    imprimir("1 - Se aproximar para tentar enxergar melhor\n");
    imprimir("2 - Esperar o barulho parar\n");
    if (lanterna == 1){
            imprimir("3 - iluminar o local com sua lanterna\n");
        }
    scanf("%d", &escolha);
    if (escolha == 1){ // se aproximar pra enxergar melhor
        imprimir("Você estava tentando se aproximar mas sem querer acaba tropeçando na raiz de uma arvore, fazendo um pouco de barulho, para o seu azar uma figura humanoide encapuzada escutou o som veio na sua direção e te encontrou...\n");
        imprimir("1 - Atacar.\n");
        imprimir("2 - Tentar conversar com a figura.\n");
        scanf("%d", &escolha);
        if (escolha == 1){
            //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
            if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====");
                            imprimir("A figura encapuzada ganha de você e te usa como saacrificio para o Deus maligno que ela cultua");
                    }
                    if (vitoria == 1){
                        combate = 1;
                    }
                } // if da escolha 1 "Atacar"
        if (escolha == 2){
            imprimir("A figura te esfaqueia, agora você esta sangrando.");
            sangramento = 1;
            //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
            if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====\n");
                            imprimir("A figura encapuzada ganha de você e te usa como saacrificio para o Deus maligno que ela cultua\n");
                            escolha = 0;
                    }
                    if (vitoria == 1){
                        imprimir("Analisando o corpo da figura para ver oq ela tinha, a figura não tinha nada de valioso mas uma chave chama sua atenção, ela provavelmente deve abrir algo importante.\n");
                        combate = 1;
                    }
                } // if da escolha 2 "Conversar"
    } 
    if (escolha == 3){ // usar a lanterna
        imprimir("você ilumina o interior da estrutura com a sua lanterna, para o seu azar o barulho de pessoas falando era de fato pessoas falando... oque você esperava? de qualquer forma, agora uma figura encapuzada esta vindo na sua direção com uma faca na mão.");
        //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
        if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====");
                            imprimir("A figura encapuzada ganha de você e te usa como saacrificio para o Deus maligno que ela cultua");
                    }
                    if (vitoria == 1){
                        imprimir("Analisando o corpo da figura para ver oque ela tinha, a figura não tinha nada de valioso mas uma chave chama sua atenção, ela provavelmente deve abrir algo importante.\n");
                        combate = 1;
                    }
    }
    if (escolha == 2){ // Esperar o barulho parar
        imprimir("Você é uma pessoa esperta e sabe que seja la quem esta la dentro provavelmente não te recebera de braços abertos, assim tomando a sábia escolha de esperar o barulho parar.\n");
        imprimir("Mais ou menos 20 minutos se passaram e as vozes finalmente pararam de falar e você entra dentro da estrutura.\n");
        combate = 0;
    }
    imprimir("\nVocê entra dentro desta estrutura e decide analisar o interior dela, em busca de algo para pagar sua divida claro... encontrando assim 2 barras de ouro, observando outros detalhes do local é possivel ver que as paredes estão infestadas de vinhas e o chão tem um pouco de musgo e oque aparenta ser pegadas indo para a direção de uma sala um pouco mais iluminada, entretanto você também encontra 2 outros possíveis caminhos, ambos são portas, 1 porta com diversos ornamentos trancadas com uma fechadura verde e a outra que esta levemente aberta.\n");
    imprimir("1 - Seguir as pegadas.\n");
    imprimir("2 - Entrar na porta levemente aberta\n");
    scanf("%d", &escolha);
    if (escolha == 1){ // pegadas
        if (combate == 0){
            imprimir("você é cauteloso e segue as pegada silenciosamente, ao entrar dentro da sala iluminada é possível visualizar uma figura de costas fazendo alguma coisa em  cima de algo que parecia ser um altar.\n");
            imprimir("1 - atacar a figura por tras.\n");
            scanf("%d", &escolha);
            if (escolha == 1){
                imprimir("Você rapidamente neutraliza o ser encapuzado evitando um combate\n");
                combate = 1;
            }
        }
        if (combate == 1){
           imprimir("As pegadas que estavam no chão provavelmente é da figura que vc havia eliminado recentemente, analisando a sala iluminada, é possível visualizar algumas escrituras na parede, analisando-as melhor vc consegue uma frase 'Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn', e em baixo desta frase estava um altar com oq parecia ser um anel levemente ensanguentado.");
            imprimir("pegando o anel você o observa melhor e  ve que ele tem um pequeno diamante nele, com isso você decide guarda-lo na sua bolsa e seguir pelo caminho da porta levemente aberta");
            escolha = 2;
        } // após o combate
        } // pegadas
    if (escolha == 2){ // Porta levemente aberta
        imprimir("\nA porta levemente aberta levava para uma grande sala, o local não estava muito escuro uma vez que a luz da lua podia ilumina-lo, com isso era possível de ver algo similar com o interior de uma igreja com diversos assentos e um altar, entretanto, haviam cabeças humanoides com uma barba em formato de tentáculos esculpidas nos pilares do lugar.\n");
            imprimir("1 - procurar algo no altar\n");
            imprimir("2 - procurar nos cantos da sala\n");
            scanf("%d", &escolha);
        if (escolha == 2){
            imprimir("Procurando algo de valor que você possa não ter percebido nos cantos da sala, você encontra uma passagem bloqueada por diversas raizes.\n");
            if (facao == 1){
                imprimir("\nFelizmente você possue um facão e pode cortar estas raizes.\n");
                imprimir("Passando pelas raizes cortadas existia uma salinha com algumas pedras preciosas dentro, após guardar estas pedras na sua bolsa você decide voltar e procurar algo no altar.\n");
                escolha = 1;
            }
            if (facao == 0){
                imprimir("Infelizmente você não possue uma ferramenta que possa cortar silenciosamente estas raizes, com isso o melhor é voltar e procurar alguma coisa no altar.");
                escolha = 1;
            }
        }
        if (escolha == 1){
            imprimir("\nProcurando algo de valor no altar você encontra um cetro com a ponta em um formato que simboliza a criatura esculpida nos pilares deste lugar, você decide pega-lo, dado que ele parecia ser feito de alguma pedra valiosa, além disso você também encontra uma caixa trancada com um cadeado e uma chave verde em cima.\n");
            imprimir("1 - Sair da sala as coisas que você encontrou e testar a chave na porta com diversos ornamentos.\n");
            if (facao == 1 && chave_simples == 1){
                imprimir("2 - Tentar abrir a caixa usando o facão.\n");
                imprimir("3 - Utilizar a Chave Simples.\n");
            }
            if (chave_simples == 1 && facao == 0){
                imprimir("2 - Utilizar a Chave Simples.\n");
            }
            if (chave_simples == 0 && facao == 1){
                imprimir("2 - Tentar abrir a caixa usando o facão.\n");
            }
            scanf("%d", &escolha);
            if (escolha == 2 || escolha == 3){
                imprimir("Dentro da caixa havia um colar com um pingente de uma pedra que parece esmeralda, isto deve valer um bom dinheiro, mas que por algum motivo também faz você se sentir protegido\n");
                colar_hp = 1;
            escolha = 1;
            }
            if (escolha == 1){ // sair do altar e voltar para a porta
                if (combate == 0){ // verifica se o jogador teve um combate antes
                    imprimir("Saindo do local você é descuidado e acaba sendo emboscado por uma figura encapuzada e inicia um COMBATE\n");
                        //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
                        // os ifs verificam se o jogador venceu ou não o combate
                        if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====\n");
                            imprimir("A figura encapuzada ganha de você e te usa como sacrificio para o Deus maligno que ela cultua\n");
                            escolha = 0;
                    }
                    if (vitoria == 1){
                        imprimir("Analisando o corpo da figura para ver oq ela tinha, a figura não tinha nada de valioso mas uma chave chama sua atenção, ela provavelmente deve abrir algo importante\n");
                        combate = 1;
                    }
                }
    }
            if (combate == 1){
                    imprimir("\nSaindo do salão e indo para a porta ornamental que estava trancada, você decide utilizar a chave verde que você encontrou no altar, assim abrindo a porta e entrando em uma sala que tinha um pequeno altar com diversas velas e um diamante grande o suficiente para pagar sua dívida, entretanto, você escuta um barulho de algo se mexendo nas paredes desta sala, para sua surpresa não era nada que você tenha visto antes, mas sim um tentáculo maior do que um homem... por mais assustador que seja para poder quitar sua dívida aquele diamante gigante certamente será necessário...\n");
                    imprimir("1 - Entrar na sala\n");
                    imprimir("2 - Fugir deste templo macabro\n");
                    scanf("%d", &escolha);
                    if (escolha == 1){
                        imprimir("Você junta toda sua coragem e entra dentro da sala determinado a enfrentar este monstro para conseguir cumprir seu objetivo principal de conseguir ser livre de sua dívida.\n");
                        //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
                        // os ifs verificam se o jogador venceu ou não o combate
                    if (vitoria == 0){
                        imprimir("=====FINAL RUIM=====\n");
                        imprimir("O tentáculo pega seu cadáver joga para fora da sala e fecha a porta, esperando a sua próxima vítima.\n");
                        escolha = 0;
                    }
                    if (vitoria == 1){
                        imprimir("=====FINAL BOM=====\n");
                        imprimir("Após a luta, você sai correndo para fora daquele templo sabendo que oque você já havia encontrado era muito mais  do que o suficiente para pagar sua dívida! assim, voltando para o seu barquinho e fugindo daquela ilha.\n");
                        imprimir("Você consegue pagar toda sua dívida e viver uma vida de luxo pelos próximos anos sem se preocupar em trabalhar de novo!");
                        escolha = 0;
                    }
                    }
                    if (escolha == 2){
                        imprimir("=====FINAL NEUTRO=====\n");
                        imprimir("você sai correndo para fora daquele templo esperando que oque você já havia encontrado era milagrosamente o suficiente para pagar sua dívida... você volta para o seu barquinho e foge daquela ilha.\n");
                        imprimir("Com isso, você consegue pagar parte de sua dívida mas ainda tera de trabalhar o resto de sua vida para se tornar livre dela... felizmente pagar parte do valor fez o seu cobrador não tomar uma medida mais radical contra você...\n");
                        escolha = 0;
                    }
                    }
                }
        
    
    } 
    }// chaves lado ESQUERDO
// LADO DIREITO
    if (escolha == 1){
        imprimir("Seguindo pela Direita você encontra oque parece ser um templo antigo e que aparenta ter sido abandonado há muito tempo...\n");
        imprimir("1 - Analisar a entrada do templo.\n");
        imprimir("2 - Entrar no templo.\n");
        scanf("%d", &escolha);
        
            if (escolha == 1){
                if (lanterna == 1){
                    imprimir("Ao analisar o templo utilizando sua lanterna você lê uma frase escrita na parede 'Templo do nosso senhor Cthulhu', alguns tentaculos esculpidos na parede, e 2 barras de ouro e ele só tem a opção de Entrar no templo após isso, caso ele tenha uma lanterna ele encontra algumas moedas na entrada e um colar com um pingente de uma pedra que parece rubi, isto deve valer um bom dinheiro, mas que por algum motivo também te trás a sensação de força?\n");
                    colar_forca = 1;
                    escolha = 2;
                }else{
                imprimir("Ao analisar o templo você lê uma frase escrita na parede 'Templo do nosso senhor Cthulhu', alguns tentaculos esculpidos na parede, e 2 barras de ouro.\n");
                    escolha = 2;
                }
            }
        // Entrando no Templo
        if(escolha == 2){
                imprimir("\nEntrando no templo vc se depara com diversos corredores escuros que se bifurcam em diversos caminhos que levam a incontáveis salas, após andar por um tempo algo chama sua atenção, dentro de uma das câmaras vc percebe algo brilhando, possivelmente mais barras de ouro.\n");
    imprimir("1 - ir diretamente na direção do brilho.\n");
    imprimir("2 - não arriscar e continuar explorando o templo.\n");
    if (lanterna == 1){
        imprimir("3 - Utilizar sua lanterna para ver se existem armadilhas por perto.\n");   
    }
        scanf("%d", &escolha);
        if (escolha == 1){
            imprimir("Cegado pela possibilidade de encontrar mais tesouros para conseguir pagar sua dívida você vai na direção do brilho, entrando na câmara você bate em um conjunto de ossos q estava pendurado na entrada do lugar, você não sabe se são de fato ossos humanos, mas o mais preocupante é que o barulho que você fez colidindo com eles parece ter chamado a atenção de algo ou alguém para a sua direção, você se agiliza para pegar oque de fato era uma barra de ouro no centro da câmara mas na hora de sair, uma figura encapuzada bloqueia seu caminho.\n");
                //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
            if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====\n");
                            imprimir("A figura encapuzada ganha de você e te usa como saacrificio para o Deus maligno que ela cultua\n");
                    }
            if (vitoria == 1){
                imprimir("Analisando o corpo da figura para ver oque ela tinha, a figura não tinha nada de valioso mas uma chave chama sua atenção, ela provavelmente deve abrir algo importante.\n");
                combate = 1;
                chave_simples = 1;
                    }
            escolha = 0;
        }
        if (escolha == 2){
            imprimir("Seja lá oque era aquele brilho este lugar provavelmente esta cheio de armadilhas e você deu sorte de ainda não ter encontrado nenhuma...\n");
            escolha = 0;
        }           
        if (escolha == 3){
            imprimir("você utiliza sua lanterna para iluminar o caminho e você vê um conjunto de ossos que estava pendurado na entrada do lugar, você não sabe se são de fato ossos humanos oque te da um arrepio na espinha, após se abaixar para evitar encostar nestes ossos você entra na câmara pega oque de fato era uma barra de ouro e sai.\n");
            escolha = 0;
            }
        if (escolha == 0){
            imprimir("\nSeguindo estes corredores você encontra uma porta extremamente detalhada com ornamentos similares aos que você viu na entrada do templo, após tentar abri-la você percebe que ela esta trancada e analisando a fechadura você sabe que uma chave qualquer não abriria esta porta, é possivel voltar aqui depois.\n");
            imprimir("\nSeguindo em frente você finalmente chega em algo que não é um corredor ou outra câmara mas sim uma grande sala, o local não estava muito escuro uma vez que a luz da lua podia ilumina-lo, com isso era possível de ver algo similar com o interior de uma igreja com diversos assentos e um altar, entretanto, haviam cabeças humanoides com uma barba em formato de tentáculos esculpidas nos pilares do lugar.\n");
            imprimir("1 - procurar algo no altar\n");
            imprimir("2 - procurar nos cantos da sala\n");
            scanf("%d", &escolha);
        if (escolha == 2){
            imprimir("Procurando algo de valor que você possa não ter percebido nos cantos da sala, você encontra uma passagem bloqueada por diversas raizes.\n");
            if (facao == 1){
                imprimir("\nFelizmente você possue um facão e pode cortar estas raizes.\n");
                imprimir("Passando pelas raizes cortadas existia uma salinha com algumas pedras preciosas dentro, após guardar estas pedras na sua bolsa você decide voltar e procurar algo no altar.\n");
                escolha = 1;
            }
            if (facao == 0){
                imprimir("Infelizmente você não possue uma ferramenta que possa cortar silenciosamente estas raizes, com isso o melhor é voltar e procurar alguma coisa no altar.");
                escolha = 1;
            }
        }
        if (escolha == 1){
            imprimir("\nProcurando algo de valor no altar você encontra um cetro com a ponta em um formato que simboliza a criatura esculpida nos pilares deste lugar, você decide pega-lo, dado que ele parecia ser feito de alguma pedra valiosa, além disso você também encontra uma caixa trancada com um cadeado e uma chave verde em cima.\n");
            imprimir("1 - Sair da sala as coisas que você encontrou e testar a chave na porta com diversos ornamentos.\n");
            if (facao == 1 && chave_simples == 1){
                imprimir("2 - Tentar abrir a caixa usando o facão.\n");
                imprimir("3 - Utilizar a Chave Simples.\n");
            }
            if (chave_simples == 1 && facao == 0){
                imprimir("2 - Utilizar a Chave Simples.\n");
            }
            if (chave_simples == 0 && facao == 1){
                imprimir("2 - Tentar abrir a caixa usando o facão.\n");
            }
            scanf("%d", &escolha);
            if (escolha == 2 || escolha == 3){
                imprimir("Dentro da caixa havia um colar com um pingente de uma pedra que parece esmeralda, isto deve valer um bom dinheiro, mas que por algum motivo também faz você se sentir protegido\n");
                colar_hp = 1;
            escolha = 1;
            }
            if (escolha == 1){ // sair do altar e voltar para a porta
                if (combate == 0){ // verifica se o jogador teve um combate antes
                    imprimir("Saindo do local você é descuidado e acaba sendo emboscado por uma figura encapuzada e inicia um COMBATE\n");
                        //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
                        // os ifs verificam se o jogador venceu ou não o combate
                        if (vitoria == 0){
                            imprimir("=====FINAL RUIM=====\n");
                            imprimir("A figura encapuzada ganha de você e te usa como saacrificio para o Deus maligno que ela cultua\n");
                    }
                    if (vitoria == 1){
                        imprimir("Analisando o corpo da figura para ver oq ela tinha, a figura não tinha nada de valioso mas uma chave chama sua atenção, ela provavelmente deve abrir algo importante\n");
                        combate = 1;
                    }
                }
                if (combate == 1){
                    imprimir("\nSaindo deste salão você volta para aquela porta ornamental e decide tentar abri-la com sua nova chave, para sua surpresa ela realmente abre e você entra em uma sala que tinha um pequeno altar com diversas velas e um diamante grande o suficiente para pagar sua dívida, entretanto, também havia uma figura encapuzada ajoelhada na frente do altar\n");
                    imprimir("1 - Ataca----!??... opção do jogador interrompida-\n");
                    imprimir("Por algum motivo aquela figura começa a rir... segundos depois o pescoço da figura vira para que o olhar dela encontre o seu, você {nome} esta paralisado de medo e esta monstruosidade te ataca.\n");
                    sangramento = 1;
                    //func_combate fazer essa bomba retornar uma vitoria = 1 ou 0
                    // os ifs verificam se o jogador venceu ou não o combate
                    if (vitoria == 0){
                        imprimir("=====FINAL RUIM=====\n");
                        imprimir("você é comido ainda vivo por esta criatura e tem uma morte horrível e grotesca.\n");
                        imprimir("Eu sei que você vai voltar");
                    }
                    if (vitoria == 1){
                        imprimir("=====FINAL BOM=====\n");
                        imprimir("Após a luta, você sai correndo para fora daquele templo sabendo que oque você já havia encontrado era muito mais  do que o suficiente para pagar sua dívida! assim, voltando para o seu barquinho e fugindo daquela ilha.\n");
                        imprimir("Você consegue pagar toda sua dívida e viver uma vida de luxo pelos próximos anos sem se preocupar em trabalhar de novo!");
                    }
                }
            }
        }
        }
        }
    }
    return 0;
}