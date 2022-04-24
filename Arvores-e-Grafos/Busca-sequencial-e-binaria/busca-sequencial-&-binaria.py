# -*- coding: UTF-8 -*-

vetor = [3, 5, 7, 9, 11, 13, 15, 17]
iteracoes = 0
size = len(vetor)
inicial = 0
final = size
flag = 0

def pesquisaSequencial(vetor, chave):
    global iteracoes, size
    iteracoes = 0

    for i in range(len(vetor)):
        iteracoes += 1
        if int(vetor[i]) == int(chave):
            print("\nChave {} encontrada. \nNúmero de iterações: {}".format(chave, iteracoes))
            break
        elif int(i) == int(size)-1 and int(chave) > vetor[i]:
            print("\nChave {} não encontrada. Número de iterações: {}".format(chave, iteracoes))

def pesquisaBinaria(vetor, chave, inicial, final):
    global iteracoes,size

    middle = int((inicial + final) / 2)

    while inicial <= final:
        if chave > vetor[int(size-1)]:
            print("\nA chave {} não se encontra no conjunto de dados.".format(chave))
            break
        else:
            if vetor[middle] == chave:
                iteracoes += 1
                print("\nChave {} encontrada. \nNúmero de iterações: {}".format(chave, iteracoes))
                break
            elif chave < vetor[middle]:
                iteracoes += 1
                final = middle - 1
                pesquisaBinaria(vetor, chave, inicial, final)
                break
            elif chave > vetor[middle]:
                iteracoes += 1
                inicial = middle + 1
                pesquisaBinaria(vetor, chave, middle + 1, final)
                break

while True:
    iteracoes = 0
    print("\nALGORITMOS DE BUSCA SEQUENCIAL e BINÁRIA")
    print("\nVetor:", vetor)

    opcao = input("\nEscolha o algoritmo: \n[1]Busca Sequencial \n[2]Busca Binária \nResposta: ")
    while True:

        if int(opcao) == 1:
            chave = input("\nDigite a chave a ser buscada: ")
            pesquisaSequencial(vetor, chave)
            break
        elif int(opcao) == 2:
            chave = input("\nDigite a chave a ser buscada: ")
            pesquisaBinaria(vetor, int(chave), inicial, final)
            break
        else:
            print("Insira uma opção válida!")
            break

    opcao = input("\nDeseja executar novamente: \n[1]SIM \n[2]NÃO \nResposta: ")

    if int(opcao) == 1 or int(opcao) == 2:
        if int(opcao) == 1:
            continue
        elif int(opcao) == 2:
            break
    else:
        print("Opção inválida!")
        break