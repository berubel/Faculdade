import socket

UDP_IP = str("127.0.0.1")
UDP_PORT = 5007

print ("Comunicação com Sockets - UDP")

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

while True:
    data, addr = sock.recvfrom(1024) 
    print('Mensagem recebida: {}' .format(data))
    print("Mensagem invertida: {}" .format(data[::-1]))