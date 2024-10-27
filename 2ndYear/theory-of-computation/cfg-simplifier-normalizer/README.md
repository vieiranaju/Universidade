## Simplificador e Normalizador de Gramáticas Livres de Contexto

Este repositório contém um projeto para simplificar e normalizar gramáticas livres de contexto (GLCs) como parte de uma atividade da disciplina de Teoria da Computação. O projeto implementa algoritmos para simplificação e conversão para formas normais de gramáticas.

## Funcionalidades

### Simplificação de Gramáticas
- Remoção de Símbolos Inúteis/Inalcançáveis
- Eliminação de Produções Vazias
- Substituição de Produções

### Normalização para Formas Normais
- Forma Normal de Chomsky (CNF)
- Forma Normal de Greibach (GNF) <- Não está funcionando direito


## Estrutura do Projeto
- `main.py`: Script principal.
- `simplificacao.py`: Algoritmos de Simplificação.
- `cnf.py`: Algoritmo de Normalização para Forma de Chomsky.
- `gnf.py`: Algoritmo de Normalização para Forma de Greibach.
- `utils.py`: Funções comuns de leitura e escrita.
- `README.md`: Este arquivo.
- `exemplos/`: Pasta contendo exemplos de arquivos `.glc` e `.out`.

## Uso

O programa lê uma gramática livre de contexto a partir de um arquivo de entrada e produz uma gramática simplificada e normalizada em um arquivo de saída.

### Executando o Programa

```bash
python main.py <arquivo_entrada.glc> <arquivo_saida.out>

<arquivo_entrada.glc>: Arquivo de entrada contendo a gramática livre de contexto no formato:
S -> aAa | bBv
A -> a | aA
<arquivo_saida.out>: Arquivo de saída onde a gramática simplificada e normalizada será salva.


