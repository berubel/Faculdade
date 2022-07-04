import xmlrpc.client

with xmlrpc.client.ServerProxy("http://localhost:8000/", allow_none=True) as proxy:
    msg = str(input("Digite a mensagem a ser invertida pelo servidor: "))
    print("Mensagem invertida: {}" .format(proxy.message(msg)))
