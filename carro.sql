USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='carro')
BEGIN
	RAISERROR('Dropping existing carro database...',0,1)
	DROP DATABASE carro;
END
GO

CREATE DATABASE carro;
GO

USE carro;
GO

IF db_name()<>'carro'
BEGIN
	RAISERROR('Use database failed...',22,127) WITH LOG
	DROP DATABASE carro;
END
GO

CREATE TABLE dbo.department
(
	department_id INT NOT NULL PRIMARY KEY IDENTITY,
	street NVARCHAR(40) NOT NULL
);
GO

INSERT INTO department(street)VALUES('Agustin Melgar');
INSERT INTO department(street)VALUES('Francisco I Madero');
INSERT INTO department(street)VALUES('Francisco Villa');
INSERT INTO department(street)VALUES('Emiliano Zapata');
INSERT INTO department(street)VALUES('Aquiles Serdan');
INSERT INTO department(street)VALUES('Porfirio Diaz');
INSERT INTO department(street)VALUES('Francisco Villa');
INSERT INTO department(street)VALUES('Jose Maria Pino Suarez');
GO

--CREATE TABLE userx
--(
--	userx_id INT NOT NULL PRIMARY KEY IDENTITY,
--	first_name VARCHAR(32) NOT NULL,
--	last_name VARCHAR(32) NOT NULL,
--	phone NVARCHAR(32) NOT NULL,
--	email NVARCHAR(32) NOT NULL,
--	descriptionx VARCHAR(32) NOT NULL,
--	typex BIT NOT NULL,
--	plate NVARCHAR(32) NOT NULL,
--	cedula NVARCHAR(32) NOT NULL,
--	entry_date SMALLDATETIME NOT NULL,
--	departure_date SMALLDATETIME NOT NULL,
--	department_id INT NOT NULL REFERENCES department(department_id) ON DELETE CASCADE,
--	street_block INT NOT NULL,
--	house_number INT NOT NULL
--);
--GO

--INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Ariel', 'Bautista', '462-657-6565', 'aarielabn@gmail.com', 'Audi A4, color gris',1 ,'344VPH', 'PJZ1542', GETDATE(), GETDATE(),1,2, 34);
--INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Hugo', 'Hernandez', '462-656-6465', 'superhuevo97@hotmail.com', 'BMW Z4, color anaranjado',1, '824DCI', 'TGF234', GETDATE(), GETDATE(), 2 , 2,56 );
--INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Javier', 'Ramirez', '462-565-6657', 'xratfx@gmail.com','CHEVROLET Cruze, color gris',0, 'PFH9371', 'JHG456', GETDATE(), GETDATE(), 3 ,3, 67 );
--GO

CREATE TABLE dbo.item
(
	item_id INT NOT NULL PRIMARY KEY IDENTITY,
	street NVARCHAR(40) NOT NULL
);
GO

CREATE TABLE dbo.userx
(
	userx_id INT NOT NULL PRIMARY KEY IDENTITY,
	first_name VARCHAR(32) NOT NULL,
	last_name VARCHAR(32) NOT NULL,
	phone NVARCHAR(32) NOT NULL,
	email NVARCHAR(32) NOT NULL,
	descriptionx VARCHAR(32) NOT NULL,
	typex BIT NOT NULL,
	plate NVARCHAR(32) NOT NULL,
	cedula NVARCHAR(32) NOT NULL,
	entry_date SMALLDATETIME NOT NULL,
	departure_date SMALLDATETIME NOT NULL,
	department_id INT NOT NULL REFERENCES department(department_id) ON DELETE CASCADE,
	street_block INT NOT NULL,
	house_number INT NOT NULL
);
GO

INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Ariel', 'Bautista', '462-657-6565', 'aarielabn@gmail.com', 'Audi A4, color gris',1 ,'VPH345', 'PJZDF1542', GETDATE(), GETDATE(),1,2, 34);
INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Hugo', 'Hernandez', '462-656-6465', 'superhuevo97@hotmail.com', 'BMW Z4, color anaranjado',1, 'DCI455', 'TGFFF234', GETDATE(), GETDATE(), 2 , 2,56 );
INSERT INTO userx(first_name, last_name, phone, email, descriptionx, typex, plate, cedula, entry_date, departure_date, department_id, street_block, house_number)VALUES('Javier', 'Ramirez', '462-565-6657', 'xratfx@gmail.com','CHEVROLET Cruze, color gris',0, 'PFH9371', 'JHGFG456', GETDATE(), GETDATE(), 3 ,3, 67 );
GO


----------------------------------------------Consultas 
--SELECT*FROM department;
--SELECT*FROM vehiclee;
--SELECT*FROM userx;

--Vistas 
CREATE VIEW vw_Usuario AS
SELECT u.userx_id, u.first_name+' '+last_name AS usuario, u.phone, u.email,u.descriptionx, REPLACE(REPLACE(u.typex, '1','Yes'), '0', 'No') AS typex,u.plate, u.cedula, u.entry_date, u.departure_date, u.department_id, d.street AS street, u.street_block, u.house_number
FROM userx u, department d
WHERE u.userx_id=d.department_id;
GO




