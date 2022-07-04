from xmlrpc.server import SimpleXMLRPCServer

def message(msg):
    print("Mensagem recebida: {}".format(msg))
    msg = msg[::-1]
    return str(msg)

server = SimpleXMLRPCServer(("localhost", 8000))
print("Listening on port 8000...")
server.register_function(message, "message")
server.serve_forever()
