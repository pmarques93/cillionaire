# Relatório Projecto Final Cillionaire - Introdução à Computação

![cillionaire](https://temptempo.yolasite.com/resources/C%20-%20relatorio%20Proj%20Final%201%20ano.png)

### Gabriel Santos, 21901441
### Gonçalo Verde, 21901395
### Pedro Marques, 21900253
### Grupo - #DreamTeam

---

## **Descrição da solução**
De modo a criar a solução, inicialmente criámos a estrutura das perguntas juntamente com a estrutura base da função *readFile()*, com a qual o software lê as perguntas. Esta função vai ter como responsabilidade a leitura do ficheiro, tal como a deteção da dificuldade nível das perguntas e respostas. Tem também como responsabilidade a criação de memória dinâmica.

De seguida melhorámos a estrutura das perguntas e criámos um *enum* para termos acesso à dificuldade das perguntas. Criámos também a função *pressKey()* em que criámos um *switch* de modo a que conseguirmos aceder às várias funções. 

Após este passo, editámos o *readFile()* de modo a que a resposta certa fosse apresentada em posições randomizadas cada vez que é corrido. Depois desta edição criámos o *output* para os créditos e para o *score* apresentado no final de cada jogada. 

Com estes passos feitos, dividimos os ficheiros de modo a criar um código mais organizado.

De seguida criámos a função *joker50()* que imprime a resposta certa mais outra resposta randomizada da pergunta analisada.

Posteriormente, criámos/desenvolvemos as funções *printScore()* e *level_check()*. A *printScore()* ficou então responsável por imprimir o nome, *score* e *jokers* depois de cada jogada e a *level_check()* serviu para sabermos em que nível nos encontrávamos depois de cada resposta.

Depois de todos estes passos, apercebemo-nos que a *seed* e o comando para leitura de ficheiros recebidos na *command line* não estavam a funcionar como era suposto. Procedemos então à alteração da estrutura da *main()*, *game()* e *readFile()* de modo a que recebesse as opções como pedido no enunciado.

Por fim, criámos a função *joker25()*, contudo, apesar da funcionalidade da mesma na execução do código, o *Pandora* não aceita a execução das mesma.

---

## **Estrutura do software**
O software é executado com as seguintes *libraries*, ficheiros e funções:

- <stdio.h>;
- <stdlib.h>;
- <time.h>;
- <ctype.h>;
- <string.h>;

*cillionaire.c*

- *main()*;
  - Recebe os argumentos da *command line*; executa as restantes funções de modo a correr o jogo.
- *keyPress()*;
  - Reponsável por executar as funções após ser premida uma das teclas definidas.
- *printCredits()*;
  - Faz *print* dos créditos;
- *printMenu()*;
  - Faz *print* do menu com as várias opções possíveis.

*game.c*

- *game()*;
  - Responsável por correr todo o jogo;
- *joker50()*;
  - Corta 2 opções erradas e deixa apenas a certa e um das outras opções;
 - *joker50()*;
  - Corta 1 opcção errada e deixa apenas a certa e uma das outras opções;
- *level_check()*;
  - Responsável por retornar a dificuldade do jogo consoante o *score* definido;
- *printScore()*;
  - Responsável por fazer *print* do nome, *level*, *joker*50 e *joker*25 restantes;
  
*readFile.c*

- *readFile()*;
  - Responsável pela leitura do ficheiro; Detecta a pergunta, respostas e dificuldades das mesmas;

*classes.h*
- Contém a estrutura para as perguntas

#
## **Conclusões e Matéria Aprendida**
Concluíndo, com este projecto conseguimos adquirir uma melhor percepção do funcionamento das listas ligadas e a utilidade das mesmas. Tivémos algumas dificuldades na passagem dos argumentos recebidos na *command line* de modo a que lesse o ficheiro corretamente, mas, conseguimos superar o problema com alguma pesquisa. Apercebemo-nos, também, que, em projetos de grande dimensão, a separação de ficheiros garante uma maior facilidade no trabalho colaborativo. Foi-nos possível desenvolver a utilização e conhecimento do *git* de modo a trabalhar nos mesmos ficheiros em conjunto. 



## **Referências e trocas de ideias**
Para realização do projecto utilizámos conselhos do professor relativamente à criação e separação dos vários ficheiros *.c* e *.h*. Tivemos também ajuda na criação da função *readFile()*. Contámos com a ajuda dos colegas Daniel Fernandes e Marco Domingos para a resolução de vários problemas encontrados.

Para um dos problema que encontrámos, relativamente à passagem do nome do ficheiro na *command line*, tirámos algumas ideias do seguinte link: https://stackoverflow.com/questions/5046035/how-to-read-string-from-command-line-argument-in-c

