--
-- PostgreSQL database dump
--

-- Dumped from database version 11.5
-- Dumped by pg_dump version 11.5

-- Started on 2023-06-20 06:24:49

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 203 (class 1255 OID 9638379)
-- Name: atualiza_qtd_curtidas(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.atualiza_qtd_curtidas(id_pessoa_nova integer) RETURNS void
    LANGUAGE plpgsql
    AS $$

declare 
contador_curtidas integer;
begin 
	select count(ctd.id_seguidor) into contador_curtidas
	from postagem pos, curtida ctd, pessoa pe
	where pos.id_seq = ctd.id_seq and 
	  	  pe.id = pos.id_pessoa	and
		  pos.id_pessoa = id_pessoa_nova;
	
	update quantidade_curtidas set qtd_curtidas = contador_curtidas where 
	quantidade_curtidas.id_pessoa = id_pessoa_nova;
	raise notice 'Valor atualizado';
	
end;
$$;


ALTER FUNCTION public.atualiza_qtd_curtidas(id_pessoa_nova integer) OWNER TO postgres;

--
-- TOC entry 204 (class 1255 OID 9638382)
-- Name: q5(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION public.q5(id integer) RETURNS void
    LANGUAGE plpgsql
    AS $$

declare 
cont integer;

begin

	select count(*) into cont
	from pessoa p, curtida c, postagem post
	where p.id = post.id_pessoa and post.id_seq = c.id_seq and p.id = id
	group by p.id, p.nickname;

	update QUANTIDADE_CURTIDAS set quantidade = cont where id_pessoa = id;
end;
$$;


ALTER FUNCTION public.q5(id integer) OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 196 (class 1259 OID 9638384)
-- Name: comentario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.comentario (
    id_seq_postagem integer NOT NULL,
    id_seguidor integer NOT NULL,
    comentario character varying(50) NOT NULL
);


ALTER TABLE public.comentario OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 9638387)
-- Name: curtida; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.curtida (
    id_seq_postagem integer NOT NULL,
    id_seguidor integer NOT NULL
);


ALTER TABLE public.curtida OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 9638394)
-- Name: pessoa; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.pessoa (
    id integer NOT NULL,
    nickname character varying(20)
);


ALTER TABLE public.pessoa OWNER TO postgres;

--
-- TOC entry 199 (class 1259 OID 9638397)
-- Name: pessoa_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.pessoa_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.pessoa_id_seq OWNER TO postgres;

--
-- TOC entry 2854 (class 0 OID 0)
-- Dependencies: 199
-- Name: pessoa_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.pessoa_id_seq OWNED BY public.pessoa.id;


--
-- TOC entry 200 (class 1259 OID 9638399)
-- Name: postagem; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.postagem (
    id_pessoa integer,
    id_seq integer NOT NULL,
    descricao character varying(50)
);


ALTER TABLE public.postagem OWNER TO postgres;

--
-- TOC entry 201 (class 1259 OID 9638402)
-- Name: postagem_id_seq_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.postagem_id_seq_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.postagem_id_seq_seq OWNER TO postgres;

--
-- TOC entry 2855 (class 0 OID 0)
-- Dependencies: 201
-- Name: postagem_id_seq_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.postagem_id_seq_seq OWNED BY public.postagem.id_seq;


--
-- TOC entry 202 (class 1259 OID 9638404)
-- Name: seguidor; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.seguidor (
    id_pessoa integer NOT NULL,
    id_seguidor integer NOT NULL
);


ALTER TABLE public.seguidor OWNER TO postgres;

--
-- TOC entry 2705 (class 2604 OID 9638414)
-- Name: pessoa id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.pessoa ALTER COLUMN id SET DEFAULT nextval('public.pessoa_id_seq'::regclass);


--
-- TOC entry 2706 (class 2604 OID 9638415)
-- Name: postagem id_seq; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.postagem ALTER COLUMN id_seq SET DEFAULT nextval('public.postagem_id_seq_seq'::regclass);


--
-- TOC entry 2842 (class 0 OID 9638384)
-- Dependencies: 196
-- Data for Name: comentario; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.comentario VALUES (2, 1, 'Uhuuuuuu!');
INSERT INTO public.comentario VALUES (1, 2, '=) ');
INSERT INTO public.comentario VALUES (3, 2, 'Será hein???');
INSERT INTO public.comentario VALUES (2, 1, 'kkkkkkkkkkkkkkkkk');
INSERT INTO public.comentario VALUES (2, 2, 'ttttttttttttttttttt');


--
-- TOC entry 2843 (class 0 OID 9638387)
-- Dependencies: 197
-- Data for Name: curtida; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.curtida VALUES (3, 2);
INSERT INTO public.curtida VALUES (4, 3);
INSERT INTO public.curtida VALUES (4, 4);
INSERT INTO public.curtida VALUES (4, 1);
INSERT INTO public.curtida VALUES (2, 1);
INSERT INTO public.curtida VALUES (2, 5);
INSERT INTO public.curtida VALUES (2, 3);
INSERT INTO public.curtida VALUES (2, 6);
INSERT INTO public.curtida VALUES (2, 9);
INSERT INTO public.curtida VALUES (2, 4);
INSERT INTO public.curtida VALUES (2, 7);
INSERT INTO public.curtida VALUES (2, 10);
INSERT INTO public.curtida VALUES (2, 11);
INSERT INTO public.curtida VALUES (2, 8);
INSERT INTO public.curtida VALUES (2, 12);


