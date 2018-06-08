USE master;
GO

IF EXISTS(SELECT * FROM sysdatabases WHERE name='Residence')
BEGIN
	RAISERROR('Dropping existing Residence database...',0,1)
	DROP DATABASE Residence;
END
GO

CREATE DATABASE Residence;
GO

USE Residence;
GO

IF db_name()<>'Residence'
BEGIN
	RAISERROR('Use database failed...',22,127) WITH LOG
	DROP DATABASE Residence;
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


CREATE TABLE dbo.userx
(
	userx_id INT NOT NULL PRIMARY KEY IDENTITY,
	first_name VARCHAR(32) NOT NULL,
	last_name VARCHAR(32) NOT NULL,
	phone NVARCHAR(32) NOT NULL,
	email NVARCHAR(32) NOT NULL
);
GO

INSERT INTO userx(first_name, last_name, phone, email)VALUES('Ariel', 'Bautista', '462-657-6565', 'aarielabn@gmail.com');
INSERT INTO userx(first_name, last_name, phone, email)VALUES('Hugo', 'Hernandez', '462-656-6465', 'superhuevo97@hotmail.com');
INSERT INTO userx(first_name, last_name, phone, email)VALUES('Javier', 'Ramirez', '462-565-6657', 'xratfx@gmail.com');
GO

CREATE TABLE dbo.vehicle
(
	vehicle_id INT NOT NULL PRIMARY KEY IDENTITY,
	marca NVARCHAR(40) NOT NULL,
	color VARCHAR(40) NOT NULL,
	placa NVARCHAR(40) NOT NULL
);
GO

INSERT INTO vehicle(marca, color, placa)VALUES('BMW 1569', 'Blanco', 'GTM465');
GO

CREATE TABLE dbo.visita
(
	visita_id INT NOT NULL PRIMARY KEY IDENTITY,
	userx_id INT NOT NULL REFERENCES userx(userx_id) ON DELETE CASCADE,
	vehicle_id INT NOT NULL REFERENCES vehicle(vehicle_id) ON DELETE CASCADE,
	entry_date SMALLDATETIME NOT NULL,
	departure_date SMALLDATETIME NOT NULL,
	department_id INT NOT NULL REFERENCES department(department_id) ON DELETE CASCADE
);
GO


----------------------------------------------Consultas 
--SELECT*FROM department;
--SELECT*FROM vehicle;
--SELECT*FROM userx;

--Vistas 
--CREATE VIEW vw_Usuario AS
--SELECT u.userx_id, u.first_name+' '+last_name AS usuario, u.phone, u.email,u.descriptionx, REPLACE(REPLACE(u.typex, '1','Yes'), '0', 'No') AS typex,u.plate, u.cedula, u.entry_date, u.departure_date, u.department_id, d.street AS street, u.street_block, u.house_number
--FROM userx u, department d
--WHERE u.userx_id=d.department_id;
--GO

CREATE VIEW vw_User AS
SELECT userx_id, first_name+' '+last_name AS usuario, phone, email
FROM userx
GO

CREATE VIEW vw_Vehi AS
SELECT v.vehicle_id,u.first_name+' '+last_name AS usuario, v.marca, v.color, v.placa
FROM userx u, vehicle v
WHERE u.userx_id=v.vehicle_id;
GO

CREATE VIEW vw_Visi AS
SELECT v.visita_id,
		v.userx_id,
		v.vehicle_id,
		v.department_id,
		userx.usuario AS Usuario,
		veh.marca AS vehiclee,
		v.entry_date AS entry_date,
		v.departure_date AS departure_date,
		d.street AS street
FROM	visita v,
		vw_User userx,
	    vehicle veh,
		department d
WHERE   v.userx_id=userx.userx_id AND 
		v.vehicle_id=veh.vehicle_id AND
		v.department_id=d.department_id;
GO