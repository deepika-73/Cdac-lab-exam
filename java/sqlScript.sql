use test_acts;

create table mybuddies
(
email_id varchar(40) primary key,
buddy_name varchar(20) not null,
phone_no varchar(25) ,
dob date,
city varchar(10)
);

insert into mybuddies values('ankita@gmail.com','ankita','9673902480','1997-11-01','nanded') ;
insert into mybuddies values('deepika@gmail.com','deepika','985236974','1997-04-29','nanded') ;
insert into mybuddies values('vedika@gmail.com','vedika','9278612856','1994-10-19','nanded') ;

select * from mybuddies;
delete from mybuddies where buddy_name="vedika"
