CREATE DATABASE xpto_transports;

CREATE TABLE usuarios(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	email VARCHAR(200) NOT NULL,
	cpf CHAR(11) UNIQUE NOT NULL,
	senha VARCHAR(200) NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN
);

CREATE TABLE motoristas(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	cpf CHAR(11) UNIQUE NOT NULL,
	cat_cnh CHAR(2) NOT NULL,
	num_cnh varchar(50) UNIQUE,
	sexo CHAR(1) NOT NULL, -- M / F
	dt_nascimento DATE NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN DEFAULT TRUE
);

CREATE TABLE combustiveis(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN DEFAULT TRUE
);

CREATE TABLE veiculos(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	placa CHAR(7) UNIQUE NOT NULL,
	fabricante VARCHAR(200) NOT NULL,
	ano_fab SMALLINT NOT NULL,
	max_tanque INT NOT NULL,
	obs TEXT,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN DEFAULT TRUE
);

CREATE TABLE veiculo_combustiveis(
	id_veiculo INT,
	id_combustivel INT,
	
	CONSTRAINT pk_veiculo_combustiveis -- Nome da restrição
		PRIMARY KEY(id_veiculo, id_combustivel), -- Destino tabela(column)
	
	CONSTRAINT fk_veiculo -- Nome da restrição
		FOREIGN KEY(id_veiculo) -- Coluna local 
   			REFERENCES veiculos(id), -- Destino tabela(column)
	
	CONSTRAINT fk_combustivel -- Nome da restrição
		FOREIGN KEY(id_combustivel) -- Coluna local 
   			REFERENCES combustiveis(id) -- Destino tabela(column)
);

CREATE TABLE cidades(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	uf CHAR(2) NOT NULL
);

CREATE TABLE postos(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(200) NOT NULL,
	bandeira VARCHAR(200) NOT NULL,
	endereco VARCHAR(200),
	id_cidade INT NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN DEFAULT TRUE,
	
	CONSTRAINT fk_cidade -- Nome da restrição
		FOREIGN KEY(id_cidade) -- Coluna local 
   			REFERENCES cidades(id) -- Destino tabela(column)
);

CREATE TABLE abastecimentos(
	id SERIAL PRIMARY KEY,
	id_veiculo INT NOT NULL,
	id_motorista INT NOT NULL,
	id_combustivel INT NOT NULL,
	id_posto INT NOT NULL,
	data DATE NOT NULL,
	valor_litro FLOAT NOT NULL,
	quantidade FLOAT NOT NULL,
	id_usuario INT NOT NULL,
	dt_create DATE DEFAULT CURRENT_DATE NOT NULL,
	dt_update DATE,
	status BOOLEAN DEFAULT TRUE,
	
	CONSTRAINT fk_veiculo FOREIGN KEY(id_veiculo) REFERENCES veiculos(id),
	CONSTRAINT fk_motorista FOREIGN KEY(id_motorista) REFERENCES motoristas(id),
	CONSTRAINT fk_combustivel FOREIGN KEY(id_combustivel) REFERENCES combustiveis(id),
	CONSTRAINT fk_posto FOREIGN KEY(id_posto) REFERENCES postos(id),
	CONSTRAINT fk_usuario FOREIGN KEY(id_usuario) REFERENCES usuarios(id)
	
);



SELECT 
	m.nome
	m.cpf
	p.nome AS nome_posto,
	a.data AS data_abastecimento,
	a.quantidade,
	a.valor_litro,
	(a.valor_litro * a.quantidade) AS TOTAL,
	cb.nome
FROM abastecimentos a
INNER JOIN postos p ON a.id_posto = p.id --faz relação entre as duas tabelas
INNER JOIN cidades c ON p.id_cidade = c.id
INNER JOIN combustiveis cb ON a.id_combustivel = cb.id
INNER JOIN motoristas m ON a.id_motorista = m.id
INNER JOIN veiculos v ON a.id_veiculo = v.id
--WHERE a.id = 4


-- Motoristas Ativos
SELECT * FROM motoristas WHERE status = true

-- Atualizar determinados motoristas
UPDATE motoristas SET status = true WHERE id IN (24, 25, 26, 27)

-- Motoristas que não possuem abastecimentos
SELECT m.* FROM motoristas m
LEFT JOIN abastecimentos a ON a.id_motorista = m.id
WHERE 
a.id IS NULL


