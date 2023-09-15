create schema universidade;

-- criação das tabelas --

create table universidade.Professor (nome varchar(30), siape int, categoria varchar, salario real, cod_depto int
	CONSTRAINT ck_categoria CHECK (categoria::text = ANY (ARRAY['Adjunto II'::character varying, 'Adjunto I'::character varying, 'Assistente I'::character varying]::text[]))
);

create table universidade.Disciplina (nome varchar(30), cod_disciplina serial, carga_horaria int);

create table universidade.Departamento (nome_depto varchar(30), numero_depto serial);

create table universidade.Ministra (siape int, cod_disciplina int, periodo varchar(6));

-- criação das restrições de chave e chave estrangeira --

alter table universidade.Professor add constraint pk_prof primary key  (siape);

alter table universidade.Disciplina add constraint pk_disc primary key  (cod_disciplina);

alter table universidade.Departamento add constraint pk_dept primary key  (numero_depto);

alter table universidade.Ministra add constraint pk_min primary key  (siape, cod_disciplina, periodo);

alter table universidade.Professor add constraint fk_prof_dep foreign key (cod_depto) references universidade.Departamento(numero_depto);

alter table universidade.Ministra add constraint fk_min_prof foreign key (siape) references universidade.Professor(siape);

alter table universidade.Ministra add constraint fk_min_disc foreign key (cod_disciplina) references universidade.Disciplina(cod_disciplina);

-- inserções -- 
insert into universidade.Departamento (nome_depto) values ('Computação'), ('Sistemas de Informação'), ('Redes'), ('Eng. Computação'), ('Design Digital');

insert into universidade.Professor values
	('Ricardo Silva', 124, 'Adjunto I', 2000.00, 1),
	('João Fernando', 134, 'Adjunto II', 3000.00, 1),
	('Claudia Sales', 144, 'Adjunto II', 3000.00, 2),
	('Marcelo Antonio', 154, 'Adjunto I', 2000.00, 3),
	('Paulo Cesar', 164, 'Adjunto I', 2500.00, 4),
	('Cristina Oliveira', 174, 'Assistente I', 1500.00, 1),
	('Aparecida Souza', 184, 'Adjunto I', 2500.00, 5),
	('Joana Maria', 194, 'Adjunto I', 2500.00, 4),
	('Denis Maia', 204, 'Adjunto I', 2500.00, 5);

insert into universidade.Disciplina (nome , carga_horaria) values
	('Fundamentos de Bancos de Dados', 64),
	('Teoria da Computação', 64),
	('Autômatos e Linguagens Formais', 60),
	('Redes de alta velocidade', 86),
	('Mineração de Dados', 86),
	('Teoria Geral dos Sistemas', 30),
	('Programação para desing', 86),
	('Programação linear', 86);


insert into universidade.Ministra (siape , cod_disciplina, periodo) values
	(124, 1, '2013.1'),
	(124, 1, '2013.2'),
	(124, 1, '2014.1'),
	(134, 2, '2015.1'),
	(144, 3, '2015.1'),
	(154, 4, '2015.1'),
	(164, 5, '2015.1'),
	(174, 6, '2015.1'),
	(194, 7, '2015.1'),
	(204, 8, '2015.1');