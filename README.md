# Árvore AVL
Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada (árvore completa) são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências idênticas. Contudo, para garantir essa propriedade em aplicações dinâmicas, é preciso reconstruir a árvore para seu estado ideal a cada operação sobre seus nós (inclusão ou exclusão), para ser alcançado um custo de algoritmo com o tempo de pesquisa tendendo a O(log n).

As operações de busca, inserção e remoção de elementos possuem complexidade O(log n) (no qual n é o número de elementos da árvore), que são aplicados à árvore de busca binária.
 
O nome AVL vem de seus criadores soviéticos Adelson Velsky e Landis, e sua primeira referência encontra-se no documento "Algoritmos para organização da informação" de 1962.
 
Nessa estrutura de dados cada elemento é chamado de nó. Cada nó armazena uma chave e dois ponteiros, uma para a subárvore esquerda e outra para a subárvore direita.
 
No presente artigo serão apresentados: os conceitos básicos, incluindo uma proposta de estrutura; apresentação das operações busca, inserção e remoção, todas com complexidade O(log n).

Pensando nisso, foi desenvolvido um algoritmo em C para fazer uma árvore AVL.

## Requisitos
É necessário ter ter o compilador de C/C++ intalado em seu computador.

### Execução
Basta compilar os arquivos contidos neste repositório e executá-los.
