use xyz;

select * from customers;
select * from transactions;
ALTER TABLE transactions DROP FOREIGN KEY fkey;
ALTER TABLE transactions ADD CONSTRAINT fkey FOREIGN KEY(id) REFERENCES customers(id) ON UPDATE CASCADE ON DELETE CASCADE;

insert into transactions(amount, trans_id) values(100, NULL);
insert into customers(id, firstname, lastname) values(null, 'name', 'name');

select * from transactions;


-- inner join

-- select * from table_to_be_on_left INNER JOIN table-on-right ON left-table.fk = right-table.fk-ka-reference
select * from transactions INNER JOIN customers ON transactions.id = customers.id;
select trans_id, amount, firstname, lastname from transactions INNER JOIN customers ON transactions.id = customers.id;

select * from transactions LEFT JOIN customers ON transactions.id = customers.id;

select * from transactions RIGHT JOIN customers ON transactions.id = customers.id;

select * from transactions FULL OUTER JOIN customers ON transactions.id = customers.id;


select trans_id, count(amount) from transactions GROUP BY trans_id;