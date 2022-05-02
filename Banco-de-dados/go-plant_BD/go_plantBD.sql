-- GO PLANT Integrantes:
-- 2011475 - Ana Beatriz Ferreira Pessoa
-- 2011138 - Cedric Arnaud Sagang Pfembi
-- 2010840 - Gabriele Cardoso das Virgens
-- 2010012 - Gustavo Alves Cardoso Segantini
-- 2011321 - João Cândido de Jesus Neto
-- 2020033 - Jorge Luis Ribeiro Neto
-- 1810096 - Natal Junio Barbosa de Sousa
-- 2011671 - Sérgio Glésio de Oliveira Júnior

--CRIANDO BASE DE DADOS -----------------------------------
CREATE DATABASE GOPlant_BD;
SET search_path = 'GOPlant_BD';
-----------------------------------------------------------

-- Query de criação das tabelas 

CREATE TABLE Usuarios(
	ID_usuario INT PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	email VARCHAR(200) NOT NULL,
	cpf CHAR(11) UNIQUE NOT NULL,
	senha VARCHAR(200) NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN
);

CREATE TABLE Plantas (
	ID_planta INT PRIMARY KEY, 
	nome VARCHAR(255) NOT NULL,
	imagem VARCHAR(255)  NOT NULL,
	descricao TEXT  NOT NULL,
	data_cadastro DATE  DEFAULT CURRENT_DATE NOT NULL
);

CREATE TABLE Tipos(
	ID_tipo INT PRIMARY KEY ,
	nome VARCHAR (255) NOT NULL
);

CREATE TABLE Tipos_has_Plantas(
	ID_tipo_has_plantas INT PRIMARY KEY,
	FK_planta INT NOT NULL,
	FK_tipo INT NOT NULL,
	FOREIGN KEY (FK_planta) REFERENCES Plantas (ID_planta),
	FOREIGN KEY (FK_tipo) REFERENCES Tipos (ID_tipo)
);

CREATE TABLE Cultivos(
	ID_cultivo INT PRIMARY KEY,
	data_inicio DATE NOT NULL,
	data_termino DATE,
	FK_tipo_has_plantas INT NOT NULL,
	FOREIGN KEY (FK_tipo_has_plantas) REFERENCES Tipos_has_Plantas (ID_tipo_has_plantas)
);

CREATE TABLE Cuidados(
	ID_cuidado INT PRIMARY KEY,
	nome VARCHAR(255) NOT NULL
);

CREATE TABLE Plantas_has_Cuidados(
	dias INT,
	obs TEXT,
	FK_planta INT NOT NULL,
	FK_cuidado INT NOT NULL,
	PRIMARY KEY(FK_planta, FK_cuidado),
	FOREIGN KEY (FK_planta) REFERENCES Plantas (ID_planta),
	FOREIGN KEY (FK_cuidado) REFERENCES Cuidados (ID_cuidado)
); 

CREATE TABLE Cronograma_Cuidado_Cultivos(
	data_tempo TIMESTAMP NOT NULL,
	FK_cultivo INT NOT NULL,
	FK_cuidado INT NOT NULL,
	PRIMARY KEY(FK_cultivo, FK_cuidado), 
	FOREIGN KEY (FK_cultivo) REFERENCES Cultivos (ID_cultivo),
	FOREIGN KEY (FK_cuidado) REFERENCES Cuidados (ID_cuidado)
);

CREATE TABLE Etapas(
	ID_etapa INT PRIMARY KEY,
	fases_plantio VARCHAR(255) NOT NULL
);

CREATE TABLE Tempo_Etapa_Plantas(
	tempo INT NOT NULL,
	obs VARCHAR NOT NULL,
	FK_etapa INT NOT NULL,
	FK_planta INT NOT NULL,
	PRIMARY KEY(FK_etapa, FK_planta), 
	FOREIGN KEY (FK_etapa) REFERENCES Etapas (ID_etapa),
	FOREIGN KEY (FK_planta) REFERENCES Plantas (ID_planta)
);




-- Query de inserção de dados

INSERT INTO Usuarios (id_usuario, cpf, nome, email, senha, status)
	VALUES (1, '99988877722', 'Gabriele Cardoso das Virgens', 'pompom@gmail.com', 'po125mPO*', 'true');
INSERT INTO Usuarios (id_usuario, cpf, nome, email, senha, status)
	VALUES (2, '62986845123', 'Cedric Arnaud', 'james@gmail.com', 'pa111mPO*', 'true');	
