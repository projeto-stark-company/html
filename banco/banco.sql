
CREATE TABLE mercadoria (
id_mercadoria NUMBER(4) PRIMARY KEY,
nome VARCHAR2(40),
foto VARCHAR2(255),
data_criacao DATE
);

CREATE TABLE transportadora (
id_transportadora NUMBER(4) PRIMARY KEY,
razao_social VARCHAR2(40),
cnpj VARCHAR2(15),
nome_responsavel VARCHAR2(40),
cpf VARCHAR2(15),
endereco VARCHAR2(100),
cidade VARCHAR2(30),
uf CHAR(2)
);

CREATE TABLE departamento (
id_departamento NUMBER(4) PRIMARY KEY,
departamento VARCHAR2(40),
descricao VARCHAR2(255)
);

CREATE TABLE modelagem (
id_modelagem NUMBER(4) PRIMARY KEY,
tamanho CHAR(2)
);

CREATE TABLE empregado (
id_empregado NUMBER(4) PRIMARY KEY,
nome VARCHAR2(40),
cpf VARCHAR2(15),
rg VARCHAR2(15),
endereco VARCHAR2(100),
id_departamento NUMBER(4),
CONSTRAINT fk_departamento_empregado
    FOREIGN KEY (id_departamento)
    REFERENCES departamento (id_departamento)
);

CREATE TABLE comprador (
id_comprador NUMBER(4) PRIMARY KEY,
nome VARCHAR2(40),
cpf VARCHAR2(15),
rg VARCHAR2(15),
endereco VARCHAR2(100),
cidade VARCHAR2(30),
uf CHAR(2),
email VARCHAR2(100),
telefone VARCHAR2(15),
data_nascimento DATE,
id_empregado NUMBER(4),
  CONSTRAINT fk_empregado_comprador
    FOREIGN KEY (id_empregado)
    REFERENCES empregado (id_empregado)
);

CREATE TABLE categoria (
id_categoria NUMBER(4) PRIMARY KEY,
categoria VARCHAR2(40),
descricao VARCHAR2(255),
id_mercadoria NUMBER(4),
CONSTRAINT fk_mercadoria_categoria
    FOREIGN KEY (id_mercadoria)
    REFERENCES mercadoria (id_mercadoria)
);



CREATE TABLE preco (
id_preco NUMBER(4) PRIMARY KEY,
id_categoria NUMBER(4),
id_modelagem NUMBER(4),
valor NUMBER(4),
CONSTRAINT fk_categoria_preco
    FOREIGN KEY (id_categoria)
    REFERENCES categoria (id_categoria),
CONSTRAINT fk_modelagem_compra
    FOREIGN KEY (id_modelagem)
    REFERENCES modelagem (id_modelagem)
);


CREATE TABLE compra (
id_compra NUMBER(4) PRIMARY KEY,
id_comprador NUMBER(4),
id_empregado NUMBER(4),
id_preco NUMBER(4),
id_transportadora NUMBER(4),
quantidade NUMBER(4),
valor_compra NUMBER(10, 2),
CONSTRAINT fk_empregado_compra
    FOREIGN KEY (id_empregado)
    REFERENCES empregado (id_empregado),
CONSTRAINT fk_comprador_compra
    FOREIGN KEY (id_comprador)
    REFERENCES comprador (id_comprador),
CONSTRAINT fk_transportadora_compra
    FOREIGN KEY (id_transportadora)
    REFERENCES transportadora (id_transportadora),
CONSTRAINT fk_preco_compra
    FOREIGN KEY (id_preco)
    REFERENCES preco (id_preco)
);

INSERT INTO departamento(id_departamento, departamento, descricao)
VALUES(01,'RH','Setor responsavel por novos empregados');


INSERT INTO departamento(id_departamento, departamento, descricao)
VALUES(02,'VENDAS','Setor responsavel por novas vendas');


INSERT INTO empregado(id_empregado, nome, cpf, rg, endereco, id_departamento)
VALUES(10,'Luan Ricardo','820.705.428-07','26.559.099-1','Rua José Sá Barreto, s/n','01');


INSERT INTO empregado(id_empregado, nome, cpf, rg, endereco, id_departamento)
VALUES(20,'Maya Eduarda Antônia Cardoso','135.337.315-02','50.187.275-9','Praça Heribaldo Alves de Gois, s/n','02');


INSERT INTO comprador(id_comprador, nome, cpf, rg, endereco, cidade, uf, email, telefone, data_nascimento, id_empregado)
VALUES(100,'Ian Paulo Bernardo Campos','931.148.989-12','32.091.420-3','Rua Trucal','Belo Horizonte','MG',
'ianpaulobernardocampos_@evolink.com.br','(31)2925-4594','02/10/1996','10');


INSERT INTO comprador(id_comprador, nome, cpf, rg, endereco, cidade, uf, email, telefone, data_nascimento, id_empregado)
VALUES(200,'Beatriz Ester Josefa Carvalho','707.802.714-08','42.866.186-5','Rua Chouro','Jaboatão dos Guararapes',
'PE','beatrizesterjosefacarvalho@eberlin.agr.br','(81)2768-5707','04/10/1980','20');

UPDATE empregado
SET nome = 'João da Silva'
WHERE id_empregado = 10;


UPDATE comprador
SET endereco = 'Acesso Carlos Correa, Correia Velho - 896'
WHERE id_comprador = 200;


UPDATE departamento
SET departamento = 'Financeiro'
WHERE id_departamento = 01;

SELECT nome,
       id_empregado
FROM empregado
WHERE id_departamento = 01;


SELECT nome,
       id_empregado
FROM empregado
WHERE id_departamento = 01;


SELECT id_comprador,
       nome,
       id_empregado
FROM comprador;


SELECT id_comprador,
       nome
FROM comprador
WHERE nome LIKE 'B%';


SELECT COUNT(*)
FROM departamento;

DELETE
FROM comprador
WHERE id_comprador = 200;


DELETE
FROM empregado
WHERE id_empregado = 20;


DELETE
FROM departamento
WHERE id_departamento = 02;






