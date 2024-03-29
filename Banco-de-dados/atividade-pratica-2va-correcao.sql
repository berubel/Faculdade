CREATE TABLE funcionario (
    nome character varying(30) not null,
    inicial char,
    sobrenome character varying(30) not null,
    cpf character(9) not null,
    data_nasc date,
    endereco character varying(60),
    gen character(1),
    salario numeric(10,2),
    super_cpf character(9),
    dno integer not null default 1,
    primary key (cpf),
    foreign key (super_cpf) references funcionario(cpf) on delete set null on update cascade
);


CREATE TABLE departamento (
    dnome character varying(15) not null unique,
    dnumero integer not null primary key,
    chefia_cpf character(9) not null default '888665555',
    chefia_inicio date,
    foreign key (chefia_cpf) references funcionario(cpf) on delete set default on update cascade
);


alter table funcionario add constraint func_depart_fkey foreign key (dno) references departamento(dnumero) on delete set default on update cascade;


CREATE TABLE dept_locais (
    dnumero integer,
    dlocal character varying(15),
    constraint dept_locais_pkey primary key (dnumero, dlocal),
    constraint dept_locais_fkey foreign key (dnumero) references departamento(dnumero) on delete cascade on update cascade
);

CREATE TABLE projeto (
    pnome character varying(18) not null,
    pnumero integer not null primary key,
    plocal character varying(15),
    dnum integer not null default 1 references departamento(dnumero) on delete set default on update cascade,
    unique (pnome)
);

CREATE TABLE func_proj (
    cpf character(9) not null references funcionario(cpf) on delete cascade on update cascade,
    pno integer not null references projeto(pnumero) on delete cascade on update cascade,
    horas numeric(3,1) not null,
    primary key (cpf, pno)
);

CREATE TABLE dependente (
    cpf character(9) NOT NULL references funcionario(cpf) on delete cascade on update cascade,
    nome character varying(15) NOT NULL,
    gen character(1),
    data_nasc date,
    parentesco varchar(8),
    primary key (cpf, nome)
);


alter table funcionario alter column dno drop not null;

INSERT INTO funcionario VALUES 
  ('James','E','Borg','888665555','10-NOV-27','450 Stone, Houston, TX','M',55000,null,null);
INSERT INTO funcionario VALUES 
  ('Franklin','T','Wong','333445555','08-DEC-45','638 Voss, Houston, TX','M',40000,'888665555',null);
INSERT INTO funcionario VALUES 
  ('Jennifer','S','Wallace','987654321','20-JUN-31','291 Berry, Bellaire, TX','F',43000,'888665555',null);
INSERT INTO funcionario VALUES
  ('Jared','D','James','111111100','10-OCT-1966','123 Peachtree, Atlanta, GA','M',85000,null,null);
INSERT INTO funcionario VALUES
  ('Alex','D','Freed','444444400','09-OCT-1950','4333 Pillsbury, Milwaukee, WI','M',89000,null,null);
INSERT INTO funcionario VALUES
  ('John','C','James','555555500','30-JUN-1975','7676 Bloomington, Sacramento, CA','M',81000,null,null);




INSERT INTO departamento VALUES ('Research', 5, '333445555', '22-MAY-78');
INSERT INTO departamento VALUES ('Administration', 4, '987654321', '01-JAN-85');
INSERT INTO departamento VALUES ('Headquarters', 1, '888665555', '19-JUN-71');
INSERT INTO departamento VALUES ('Software',6,'111111100','15-MAY-1999');
INSERT INTO departamento VALUES ('Hardware',7,'444444400','15-MAY-1998');
INSERT INTO departamento VALUES ('Sales',8,'555555500','01-JAN-1997');


UPDATE funcionario SET dno = 5 WHERE cpf = '333445555';
UPDATE funcionario SET dno = 4 WHERE cpf = '987654321';
UPDATE funcionario SET dno = 1 WHERE cpf = '888665555';
UPDATE funcionario SET dno = 6 WHERE cpf = '111111100';
UPDATE funcionario SET dno = 7 WHERE cpf = '444444400';
UPDATE funcionario SET dno = 6 WHERE cpf = '555555500';

