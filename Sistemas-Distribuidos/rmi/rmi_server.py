#server

#python -m Pyro4.naming
import Pyro4

@Pyro4.expose
class Jormungandr(object):
    def invertString(self, string):
        return 'Mensagem recebida: {}\nMensagem invertida: {}'.format(string, string[::-1])
    
    def sum(self, a, b):
        return "{0} + {1} = {2}".format(a, b, int(a)+int(b))

daemon = Pyro4.Daemon()               
ns = Pyro4.locateNS()                  
uri = daemon.register(Jormungandr)   
ns.register("example.jor", uri)  

print("Olá! Jormungandr está ativado.")
daemon.requestLoop()                  