INSERT INTO Usuarios (id_usuario, cpf, nome, email, senha, status)
	VALUES (3, '61897865589', 'João cândido', 'joao@gmail.com', '1235jo*', 'true');
INSERT INTO Usuarios (id_usuario, cpf, nome, email, senha, status)
	VALUES (4, '51895466889', 'Gustavo', 'gustavo@gmail.com', 'gust03O*', 'true');	
	
	
INSERT INTO Plantas (ID_planta, nome, imagem, descricao)
	VALUES (1, 'laranja','','A laranja é o fruto da laranjeira, uma árvore da família Rutaceae'),
		   (2, 'banana','','Banana é uma pseudobaga da bananeira, uma planta herbácea vivaz acaule da família Musaceae'),
		   (3, 'feijao','','Feijão é um nome comum para uma grande variedade de sementes de plantas de alguns gêneros da família Fabaceae'),
		   (4, 'tomate','','O tomate é o fruto do tomateiro (Solanum lycopersicum; Solanaceae). Da sua família, fazem também parte as berinjelas, as pimentas e os pimentões'),
		   (5, 'alface','','A alface é uma verdura originária do leste do Mediterrâneo, sendo utilizada na alimentação há muito tempo, desde 500 a.C'),
		   (6, 'beterraba','','A beterraba é uma raiz tuberosa típica de climas temperados');
		
INSERT INTO Tipos (ID_tipo, nome) 
	VALUES (1,'Frutas'),
		   (2,'Verduras'),
		   (3,'Legumes');
		   
INSERT INTO Tipos_has_Plantas (ID_tipo_has_plantas, FK_planta, FK_tipo) 
	VALUES (1, 1, 1),
		   (2, 2, 1),
		   (3, 3, 3),
		   (4, 4, 3),
		   (5, 5, 2);
		   
INSERT INTO Cultivos (id_cultivo, data_inicio, data_termino, FK_tipo_has_plantas, fk_usuario)
	VALUES (1, '03/04/2022', '05/05/2022', 1, 1),
		   (2, '03/04/2022', '05/05/2022', 2, 1),
		   (3, '03/04/2022', '05/05/2022', 3, 1),
		   (4, '03/04/2022', '05/05/2022', 4, 1),
		   (5, '03/04/2022', '05/05/2022', 5, 1);

INSERT INTO Cuidados (id_cuidado, nome)
	VALUES (1, 'Regar'),
		   (2, 'Controle de pragas'),
		   (3, 'Adubagem');
		  
INSERT INTO Plantas_has_Cuidados(dias, obs, fk_planta, fk_cuidado)
	VALUES (2, 'Por semana', 1, 1),
		   (3, 'Por semana', 2, 1),
		   (1, 'Por semana', 3, 1),
		   (5, 'Por semana', 4, 1),
		   (4, 'Por semana', 5, 1);
		  
INSERT INTO Cronograma_Cuidado_Cultivos (data_tempo,fk_cuidado,fk_cultivo)
	VALUES ('03/04/2022 10:05:06', 1, 1),
		   ('05/04/2022 11:30:06', 3, 3),
		   ('05/04/2022 11:30:06', 1, 4),
		   ('03/04/2022 11:30:06', 2, 5);
		   
INSERT INTO Etapas (id_etapa, fases_plantio)
	VALUES (1, 'Germinação'),
	 	   (2, 'Maturação'),
		   (3, 'Colheita');
		   
INSERT INTO Tempo_Etapa_Plantas(fk_etapa, fk_planta, tempo, obs)
	VALUES (1, 1, 30, 'dias'),
	 	   (2, 1, 15, 'dias'),
		   (3, 1, 5, 'dias');
		   
		   
-- Query de alteração das tabelas
ALTER TABLE Cultivos ADD COLUMN FK_usuario INT; --adiciona coluna idCidade para relacionar com a tabela cidades
		ALTER TABLE Cultivos
		ADD CONSTRAINT FK_usuario FOREIGN KEY (FK_usuario) REFERENCES Usuarios(ID_usuario);



SELECT * FROM Usuarios;
SELECT * FROM Plantas;
SELECT * FROM Tipos;
SELECT * FROM Tipos_has_Plantas;
SELECT * FROM Cultivos;
SELECT * FROM Cronograma_Cuidado_Cultivos;
SELECT * FROM Plantas_has_Cuidados; 
SELECT * FROM Cuidados;
SELECT * FROM Etapas;
SELECT * FROM Tempo_Etapa_Plantas;

--Query de visualização de dados

