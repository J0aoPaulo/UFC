set schema 'apprel';
-- comandos DDL
-- drop table usuario;
create table usuario(id_u serial primary key, 
email varchar(50) unique not null, 
nome varchar(70) not null,
cidade varchar(30),
bio varchar(300), 
genero char(1) not null,
data_nasc date not null, 
idade integer check (idade >= 18) not null);

create table hobbies(id_hobbie serial primary key,
					descricao varchar(30) unique);

create table user_hobbies(id_u integer,
						 id_h integer,
						 primary key(id_u, id_h));
						 
--alter table user_hobbies drop constraint user_fk; 
alter table user_hobbies
add constraint user_hobbies_user_fk
foreign key (id_u) references usuario(id_u);

alter table user_hobbies
add constraint user_hobbies_hobbie_fk
foreign key (id_h) references hobbies(id_hobbie);

insert into usuario 
(email, nome, bio, genero, data_nasc, idade) 
values 
('joao92@gmail.com', 'João Pedro', 'Uma pessoa legal!',
'M', '1992-06-07', 30),
('amandaXX@hotmail.com', 'Amanda S.','Linda de viver.', 
 'F','2001-01-01',22);
-- adicionando usuarios 
insert into usuario
(email, nome, bio, genero, data_nasc, idade) 
values
('samuelNascimento24', 'Samuel Nascimento', 'Gosto de coisas diferentes',
'M', '2000-06-10', 20),
('hermesonBastao96', 'Hermeson Bastos', 'Gosto de ser nerd',
'M', '2003-12-25', 19),
('lucasAnthony789', 'Lucas Anthony', 'jogar jogos indies',
'M', '2004-03-27', 21);

select * from usuario;

insert into hobbies (descricao) values 
('praia'), ('plantas'), ('jogos'), ('futebol'), 
('cervejinha'), ('música'), ('balada');

select * from hobbies;

insert into user_hobbies values (1,1), (1,2), (2,4), (2, 2);

select * from user_hobbies;

-- adicionando mais pesssoas que curtem praia e balada
insert into user_hobbies values (1,7), (2,7), (2,1), (4,7), (4,1);

select *
from apprel.usuario;

select id_u, email, nome
from apprel.usuario;

select id_u, email, nome
from apprel.usuario
where idade >= 25 and idade <=30;

select id_u, email, nome
from apprel.usuario
where idade between 25 and 30;

select id_u, email, nome
from apprel.usuario
where data_nasc between '1992-06-07' and '1992-06-30';

select id_u, email, nome
from apprel.usuario
where date_part('year',data_nasc) = 1992;

select id_u, email, nome
from apprel.usuario
where nome like 'João Pedro';

select id_u, email, nome
from apprel.usuario
where nome like 'A%';

insert into apprel.usuario 
(email, nome, bio, genero, data_nasc, idade) 
values ('anaxxx@gmail.com', 'Ana', 'Uma pessoa legal!',
'F', '1994-06-07', 28);

select id_u, email, nome
from apprel.usuario
where nome like 'A__';
set schema 'apprel';

select usuario.id_u, email, nome
from usuario;

-- Obter o nome do usuário e o id dos hobbies de cada usuário
-- Resultado parcial com produto cartesiano
select * 
from usuario, user_hobbies;
-- Resultado final com junção (produto cartesiano + condição de junção)
select usuario.nome, user_hobbies.id_h
from usuario, user_hobbies
where usuario.id_u = user_hobbies.id_u;

-- outros exemplos 
-- colunas com mesmo nome
select usuario.nome, user_hobbies.id_h, user_hobbies.id_u
from usuario, user_hobbies
where usuario.id_u = user_hobbies.id_u;
-- renomeação
select u.nome, uh.id_h
from usuario as u, user_hobbies uh -- apelidando as tabelas
where u.id_u = uh.id_u;

-- Obter o nome do usuário e a descrição dos hobbies
-- de cada usuário
select u.nome, h.descricao
from usuario as u, user_hobbies as uh, hobbies as h
where u.id_u = uh.id_u and uh.id_h = h.id_hobbie;
-- quando o id da tabela usuario for igual ao id_usuario da tabela user_hobbies
-- quando o id do hobbies for igual ao id da tabela hobbie

-- renomeação de atributos
select u.nome, h.descr
from usuario as u, user_hobbies as uh, hobbies as h(idh, descr)
where u.id_u = uh.id_u and uh.id_h = h.idh;

