# Atividade_Prática_Implementação_de_Filas

    Implementar um escalonador de processos por prioridades.

 # Requisitos 

* O processo deve conter um id do processo (PID) e o nome do processo.
 
* O escalonador deve conter pelo menos duas filas de prioridade.
 
* Devem constar as seguintes funções:
 
    * Adicionar processo: adiciona um novo processo a uma fila. Caso não seja definida a fila o processo será adicionado à fila de menor prioridade
    * Executar processo: executa o primeiro processo da fila de maior prioridade que esteja com processos pendentes. O processo é movido para o final da fila de prioridade     imediatamente inferior.
    * Mover processo entre filas: transfere um processo de uma fila para outra. O processo movido pode estar em qualquer posição da fila de origem e será colocado no final da fila de destino.
    * Finalizar processo: Encerra o primeiro processo da fila de maior prioridade, removendo-o completamente do sistema.
    * Finalizar processo específico: Encerra um processo a partir do ID escolhido, removendo-o completamente do sistema. O processo pode estar em qualquer fila no momento da remoção.

Forma de entrega: Link do Github com o projeto.

Grupo: até 5 pessoas

# Grupo

- 2010840 - Gabriele Cardoso das Virgens

