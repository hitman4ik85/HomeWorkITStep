USE Academy;
GO

-- Clear existing data
DELETE FROM Teachers;
DELETE FROM Groups;
DELETE FROM Faculties;
DELETE FROM Departments;

-- Reset identity columns
DBCC CHECKIDENT ('Teachers', RESEED, 0);
DBCC CHECKIDENT ('Groups', RESEED, 0);
DBCC CHECKIDENT ('Faculties', RESEED, 0);
DBCC CHECKIDENT ('Departments', RESEED, 0);