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

CREATE TABLE Temporadas(
	ID_temporada INT PRIMARY KEY,
	nome VARCHAR(255) NOT NULL
);

CREATE TABLE Temporadas_Has_Plantas(
	FK_temporada INT NOT NULL,
	FK_planta INT NOT NULL,
	PRIMARY KEY(FK_temporada, FK_planta),
	FOREIGN KEY (FK_temporada) REFERENCES Temporadas (ID_temporada),
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
	VALUES 
		   (1, 'laranja','','A laranja é o fruto da laranjeira, uma árvore da família Rutaceae'),
		   (2, 'banana','','Banana é uma pseudobaga da bananeira, uma planta herbácea vivaz acaule da família Musaceae'),
		   (3, 'feijao','','Feijão é um nome comum para uma grande variedade de sementes de plantas de alguns gêneros da família Fabaceae'),
		   (4, 'tomate','','O tomate é o fruto do tomateiro (Solanum lycopersicum; Solanaceae). Da sua família, fazem também parte as berinjelas, as pimentas e os pimentões'),
		   (5, 'alface','','A alface é uma verdura originária do leste do Mediterrâneo, sendo utilizada na alimentação há muito tempo, desde 500 a.C'),
		   (6, 'beterraba','','A beterraba é uma raiz tuberosa típica de climas temperados');
		   (7, 'morango','', 'Morango é considerado, na linguagem vulgar, como o fruto vermelho do morangueiro, da família das rosáceas'),
		   (8, 'quiabo', '', 'O quiabo é uma hortaliça muito utilizada na cozinha tradicional africana, asiática e latino-americana mas, aos poucos, o seu sabor delicado e a boa aparência estão encontrando o merecido espaço na cozinha dos grandes chefs.'),
		   (9, 'melancia', '', 'Melancia é uma planta da família Cucurbitaceae e do seu fruto. Trata-se de uma trepadeira rastejante originária da África.'),
		   (10, 'couve', '', 'Couve é o nome vulgar, genérico, das diversas variedades cultivares da espécie Brassica oleracea L., da família das Brassicaceae, a que também pertence o nabo e a mostarda'),
		   (11, 'acelga', '', 'A beterraba branca ou acelga portuguesa é uma hortaliça que apresenta talos longos e firmes e folhas baças ou brilhantes, com coloração verde ou avermelhada.'),
		   (12, 'espinafre', '', 'O espinafre (Tetragonia tetragonoides) é um vegetal de folhas verde-escuras que teve origem na Pérsia. Ele ficou bastante conhecido no mundo todo por ser responsável pela força do marinheiro Popeye nos desenhos'),
		   (13, 'abóbora', '', 'Abóbora ou jerimum, fruto da aboboreira, é uma designação popular atribuída a diversas espécies de plantas da família Cucurbitaceae'),
		   (14, 'pimentão', '', 'Pimentão ou pimento refere-se a um grupo de cultivares da espécie Capsicum annuum, muito utilizado na culinária de todo o mundo.'),
		   (15, 'repolho', '', 'O repolho é um vegetal pertencente ao gênero Brassica, o mesmo do brócolis, da couve-flor e da couve. Ele é encontrado nas cores vermelho, roxo, branco e verde, e suas folhas podem ser enrugadas ou lisas.'),
		   (16, 'cenoura', '', 'Daucus carota subsp. sativus popularmente conhecido como cenoura, é uma planta da família das apiáceas conhecida e apreciada desde a época dos antigos gregos e romanos. '),
		   (17, 'uva', '', 'A uva é o fruto da videira, uma planta da família das Vitaceae. É utilizada frequentemente para produzir sumo, doce, vinho e passas, podendo também ser consumida ao natural.'),
		   (18, 'brócolis', '', 'O brócolis é uma hortaliça pertencente à família Brassicácea, mesma família da couve, do repolho e da couve-flor. É um alimento muito conhecido pelos brasileiros, sendo um componente habitual da dieta de várias pessoas.'),
		   (19, 'aipo', '', 'O salsão, aipo ou salsa em ponto grande é uma planta aromática comestível da família das apiáceas.'),
		   (20, 'batata', '', 'Batata, batata-inglesa, batatinha, pataca, escorva, papa, ou semilha é uma planta perene da família das solanáceas. '),
		   (21, 'maçã', '', 'A maçã é o pseudofruto pomáceo da macieira, árvore da família Rosaceae. É um dos pseudofrutos de árvore mais cultivados.'),
		   (22, 'pêra', '', 'A pera é uma fruta de sabor suave e doce, com um centro fibroso. Com baixo valor calórico, é rica em vitaminas, antioxidantes essenciais, compostos vegetais e sais minerais'),
		   (23, 'mamão', '', 'Carica papaya é uma espécie de fruteira tropical que produz os frutos conhecidos pelos nomes comerciais de papaia ou ababaia, ou mamão.'),
		   (24, 'chuchu', '', 'Sechium edule é uma planta da família Curcubitaceae cujo fruto é uma hortaliça conhecida pelos nomes comuns de chuchu, machucho, caiota e pimpinela.'),
		   (25, 'limão', '', 'O limão-siciliano é o fruto de uma pequena árvore de folha perene originária da região sudeste da Ásia, da família das rutáceas.');
		   
INSERT INTO Tipos (ID_tipo, nome) 
	VALUES (1,'Frutas'),
		   (2,'Verduras'),
		   (3,'Legumes');
		   
INSERT INTO Tipos_has_Plantas (ID_tipo_has_plantas, FK_planta, FK_tipo) 
	VALUES (1, 1, 1),
		   (2, 2, 1),
		   (3, 3, 3),
		   (4, 4, 3),
		   (5, 5, 2),
		   (6, 6, 2),
		   (7, 7, 1),
		   (8, 8, 3),
		   (9, 9, 1),
		   (10, 10, 2),
		   (11, 11, 2),
		   (12, 12, 2),
		   (13, 13, 3),
		   (14, 14, 3),
		   (15, 15, 2),
		   (16, 16, 3),
		   (17, 17, 1),
		   (18, 18, 2),
		   (19, 19, 2),
		   (20, 20, 3),
		   (21, 21, 1),
		   (22, 22, 1),
		   (23, 23, 1),
		   (24, 24, 3),
		   (25, 25, 1);
		   
INSERT INTO Cultivos (id_cultivo, data_inicio, data_termino, FK_tipo_has_plantas, fk_usuario)
	VALUES (1, '03/04/2022', '05/05/2022', 1, 1),
		   (2, '03/04/2022', '05/05/2022', 2, 1),
		   (3, '03/04/2022', '05/05/2022', 3, 1),
		   (4, '03/04/2022', '05/05/2022', 4, 1),
		   (5, '03/04/2022', '05/05/2022', 5, 1),
		   (6, '03/04/2022', '05/05/2022', 20, 2),
		   (7, '03/04/2022', '05/05/2022', 8, 2),
		   (8, '03/04/2022', '05/05/2022', 12, 3);

INSERT INTO Cuidados (ID_cuidado, nome)
	VALUES (1, 'Regar'),
		   (2, 'Controle de pragas'),
		   (3, 'Adubagem');
		  
INSERT INTO Plantas_has_Cuidados(dias, obs, FK_planta, FK_cuidado)
	VALUES (2, 'Por semana', 1, 1),
		   (3, 'Por semana', 2, 1),
		   (1, 'Por semana', 3, 1),
		   (5, 'Por semana', 4, 1),
		   (4, 'Por semana', 5, 1),
		   (2, 'Por semana', 6, 1),
		   (3, 'Por semana', 7, 1),
		   (1, 'Por semana', 8, 1),
		   (5, 'Por semana', 9, 1),
		   (2, 'Por semana', 10, 1),
		   (3, 'Por semana', 11, 1),
		   (1, 'Por semana', 12, 1),
		   (5, 'Por semana', 13, 1),
		   (2, 'Por semana', 14, 1),
		   (3, 'Por semana', 15, 1),
		   (1, 'Por semana', 16, 1),
		   (5, 'Por semana', 17, 1),
		   (2, 'Por semana', 18, 1),
		   (3, 'Por semana', 19, 1),
		   (1, 'Por semana', 20, 1),
		   (5, 'Por semana', 21, 1),
		   (2, 'Por semana', 22, 1),
		   (3, 'Por semana', 23, 1),
		   (1, 'Por semana', 24, 1),
		   (5, 'Por semana', 25, 1);
		  
INSERT INTO Cronograma_Cuidado_Cultivos (data_tempo, FK_cuidado, FK_cultivo)
	VALUES 
		   ('03/04/2022 11:30:06', 1, 1),
		   ('03/04/2022 11:30:06', 3, 2),
		   ('03/04/2022 11:30:06', 2, 3),
		   ('03/04/2022 11:30:06', 1, 4),
		   ('03/04/2022 11:30:06', 3, 5),
		   ('03/04/2022 11:30:06', 1, 6),
		   ('03/04/2022 11:30:06', 3, 7),
		   ('03/04/2022 11:30:06', 2, 8);
		   
INSERT INTO Etapas (id_etapa, fases_plantio)
	VALUES (1, 'Germinação'),
	 	   (2, 'Maturação'),
		   (3, 'Colheita');
		   
INSERT INTO Tempo_Etapa_Plantas(FK_etapa, fk_planta, tempo, obs)
	VALUES (1, 1, 30, 'dias'),
	 	   (2, 1, 15, 'dias'),
		   (3, 1, 5, 'dias'),
		   (1, 2, 30, 'dias'),
	 	   (2, 2, 15, 'dias'),
		   (3, 2, 5, 'dias'),
		   (1, 3, 30, 'dias'),
	 	   (2, 3, 15, 'dias'),
		   (3, 3, 5, 'dias'),
		   (1, 4, 30, 'dias'),
	 	   (2, 4, 15, 'dias'),
		   (3, 4, 5, 'dias'),
		   (1, 5, 30, 'dias'),
	 	   (2, 5, 15, 'dias'),
		   (3, 5, 5, 'dias'),
		   (1, 6, 30, 'dias'),
	 	   (2, 6, 15, 'dias'),
		   (3, 6, 5, 'dias'),
		   (1, 7, 30, 'dias'),
	 	   (2, 7, 15, 'dias'),
		   (3, 7, 5, 'dias'),
		   (1, 8, 30, 'dias'),
	 	   (2, 8, 15, 'dias'),
		   (3, 8, 5, 'dias'),
		   (1, 9, 30, 'dias'),
	 	   (2, 9, 15, 'dias'),
		   (3, 9, 5, 'dias'),
		   (1, 10, 30, 'dias'),
	 	   (2, 10, 15, 'dias'),
		   (3, 10, 5, 'dias'),
		   (1, 11, 30, 'dias'),
	 	   (2, 11, 15, 'dias'),
		   (3, 11, 5, 'dias'),
		   (1, 12, 30, 'dias'),
	 	   (2, 12, 15, 'dias'),
		   (3, 12, 5, 'dias'),
		   (1, 13, 30, 'dias'),
	 	   (2, 13, 15, 'dias'),
		   (3, 13, 5, 'dias'),
		   (1, 14, 30, 'dias'),
	 	   (2, 14, 15, 'dias'),
		   (3, 14, 5, 'dias'),
		   (1, 15, 30, 'dias'),
	 	   (2, 15, 15, 'dias'),
		   (3, 15, 5, 'dias'),
		   (1, 16, 30, 'dias'),
	 	   (2, 16, 15, 'dias'),
		   (3, 16, 5, 'dias'),
		   (1, 17, 30, 'dias'),
	 	   (2, 17, 15, 'dias'),
		   (3, 17, 5, 'dias'),
		   (1, 18, 30, 'dias'),
	 	   (2, 18, 15, 'dias'),
		   (3, 18, 5, 'dias'),
		   (1, 19, 30, 'dias'),
	 	   (2, 19, 15, 'dias'),
		   (3, 19, 5, 'dias'),
		   (1, 20, 30, 'dias'),
	 	   (2, 20, 15, 'dias'),
		   (3, 20, 5, 'dias'),
		   (1, 21, 30, 'dias'),
	 	   (2, 21, 15, 'dias'),
		   (3, 21, 5, 'dias'),
		   (1, 22, 30, 'dias'),
	 	   (2, 22, 15, 'dias'),
		   (3, 22, 5, 'dias'),
		   (1, 23, 30, 'dias'),
	 	   (2, 23, 15, 'dias'),
		   (3, 23, 5, 'dias'),
		   (1, 24, 30, 'dias'),
	 	   (2, 24, 15, 'dias'),
		   (3, 24, 5, 'dias'),
		   (1, 25, 30, 'dias'),
	 	   (2, 25, 15, 'dias'),
		   (3, 25, 5, 'dias');

INSERT INTO Temporadas (ID_temporada, nome)
	VALUES (1, 'Primavera'),
		   (2, 'Verão'),
		   (3, 'Outono'),
		   (4, 'Inverno');
		   
INSERT INTO Temporadas_Has_Plantas (FK_temporada, FK_planta)
	VALUES (1, 1),
		   (1, 2),
		   (1, 3),
		   (1, 4),
		   (1, 5),
		   (2, 6),
		   (2, 7),
		   (2, 8),
		   (2, 9),
		   (2, 10),
		   (2, 11),
		   (2, 12),
		   (3, 13),
		   (3, 14),
		   (3, 15),
		   (3, 16),
		   (3, 17),
		   (3, 18),
		   (4, 19),
		   (4, 20),
		   (4, 21),
		   (4, 22),
		   (4, 23),
		   (4, 24),
		   (4, 25);
		   
-- Query de alteração das tabelas

ALTER TABLE Cultivos ADD COLUMN FK_usuario INT;
		ALTER TABLE Cultivos
		ADD CONSTRAINT FK_usuario FOREIGN KEY (FK_usuario) REFERENCES Usuarios(ID_usuario);
		
ALTER TABLE Plantas ADD COLUMN temperatura INT; 
ALTER TABLE Plantas ADD COLUMN agua_qtd INT; 

-- Query de atualização dos dados

UPDATE public.Plantas SET temperatura = 25;
UPDATE public.Plantas SET agua_qtd = 1;

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
SELECT * FROM Temporadas;
SELECT * FROM Temporadas_Has_Plantas;

--Seleciona informações relacionadas ao cultivo
SELECT 
	Usuarios.ID_usuario,
	Usuarios.nome,
	Plantas.nome,
	Tipos.nome,
	Temporadas.nome,
	Plantas.agua_qtd,
	Plantas.temperatura,
	Cultivos.data_inicio,
	Cultivos.data_termino,
	Cuidados.nome,
	Cronograma_Cuidado_Cultivos.data_tempo
FROM Plantas, Tipos, Cronograma_Cuidado_Cultivos, Cultivos, Tipos_has_Plantas, Cuidados, Usuarios, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Cultivos.FK_tipo_has_plantas
	AND Tipos_has_Plantas.FK_planta = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Cronograma_Cuidado_Cultivos.FK_cuidado = Cuidados.ID_cuidado
	AND Cronograma_Cuidado_Cultivos.FK_cultivo = Cultivos.ID_cultivo
	AND Cultivos.FK_usuario = Usuarios.ID_usuario
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta
ORDER BY Usuarios.ID_usuario ASC;

-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 1(fruta)
SELECT 
	Plantas.nome,
	Tipos.nome,
	Temporadas.nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 1
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	
	
-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 2 (verdura)	
SELECT 
	Plantas.nome,
	Tipos.nome,
	Temporadas.nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 2
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	
-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 3 (legumes)	
SELECT 
	Plantas.nome,
	Tipos.nome,
	Temporadas.nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 3
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;

--Seleciona os cuidados básicos das plantas
SELECT 
	Plantas.nome,
	Tipos.nome,
	Temporadas.nome,
	Cuidados.nome,
	Plantas_has_Cuidados.dias,
	Plantas_has_Cuidados.obs
FROM Plantas, Tipos, Tipos_has_Plantas, Cuidados, Plantas_has_Cuidados, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.FK_planta = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Plantas_has_Cuidados.FK_cuidado = Cuidados.ID_cuidado
	AND Plantas_has_Cuidados.FK_planta = Plantas.ID_planta
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	
--Seleciona nome da planta e seu tipo 	
SELECT 
	t.nome,
	p.nome
FROM Tipos_has_Plantas tp
INNER JOIN  Plantas p ON tp.ID_tipo_has_plantas = p.ID_planta
INNER JOIN  Tipos t ON tp.FK_tipo = t.ID_tipo
ORDER BY t.nome ASC;

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
SELECT COUNT(*) FROM Plantas;
SELECT COUNT(*) FROM Usuarios;

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

-- VIEWS

CREATE VIEW usuario_cultivo AS

--Seleciona informações relacionadas ao cultivo
SELECT 
	Usuarios.ID_usuario,
	Usuarios.nome as usuario_nome,
	Plantas.nome as planta_nome,
	Tipos.nome as tipo_nome,
	Temporadas.nome as temporada_nome,
	Plantas.agua_qtd,
	Plantas.temperatura,
	Cultivos.data_inicio,
	Cultivos.data_termino,
	Cuidados.nome as cuidado_nome,
	Cronograma_Cuidado_Cultivos.data_tempo
FROM Plantas, Tipos, Cronograma_Cuidado_Cultivos, Cultivos, Tipos_has_Plantas, Cuidados, Usuarios, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Cultivos.FK_tipo_has_plantas
	AND Tipos_has_Plantas.FK_planta = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Cronograma_Cuidado_Cultivos.FK_cuidado = Cuidados.ID_cuidado
	AND Cronograma_Cuidado_Cultivos.FK_cultivo = Cultivos.ID_cultivo
	AND Cultivos.FK_usuario = Usuarios.ID_usuario
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta
ORDER BY Usuarios.ID_usuario ASC;

CREATE VIEW inf_fruta AS

-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 1(fruta)
SELECT 
	Plantas.nome as planta_nome,
	Tipos.nome as tipo_nome,
	Temporadas.nome as temporada_nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 1
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	

CREATE VIEW inf_verdura AS

-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 2 (verdura)	
SELECT 
	Plantas.nome as planta_nome,
	Tipos.nome as tipo_nome,
	Temporadas.nome as temporada_nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 2
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	

CREATE VIEW inf_legumes AS

-- Seleciona nome, tipo, temporada, quantidade de água e temperatura das plantas do tipo 3 (legumes)	
SELECT 
	Plantas.nome as planta_nome,
	Tipos.nome as tipo_nome,
	Temporadas.nome as temporada_nome,
	Plantas.agua_qtd,
	Plantas.temperatura

FROM Plantas, Tipos, Tipos_has_Plantas, Temporadas, Temporadas_Has_Plantas
WHERE
	Tipos_has_Plantas.ID_tipo_has_plantas = Plantas.ID_planta
	AND Tipos_has_Plantas.FK_tipo = Tipos.ID_tipo
	AND Tipos_has_Plantas.FK_tipo = 3
	AND Temporadas_Has_Plantas.FK_temporada = Temporadas.ID_temporada
	AND Temporadas_Has_Plantas.FK_planta = Plantas.ID_planta;
	
--Seleciona todos os nomes e emails dos usuários ativos e ordena por ordem cresente
CREATE VIEW vw_usuarios AS
SELECT 
	nome, 
	email 
FROM Usuarios 
WHERE 
	status = 'true'
ORDER BY nome ASC;


--Altera a view adicionando a coluna cpf e seleciona nome, cpf e email dos usuários ativos
CREATE OR REPLACE VIEW vw_usuarios AS 
SELECT 
	nome, 
	email, 
	cpf 
FROM Usuarios 
WHERE 
	status = 'true'
ORDER BY nome ASC;

-- Seleciona todas as planatas em ordem crescente
CREATE VIEW vw_plantas AS 
SELECT 
	nome
FROM Plantas
ORDER BY nome ASC;

-- Drop view
DROP VIEW vw_usuarios;
	
-- SELECT VIEWS
SELECT * FROM usuario_cultivo;
SELECT * FROM inf_legumes;
SELECT * FROM inf_fruta;
SELECT * FROM inf_verdura;
SELECT * FROM vw_plantas;
SELECT * FROM vw_usuarios;

-- DTL

-- DTL para alterar data de plantio de um determinado cultivo do usuário

BEGIN; -- Iniciar Transação

UPDATE Cultivos SET data_inicio = '28/05/2022' 
	WHERE Cultivos.ID_cultivo = 1 
	AND Cultivos.FK_usuario = 1;

COMMIT; -- Efetivar
ROLLBACK; -- Cancelar

-- DTL para alterar o cronograma de um cuidado de um determinado cultivo do usuário

BEGIN; -- Iniciar Transação

UPDATE Cronograma_Cuidado_Cultivos SET data_tempo = '28/05/2022 11:30:06' 
	WHERE Cronograma_Cuidado_Cultivos.FK_cultivo = 1 
	AND Cronograma_Cuidado_Cultivos.FK_cuidado = 1;

COMMIT; -- Efetivar
ROLLBACK; -- Cancelar

-- DTL para alterar a temperatura e quantidade de água das plantas de um determinado tipo

BEGIN; -- Iniciar Transação

UPDATE Plantas SET temperatura = 20 
WHERE ID_planta IN (SELECT Tipos_has_Plantas.FK_planta 
					FROM Tipos_has_Plantas 
					WHERE Tipos_has_Plantas.FK_tipo = 1
				    AND Tipos_has_Plantas.FK_planta = Plantas.ID_planta);
					
UPDATE Plantas SET agua_qtd = 2
WHERE ID_planta IN (SELECT Tipos_has_Plantas.FK_planta 
					FROM Tipos_has_Plantas 
					WHERE Tipos_has_Plantas.FK_tipo = 1
					AND Tipos_has_Plantas.FK_planta = Plantas.ID_planta);
COMMIT; -- Efetivar
ROLLBACK; -- Cancelar

BEGIN; -- Iniciar Transação

-- DTL para alterar o nome de um usuário

UPDATE Usuarios SET nome = 'Cedric Arnaud Sagang Pfembi' WHERE nome = 'Cedric Arnaud' ; 

COMMIT; -- Efetivar
ROLLBACK; -- Cancelar




