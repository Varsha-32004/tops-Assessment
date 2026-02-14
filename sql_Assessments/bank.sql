/*Here we are talking about the Bank related information of a person.
For which you need to create three tables named as Bank, Account holder and Loan
table.
And solve the problem stated below.*/

-- Create a Bank table, attributes are : branch id, branch name, branch city

create schema bank_detail;
use bank_detail;

create table bank(
branch_id int primary key,
branch_name varchar(100) not null,
branch_city varchar(100) not null
);

insert into bank(branch_id,branch_name,branch_city) value
(101,'BOB BANK','PORBANDAR'),
(102,'SBI BANK','AHMEDABAD'),
(103,'HDFC BANK','VADODARA'),
(104,'PANJAB NATIONAL BANK','MUMBAI'),
(105,'ICICI BANK','DELHI'),
(106,'UNION BANK','SURAT'),
(107,'AXIS BANK','BANGLORE'),
(108,'YES BANK','AHEMEDABAD'),
(109,'HDFC BANK','PORBANDAR'),
(110,'SBI BANK','MUMBAI'),
(111,'ICIC BANK','DELHI'),
(112,'UNION BANK','RAJKOT');
select*FROM bank;

/*Create a Loan table, attributes are : loan no, branch id, account holder’s id, loan
amount and loan type*/

use bank_detail;
create table loan(
loan_no int primary key,
loan_type varchar(50),
loan_amount double,
branch_id int,
account_holder_id int,
foreign key(branch_id) references bank(branch_id)
); 
-- drop table lone;
insert into loan (loan_no,loan_type,loan_amount,branch_id,account_holder_id) values
(1,'PERSONAL LOAN',100000,101,201),
(2,'HOME LOAN',20000,102,202),
(3,'CAR LOAN',60000,103,203),
(4,'BUSINESS LOAN',500000,104,204),
(5,'STUDENT LOAN',70000,105,205),
(6,'CREDIT CARD LOAN',90000,106,206),
(7,'CAR LOAN',30000,107,207),
(8,'HOME LOAN',25000,108,208),
(9,'PERSONAL LOAN',20000,109,209),
(10,'CREDIT CARD LOAN',78000,110,210),
(11,'BUSINESS LOAN',15000,111,211),
(12,'HOME LONE',25000,112,212);
select*from loan;

/*Create a table named as Account holder for the same scenario containing the
attributes are account holder’s id, account no, account holder’s name,
city,contact, date of account created, account status (active or terminated),
account type and balance.*/

use bank_detail;

create table account_holder
(
account_holder_id int primary key,
account_no int,
account_holder_name varchar(50),
city varchar(50),
contact varchar(15),
date_of_account_craeted date,
account_status varchar(15),
account_type varchar(15),
balance double
);

use bank_detail;
insert into account_holder(account_holder_id,account_no,account_holder_name,city,contact,date_of_account_craeted,account_status,account_type,balance) values
(201,1111,'VARSHA PARMAR','PORBANDAR',2345678976,'2023-01-09','ACTIVE','SAVING',20000),
(202,2222,'BHAVISHA PARMRA','RAJKOT',9845786432,'2022-08-25','TERMINATED','CURRENT',35000),
(203,3333,'NILESH PARMRA','AHEMDABAD',9913904562,'2025-02-12','ACTIVE','FIXED DEPOSIT',100000),
(204,4444,'VISHAVA TIMBA','SURAT',6547652387,'2017-05-19','ACTIVE','CHECKING',80000),
(205,5555,'KAJAL ODEDARA','MUMBAI',2983746587,'2015-03-22','TERMINATED','SAVING',50000),
(206,6666,'HETAL BAPODARA','VADODARA',9987654765,'2022-07-06','ACTIVE','FIXED DEPOSIT',15000),
(207,7777,'GARIMA YADAV','BANGLORE',7865432345,'2020-11-28','ACTIVE','CURRENT',450000),
(208,8888,'DIYA GAGLANI','SURAT',2376458923,'2021-12-11','TERMINATED','CHECKING',600000),
(209,9999,'NANDITA GOHEL','VADODARA',5612387549,'2026-01-17','ACTIVE','FIXED DEPOSIT',20000),
(210,1010,'NIDHI CHOHAN','PORBANDAR',9823675487,'2012-07-12','ACTIVE','CURRENT',75000),
(211,1122,'RUDARA SHIGHANIYA','RAJKOT',2396543873,'2018-04-03','ACTIVE','CURRENT',65000),
(212,2211,'AGSTYA RAYCHAND','AHEMDABAD',5786743212,'2019-06-13','TERMINATED','SAVING',55000);

select*from account_holder;


/* Consider an example where there’s an account holder table where we are
doing an intra bank transfer i.e. a person holding account A is trying to
transfer $100 to account B.

- for this you have to make a transaction in sql which can
  transfer fund from account A to B
- Make sure after the transaction the account information
  have to be updated for both the credit account and the
  debited account*/
    -- drop procedure fund_transfer;
    DROP PROCEDURE IF EXISTS fund_transfer;
  use bank_detail;
  delimiter &&
  create procedure fund_transfer (in from_account int,in to_account int,in transfer_amount double)
  begin
   declare available_balance double;
   
   if not exists(select 1 from account_holder where account_no = from_account) then
   signal sqlstate '45000'  set message_text = 'From Account Doen Not Exits';
   end if;
   
   if not exists (select 1 from account_holder where account_no=to_account) then
   signal sqlstate '45000' set message_text = 'To Account Doen Not Exits';
   end if;
   
   select balance into available_balance
   from account_holder
   where account_no = from_account;
   
   if available_balance < transfer_amount then
   signal sqlstate '45000'
   set message_text = 'Insufficient Balance';
   end if;
   start transaction;
   update account_holder set balance = balance - transfer_amount where account_no = from_account;
   update account_holder set balance = balance + transfer_amount where account_no = to_account;
   commit;
   end &&
   call fund_transfer(1111,2222,1000);
   DELIMITER ;


/*Also fetch the details of the account holder who are related from the same
city*/

select*from account_holder
where city in (select city from account_holder group by city having count(*) > 1)
order by city;


/*Write a query to fetch account number and account holder name, whose
accounts were created after 15th of any month*/

select account_no,account_holder_name from account_holder where day(date_of_account_craeted) > 15;

/*Write a query to display the city name and count the branches in that city.
Give the count of branches an alias name of Count_Branch.*/

select branch_city,count(branch_id) as count_branch from bank group by branch_city;

/*Write a query to display the account holder’s id, account holder’s name,
branch id, and loan amount for people who have taken loans. (NOTE : use
sql join concept to solve the query)*/

select a.account_holder_id,a.account_holder_name,l.branch_id,l.loan_amount from loan l inner join account_holder a on l.account_holder_id = a.account_holder_id;









