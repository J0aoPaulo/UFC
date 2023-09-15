set schema 'bilheteria';

CREATE TABLE FILME(
	CODIGO SERIAL PRIMARY KEY,
	TITULO VARCHAR(100) NOT NULL,
	SINOPSE TEXT,
	DURACAO_MIN INTEGER NOT NULL,
	CLASSIFICACAO VARCHAR(10)	
);

CREATE TABLE SALA(
NUMERO SERIAL,
QTD_POLTRONAS INTEGER,
PRIMARY KEY(NUMERO)
);

CREATE TABLE POLTRONA(
NUMERO_SALA INTEGER,
COD_POLTRONA VARCHAR(3)	
);

ALTER TABLE POLTRONA
ADD CONSTRAINT poltrona_pk
PRIMARY KEY(NUMERO_SALA,COD_POLTRONA);

ALTER TABLE POLTRONA
ADD CONSTRAINT poltrona_sala_fk
FOREIGN KEY(NUMERO_SALA) 
REFERENCES SALA(NUMERO);

INSERT INTO SALA(QTD_POLTRONAS)
VALUES(20);

CREATE TABLE SESSAO(
COD_SESSAO SERIAL PRIMARY KEY,
DT DATE,
HORARIO INTEGER,
DIM CHAR(2),
LINGUAGEM VARCHAR(20),
SALA_NUM INTEGER,
FILME_ID INTEGER,
FOREIGN KEY (SALA_NUM)  REFERENCES SALA(NUMERO),
FOREIGN KEY (FILME_ID)  REFERENCES FILME(CODIGO),
UNIQUE(DT,HORARIO,SALA_NUM)
);

-- 1. Execute o comando para alterar a tabela Poltrona inserindo uma coluna extra e uma chave única.
ALTER TABLE POLTRONA
ADD COLLUMN idp INTEGER;

ALTER TABLE POLTRONA
ADD CONSTRAINT unk_idp unique(idp);

INSERT INTO FILME(TITULO, SINOPSE, DURACAO_MIN, CLASSIFICACAO)
VALUES 
('A Era do Gelo', 'Um grupo de animais pré-históricos tenta devolver um bebê humano à sua tribo enquanto fogem de um desastre natural.', 81, 'Livre'),
('A Era do Gelo 2', 'Os animais da Era do Gelo descobrem que precisam sobreviver a um derretimento de gelo e procuram um novo lar.', 91, 'Livre'),
('A Era do Gelo 3', 'Sid, Diego e Manny embarcam em uma aventura para salvar Sid e encontrar a mãe dos dinossauros.', 94, 'Livre'),
('A Era do Gelo 4', 'Manny, Diego e Sid navegam em busca de uma nova casa depois que um cataclismo destrói seu continente.', 88, 'Livre'),
('A Era do Gelo: O Big Bang', 'Manny, Diego, Sid e seus amigos tentam impedir que um meteoro atinja a Terra.', 94, 'Livre');

INSERT INTO SALA(QTD_POLTRONAS)
VALUES 
(100),
(150),
(80),
(120),
(200);

INSERT INTO POLTRONA(NUMERO_SALA, COD_POLTRONA, idp)
VALUES
(1, 'A1', 1),
(1, 'A2', 2),
(1, 'A3', 3),
(2, 'B1', 4),
(2, 'B2', 5);

INSERT INTO SESSAO(DT, HORARIO, DIM, LINGUAGEM, SALA_NUM, FILME_ID)
VALUES 
('2023-04-17', 15, '2D', 'Dublado', 1, 1),
('2023-04-17', 18, '3D', 'Legendado', 1, 2),
('2023-04-18', 14, '2D', 'Dublado', 2, 3),
('2023-04-18', 19, '3D', 'Legendado', 2, 4),
('2023-04-19', 21, '2D', 'Dublado', 3, 5);

-- 3. Use o comando SELECT * FROM NOME_TABELA para visualizar os dados inseridos em cada tabela.
select * from POLTRONA;
select * from FILME;
select * from SESSAO;
select * from SALA;

-- 4. Considere a tabela Bilhete(cod_sessao, id_poltrona, cod_bilhete)

-- As chaves estrangeira são c_sessao e idb_poltrona que 
-- se referem respectivamente a tabela sessao.cod_sessao e 
-- e POLTRONA.idp

-- 4.b Chaves candidatas da tabela Bilhete 

