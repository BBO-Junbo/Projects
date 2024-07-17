use db1;
drop table if exists Studens; 
create table Students(
	id int primary key auto_increment,
    name varchar(30) not null,
    gender varchar(1)not null,
    age tinyint not null,
    idcardnumber varchar(18)not null,
    check(gender in('F','M','T','W','X') )
);
drop table if exists Student_contacts;
create table Student_contacts(
	id int primary key auto_increment,
    phone_num varchar(11) not null,
    email  varchar(50) not null,
    address  varchar(50) not null,
    student_id int,
    foreign key(student_id) references Students(id)
);
drop table if exists Classes;
create table Classes(
	id int primary key auto_increment,
    name varchar(50) not null,    
    start_date date,
    end_date date
);
drop table if exists Courses;
create table Courses(
	id int primary key auto_increment,
    name varchar(50) not null, 
    description text,
    instructor varchar(50)not null,
	start_date date,
    end_date date
    
);
drop table if exists Student_course;
create table Student_course(
	student_id int,
    course_id int,
    foreign key(student_id) references Students(id),
    foreign key(course_id) references Courses(id),
    primary key(student_id, course_id)
);





