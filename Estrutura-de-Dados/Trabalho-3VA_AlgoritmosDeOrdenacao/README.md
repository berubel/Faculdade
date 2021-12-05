# Análise_dos_Algoritmos_de_Ordenação

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
      
O computador utilizado para os testes possui as seguintes configurações:

* Processador Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz   1.99 GHz
* 8,00 GB de Memória RAM com frequência de 2400Mhz
* Windows 11 Home 64 bits, processador baseado em x64
* SSD M.2 2280 de 256GB, leitura 3500MB/s, gravação 2400MB/s

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

### bubble_sort

O bubble sort é o algoritmo mais simples, mas o menos eficientes. Neste algoritmo cada elemento da posição j será comparado com o elemento da posição j + 1, ou seja, um elemento da posição 1 será comparado com o elemento da posição 2. Se o elemento da posição 1 for maior que o da posição 2, eles trocam de lugar e assim sucessivamente. Por causa dessa forma de execução, o vetor terá que ser percorrido quantas vezes for necessário e fazer inúmeras trocas (swap), até que seja completamente ordenado, tornando o algoritmo ineficiente para estruturas muito grandes.

### selection_sort 

O algoritmo selection sort consiste em se passar sempre o menor valor do vetor para a primeira posição, depois o segundo menor valor para a segunda posição e assim sucessivamente, até os últimos dois elementos. Desse modo, o primeiro elemento selecionado é comparado com todos os seus posteriores, caso encontrado um valor menor, trocam-se as posições e repete-se a ação para os próximos elementos, até que a ordenação do vetor esteja concluída. Assim como no bubble sort, esse algoritmo de ordenação apresentará problemas quando implementado para grandes estruturas, uma vez que a busca pelo menor valor se torna extensa quando há milhares de elementos para comparar.

### insertion_sort 



# Grupo

- 2010840 - Gabriele Cardoso das Virgens
