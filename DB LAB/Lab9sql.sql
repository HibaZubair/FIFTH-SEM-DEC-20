--The price of a product changes constantly. It is important to maintain the history of the prices of the products. 
--We can create a trigger to update the 'product_price_history' table when the price of the product is updated in the 
--'product' table.

CREATE TABLE product_price_history
(product_id number(5),
product_name VARCHAR(20),
supplier_name VARCHAR (20),
unit_price number(7,2) );

CREATE TABLE product
(product_id number(5),
product_name VARCHAR(20),
supplier_name VARCHAR (20),
unit_price number(7,2) ) ;



CREATE OR REPLACE TRIGGER price_history_after
AFTER UPDATE OF unit_price ON product
FOR EACH ROW
BEGIN
INSERT INTO product_price_history VALUES (:old.product_id,
:old.product_name,:old.supplier_name,:old.unit_price);
END;


drop trigger price_history_trigger;


Insert into product values (100, 'Laptop', 'Dell', 262.22);
Insert into product values (101, 'Laptop', 'HP', 362.22);
select * from PRODUCT;
SELECT * from product_price_history;



UPDATE PRODUCT SET unit_price=900 WHERE product_id=100;




select * from product_price_history;
select * from product;




CREATE OR REPLACE TRIGGER price_history_trigger_delete
BEFORE DELETE ON product
FOR EACH ROW
BEGIN
INSERT INTO product_price_history VALUES (:old.product_id,:old.product_name,
:old.supplier_name,:old.unit_price);
END;




delete from product  where UNIT_PRICE=900;
INSERT INTO PRODUCT VALUES(111,'Keyboard','DELL',2500);
delete from product  where UNIT_PRICE=2500;
select * from product_price_history;
select * from product;




--CREATE OR REPLACE TRIGGER price_history_trigger_insert
--BEFORE INSERT ON product
--FOR EACH ROW
--BEGIN
--INSERT INTO product_price_history VALUES (:old.product_id,:old.product_name,:old.supplier_name,:old.unit_price);
--END;


--INSERT INTO product VALUES(111,'Keyboard','Dell',20000);  
--select * from product_price_history;
--select * from product;



CREATE OR REPLACE TRIGGER price_his_tri_insert_after1
AFTER INSERT ON product
FOR EACH ROW
BEGIN
INSERT INTO product_price_history VALUES (:new.product_id,:new.product_name,
:new.supplier_name,:new.unit_price);
END;



INSERT INTO product VALUES(114,'charger','HP',1500);  
select * from product_price_history;
select * from product;
delete from product_price_history;



drop trigger price_his_tri_insert_after;





--Let's create a table 'product_check' which we can use to store 
--messages when triggers are fired.
CREATE TABLE product_check
(Message VARCHAR(50),
Current_Date Date
);




--Let's create a BEFORE and AFTER statement and row level triggers for the product table
CREATE or REPLACE TRIGGER Before_Update_Stat_product
BEFORE
UPDATE ON product
BEGIN
INSERT INTO product_check Values ('Before update, statement level', sysdate);
END;
/


UPDATE PRODUCT SET unit_price=800 WHERE product_id=100;
--This above trigger will insert a record into the table
--'product_check' before a Sql update statement is executed, at the statement level .
select * from PRODUCT_CHECK;
select * from PRODUCT;
SELECT * from product_price_history;
UPDATE PRODUCT SET unit_price=50000 WHERE product_id=101;



CREATE or REPLACE TRIGGER Before_Update_Row_product
BEFORE
UPDATE ON product
FOR EACH ROW
BEGIN
INSERT INTO product_check
Values ('Before update row level', sysdate);
END;



UPDATE PRODUCT SET unit_price=2500 WHERE product_id=114;
select * from PRODUCT_CHECK;
select * from product;
select * from product_price_history;



--This trigger will insert a record into the table 'product_check' before each row is update.
CREATE or REPLACE TRIGGER After_Update_Stat_product
AFTER
UPDATE ON product
BEGIN
INSERT INTO product_check
Values ('After update, statement level', sysdate);
END;
/
CREATE or REPLACE TRIGGER After_Update_row_product
AFTER
UPDATE ON product
BEGIN
INSERT INTO product_check
Values ('After update, row level', sysdate);
END;

INSERT INTO PRODUCT VALUES(122,'Speakers','ABC',1200);
INSERT INTO PRODUCT VALUES(125,'Mouse','ABC',1300);
UPDATE PRODUCT SET unit_price=5000 WHERE product_NAME='Mouse' OR PRODUCT_ID=122;
savepoint s1;
update
select
insert
delete;
rollback;
select * from PRODUCT_CHECK;
select * from product;
select * from product_price_history;



delete from product WHERE PRODUCT_ID=124
delete from product_price_history
delete from PRODUCT_CHECK;
ROLLBACK;






UPDATE PRODUCT SET unit_price=800 WHERE product_id=100;
select * from PRODUCT_CHECK;








