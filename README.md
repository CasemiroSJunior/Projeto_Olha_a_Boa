# Olha a Boa - Desafio de Estruturas de Dados

## Descrição

**Olha a Boa** é um projeto desenvolvido como parte de um desafio proposto pelo professor Orlando Saraiva Junior. O objetivo deste projeto é colocar em prática os conceitos e conhecimentos adquiridos durante o curso de Estruturas de Dados. Através deste desafio, exploramos tópicos fundamentais como:

- **Ponteiros**
- **Fila**
- **Alocação dinâmica de memória**
- Entre outros conceitos relacionados a estruturas de dados.

O projeto foi desenvolvido para aprofundar o entendimento sobre o funcionamento e a implementação dessas estruturas fundamentais, além de permitir o exercício de técnicas de manipulação de memória e gestão de dados de forma eficiente.

## Objetivo

O principal objetivo deste projeto é reforçar a teoria de estruturas de dados ao aplicá-la em um cenário prático, utilizando as abordagens de alocação dinâmica, manipulação de ponteiros e manipulação de filas.

## Tecnologias Utilizadas

- **Linguagem:** C/C++
- **Compilador:** MinGW (Minimalist GNU for Windows)

## Pré-requisitos

Antes de rodar o projeto, você precisará ter o MinGW instalado e configurado corretamente em seu sistema. Além disso, as variáveis de ambiente devem ser configuradas para permitir o uso do compilador de forma global.

### Instalando o MinGW e Configurando as Variáveis de Ambiente

1. **Baixar e instalar o MinGW**:
    - Acesse o site oficial do [MinGW](https://osdn.net/projects/mingw/releases/) e baixe o instalador.
    - Durante a instalação, selecione o pacote `mingw32-gcc-g++` para instalar o compilador C/C++.

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
      gcc --version
      ```
    - Se o MinGW estiver instalado corretamente, você verá a versão do GCC sendo exibida.

## Como Rodar o Projeto

1. **Clone o repositório**
    ```bash
    git clone https://github.com/usuario/olha-a-boa.git
    ```

2. **Navegue até o diretório do projeto**
    ```bash
    cd olha-a-boa
    ```

3. **Compilar o código**
    - No terminal, use o seguinte comando para compilar o código (assumindo que o arquivo principal seja `main.c`):
    ```bash
    gcc -o projeto main.c
    ```
    - Caso você tenha múltiplos arquivos, você pode compilar todos de uma vez:
    ```bash
    gcc -o projeto main.c outro_arquivo.c
    ```

4. **Executar o programa**
    - Após a compilação, execute o programa gerado com o comando:
    ```bash
    ./projeto
    ```

## Funcionalidades

- Implementação de uma fila com operações básicas.
- Uso de alocação dinâmica de memória para manipulação de dados.
- Manipulação de ponteiros para estruturar a fila e realizar inserções/remoções.

## Contribuição

Se desejar contribuir com o projeto, siga estas etapas:

1. Faça um fork deste repositório.
2. Crie uma nova branch (`git checkout -b feature/nome-da-feature`).
3. Faça as alterações desejadas.
4. Comite suas alterações (`git commit -m 'Adiciona nova funcionalidade'`).
5. Envie para a branch principal (`git push origin feature/nome-da-feature`).
6. Abra um pull request para revisão.

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