alter table funcionario alter column dno set not null;

INSERT INTO funcionario VALUES 
  ('John','B','Smith','123456789','09-Jan-55','731 Fondren, Houston, TX','M',30000,'333445555',5);
INSERT INTO funcionario VALUES 
  ('Alicia','J','Zelaya','999887777','19-JUL-58','3321 Castle, Spring, TX','F',25000,'987654321',4);
INSERT INTO funcionario VALUES 
  ('Ramesh','K','Narayan','666884444','15-SEP-52','971 Fire Oak, Humble, TX','M',38000,'333445555',5);
INSERT INTO funcionario VALUES 
  ('Joyce','A','English','453453453','31-JUL-62','5631 Rice Oak, Houston, TX','F',25000,'333445555',5);
INSERT INTO funcionario VALUES 
  ('Ahmad','V','Jabbar','987987987','29-MAR-59','980 Dallas, Houston, TX','M',25000,'987654321',4);
insert into funcionario values
  ('Jon','C','Jones','111111101','14-NOV-1967','111 Allgood, Atlanta, GA','M',45000,'111111100',6);
insert into funcionario values
  ('Justin',null,'Mark','111111102','12-JAN-1966','2342 May, Atlanta, GA','M',40000,'111111100',6);
insert into funcionario values
  ('Brad','C','Knight','111111103','13-FEB-1968','176 Main St., Atlanta, GA','M',44000,'111111100',6);
insert into funcionario values
  ('Evan','E','Wallis','222222200','16-JAN-1958','134 Pelham, Milwaukee, WI','M',92000,null,7);
insert into funcionario values
  ('Josh','U','Zell','222222201','22-MAY-1954','266 McGrady, Milwaukee, WI','M',56000,'222222200',7);
insert into funcionario values
  ('Andy','C','Vile','222222202','21-JUN-1944','1967 Jordan, Milwaukee, WI','M',53000,'222222200',7);
insert into funcionario values
  ('Tom','G','Brand','222222203','16-DEC-1966','112 Third St, Milwaukee, WI','M',62500,'222222200',7);
insert into funcionario values
  ('Jenny','F','Vos','222222204','11-NOV-1967','263 Mayberry, Milwaukee, WI','F',61000,'222222201',7);
insert into funcionario values
  ('Chris','A','Carter','222222205','21-MAR-1960','565 Jordan, Milwaukee, WI','F',43000,'222222201',7);
insert into funcionario values
  ('Kim','C','Grace','333333300','23-OCT-1970','6677 Mills Ave, Sacramento, CA','F',79000,null,6);
insert into funcionario values
  ('Jeff','H','Chase','333333301','07-JAN-1970','145 Bradbury, Sacramento, CA','M',44000,'333333300',6);
insert into funcionario values
  ('Bonnie','S','Bays','444444401','19-JUN-1956','111 Hollow, Milwaukee, WI','F',70000,'444444400',7);
insert into funcionario values
  ('Alec','C','Best','444444402','18-JUN-1966','233 Solid, Milwaukee, WI','M',60000,'444444400',7);
insert into funcionario values
  ('Sam','S','Snedden','444444403','31-JUL-1977','987 Windy St, Milwaukee, WI','M',48000,'444444400',7);
insert into funcionario values
  ('Nandita','K','Ball','555555501','16-APR-1969','222 Howard, Sacramento, CA','M',62000,'555555500',6);
insert into funcionario values
  ('Bob','B','Bender','666666600','17-APR-1968','8794 Garfield, Chicago, IL','M',96000,null,8);
insert into funcionario values
  ('Jill','J','Jarvis','666666601','14-JAN-1966','6234 Lincoln, Chicago, IL','F',36000,'666666600',8);
insert into funcionario values
  ('Kate','W','King','666666602','16-APR-1966','1976 Boone Trace, Chicago, IL','F',44000,'666666600',8);
insert into funcionario values
  ('Lyle','G','Leslie','666666603','09-JUN-1963','417 Hancock Ave, Chicago, IL','M',41000,'666666601',8);