CREATE TABLE likes (
	id_u_like integer,
	id_u_liked integer
);

alter table likes 
add constraint like_user
foreign key (id_u_like) references usuario (id_u);

alter table likes
add constraint liked_user
foreign key (id_u_liked) references usuario (id_u);

create table matches (
	id_u1 integer,
	id_u2 integer, 
	data_hora timestamp default now()
); 

alter table matches
add constraint id_usuario1_m
foreign key (id_u1) references usuario (id_u);

alter table matches
add constraint id_usuario2_m
foreign key (id_u2) references usuario (id_u);

-- adicionando curtidas
insert into likes 
values (5,1), (5,2), (1,2), (4,3), (3,4);

-- 1. Listar o nome de quem foi curtido e de quem curtiu.
select 
(select nome from usuario where id_u = lk.id_u_like) as likes,
(select nome from usuario where id_u = lk.id_u_liked) as likes
from likes as lk;

select * from likes;

-- adicionando mais matches
insert into likes
values (2,1), (1,5), (2,5), (2,3), (3,2); 

-- inserir os matches na tabela match
insert into matches
values (5,1, '2023-06-23 16:25:05'), (1,5, '2023-06-23 17:25:05'),
(5,2, '2023-06-23 14:10:15'), (2,5, '2023-06-23 15:25:05'),
(1,2, '2023-06-20 10:25:05'), (2,1, '2023-06-20 16:55:05'),
(4,3, '2023-06-23 09:30:05'), (3,4, '2023-06-23 10:40:05'),
(2,3, '2023-06-23 16:20:05'), (3,2, '2023-06-23 07:27:05');

select usuario.id_u, matches.id_u1
where usuario.nome like 'Ana%' where matches.id_u2 = usuario.id_u;

-- 2. Listar os ids dos matches da 'Ana'
select usuario.id_u, matches.id_u1
from usuario, matches
where usuario.nome like 'Ana' and matches.id_u2 = usuario.id_u;

-- 3.Listar o nome de cada usuário juntamente com o nome de quem lhe deu match.
select
(select nome from usuario where id_u = matches.id_u1),
(select nome from usuario where id_u = matches.id_u2)
from matches;

-- 4. Listar as pessoas que nasceram nos anos de 2000 a 2005
select usuario.nome, usuario.data_nasc from usuario
where data_nasc between '2000-01-01' and '2005-12-31';

-- 5. Listar o nome dos hobibies das pessoas que nasceram nos anos de 2000 a 2005.
select usuario.nome, hobbies.descricao from usuario, hobbies
where data_nasc between '2000-01-01' and '2005-12-31';

-- 6. Listar os dados das pessoas que curtem praia e balada.
select usuario.nome
from usuario
where usuario.id_u in 
(select user_hobbies.id_u from user_hobbies, hobbies
where user_hobbies.id_h = hobbies.id_hobbie and hobbies.descricao = 'praia'
) 
and usuario.id_u in (
  select user_hobbies.id_u
  from user_hobbies, hobbies
  where user_hobbies.id_h = hobbies.id_hobbie and hobbies.descricao = 'balada'
);

create table chat (
	id_emissor integer,
	id_receptor integer,
	mensagem varchar(200) unique not null,
	data_hora_chat timestamp default now()
);

-- inserindo mensagens 
insert into chat
values
(3,4,'oi, tudo certo', '2023-10-25 10:12:00'), 
(4,3,'tudo certo, gostei muito dos seus gostos', '2023-10-25 10:13:00'),
(3,4,'kkkk obrigada, tbm gostei muito da sua', '2023-10-25 10:14:00'),
(4,3,'valeu, olha eu pessoalmente não curto muito trocar mensagem, podemos nos encontrar', '2023-10-25 10:14:30'),
(3,4,'que bom! tbm não curto muito conversar por mensagem', '2023-10-25 10:15:00'),
(4,3,'cafeteria magiu as 19:30?', '2023-10-25 10:16:00'), (3,4,'combinado! nos encontramos la', '2023-10-25 10:12:00');

-- 7. Listar as mensagens da última semana do chat da 'Ana'
select chat.mensagem
from chat, usuario
where usuario.nome like 'Ana' 
and (usuario.id_u = chat.id_emissor) or usuario.nome like 'Ana' and (usuario.id_u = chat.id_receptor)
and chat.data_hora_chat between '2023-03-25 10:12:00' and '2023-03-25 10:15:00';