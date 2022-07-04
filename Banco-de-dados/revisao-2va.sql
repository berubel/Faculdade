create table atores(
idator Int not null primary key,
 Nome varchar(100) not null, 
datanascimento Date);

create table filmes(
idfilme Int not null primary key, 
Nome varchar(100) not null,
 Genero Varchar(100));

create table atoresfilmes(
idatorfilme Int not null primary key, 
idator Int not null, 
idfilme Int not null, 
foreign key (idator) references atores (idator),
foreign key (idfilme) references filmes (idfilme));

create table precosfilmes(
idprecofilme Int not null primary key, 
idfilme Int not null,
 preco float, datavigencia Date, 
 foreign key (idfilme) references filmes (idfilme));

create table clientes(
idcliente Int not null primary key, 
nome Varchar(100) not null, 
sexo char(1), 
datanascimento Date);

create table telefones( 
idtelefone Int not null primary key, 
idcliente Int not null, 
numero Varchar(100) not null, 
foreign key (idcliente) references clientes(idcliente));

create table locacoes(
idlocacao Int primary key not null, 
idcliente Int not null, 
datalocacao Date not null, 
foreign key (idcliente) references clientes(idcliente));

create table itenslocacoes(
iditemlocacao Int not null, 
idlocacao Integer not null, 
idprecofilme Integer not null,
foreign key (idlocacao) references Locacoes(idlocacao), 
foreign key (idprecofilme) references PrecosFilmes(idprecofilme));


insert into atores(idator, nome, datanascimento) values (1,'Richard Gueer', '19500201');
insert into atores(idator, nome, datanascimento) values (2,'Richard Gueer', '19500201');
insert into atores(idator, nome, datanascimento) values (3,'Leonardo DiCaprio', '19750701');
insert into atores(idator, nome, datanascimento) values (4,'Angelina Julie', '19760214');
insert into atores(idator, nome, datanascimento) values (5,'Michele Fifer', '19451015');
insert into atores(idator, nome, datanascimento) values (6,'Jenifer Lopes', '19771104');
insert into atores(idator, nome, datanascimento) values (7,'Jenifer Enistong', '19730315');
insert into atores(idator, nome, datanascimento) values (8,'Kevin Cosner', '19500220');
insert into atores(idator, nome, datanascimento) values (9,'Morgan Freeman', '19451201');
insert into atores(idator, nome) values (10,'Emile Hirsch');
insert into atores(idator, nome) values (11,'Justine Clarke');
insert into atores(idator, nome) values (12,'Trine Dyrholm');
insert into atores(idator, nome) values (13,'Ne-Yo');
insert into atores(idator, nome) values (14,'Ah-sung Kon');
insert into atores(idator, nome) values (15,'Robert Mann');
insert into atores(idator, nome) values (16,'Daniella Alonso');
insert into atores(idator, nome) values (17,'Dermot Mulroney');
insert into atores(idator, nome) values (18,'Sidney Santiago');
insert into atores(idator, nome) values (19,'Helen Mirren');
insert into atores(idator, nome) values (20,'Diane Keaton');

