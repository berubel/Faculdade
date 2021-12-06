# Análise dos Algoritmos de Ordenação

Realizar uma análise de desempenho dos seguintes algoritmos de ordenação:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Merge Sort
    
Para esta análise execute cada algoritmo no mínimo 5 vezes para os seguintes tamanhos de vetor:

* 10
* 100
* 1000
* 10000
* 100000

#### OBS: Vetores com elementos randomizados.
  
## Especificações

O computador utilizado para os testes possui as seguintes configurações:

* Processador Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz   1.99 GHz
* 8,00 GB de Memória RAM com frequência de 2400Mhz
* SSD M.2 2280 de 256GB, leitura 3500MB/s, gravação 2400MB/s
* Windows 11 Home 64 bits, processador baseado em x64

# Resultados 

### bubble_sort

Tempo médio de 5 execuções em milissegundos (ms) para cada tamanho de vetor:
* 10 - 0,000000 ms
* 100 - 0,000000 ms
* 1000 - 2,600000 ms
* 10000 - 290,600000 ms
* 100000 - 33407,400000 ms 

### selection_sort 

Tempo médio de 5 execuções em milissegundos (ms) para cada tamanho de vetor:
* 10 - 0,000000 ms
* 100 - 0,000000 ms
* 1000 - 2,000000 ms
* 10000 - 248,000000 ms
* 100000 - 24700,600000 ms

### insertion_sort 

Tempo médio de 5 execuções em milissegundos (ms) para cada tamanho de vetor:
* 10 - 0,000000 ms
* 100 - 0,000000 ms
* 1000 - 0,00000 ms
* 10000 - 57,600000 ms
* 100000 - 5024,200000 ms

### merge_sort 

Tempo médio de 5 execuções em milissegundos (ms) para cada tamanho de vetor:
* 10 - 0,000000 ms
* 100 - 0,000000 ms
* 1000 - 0,00000 ms
* 10000 - 2,200000 ms
* 100000 - 21,400000 ms

# Conclusão

Nos algoritmos de ordenação as medidas de complexidade relevantes são:

    Número de comparações C(n) entre chaves.
    Número de movimentações M(n) dos registros dos vetores.
    
Onde n é o número de registros.

### bubble_sort

O bubble sort é o algoritmo mais simples, mas o menos eficientes. Neste algoritmo cada elemento da posição j será comparado com o elemento da posição j + 1, ou seja, um elemento da posição 1 será comparado com o elemento da posição 2. Se o elemento da posição 1 for maior que o da posição 2, eles trocam de lugar e assim sucessivamente. Por causa dessa forma de execução, o vetor terá que ser percorrido quantas vezes for necessário e fazer inúmeras trocas (swap), até que seja completamente ordenado, tornando o algoritmo ineficiente para estruturas muito grandes.

    Para todos os casos (melhor, médio e pior caso) possui complexidade C(n) = O(n²). É um algoritmo estável.

### selection_sort 

O algoritmo selection sort consiste em se passar sempre o menor valor do vetor para a primeira posição, depois o segundo menor valor para a segunda posição e assim sucessivamente, até os últimos dois elementos. Desse modo, o primeiro elemento selecionado é comparado com todos os seus posteriores, caso encontrado um valor menor, trocam-se as posições e repete-se a ação para os próximos elementos, até que a ordenação do vetor esteja concluída. Assim como no bubble sort, esse algoritmo de ordenação apresentará problemas quando implementado para grandes estruturas, uma vez que a busca pelo menor valor se torna extensa quando há milhares de elementos para comparar.

    Para todos os casos (melhor, médio e pior caso) possui complexidade C(n) = O(n²). Não é um algoritmo estável.

### insertion_sort 

O insertion sort é um algoritmo simples e eficiente quando aplicado em pequenas listas. Neste algoritmo a lista é percorrida da esquerda para a direita, à medida que avança vai deixando os elementos mais à esquerda ordenados, isto é, a cada iteração ocorre a comparação do elemento atual com os anteriores, caso menor faz-se o swap entre as posições, até que todos elementos do vetor estejam completamente ordenados. Para os vetores menores e até mesmos os mais extensos, tem desempenho superior aos algoritmos anteriores, pois o número de comparações que ocorre nesse método é consideravelmente menor, o que pode ser um bonificador para a execução.

    Possui complexidade C(n) = O(n) no melhor caso e C(n) = O(n²) no caso médio e pior caso. É um algoritmo estável.

### merge_sort 

O merge sort é um algoritmo que divide o todo em pequenos pedaços, resolve cada pedaço e depois intercala (merge) os resultados. Para isso, o vetor, a partir da recursão, será dividido em duas metades iguais, que serão cada uma divididas em duas partes, até que não seja mais possível a divisão. Em seguida, os elementos de cada grupo (metade) serão organizados de modo que fiquem ordenados. Para juntar as partes ordenadas os dois elementos de cada metade são separados e o menor deles é selecionado e retirado de sua parte. Feito isso, os menores entre os restantes são comparados e assim sucessivamente, intercalando-os até que todos estejam unidos novamente em uma única estrutura. Dentre todos os métodos testados, este é o mais eficiente, com um desempenho extremamente superior quando comparado aos demais. No entanto, por conta da recursividade, o mesmo é indicado para implementação em grandes estruturas desorganizadas, em situações opostas, a recursão pode trazer um aumento desnecessário no tempo de processamento.

    Possui complexidade C(n) = O(n log n) para todos os casos. É um algoritmo estável.

# Grupo

- 2010840 - Gabriele Cardoso das Virgens