insert into funcionario values
  ('Billie','J','King','666666604','01-JAN-1960','556 Washington, Chicago, IL','F',38000,'666666603',8);
insert into funcionario values
  ('Jon','A','Kramer','666666605','22-AUG-1964','1988 Windy Creek, Seattle, WA','M',41500,'666666603',8);
insert into funcionario values
  ('Ray','H','King','666666606','16-AUG-1949','213 Delk Road, Seattle, WA','M',44500,'666666604',8);
insert into funcionario values
  ('Gerald','D','Small','666666607','15-MAY-1962','122 Ball Street, Dallas, TX','M',29000,'666666602',8);
insert into funcionario values
  ('Arnold','A','Head','666666608','19-MAY-1967','233 Spring St, Dallas, TX','M',33000,'666666602',8);
insert into funcionario values
  ('Helga','C','Pataki','666666609','11-MAR-1969','101 Holyoke St, Dallas, TX','F',32000,'666666602',8);
insert into funcionario values
  ('Naveen','B','Drew','666666610','23-MAY-1970','198 Elm St, Philadelphia, PA','M',34000,'666666607',8);
insert into funcionario values
  ('Carl','E','Reedy','666666611','21-JUN-1977','213 Ball St, Philadelphia, PA','M',32000,'666666610',8);
insert into funcionario values
  ('Sammy','G','Hall','666666612','11-JAN-1970','433 Main Street, Miami, FL','M',37000,'666666611',8);
insert into funcionario values
  ('Red','A','Bacher','666666613','21-MAY-1980','196 Elm Street, Miami, FL','M',33500,'666666612',8);

INSERT INTO projeto VALUES ('ProductX',1,'Bellaire',5);
INSERT INTO projeto VALUES ('ProductY',2,'Sugarland',5);
INSERT INTO projeto VALUES ('ProductZ',3,'Houston',5);
INSERT INTO projeto VALUES ('Computerization',10,'Stafford',4);
INSERT INTO projeto VALUES ('Reorganization',20,'Houston',1);
INSERT INTO projeto VALUES ('Newbenefits',30,'Stafford',4);
INSERT INTO projeto VALUES ('OperatingSystems',61,'Jacksonville',6);
INSERT INTO projeto VALUES ('DatabaseSystems',62,'Birmingham',6);
INSERT INTO projeto VALUES ('Middleware',63,'Jackson',6);
INSERT INTO projeto VALUES ('InkjetPrinters',91,'Phoenix',7);
INSERT INTO projeto VALUES ('LaserPrinters',92,'LasVegas',7);

INSERT INTO dept_locais VALUES (1,'Houston');
INSERT INTO dept_locais VALUES (4,'Stafford');
INSERT INTO dept_locais VALUES (5,'Bellaire');
INSERT INTO dept_locais VALUES (5,'Sugarland');
INSERT INTO dept_locais VALUES (5,'Houston');
INSERT INTO dept_locais VALUES (6,'Atlanta');
INSERT INTO dept_locais VALUES (6,'Sacramento');
INSERT INTO dept_locais VALUES (7,'Milwaukee');
INSERT INTO dept_locais VALUES (8,'Chicago');
INSERT INTO dept_locais VALUES (8,'Dallas');
INSERT INTO dept_locais VALUES (8,'Philadephia');
INSERT INTO dept_locais VALUES (8,'Seattle');
INSERT INTO dept_locais VALUES (8,'Miami');

INSERT INTO dependente VALUES ('333445555','Alice','F','05-APR-76','Daughter');
INSERT INTO dependente VALUES ('333445555','Theodore','M','25-OCT-73','Son');
INSERT INTO dependente VALUES ('333445555','Joy','F','03-MAY-48','Spouse');
INSERT INTO dependente VALUES ('987654321','Abner','M','29-FEB-32','Spouse');
INSERT INTO dependente VALUES ('123456789','Michael','M','01-JAN-78','Son');
INSERT INTO dependente VALUES ('123456789','Alice','F', '31-DEC-78','Daughter');
INSERT INTO dependente VALUES ('123456789','Elizabeth','F','05-MAY-57','Spouse');
INSERT INTO dependente VALUES ('444444400','Johnny','M','04-APR-1997','Son');
INSERT INTO dependente VALUES ('444444400','Tommy','M','07-JUN-1999','Son');
INSERT INTO dependente VALUES ('444444401','Chris','M','19-APR-1969','Spouse');
INSERT INTO dependente VALUES ('444444402','Sam','M','14-FEB-1964','Spouse');



