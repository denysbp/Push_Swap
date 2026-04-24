# Push Swap Notes

## Estrutura recomendada

push_swap
|
+-- includes/
|   +-- push_swap.h
|   +-- libft.h
|   +-- ft_printf.h
+-- libft/
|   +-- libft.a
|   +-- srcs...
+-- ft_printf/
|   +-- libftprintf.a
|   +-- srcs...
+-- src/
|   +-- main.c
|   +-- parsing/
|   |   +-- parse_args.c
|   |   +-- split_args.c
|   |   +-- atoi_safe.c
|   +-- validation/
|   |   +-- check_numbers.c
|   |   +-- check_duplicates.c
|   |   +-- check_overflow.c
|   +-- stack/
|   |   +-- stack_init.c
|   |   +-- stack_utils.c
|   |   +-- stack_free.c
|   +-- operations/
|   |   +-- swap.c
|   |   +-- push.c
|   |   +-- rotate.c
|   |   +-- reverse.c
|   +-- sort/
|   |   +-- simple/
|   |   |   +-- sort_simple.c
|   |   |   +-- simple_utils.c
|   |   +-- medium/
|   |   |   +-- sort_chunks.c
|   |   |   +-- chunk_utils.c
|   |   +-- complex/
|   |   |   +-- radix_sort.c
|   |   |   +-- radix_utils.c
|   |   +-- small/
|   |   |   +-- sort_three.c
|   |   |   +-- sort_five.c
|   |   +-- adaptive/
|   |   |   +-- adaptive_sort.c
|   |   |   +-- disorder.c
|   |   +-- sort_utils.c
|   +-- output/
|       +-- print_ops.c
+-- Makefile
+-- README.md
+-- NOTES.md

## Header principal: includes/push_swap.h

Vai conter os prototypes de:

- parsing
- validation
- stack
- operations
- sort
- output
- free/error handling
- includes/libft.h e printf

## src/main.c

Responsabilidade:

- receber argc e argv
- verificar se há argumentos suficientes
- chamar validação
- criar stack A
- verificar se já está ordenado
- escolher algoritmo
- libertar memória no final

Fluxo esperado:

argc/argv
-> validar input
-> criar stack_a
-> atribuir index
-> se já estiver ordenado, sair
-> ordenar
-> free

## src/parsing/parse_args.c

Responsabilidade:

- transformar os argumentos recebidos em números
- lidar com estes dois casos:
  - ./push_swap 1 2 3
  - ./push_swap "1 2 3"
- preparar os dados para serem colocados na stack

## src/parsing/split_args.c

Responsabilidade:

- separar strings quando o input vem entre aspas

Exemplo:

./push_swap "4 67 3 87"

Deve transformar isso em algo parecido com:

["4", "67", "3", "87"]

## src/parsing/atoi_safe.c

Responsabilidade:

- converter string para número
- proteger contra overflow e underflow
- aceitar apenas valores dentro de int

Limites:

- INT_MIN = -2147483648
- INT_MAX = 2147483647

Se passar do limite, deve dar erro.

## src/validation/check_numbers.c

Responsabilidade:

- verificar se cada argumento é um número válido

Aceitar:

- 42
- -42
- +42

Recusar:

- --
- ++
- 42a
- abc
- 4-2

## src/validation/check_duplicates.c

Responsabilidade:

- verificar se existem números repetidos

Exemplo inválido:

./push_swap 1 2 3 2

Deve dar Error.

## src/validation/check_overflow.c

Responsabilidade:

- garantir que nenhum número passa do limite de int

Pode ser feito junto com atoi_safe.c, mas manter separado ajuda na organização.

## src/stack/stack_init.c

Responsabilidade:

- criar os nós da linked list
- preencher value
- iniciar index
- adicionar nós à stack A

Exemplo:

input: 3 1 2

stack_a:
3 -> 1 -> 2 -> NULL

## src/stack/stack_utils.c

Responsabilidade:

Funções auxiliares da stack. Pode conter:

- stack_size
- stack_last
- is_sorted
- find_min
- find_max
- assign_index

## src/stack/stack_free.c

Responsabilidade:

- libertar a stack inteira
- libertar arrays criados por ft_split
- lidar com erros e free antes de sair

Funções úteis:

- free_stack
- free_split
- error_exit

## src/operations/swap.c

Responsabilidade:

- implementar sa, sb, ss

Operações:

- sa: troca os dois primeiros elementos da stack A
- sb: troca os dois primeiros elementos da stack B
- ss: faz sa e sb ao mesmo tempo

## src/operations/push.c

Responsabilidade:

- implementar pa e pb

Operações:

- pa: move o topo da stack B para a stack A
- pb: move o topo da stack A para a stack B

## src/operations/rotate.c

Responsabilidade:

- implementar ra, rb, rr

Operações:

- ra: primeiro elemento da A vai para o fim
- rb: primeiro elemento da B vai para o fim
- rr: faz ra e rb ao mesmo tempo

## src/operations/reverse.c

Responsabilidade:

- implementar rra, rrb, rrr

Operações:

- rra: último elemento da A vai para o topo
- rrb: último elemento da B vai para o topo
- rrr: faz rra e rrb ao mesmo tempo

## SORT ARCHITECTURE

