drop database if exists dogwalking;     
CREATE DATABASE dogwalking CHARSET utf8;
USE dogwalking;
-- 创建用户表
CREATE TABLE Users (
  user_id INT PRIMARY KEY auto_increment,
  username VARCHAR(255) NOT NULL,
  password VARCHAR(255) NOT NULL,
  salt varchar(36) ,
  phone VARCHAR(20) ,
  email VARCHAR(255) ,
  gender VARCHAR(50) ,
  avatar VARCHAR(50) COMMENT '头像',
  is_delete INT COMMENT '是否删除：0-未删除，1-已删除',
  role VARCHAR(50) NOT NULL,
  	created_user VARCHAR(20) COMMENT '创建人',
	created_time DATETIME COMMENT '创建时间',
	modified_user VARCHAR(20) COMMENT '修改人',
	modified_time DATETIME COMMENT '修改时间'
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 创建狗表
CREATE TABLE Dog (
  dog_id INT PRIMARY KEY auto_increment,
  user_id INT,
  master_name VARCHAR(255) NOT NULL,
  address VARCHAR(255),
  dog_name VARCHAR(255) NOT NULL,
  dog_breed VARCHAR(255),
  dog_age INT,
  dog_gender VARCHAR(50),
  is_neutered varchar(255),
  is_sick varchar(255),
  remark VARCHAR(255),
  image_url VARCHAR(255), -- 新添加的图像地址属性
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
created_user VARCHAR(20) COMMENT '创建人',
created_time DATETIME COMMENT '创建时间',
modified_user VARCHAR(20) COMMENT '修改人',
modified_time DATETIME COMMENT '修改时间'
);



-- 创建顾客表
CREATE TABLE Customers (
  customer_id INT PRIMARY KEY auto_increment,
  user_id INT,
  name VARCHAR(255) NOT NULL,
  address VARCHAR(255),
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  	created_user VARCHAR(20) COMMENT '创建人',
	created_time DATETIME COMMENT '创建时间',
	modified_user VARCHAR(20) COMMENT '修改人',
	modified_time DATETIME COMMENT '修改时间'
);

-- 创建约会表
CREATE TABLE Appointments (
  appointment_id INT PRIMARY KEY auto_increment,
  dog_id INT,
  customer_id INT,
  start_time DATETIME,
  end_time DATETIME,
  FOREIGN KEY (dog_id) REFERENCES Dog(dog_id),
  FOREIGN KEY (customer_id) REFERENCES Customers(customer_id),
  	created_user VARCHAR(20) COMMENT '创建人',
	created_time DATETIME COMMENT '创建时间',
	modified_user VARCHAR(20) COMMENT '修改人',
	modified_time DATETIME COMMENT '修改时间'
);
-- 创建狗可用性表
CREATE TABLE dogAvailability (
  availability_id INT PRIMARY KEY auto_increment,
  dog_id INT,
  is_reserved boolean,
  start_time DATETIME,
  end_time DATETIME,
  FOREIGN KEY (dog_id) REFERENCES Dog(dog_id),
  created_user VARCHAR(20) COMMENT '创建人',
  created_time DATETIME COMMENT '创建时间',
  modified_user VARCHAR(20) COMMENT '修改人',
  modified_time DATETIME COMMENT '修改时间'
);

-- 创建顾客评论表
CREATE TABLE customerReview (
  creview_id INT PRIMARY KEY auto_increment,
  customer_id INT,
  user_id INT,
  rating double,
  comment TEXT,
  FOREIGN KEY (customer_id) REFERENCES Customers(customer_id),
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  	created_user VARCHAR(20) COMMENT '创建人',
	created_time DATETIME COMMENT '创建时间',
	modified_user VARCHAR(20) COMMENT '修改人',
	modified_time DATETIME COMMENT '修改时间'
);

-- 创建狗评论表
-- 创建狗评论表
CREATE TABLE DogReview (
  dreview_id INT PRIMARY KEY auto_increment,
  dog_id INT,
  user_id INT,
  appointment_id INT,
  rating double,
  comment TEXT,
  FOREIGN KEY (dog_id) REFERENCES Dog(dog_id),
  FOREIGN KEY (user_id) REFERENCES Users(user_id),
  FOREIGN KEY (appointment_id) REFERENCES Appointments(appointment_id), 
  	created_user VARCHAR(20) COMMENT '创建人',
	created_time DATETIME COMMENT '创建时间',
	modified_user VARCHAR(20) COMMENT '修改人',
	modified_time DATETIME COMMENT '修改时间'
);