SELECT * FROM Usuarios;
SELECT * FROM Plantas;
SELECT * FROM Tipos;
SELECT * FROM Tipos_has_Plantas;
SELECT * FROM Cultivos;
SELECT * FROM Cronograma_Cuidado_Cultivos;
SELECT * FROM Plantas_has_Cuidados; 
SELECT * FROM Cuidados;
SELECT * FROM Etapas;
SELECT * FROM Tempo_Etapa_Plantas;

--Seleciona informações relacionadas ao cultivo
SELECT 
	Plantas.nome,
	Tipos.nome,
	Cultivos.data_inicio,
	Cultivos.data_termino,
	Cuidados.nome,
	Cronograma_Cuidado_Cultivos.data_tempo
FROM Plantas, Tipos, Cronograma_Cuidado_Cultivos, Cultivos, Tipos_has_Plantas, Cuidados
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Cultivos.FK_tipo_has_plantas
	AND Tipos_has_Plantas.FK_planta = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Cronograma_Cuidado_Cultivos.FK_cuidado = Cuidados.ID_cuidado
	AND Cronograma_Cuidado_Cultivos.FK_cultivo = Cultivos.ID_cultivo;

-- Seleciona nome e tipo das plantas do tipo 1(fruta)
SELECT 
	Plantas.nome,
	Tipos.nome

FROM Plantas, Tipos, Tipos_has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 1;
	
-- Seleciona nome e tipo das plantas do tipo 2 (verdura)	
SELECT 
	Plantas.nome,
	Tipos.nome

FROM Plantas, Tipos, Tipos_has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 2;
	
-- Seleciona nome e tipo das plantas do tipo 3 (legumes)	
SELECT 
	Plantas.nome,
	Tipos.nome

FROM Plantas, Tipos, Tipos_has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 3;

--Seleciona os cuidados básicos das plantas
SELECT 
	Plantas.nome,
	Tipos.nome,
	Cuidados.nome,
	Plantas_has_Cuidados.dias,
	Plantas_has_Cuidados.obs
FROM Plantas, Tipos, Tipos_has_Plantas, Cuidados, Plantas_has_Cuidados
WHERE
	Tipos_has_Plantas.FK_planta = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Plantas_has_Cuidados.FK_cuidado = Cuidados.ID_cuidado
	AND Plantas_has_Cuidados.FK_planta = Plantas.ID_planta;
	
--Seleciona nome da planta e seu tipo	
SELECT 
	t.nome,
	p.nome
FROM Tipos_has_Plantas tp
INNER JOIN  Plantas p ON tp.ID_tipo_has_plantas = p.ID_planta
INNER JOIN  Tipos t ON tp.FK_tipo = t.ID_tipo;

--Seleciona nome da planta e as informações das suas fases de plantio
SELECT 
	p.nome,
	e.fases_plantio,
	t.tempo,
	t.obs
FROM Tempo_Etapa_Plantas t
INNER JOIN  Plantas p ON t.FK_planta = p.ID_planta
INNER JOIN  Etapas e ON t.FK_etapa = e.ID_etapa; 

--Seleciona plantas que não fazem parte da tabela de cultivos do usuário
SELECT * FROM Plantas 
WHERE Plantas.ID_planta NOT IN (select FK_tipo_has_plantas from Cultivos); 
	


--**Query de funções de agrupamento, agregação e ordenação de dados** ----

--Seleção do total de registros de determinada tabela
SELECT COUNT(*) FROM Cultivos;

--Seleção total ocorrências de determinados dados em alguma tabelas agrupados
SELECT COUNT(data_tempo) FROM Cronograma_Cuidado_Cultivos;
SELECT COUNT(id_etapa) FROM Etapas WHERE fases_plantio = 'Maturação';

--Seleção retornando soma de determinados valores
SELECT SUM(id_usuario) FROM Usuarios WHERE email = 'pompom@gmail.com'; 
SELECT SUM(id_cuidado) FROM Cuidados;

--Seleção retornando media de determinados valores
SELECT AVG(tempo) FROM Tempo_Etapa_Plantas;
SELECT AVG(id_cuidado) FROM Cuidados;

--Seleção retornando o valor máximo de determinados valores
SELECT MAX(tempo) FROM Tempo_Etapa_Plantas;
SELECT MAX(dias) FROM Plantas_has_Cuidados;

--Seleção de registros em ordem crescente
SELECT 	nome FROM Usuarios ORDER BY nome ASC; 
SELECT  dias FROM Plantas_has_Cuidados ORDER BY dias ASC;

--Seleção de em ordem decrescente
SELECT 	nome FROM Tipos ORDER BY nome DESC; 
SELECT  dias FROM Plantas_has_Cuidados ORDER BY dias DESC;