A lógica de ordenação fica dividida por complexidade e por contexto de uso:

- simple/ -> O(n²)
- medium/ -> O(n√n)
- complex/ -> O(n log n)
- adaptive/ -> seleção dinâmica
- small/ -> casos específicos (<= 5 elementos)

Objetivo da organização:

- manter cada estratégia isolada
- facilitar testes por algoritmo
- permitir tuning sem mexer no resto do projeto

## src/sort/small/sort_three.c

Papel do ficheiro:

- ordenar exatamente 3 elementos
- usar apenas operações curtas (sa, ra, rra)
- servir como base para sort_five

Quando é usado:

- sempre que size == 3

## src/sort/small/sort_five.c

Papel do ficheiro:

- ordenar 4 ou 5 elementos com poucas operações
- enviar os menores para B
- resolver os 3 restantes em A com sort_three
- devolver de B para A na ordem correta

Quando é usado:

- sempre que size <= 5

## src/sort/simple/sort_simple.c

Papel do ficheiro:

- implementar estratégia simples O(n²)
- focar em listas quase ordenadas (desordem baixa)

Estratégia:

- encontrar menor índice em A
- rodar A até ele chegar ao topo
- fazer pb
- repetir até sobrar um bloco pequeno em A
- devolver tudo com pa

Quando é usado:

- cenário adaptativo com disorder < 0.2

## src/sort/simple/simple_utils.c

Papel do ficheiro:

- utilitários locais do algoritmo simples
- decidir direção de rotação para chegar ao menor em menos passos
- funções de apoio para reduzir repetição em sort_simple.c

## src/sort/medium/sort_chunks.c

Papel do ficheiro:

- implementar estratégia O(n√n)
- equilibrar número de operações entre simple e radix

Estratégia:

- dividir índices em intervalos de tamanho aproximado √n
- empurrar para B por faixa de chunk
- ao reconstruir, trazer maiores de B para A primeiro

Quando é usado:

- cenário adaptativo com 0.2 <= disorder < 0.5

## src/sort/medium/chunk_utils.c

Papel do ficheiro:

- cálculo de tamanho de chunk
- controlo de limites de faixa (start/end)
- helpers para localizar alvo de cada chunk

## src/sort/complex/radix_sort.c

Papel do ficheiro:

- implementar estratégia O(n log n) baseada em índices
- garantir comportamento estável para listas grandes

Estratégia:

- percorrer bits do índice, do menos significativo para cima
- bit 0 -> pb
- bit 1 -> ra
- no fim de cada ciclo de bit, pa até B esvaziar

Quando é usado:

- cenário adaptativo com disorder >= 0.5
- fallback seguro para inputs grandes

## src/sort/complex/radix_utils.c

Papel do ficheiro:

- calcular número máximo de bits a percorrer
- helpers de controlo de passes
- funções pequenas para manter radix_sort.c limpo

## src/sort/adaptive/disorder.c

Papel do ficheiro:

- medir nível de desordem da stack
- retornar valor normalizado no intervalo [0, 1]

Métrica sugerida:

- disorder = inversions / max_inversions

Leitura prática:

- 0.0 próximo de ordenado
- 1.0 próximo do pior caso

## src/sort/adaptive/adaptive_sort.c

Papel do ficheiro:

- decidir qual algoritmo usar para cada input
- centralizar a política de seleção

Fluxo recomendado:

1. calcular size
2. calcular disorder
3. aplicar regra de decisão

Regra de decisão:

- size <= 3 -> sort_three
- size <= 5 -> sort_five
- disorder < 0.2 -> sort_simple
- disorder < 0.5 -> sort_chunks
- caso contrário -> radix_sort

## src/sort/sort_utils.c

Papel do ficheiro:

- concentrar helpers globais usados por múltiplos algoritmos
- evitar duplicação entre simple, chunk e radix

Funções esperadas:

- assign_index
- stack_size
- is_sorted
- find_min
- find_max
- get_position

assign_index -> transforma valores em ranking(index)
stack_size   -> conta elementos
is_sorted    -> verifica se já está ordenado
find_min     -> encontra menor valor
find_max     -> encontra maior valor
get_position -> encontra posição de um elemento

Nota de implementação:

- funções genéricas ficam aqui
- funções específicas de uma estratégia ficam no utils da própria pasta

## src/output/print_ops.c

Responsabilidade:

- imprimir os movimentos

Exemplo:

sa
pb
ra

Pode usar:

- write
- ou ft_printf

Na 42, write costuma ser mais simples para isto.

## Makefile

Responsabilidade:

- compilar o projeto
- compilar libft
- compilar ft_printf
- gerar o executável push_swap

Targets obrigatórios:

- all
- clean
- fclean
- re

## Fluxo final do programa

1. Receber argumentos
2. Validar se são números
3. Verificar overflow
4. Verificar duplicados
5. Criar stack A
6. Atribuir indexes
7. Verificar se já está ordenado
8. Escolher algoritmo
9. Executar operações
10. Imprimir movimentos
11. Libertar memória

## Regra mental


- parsing -> transformar input em dados
- validation -> verificar se os dados são válidos
- stack -> criar e manipular linked list
- operations -> comandos permitidos pelo subject
- sort -> lógica de ordenação
- output -> impressão dos movimentos