import socket

TCP_IP = str('127.0.0.1')
TCP_PORT = 5008
ADDR = (TCP_IP, TCP_PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.bind(ADDR)
sock.listen(10)

print('\nComunicação com Sockets - TCP')
print('Aguardando conexão...')

con, client = sock.accept()
print('\nConectado com o cliente')
print('Aguardando uma mensagem...')

receive = str(con.recv(1024))

if receive != None:
    with open('./recebido.txt', 'w') as file:
        file.write(receive)
        print('\nArquivo recebido')

sock.close()