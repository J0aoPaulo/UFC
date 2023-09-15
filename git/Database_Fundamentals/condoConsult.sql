-- 1 - Liste o número de requisições de serviços de cada prestador juntamente com o nome do prestador.
SELECT COUNT (rdata), prnome
FROM public.l06_requisita, public.l05_prestador
WHERE rcpfprestador = prcpf
GROUP by prnome
-- 2 - Liste a quantidade total de moradores do condomínio, contando com o morador e seus familiares.
SELECT COUNT(DISTINCT mnome) + COUNT(fanome)
FROM l01_morador
LEFT JOIN l04_familiar
ON mnome = fanomemorador
WHERE mnome != 'desocupado';
-- 3 - Liste o valor total arrecadado com condomínio de todas as unidades. 
SELECT SUM(uvalorbasecond) as valorTotalCondominio
FROM l02_unidade
-- 4 - Liste o maior e o menor valor pago de condomínio.
SELECT MAX(uvalorbasecond) as aluguelMaximo, 
MIN(uvalorbasecond) as aluguelMinimo
FROM l02_unidade
-- 5 - Liste a quantidade de funcionários contratados para cada função.
SELECT COUNT(fufuncao) as funcionarioPorFuncao,
fufuncao as nomeDaFuncao
FROM public.l09_funcionario
GROUP BY fufuncao
-- 6 - Liste os prestadores que realizaram o mais que 3 serviços.
SELECT rcpfprestador
FROM public.l05_prestador, public.l06_requisita
WHERE rcpfprestador = prcpf
GROUP BY rcpfprestador 
HAVING COUNT(rcpfprestador) > 3
-- 7 - Liste as unidades que possuem mais de dois veículos.
SELECT vnrounidade
from public.l03_veiculo
GROUP BY vnrounidade
HAVING COUNT(vnrounidade) > 2
-- 8 - Liste todas as unidades que não possuem veículos.
SELECT vnrounidade
from public.l03_veiculo
WHERE vnrounidade = NULL
-- 9 - Calcule o valor médio das despesas por tipo. 
select dfuncaoadmin, AVG(dvalordespesa) as mediaPorTipo
FROM public.l08_despesa
GROUP BY dfuncaoadmin
-- 10 - Liste os tipos de despesas cujo custo  médio foi maior que 20.
SELECT dfuncaoadmin, AVG(dvalordespesa) as mediaPorTipo
FROM public.l08_despesa
GROUP BY dfuncaoadmin
HAVING AVG(dvalordespesa) > 20;