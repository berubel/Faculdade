import xmlrpc.client

with xmlrpc.client.ServerProxy("http://localhost:8000/", allow_none=True) as proxy:
    num1 = int(input("Digite um número: "))
    num2 = int(input("Digite outro número: "))
    print("Resultado da soma dos números inseridos: {}" .format(proxy.sum(num1,num2)))
