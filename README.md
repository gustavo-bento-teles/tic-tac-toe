# Tic Tac Toe em C

## Índice

- [Descrição](#descrição)
- [Estrutura de arquivos](#estrutura-de-arquivos)
- [Uso](#uso)
- [Contribuição](#contribuição)

## Descrição

O projeto é um **Tic Tac Toe** (conhecido também como **Jogo da Velha**) feito em **C**. 

Ele está completo e contém tudo o que eu pretendia colocar de acordo com as regras do jogo.

Criei ele apenas para praticar meus conhecimentos em C.

#### Tecnologias usadas:
1. C
2. Makefile

## Estrutura de arquivos

O projeto contém vários arquivos, com o principal objetivo de dividir tarefas em cada função e arquivo do projeto.

> Todo arquivo com a extensão ".h" é um header (cabeçalho) de um arquivo ".c" com mesmo nome.

> Todo arquivo ".c" contém, além das funções, comentários explicando o que a função faz.

### Arquivos "utils.c" e "utils.h"

São arquivos para **utilidades extras** que não fazem parte do principal do projeto, mas são **necessárias** para o seu funcionamento.

**Contém somente funções para o gerenciamento de memória.**

---

### Arquivos "tic_tac_toe.c" e "tic_tac_toe.h"

**Usa o "utils.h".**

São arquivos que **contém funções para as funcionalidades que o jogo** permite que você tenha e para **gerenciar os estados do jogo**, como, **se alguém ganhou.**

**Contém funções que:**
- Geram a matriz do jogo (3x3) -> gerarCampo
- Mostram a matriz do jogo -> mostrarCampo
- Verifica se uma jogada é válida -> verificaValidadeJogada
- Realiza a alocação do "X" ou do "O" no lugar desejado -> inputJogador
- Verifica se alguém venceu -> verificaVencedor

---

### Arquivos "game.c" e "game.h"

**Usa o "utils.h" e o "tic_tac_toe.h".**

**Contém a lógica em si do jogo** organizando as funções do arquivo "tic_tac_toe.c" em uma ordem lógica para que o jogo funcione de forma normal e correta.

Dentro do arquivo "game.c", **há a função na qual inicia o jogo e administra a ordem das funções**, com loopings, gerenciando a troca de turnos de cada jogador, etc.

---

### Arquivo "main.c"

**Usa o "game.h".**

Simplesmente, **roda a função principal que inicia o jogo por completo**.

---

## Uso

#### Para transformar tudo em um executável, faça:
1. Vá até a pasta onde se localizam todos os arquivos deste projeto.
2. Rode em seu terminal:
```bash
make
```
Em um sistema operacional baseado em **Linux**, isso já deve funcionar. Mas se não funcionar, faça o que é dito no comentário abaixo.

> Caso dê algum erro, **é possível que seja por causa do compilador**. Caso você não tenha, recomendo instalar um e modificar o campo "CC" em "Makefile" para a chamada de sistema do compilador que você instalou. Caso tenha, mas seja diferente do que está presente no "Makefile", recomendo que também modifique o campo "CC" em Makefile para a chamada de sistema do compilador presente na sua máquina.

#### Para limpar os arquivos objetos criados (".o") e o executável, faça:
1. Ainda na pasta que você fez o comando para criar, rode no seu terminal:
```bash
make clean
```

Desta forma todos os arquivos que não sejam de extensão ".o" e o executável continuarão na pasta, mas todos esses outros serão excluídos.

#### Como jogar?
- O plano do jogo é da seguinte forma:

|___|X:0|X:1|X:2|
|---|---|---|---|
|**Y:0**| . | . | . |
|**Y:1**| . | . | . |
|**Y:2**| . | . | . |

A partir dessas informações de como o plano funciona, é possível informar as coordenadas X e Y para realizar uma marcação de um "X" ou de um "O".

O eixo *X cresce para a direita*, representando as **colunas**.

O eixo *Y cresce para baixo*, representando as **linhas**.

### Exemplo:

Se quero marcar o último ponto da última linha, informo o **eixo X como 2** e o **eixo Y como 2** também.

Ficando:

| - | - | - |
|---|---|---|
| - | - | - |
| - | - | X |

## Contribuição

Cada arquivo com a extensão ".c" contém uma explicação breve a respeito de suas funções.

Caso queira modificar ou ter uso próprio do projeto pode ficar à vontade, **para mais informações do que é permitido ou não, recomendo que leia o arquivo "LICENSE.md"** que está presente neste mesmo repositório.

*Este projeto está licenciado sob a Licença MIT.*