-- Quem são as chaves candidatas?
-- (id_poltrona, cod_sessao) -> Não existe poltronas iguais para uma mesma sessao.
-- (c_bilhete, cod_sessao) -> Não existe bilhetes igauis para uma mesma sessao.
-- (c_bilhete, id_poltrona) -> Não existe um mesmo bilhete para duas poltronas diferentes.

-- Tornando a chave candidata em primária
ALTER TABLE Bilhete
PRIMARY KEY (id_poltrona, cod_sessao) -- Não existem poltrona de id igual em uma mesma sessao

-- 4.C Crie a tabela Bilhete especificando as chaves primárias, estrangeiras e únicas.
CREATE TABLE Bilhete(
cod_sessao INTEGER,
id_poltrona INTEGER,
c_bilhete SERIAL UNIQUE,
PRIMARY KEY (id_poltrona, cod_sessao)
);

ALTER TABLE Bilhete
ADD CONSTRAINT cod_sessao_fk
FOREIGN KEY (cod_sessao) REFERENCES SESSAO (cod_sessao);

ALTER TABLE Bilhete
ADD CONSTRAINT id_poltrona_fk
FOREIGN KEY (id_poltrona) REFERENCES POLTRONA (idp);

SELECT * FROM Bilhete;

-- 4.D Insira 5 tuplas na tabela criada.

INSERT INTO Bilhete (cod_sessao, id_poltrona) 
VALUES 
(1, 1), 
(1, 2), 
(2, 3), 
(2, 5), 
(3, 2);

-- 5. Adicionando o atributo genero_filme no banco de dados
-- 5.a Crie uma tabela para permitir que o filme tenha inúmeros gêneros.

CREATE TABLE GENERO(
id_genero SERIAL PRIMARY KEY,
genero_filme VARCHAR(20)
);

INSERT INTO GENERO (genero_filme) 
VALUES 
('Ação'), ('Drama'), ('Aventura'), ('Comedia'), ('Romance');


-- 5.a  Crie uma tabela para permitir que o filme tenha inúmeros gêneros.
CREATE TABLE filme_genero(
id_filme INTEGER,
id_gen INTEGER
);

-- 5.b Como é o esquema dessa tabela? Inclua o comando SQL especificando chaves primárias e estrangeiras.
ALTER TABLE filme_genero
ADD CONSTRAINT id_filme_fk
FOREIGN KEY (id_filme) REFERENCES FILME(CODIGO);

ALTER TABLE filme_genero
ADD CONSTRAINT id_genero_fk
FOREIGN KEY (id_gen) REFERENCES GENERO (id_genero);

ALTER TABLE filme_genero
ADD PRIMARY KEY (id_filme, id_gen);

-- 5.c Insira 5 tuplas nessa tabela.
INSERT INTO filme_genero (id_filme, id_gen) 
VALUES 
(2, 1), (2, 3), (3, 4), 
(3, 5), (4, 1), (4, 2), 
(1, 3), (1, 4), (5, 2), 
(5, 5);

-- 6. O comando DELETE FROM FILME WHERE codigo=X apaga do banco de dados o filme cujo valor do código é X. Substitua X por um valor de cósdigo existente no seu banco de dados para o qual existe uma sessão alocada. O que acontece ao tentar executar esse comando? Por quê?

DELETE FROM FILME WHERE CODIGO = 5;

-- DETAIL: Key (codigo)=(5) is still referenced from table "sessao".
-- Esse erro acontece pois apagar o codigo do filme, infringiria na modificação de uma terceira tabela 
-- com o objetivo de manter a integridade das relações entre tabelas do banco de dados.

-- 7. O comando UPDATE POLTRONA SET id_poltrona=Y WHERE id_poltrona=X altera o id da poltrona do banco de dados cujo valor do código é ‘X’ para o valor ‘Y’. Substitua X por um valor de código existente no seu banco de dados para o qual existe um bilhete vendido. O que acontece ao tentar executar esse comando? Por quê?

UPDATE POLTRONA SET idp = 3 WHERE idp = 5;

-- ERROR:  duplicate key value violates unique constraint "unk_idp"
-- DETAIL:  Key (idp)=(3) already exists.
-- Deu erro pois não existe poltronas com mesmo id em uma mesma sessão. Isso viola a regra
-- de unicidade pertencente as chaves primárias.