INSERT INTO func_proj VALUES ('123456789',1, 32.5);
INSERT INTO func_proj VALUES ('123456789',2,  7.5);
INSERT INTO func_proj VALUES ('666884444',3, 40.0);
INSERT INTO func_proj VALUES ('453453453',1, 20.0);
INSERT INTO func_proj VALUES ('453453453',2, 20.0);
INSERT INTO func_proj VALUES ('333445555',2, 10.0);
INSERT INTO func_proj VALUES ('333445555',3, 10.0);
INSERT INTO func_proj VALUES ('333445555',10,10.0);
INSERT INTO func_proj VALUES ('333445555',20,10.0);
INSERT INTO func_proj VALUES ('999887777',30,30.0);
INSERT INTO func_proj VALUES ('999887777',10,10.0);
INSERT INTO func_proj VALUES ('987987987',10,35.0);
INSERT INTO func_proj VALUES ('987987987',30, 5.0);
INSERT INTO func_proj VALUES ('987654321',30,20.0);
INSERT INTO func_proj VALUES ('987654321',20,15.0);
INSERT INTO func_proj VALUES ('888665555',20,8.0);
INSERT INTO func_proj VALUES ('111111100',61,40.0);
INSERT INTO func_proj VALUES ('111111101',61,40.0);
INSERT INTO func_proj VALUES ('111111102',61,40.0);
INSERT INTO func_proj VALUES ('111111103',61,40.0);
INSERT INTO func_proj VALUES ('222222200',62,40.0);
INSERT INTO func_proj VALUES ('222222201',62,48.0);
INSERT INTO func_proj VALUES ('222222202',62,40.0);
INSERT INTO func_proj VALUES ('222222203',62,40.0);
INSERT INTO func_proj VALUES ('222222204',62,40.0);
INSERT INTO func_proj VALUES ('222222205',62,40.0);
INSERT INTO func_proj VALUES ('333333300',63,40.0);
INSERT INTO func_proj VALUES ('333333301',63,46.0);
INSERT INTO func_proj VALUES ('444444400',91,40.0);
INSERT INTO func_proj VALUES ('444444401',91,40.0);
INSERT INTO func_proj VALUES ('444444402',91,40.0);
INSERT INTO func_proj VALUES ('444444403',91,40.0);
INSERT INTO func_proj VALUES ('555555500',92,40.0);
INSERT INTO func_proj VALUES ('555555501',92,44.0);
INSERT INTO func_proj VALUES ('666666601',91,40.0);
INSERT INTO func_proj VALUES ('666666603',91,40.0);
INSERT INTO func_proj VALUES ('666666604',91,40.0);
INSERT INTO func_proj VALUES ('666666605',92,40.0);
INSERT INTO func_proj VALUES ('666666606',91,40.0);
INSERT INTO func_proj VALUES ('666666607',61,40.0);
INSERT INTO func_proj VALUES ('666666608',62,40.0);
INSERT INTO func_proj VALUES ('666666609',63,40.0);
INSERT INTO func_proj VALUES ('666666610',61,40.0);
INSERT INTO func_proj VALUES ('666666611',61,40.0);
INSERT INTO func_proj VALUES ('666666612',61,40.0);
INSERT INTO func_proj VALUES ('666666613',61,30.0);
INSERT INTO func_proj VALUES ('666666613',62,10.0);
INSERT INTO func_proj VALUES ('666666613',63,10.0);

-- a) Liste o nome de todos os funcinários do departamento 5 que trabalham mais de 10 hs no projeto "DatabaseSystems"

SELECT * FROM projeto p WHERE p.pnome = 'DatabaseSystems'

