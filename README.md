# Olha a Boa - Desafio de Estruturas de Dados

## Descrição

**Olha a Boa** é um projeto desenvolvido como parte de um desafio proposto pelo professor Orlando Saraiva Junior. O objetivo deste projeto é colocar em prática os conceitos e conhecimentos adquiridos durante o curso de Estruturas de Dados. Através deste desafio, exploramos tópicos fundamentais como:

- **Ponteiros**
- **Fila**
- **Alocação dinâmica de memória**
- Entre outros conceitos relacionados a estruturas de dados.

### Descrição do Projeto

O projeto **Bingo - Gerenciador de Cartelas** é uma aplicação que simula o gerenciamento de cartelas de bingo, tanto para jogos presenciais quanto digitais. O jogo envolve a marcação de números em uma cartela conforme eles são sorteados aleatoriamente por um chamador.

O objetivo do jogo é preencher uma linha, coluna ou um padrão específico de números antes dos outros jogadores e anunciar "Bingo!" para sinalizar a vitória.

No seu projeto, você irá desenvolver um **gerenciador de cartelas**, permitindo que o jogador gerencie uma ou mais cartelas. O programa será capaz de realizar as seguintes operações:

- Criar novas cartelas.
- Marcar números nas cartelas conforme são sorteados.
- Verificar se a cartela completou um padrão vencedor (linha, coluna, etc.).
- Exibir o status da cartela (se o jogador ganhou ou não).

Com o advento da tecnologia, o bingo também ganhou versões digitais, onde os jogadores podem participar remotamente, com números sendo chamados automaticamente e cartelas virtuais sendo preenchidas automaticamente.

## Objetivo

O principal objetivo deste projeto é reforçar a teoria de estruturas de dados ao aplicá-la em um cenário prático, utilizando as abordagens de alocação dinâmica, manipulação de ponteiros e manipulação de filas para gerenciar as cartelas de bingo e os sorteios de números.

## Tecnologias Utilizadas

- **Linguagem:** C++
- **Compilador:** MinGW (Minimalist GNU for Windows)

## Pré-requisitos

Antes de rodar o projeto, você precisará ter o MinGW instalado e configurado corretamente em seu sistema. Além disso, as variáveis de ambiente devem ser configuradas para permitir o uso do compilador de forma global.

### Instalando o MinGW e Configurando as Variáveis de Ambiente

1. **Baixar e instalar o MinGW**:
    - Acesse o site oficial do [MinGW](https://osdn.net/projects/mingw/releases/) e baixe o instalador.
    - Durante a instalação, selecione o pacote `mingw32-gcc-g++` para instalar o compilador C++.

2. **Configurar as variáveis de ambiente**:
    - Após a instalação, adicione o caminho do MinGW à variável de ambiente `PATH` para poder usá-lo de qualquer lugar no terminal.
    - O caminho típico de instalação do MinGW será algo como:
      ```
      C:\MinGW\bin
      ```
    - Para configurar a variável `PATH` no Windows:
      1. Clique com o botão direito em "Este PC" ou "Meu Computador" e selecione "Propriedades".
      2. Selecione "Configurações avançadas do sistema".
      3. Clique em "Variáveis de Ambiente".
      4. Na seção "Variáveis do sistema", encontre a variável `Path` e clique em "Editar".
      5. Adicione o caminho da pasta `bin` do MinGW à lista e clique em "OK".

3. **Verificar se o MinGW foi instalado corretamente**:
    - Abra o terminal (Prompt de Comando ou PowerShell) e digite o seguinte comando:
      ```bash
      g++ --version
      ```
    - Se o MinGW estiver instalado corretamente, você verá a versão do GCC (G++ para C++) sendo exibida.

## Como Rodar o Projeto

1. **Clone o repositório**
    ```bash
    git clone https://github.com/casemirosjunior/olha-a-boa.git
    ```

2. **Navegue até o diretório do projeto**
    ```bash
    cd olha-a-boa
    ```

3. **Compilar o código**
    - No terminal, use o seguinte comando para compilar o código (assumindo que o arquivo principal seja `main.cpp`):
    ```bash
    g++ -o bingo main.cpp
    ```
    - Caso você tenha múltiplos arquivos, você pode compilar todos de uma vez:
    ```bash
    g++ -o bingo main.cpp outro_arquivo.cpp
    ```

4. **Executar o programa**
    - Após a compilação, execute o programa gerado com o comando:
    ```bash
    ./bingo
    ```

## Funcionalidades

- **Gerenciamento de cartelas**: O jogador pode gerenciar uma ou mais cartelas.
- **Marcação de números**: O programa permite marcar os números sorteados nas cartelas.
- **Verificação de vencedor**: O sistema verifica se o jogador completou uma linha, coluna ou um padrão de vitória na cartela.
- **Interface de texto**: A interação com o usuário é feita via terminal/console, exibindo as cartelas e o status do jogo.

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
