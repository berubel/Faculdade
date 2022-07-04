from xmlrpc.server import SimpleXMLRPCServer

def sum(num1, num2):
    result = int(num1 + num2)
    print("Soma dos números recebidos: {} + {} = {}".format(num1, num2, result))
    return int(result)

server = SimpleXMLRPCServer(("localhost", 8000))
print("Listening on port 8000...")
server.register_function(sum, "sum")
server.serve_forever()
