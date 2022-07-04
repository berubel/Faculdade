import socket
import os.path

TCP_IP = str('127.0.0.1')
TCP_PORT = 5008
ADDR = (TCP_IP, TCP_PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

print('\nConectado ao servidor: ', ADDR)
message = input("\nDigite a mensagem a ser gravada no arquivo: ")

filename = './arquivo.txt'

if os.path.isfile(filename) == False:
    print("Creating file {} \n".format(filename))

os.path.isfile(filename)
with open('./arquivo.txt', 'w') as file:
    file.write(message)
with open('./arquivo.txt', 'r') as file:
    sock.send(file.read().encode())
    print('\nArquivo enviado ao servidor ', ADDR)

sock.close()

print('\nConexão com o servidor encerrada\n')