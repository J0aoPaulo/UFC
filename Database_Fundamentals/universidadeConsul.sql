set schema 'public';

-- Recupere a média de salário dos professores de cada departamento. Apresente o nome do departamento e a média salarial. Ordene o resultado em ordem crescente por média.
SELECT d.nome_depto AS departamento, AVG(p.salario) AS media_salarial
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
GROUP BY d.nome_depto
ORDER BY media_salarial ASC;

-- Recupere o nome dos departamentos cuja média salarial dos professores é maior ou igual a 2500.
SELECT d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
GROUP BY d.nome_depto
HAVING AVG(p.salario) >= 2500;

-- Para cada professor, obtenha o nome e a quantidade de disciplinas ministradas por ele. Retorne inclusive os professores que não ministraram disciplinas. Ordene o resultado em ordem decrescente por quantidade.
SELECT p.nome, COUNT(m.cod_disciplina) AS quantidade_disciplinas
FROM universidade.Professor p
LEFT JOIN universidade.Ministra m ON p.siape = m.siape
GROUP BY p.nome
ORDER BY quantidade_disciplinas DESC;

-- Obtenha a carga-horária ofertada por período.
SELECT periodo, SUM(d.carga_horaria) AS carga_horaria_ofertada
FROM universidade.Ministra m
JOIN universidade.Disciplina d ON m.cod_disciplina = d.cod_disciplina
GROUP BY periodo;

-- Obtenha para cada professor, seu nome e a carga horária ministrada por período.
SELECT p.nome, m.periodo, SUM(d.carga_horaria) AS carga_horaria_ministrada
FROM universidade.Professor p
JOIN universidade.Ministra m ON p.siape = m.siape
JOIN universidade.Disciplina d ON m.cod_disciplina = d.cod_disciplina
GROUP BY p.nome, m.periodo;

-- Obtenha o nome do departamento e a soma dos salários por departamento.
SELECT d.nome_depto, SUM(p.salario) AS soma_salarios
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
GROUP BY d.nome_depto;

-- Obtenha o nome do departamento e a quantidade de professores em cada departamento.
SELECT d.nome_depto, COUNT(p.siape) AS quantidade_professores
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
GROUP BY d.nome_depto;

-- Apresente para o professor que teve carga-horária maior que a média, o nome do professor e do seu departamento. (Utilize consultas aninhadas).
SELECT p.nome, d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
WHERE p.siape IN (
    SELECT m.siape
    FROM universidade.Ministra m
    JOIN universidade.Disciplina d ON m.cod_disciplina = d.cod_disciplina
    GROUP BY m.siape
    HAVING SUM(d.carga_horaria) > (
        SELECT AVG(carga_horaria)
        FROM universidade.Disciplina
    )
);

-- Apresente para o professor que teve carga-horária maior que a média do seu departamento, o nome do professor e do seu departamento. (Utilize consultas aninhadas).
SELECT p.nome, d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
WHERE p.siape IN (
    SELECT m.siape
    FROM universidade.Ministra m
    JOIN universidade.Disciplina d ON m.cod_disciplina = d.cod_disciplina
    GROUP BY m.siape
    HAVING SUM(d.carga_horaria) > (
        SELECT AVG(d2.carga_horaria)
        FROM universidade.Ministra m2
        JOIN universidade.Disciplina d2 ON m2.cod_disciplina = d2.cod_disciplina
        WHERE m2.siape = p.siape
    )
);

-- Recupere os professores que nunca ministraram a disciplina de código 1 (Utilize IN/NOT IN).
SELECT p.nome
FROM universidade.Professor p
WHERE p.siape NOT IN (
    SELECT m.siape
    FROM universidade.Ministra m
    WHERE m.cod_disciplina = 1
);

-- Apresente os dados do professor (inclusive o nome do seu departamento) que ministrou o maior número de disciplinas (Utilize o operador ALL).
SELECT p.nome, d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
WHERE (SELECT COUNT(*) FROM universidade.Ministra m WHERE m.siape = p.siape) = ALL (
    SELECT COUNT(*)
    FROM universidade.Ministra m2
    GROUP BY m2.siape
);

-- Apresente os dados do professor (inclusive o nome do seu departamento) que teve a maior carga horária em algum semestre (Utilize o operador ALL).
SELECT p.nome, d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
WHERE (SELECT SUM(d2.carga_horaria) FROM universidade.Ministra m2 JOIN universidade.Disciplina d2 ON m2.cod_disciplina = d2.cod_disciplina WHERE m2.siape = p.siape) = ALL (
    SELECT SUM(d3.carga_horaria)
    FROM universidade.Ministra m3
    JOIN universidade.Disciplina d3 ON m3.cod_disciplina = d3.cod_disciplina
    GROUP BY m3.siape
);

-- Obtenha o departamento que tem professor que não ministrou disciplina em 2013.1. (Utilize os operadores IN ou NOT IN)
SELECT d.nome_depto
FROM universidade.Departamento d
WHERE d.numero_depto IN (
    SELECT p.cod_depto
    FROM universidade.Professor p
    WHERE p.siape NOT IN (
        SELECT m.siape
        FROM universidade.Ministra m
        WHERE m.periodo = '2013.1'
    )
);

-- Obtenha as disciplinas que nunca foram ministradas (Utilize IN ou NOT IN).
SELECT d.nome
FROM universidade.Disciplina d
WHERE d.cod_disciplina NOT IN (
    SELECT m.cod_disciplina
    FROM universidade.Ministra m
);

-- Recupere o nome dos professores e o nome do departamento de todos os professores que não ministraram disciplinas em 2013.1. (Utilize os operadores EXISTS ou NOT EXISTS)
SELECT p.nome, d.nome_depto
FROM universidade.Professor p
JOIN universidade.Departamento d ON p.cod_depto = d.numero_depto
WHERE NOT EXISTS (
    SELECT 1
    FROM universidade.Ministra m
    WHERE m.siape = p.siape AND m.periodo = '2013.1'
);