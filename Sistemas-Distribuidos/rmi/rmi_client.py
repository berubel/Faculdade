#client

import Pyro4
jormungandr = Pyro4.Proxy("PYRONAME:example.jor")    

string = input("Digite a mensagem a ser invertida: ").strip()
print(jormungandr.invertString(string))

a,b = input("Digite 'a', 'b' para fazer o somatório: ").split(' ')
print(jormungandr.sum(a,b))
