set SCHEMA 'public';

CREATE TABLE public.aluno
(
    matricula integer primary key,
    cpf character varying(12) unique,
    nome character varying(50) ,
    cod_curso integer
);

CREATE TABLE public.disciplina
(
    cod_disciplina integer primary key,
	nome varchar(20),
    cod_curso integer
);

CREATE TABLE public.livro
(
    cod integer primary key,
    isbn character varying(15) unique,
    titulo character varying(100),
    editora character varying(50),
	nome_autor character varying(50)
);

CREATE TABLE public.livro_adotado
(
    cod_disciplina integer,
    cod_livro integer,
	primary key(cod_disciplina,cod_livro), 
	foreign key(cod_disciplina) references disciplina(cod_disciplina),
	foreign key(cod_livro) references livro(cod)
);

INSERT INTO livro (cod, nome_autor) VALUES
(1, 'Machado de Assis'), (2, 'Carlos alberto'), (3, 'Carlão'), (4, 'Gabigol')

-- d
SELECT cod_disciplina, matricula
FROM disciplina, aluno
WHERE COUNT(matricula) > 10 IN (SELECT nota from HISTORICO > 9.00)

SELECT cod_disciplina, nota
FROM disciplina, n

CREATE TABLE HISTORICO(
    matricula_aluno integer,
    cod_disciplina integer,
    semestre integer,
    ano integer,
    nota float
    foreign key(matricula_aluno) references public.aluno(matricula),
    foreign key(cod_disciplina) references public.disciplina(cod_disciplina)
);

SELECT titulo, valorDecimal
FROM livros 
WHERE valorDecimal > (SELECT AVG(valorDecimal) from livros)
GROUP BY matricu (SELECT)