insert into filmes(idfilme, nome, genero) values (1,'Fred Gruger', 'Terror');
insert into filmes(idfilme, nome, genero) values (2,'Forrest Gamp', 'Drama');
insert into filmes(idfilme, nome, genero) values (3,'Os Outros', 'Suspense');
insert into filmes(idfilme, nome, genero) values (4,'Regras da Vida', 'Romance');
insert into filmes(idfilme, nome, genero) values (5,'Star Wars', 'Ficção');
insert into filmes(idfilme, nome, genero) values (6,'2001 Uma Odisséia do Espaço', 'Ficção');
insert into filmes(idfilme, nome, genero) values (7,'Brinquedo Assassino', 'Terror');
insert into filmes(idfilme, nome, genero) values (8,'Náufrago', 'Drama');
insert into filmes(idfilme, nome, genero) values (9,'Free Willi', 'Aventura');
insert into filmes(idfilme, nome, genero) values (10,'Alpha Dog', 'Drama');
insert into filmes(idfilme, nome, genero) values (11,'Olhe para os dois lados', 'Drama');
insert into filmes(idfilme, nome, genero) values (12,'Além do desejo', 'Drama');
insert into filmes(idfilme, nome, genero) values (13,'Stomp the Yard', 'Drama');
insert into filmes(idfilme, nome, genero) values (14,'O hospedeiro', 'Ação');
insert into filmes(idfilme, nome, genero) values (15,'A noite do terror', 'Terror');
insert into filmes(idfilme, nome, genero) values (16,'O retorno dos malditos', 'Terror');
insert into filmes(idfilme, nome, genero) values (17,'O amor pode dar certo', 'Romance');
insert into filmes(idfilme, nome, genero) values (18,'Os 12 trabalhadores', 'Drama');
insert into filmes(idfilme, nome, genero) values (19,'A rainha', 'drama');
insert into filmes(idfilme, nome, genero) values (20,'Minha mãe quer que eu case', 'Comédia');

insert into atoresfilmes (idatorfilme, idator, idfilme) values (1,1,1);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (2,4,1);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (3,9,1);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (4,10,10);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (5,6,2);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (6,2,2);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (7,1,3);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (8,2,3);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (9,3,3);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (10,7,3);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (11,6,4);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (12,2,4);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (13,3,5);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (14,9,5);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (15,11,11);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (16,12,12);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (17,13,13);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (18,14,14);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (19,15,15);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (20,16,16);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (21,17,17);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (22,18,18);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (23,19,19);
insert into atoresfilmes (idatorfilme, idator, idfilme) values (24,20,20);