--
-- TOC entry 2844 (class 0 OID 9638394)
-- Dependencies: 198
-- Data for Name: pessoa; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.pessoa VALUES (3, 'liviaa');
INSERT INTO public.pessoa VALUES (1, 'Jessika');
INSERT INTO public.pessoa VALUES (2, 'Fernanda');
INSERT INTO public.pessoa VALUES (4, 'Mathew');
INSERT INTO public.pessoa VALUES (5, 'Gui');
INSERT INTO public.pessoa VALUES (6, 'Telma
');
INSERT INTO public.pessoa VALUES (7, 'Gizele
');
INSERT INTO public.pessoa VALUES (8, 'Samara
');
INSERT INTO public.pessoa VALUES (9, 'Adriana');
INSERT INTO public.pessoa VALUES (10, 'Joao');
INSERT INTO public.pessoa VALUES (11, 'Cristina
');
INSERT INTO public.pessoa VALUES (12, 'Silvia
');


--
-- TOC entry 2846 (class 0 OID 9638399)
-- Dependencies: 200
-- Data for Name: postagem; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.postagem VALUES (1, 1, 'OI GENTE, COMO TÁ?');
INSERT INTO public.postagem VALUES (2, 2, 'PARTIU FÉRIAS!');
INSERT INTO public.postagem VALUES (3, 3, 'VCS QUE LUTEM!');
INSERT INTO public.postagem VALUES (4, 4, 'NÃO TÁ FÁCIL PRA NINGUÉM!');


--
-- TOC entry 2848 (class 0 OID 9638404)
-- Dependencies: 202
-- Data for Name: seguidor; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.seguidor VALUES (1, 2);
INSERT INTO public.seguidor VALUES (2, 1);
INSERT INTO public.seguidor VALUES (3, 2);
INSERT INTO public.seguidor VALUES (4, 1);
INSERT INTO public.seguidor VALUES (1, 4);
INSERT INTO public.seguidor VALUES (1, 3);


--
-- TOC entry 2856 (class 0 OID 0)
-- Dependencies: 199
-- Name: pessoa_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.pessoa_id_seq', 5, true);


--
-- TOC entry 2857 (class 0 OID 0)
-- Dependencies: 201
-- Name: postagem_id_seq_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.postagem_id_seq_seq', 4, true);


-- Completed on 2023-06-20 06:24:49

--
-- PostgreSQL database dump complete
--

-- Considere o banco de dados da Rede Social. Apresente uma consulta em SQL par obter o nome das pessoas em que a quantidade de seguidores é a maior.
SELECT p.nome
FROM pessoa as p
WHERE p.id IN (SELECT s.id_pessoa
               FROM seguidor as s
               GROUP BY s.id_pessoa
               HAVING COUNT(s.id_seguidor) = (SELECT MAX(qtd_seguidores)
                                             FROM (SELECT COUNT(s.id_seguidor) AS qtd_seguidores
                                                   FROM seguidor s
                                                   GROUP BY s.id_pessoa) AS qtd_seguidores));

-- Considere o banco de dados da Rede Social. Apresente uma consulta em SQL par obter o nome das pessoas que possuem ao menos uma postagem que tem curtidas. Utilize um dos comandos a seguir: IN ou Exists.
SELECT p.nome
FROM pessoa as p
WHERE p.id IN (SELECT po.id_pessoa
               FROM postagem as po
               WHERE po.id_seq IN (SELECT c.id_postagem
                                   FROM curtida as c));

--Considere o banco de dados da Rede Social. Apresente uma consulta em SQL par obter o nome das pessoas que não possuem seguidores. Utilize o comando Not Exists.
SELECT p.nome
FROM pessoa as p
WHERE NOT EXISTS (SELECT s.id_pessoa
                  FROM seguidor as s
                  WHERE s.id_pessoa = p.id);


-- Considere o banco de dados da Rede Social. Apresente uma consulta em SQL para o nome das pessoas que seguem a Jessika e que também seguem a Fernanda.
SELECT p.nome
FROM pessoa as p
WHERE p.id IN (SELECT s.id_pessoa
               FROM seguidor as s
               WHERE s.id_seguidor IN (SELECT s.id_seguidor
                                       FROM seguidor as s
                                       WHERE s.id_pessoa = 1)
                 AND s.id_seguidor IN (SELECT s.id_seguidor
                                       FROM seguidor as s
                                       WHERE s.id_pessoa = 2));

-- Considere o banco de dados da Rede Social.
-- Crie uma visão Pessoa_Estat(id, nickname, qtd_seguindo, qtd_seguidores, qtd_postagens, qtd_comentarios). O objetivo da visão Pessoa_Estat é apresentar para cada pessoa algumas estatísticas da rede social: a quantidade de pessoas que ela segue, a quantidade de seguidores, a quantidade de postagens feita pela pessoa e a quantidade de comentários em postagens que ela fez.

CREATE VIEW Pessoa_Estat AS
SELECT p.id, p.nome AS nickname, COUNT(s.id_seguidor) AS qtd_seguindo, COUNT(s.id_pessoa) AS qtd_seguidores, COUNT(po.id_seq) AS qtd_postagens, COUNT(c.id_comentario) AS qtd_comentarios
FROM pessoa as p
JOIN seguidor as s ON p.id = s.id_pessoa
JOIN postagem as po ON p.id = po.id_pessoa
JOIN comentario as c ON po.id_seq = c.id_postagem
GROUP BY p.id;

-- Utilize essa visão para responder à pergunta: Quais as pessoas que tem a quantidade de seguidores maior que a média?

SELECT pe.nickname
FROM Pessoa_Estat as pe
WHERE pe.qtd_seguidores > (SELECT AVG(qtd_seguidores)
                           FROM Pessoa_Estat);