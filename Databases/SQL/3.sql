create table tab1(ph VARCHAR(15) NOT NULL, name VARCHAR(50) not NULL);
ALTER TABLE tab1 MODIFY ph VARCHAR(20);

insert into tab1(ph, name) values ("9123412442", 'guggu');
select * from tab1;

create table tab2(ph VARCHAR(15) NOT NULL, name VARCHAR(50) DEFAULT 'ILGuggu');
insert into tab2(ph) values ("9123412442");

select * from tab2;