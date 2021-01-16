create table T1(tname varchar2(20),price number(4,2));
insert into T1 values('doll',9.99);
select * FROM T1;
commit;
select * FROM T1;
rollback;
select * FROM T1;
insert into T1 values('blue doll',8.99);
rollback;
select * FROM T1;
insert into T1 values('Turtle',7.95);
select * FROM T1;

set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      insert into T1 values('Green Turtle',15.95);
      commit;
end;
/

select * FROM T1;
rollback;
select * FROM T1;
----------------------------------------------
set transaction isolation level read committed;
insert into T1 values('purple Turtle',19.99);
select * FROM T1;

rollback;
select * FROM T1;
-------------------------------------------------------------
insert into T1 values('black ',19.99);
set transaction isolation level read committed;
select * FROM T1;
set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      insert into T1 values('black Turtle',19.99);
      commit;
end;
/
select * FROM T1;
rollback;
select * FROM T1;
----------------------
set transaction isolation level read committed;
select * FROM T1;
set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      insert into T1 values('yellow Turtle',19.99);
      commit; 
end;
/
commit;
select * FROM T1;
rollback;
commit;
select * FROM T1;
--------------------------------------
set transaction isolation level serializable;
select * FROM T1;
set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      update T1 set price=2.77;
      insert into  T1 values('chair',7.95);
      commit; 
end;
/
select * FROM T1;
commit;
select * FROM T1;

-----------------------------------------
set transaction isolation level serializable;
set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      update T1 set price=3.14;
      commit; 
end;
/
select * FROM T1;
commit;
select * FROM T1;
update T1 set price=price*10;
select * FROM T1;
delete from T1 where tname='doll';
select * FROM T1;
rollback;
select * FROM T1;
------------------------------------------------
select * FROM T1;
update T1 set price=price+1;
select * FROM T1;
commit;
---------------------------------------------
set transaction read only;
select * FROM T1;
update T1 set price=price+2;


set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      update T1 set price=88;
      commit; 
end;
/
select * FROM T1;
commit;
select * FROM T1;
-----------------------------
select * FROM T1;
update T1 set price=price+2;
commit;
set transaction read only;
set serveroutput on;
declare 
    pragma autonomous_transaction;
begin 
      update T1 set price=77;
      commit; 
end;
/
select * FROM T1;
commit;
select * FROM T1;
-------------------------