SELECT * FROM projeto p INNER JOIN func_proj fp ON fp.pno = p.pnumero WHERE p.pnome = 'DatabaseSystems'

SELECT * FROM projeto p 
INNER JOIN func_proj fp ON fp.pno = p.pnumero 
WHERE p.pnome = 'DatabaseSystems' AND fp.horas > 10

SELECT nome, dno FROM funcionario

-- Resposta
SELECT 
	f.nome || ' ' || f.sobrenome as nome_compl,
	f.dno as departamento
FROM projeto p 
INNER JOIN func_proj fp ON fp.pno = p.pnumero 
INNER JOIN funcionario f ON f.cpf = fp.cpf 
WHERE 
	p.pnome = 'DatabaseSystems'
	AND fp.horas > 10
	AND f.dno = 5

-- b) Liste o nome de todos os funcionários que são supervisionados diretamente por 
-- "James Borg"

SELECT fs.* FROM funcionario fs WHERE fs.nome = 'James' AND fs.sobrenome = 'Borg'

-- Respostas
SELECT f.* FROM funcionario fs 
INNER JOIN funcionario f ON f.super_cpf = fs.cpf
WHERE fs.nome = 'James' AND fs.sobrenome = 'Borg'

-- c) Para cada projeto liste o nome do projeto e o total de horas (todos os funcionários) 
-- gastos no projeto

SELECT * FROM func_proj

SELECT SUM(fp.horas) FROM func_proj fp

SELECT fp.pno, SUM(fp.horas) FROM func_proj fp GROUP BY fp.pno

SELECT fp.pno, SUM(fp.horas) FROM func_proj fp GROUP BY fp.pno ORDER BY fp.pno DESC

-- Resposta

SELECT fp.pno, p.pnome, SUM(fp.horas) FROM func_proj fp 
INNER JOIN projeto  p ON p.pnumero = fp.pno 
GROUP BY fp.pno,  p.pnome
ORDER BY p.pnome DESC

-- d) Recuperar o nome de todos os funcionarios que trabalham em cada projeto

SELECT p.pnome, f.nome || ' ' || f.sobrenome AS nome  FROM func_proj fp 
INNER JOIN projeto  p ON p.pnumero = fp.pno 
INNER JOIN funcionario f ON f.cpf = fp.cpf
ORDER BY p.pnome

-- e) Recupere o número e nome de todos os projetos que envolvam o funcionário “James Borg”, 
-- como integrante ou como gerente 

SELECT p.pnumero, p.pnome FROM projeto p 

SELECT p.pnumero, p.pnome FROM projeto p 
INNER JOIN func_proj fp ON fp.pno = p.pnumero --integrante
INNER JOIN funcionario f ON f.cpf = fp.cpf
WHERE f.nome = 'James' AND f.sobrenome = 'Borg'

SELECT * FROM projeto p 
INNER JOIN departamento d ON p.dnum = d.dnumero
INNER JOIN funcionario f ON f.cpf = d.chefia_cpf
WHERE f.nome = 'James' AND f.sobrenome = 'Borg'



-- Resposta
SELECT p.pnumero, p.pnome FROM projeto p 
INNER JOIN func_proj fp ON fp.pno = p.pnumero --integrante
INNER JOIN funcionario f ON f.cpf = fp.cpf
WHERE f.nome = 'James' AND f.sobrenome = 'Borg'
	UNION 
SELECT p.pnumero, p.pnome FROM projeto p 
INNER JOIN departamento d ON p.dnum = d.dnumero
INNER JOIN funcionario f ON f.cpf = d.chefia_cpf
WHERE f.nome = 'James' AND f.sobrenome = 'Borg'

-- f) Recupere o nome e CPF dos funcionários que não possuem dependentes

--Opção 1
SELECT f.nome, f.cpf FROM funcionario f 
LEFT JOIN dependente dp ON dp.cpf = f.cpf
WHERE dp.cpf IS NULL
--Opção 2
SELECT * FROM funcionario WHERE cpf NOT IN (SELECT cpf FROM dependente GROUP BY cpf)