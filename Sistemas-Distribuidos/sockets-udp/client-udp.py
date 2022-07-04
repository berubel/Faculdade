import socket

UDP_IP = str("127.0.0.1")
UDP_PORT = 5007

mensagem = input("Digite a mensagem a ser invertida pelo servidor: ")
print("Enviando mensagem para o servidor: {}, na porta {}.".format(UDP_IP, UDP_PORT))
print("Mensagem: %s" % mensagem)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(mensagem.encode(), (UDP_IP, UDP_PORT))