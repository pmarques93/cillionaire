# Relatório Projecto Final Cillionaire - Introdução à Computação

## Gabriel Santos,
## Gonçalo Verde,
## Pedro Marques, 21900253
## Grupo - .....................

#
## **Descrição da solução**
De modo a criar a solução, inicialmente criámos a estrutura das perguntas juntamente com a estrutura base da função readFile, com a qual o software lê as perguntas. Esta função vai ter como responsabilidade a leitura do ficheiro, tal como a deteção da dificuldade nível das perguntas e respostas. Tem também como responsabilidade a criação de memória dinâmica.**

De seguida melhorámos a estrutura das perguntas e criámos um *enum* para termos acesso à dificuldade das perguntas. Modificámos também a função pressKey em que criámos um *switch* e alterámos a mesma para a letra *n* de modo a que funcionasse.

Após este passo, editámos o readFile de modo a que a resposta certa fosse apresentada em posições randomizadas cada vez que é corrido. Depois desta edição criámos o *output* para os créditos e para o *score* apresentado no final de cada jogada. 

Com estes passos feitos, dividimos os ficheiros de modo a criar um código mais organizado.

De seguida criámos a função *joker* que imprime a resposta certa mais outra resposta randomizada da pergunta analisada.

#
## **Estrutura do software**
O software é executado com as seguintes *libraries*, ficheiros e funções:

- <stdio.h>;
- <stdlib.h>;
- <time.h>;
- <ctype.h>;
- <string.h>;

*cillionaire.c*

- main();
- keyPress();
- printCredits();
- printMenu();

*game.c*

- game();
- joker();
  
*readFile.c*

- readFile();

*questions.txt*


#
## **Conclusões e Matéria Aprendida**



## **Referências e trocas de ideias**
Para realização do projecto utilizámos conselhos do professor relativamente à criação e separação dos vários ficheiros *.c* e *.h*. Tivemos também ajuda na criação da função *readFile.c*.
