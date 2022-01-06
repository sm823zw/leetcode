# Write your MySQL query statement below
# select d.name as department, e.name as employee, e.salary 


select d.name as Department, e.name as employee, e.salary as salary 
from employee e,
(select departmentid, max(salary) as maxsal from employee group by departmentid) t,
department d
where e.departmentid = t.departmentid and
e.salary = t.maxsal and
e.departmentid = d.id;