insert into precosfilmes (idprecofilme, idfilme,  preco) values (1,1,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (2,2,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (3,3,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco, datavigencia) values (4,4,3.50,'2007-04-01');
insert into precosfilmes (idprecofilme, idfilme,  preco) values (5,5,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (6,6,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (7,7,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (8,8,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (9,9,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (10,10,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (11,4,3.00);
insert into precosfilmes (idprecofilme, idfilme,  preco, datavigencia) values (12,7,3.00,'20070405');
insert into precosfilmes (idprecofilme, idfilme,  preco) values (13,11,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (14,12,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (15,13,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (16,14,3.00);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (17,15,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (18,16,3.00);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (19,17,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (20,18,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (21,19,3.50);
insert into precosfilmes (idprecofilme, idfilme,  preco) values (22,20,3.00);

insert into clientes (idcliente, nome, sexo, datanascimento) values (1, 'Kenyo Crosara', 'M', '1980-02-25');
insert into clientes (idcliente, nome, sexo, datanascimento) values (2, 'Bruno Luiz', 'M', '1982-02-10');
insert into clientes (idcliente, nome, sexo, datanascimento) values (3, 'Lilian Xavier', 'F', '1979-02-16');
insert into clientes (idcliente, nome, sexo, datanascimento) values (4, 'Euler Stival', 'M', '1979-12-17');
insert into clientes (idcliente, nome, sexo, datanascimento) values (5, 'Donizete Aufredo', 'M', '1958-06-25');
insert into clientes (idcliente, nome, sexo, datanascimento) values (6, 'Aline Dayany ', 'F', '1983-07-09');
insert into clientes (idcliente, nome, sexo, datanascimento) values (7, 'Jacqueline Candida', 'F', '1981-08-19');
insert into clientes (idcliente, nome, sexo, datanascimento) values (8, 'Alberto Jesus', 'M', '1980-05-22');
insert into clientes (idcliente, nome, sexo, datanascimento) values (9, 'Marilene Xavier', 'F', '1984-01-02');
insert into clientes (idcliente, nome, sexo, datanascimento) values (10, 'Viviane Lemos', 'F', '1984-11-02');

insert into telefones (idtelefone, idcliente, numero) values (1, 1, '3333-4444');
insert into telefones (idtelefone, idcliente, numero) values (2, 1, '9787-4444');
insert into telefones (idtelefone, idcliente, numero) values (3, 2, '2341-4565');
insert into telefones (idtelefone, idcliente, numero) values (4, 3, '3578-4400');
insert into telefones (idtelefone, idcliente, numero) values (5, 3, '7634-4142');
insert into telefones (idtelefone, idcliente, numero) values (6, 4, '3867-3980');
insert into telefones (idtelefone, idcliente, numero) values (7, 8, '3321-2025');
insert into telefones (idtelefone, idcliente, numero) values (8,10, '3324-0101');
insert into telefones (idtelefone, idcliente, numero) values (9, 9, '3387-4929');
insert into telefones (idtelefone, idcliente, numero) values (10,6, '3328-0000');

insert into locacoes (idlocacao, idcliente, datalocacao) values (1, 1, '20130110');
insert into locacoes (idlocacao, idcliente, datalocacao) values (2, 1, '20130115');
insert into locacoes (idlocacao, idcliente, datalocacao) values (3, 1, '20130120');
insert into locacoes (idlocacao, idcliente, datalocacao) values (4, 2, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (5, 3, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (6, 4, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (7, 5, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (8, 6, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (9, 8, '20130203');
insert into locacoes (idlocacao, idcliente, datalocacao) values (10, 7, '20130521');
insert into locacoes (idlocacao, idcliente, datalocacao) values (11, 9, '20130520');
insert into locacoes (idlocacao, idcliente, datalocacao) values (12, 10, '20130524');
insert into locacoes (idlocacao, idcliente, datalocacao) values (13, 9, '20130524');
insert into locacoes (idlocacao, idcliente, datalocacao) values (14, 6, '20130524');

insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (1, 1, 1);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (2, 1, 2);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (3, 1, 3);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (4, 1, 4);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (5, 1, 1);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (6, 1, 1);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (7, 2, 7);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (8, 3, 8);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (9, 4, 10);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (10, 5, 9);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (11, 6, 3);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (12, 6, 2);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (13, 7, 1);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (14, 8, 2);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (15, 11, 13);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (16, 12, 14);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (17, 13, 15);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (18, 11, 16);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (19, 14, 17);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (20, 9, 18);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (21, 10, 19);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (22, 10, 20);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (23, 9, 21);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (24, 11, 22);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (25, 13, 18);
insert into itenslocacoes (iditemlocacao, idlocacao, idprecofilme) values (26, 12, 20);

--a)	 Selecione o nome do cliente e suas respectivas datas de locação que estão sem devolução

SELECT 
	clientes.nome,
	locacoes.datalocacao
FROM  clientes, locacoes
WHERE clientes.idcliente = locacoes.idcliente 

--b)	Retornar  a quantidade de telefones por cliente e ordene-os em ordem crescente

SELECT nome, COUNT (telefones.numero)
from clientes
INNER JOIN telefones on telefones.idcliente = clientes.idcliente
GROUP BY clientes.nome;

--c)	Retornar os clientes e sua respectiva data de nascimento se nasceram entre 01/01/1980 a 31/12/1989
SELECT
clientes.nome,
clientes.datanascimento
FROM clientes
WHERE clientes.datanascimento >= '01/01/1980' and clientes.datanascimento <= '31/12/1989'

--d)	Liste todos os clientes que não possuem telefone

SELECT 
	clientes.nome
FROM clientes, telefones
WHERE clientes.idcliente NOT IN (select telefones.idcliente from telefones); 

--e)	Selecione o nome do cliente, a data da locação e os filmes locados ordenem por nome de cliente.

SELECT 
 clientes.nome,
 locacoes.datalocacao,
 itenslocacoes.idlocacao
 FROM clientes, locacoes, itenslocacoes, precosfilmes, filmes
 WHERE clientes.idcliente = locacoes.idcliente  
 AND locacoes.idlocacao = itenslocacoes.idlocacao 
 AND precosfilmes.idprecofilme = itenslocacoes.idprecofilme
 AND precosfilmes.idfilme = filmes.idfilme
ORDER BY (clientes.idcliente);
 
 
