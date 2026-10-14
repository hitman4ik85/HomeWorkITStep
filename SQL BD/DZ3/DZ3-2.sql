USE Academy;
GO

INSERT INTO Departments (Financing, Name)
VALUES (10000, 'Software Development'),
       (15000, 'Information Systems'),
       (5000, 'Mathematics'),
       (8000, 'Cyber Security'),
       (12000, 'Data Science'),
       (7000, 'Artificial Intelligence'),
       (20000, 'Robotics'),
       (6000, 'Applied Mathematics');

INSERT INTO Faculties (Dean, Name)
VALUES ('John Doe', 'Computer Science'),
       ('Jane Smith', 'Information Technology'),
       ('Mark Taylor', 'Mathematics'),
       ('Sarah Connor', 'Engineering'),
       ('Mike Johnson', 'Robotics and Automation'),
       ('Alex Smith', 'Cyber Security'),
       ('Lucy Brown', 'Data Science and AI'),
       ('Emily White', 'Applied Mathematics and Physics');

INSERT INTO Groups (Name, Rating, Year)
VALUES ('Group A', 3, 2),
       ('Group B', 4, 3),
       ('Group C', 2, 1),
       ('Group D', 5, 4),
       ('Group E', 4, 5),
       ('Group F', 3, 1),
       ('Group G', 2, 2),
       ('Group H', 1, 3);

INSERT INTO Teachers (EmploymentDate, IsAssistant, IsProfessor, Name, Surname, Position, Premium, Salary)
VALUES ('2005-09-10', 1, 0, 'Anna', 'Ivanova', 'Assistant', 200, 1200),
       ('2001-03-15', 0, 1, 'Peter', 'Petrov', 'Professor', 300, 2500),
       ('1998-07-22', 0, 0, 'Elena', 'Kuznetsova', 'Lecturer', 150, 1800),
       ('2010-01-15', 1, 0, 'Igor', 'Sidorov', 'Assistant', 300, 1000),
       ('2005-05-20', 0, 1, 'Maria', 'Kuzmina', 'Professor', 500, 3500),
       ('2012-11-02', 0, 0, 'Ivan', 'Pavlov', 'Lecturer', 200, 1800),
       ('1995-07-12', 0, 1, 'Oksana', 'Tarasova', 'Professor', 700, 4500),
       ('2017-09-01', 1, 0, 'Nina', 'Kovalenko', 'Assistant', 250, 1300),
	   ('2021-08-15', 1, 0, 'Andrei', 'Potapenko', 'Assistant', 150, 500),
	   ('2020-10-01', 1, 0, 'Sveta', 'Loboda', 'Assistant', 100, 1100);

SELECT * FROM Departments;
SELECT * FROM Faculties;
SELECT * FROM Groups;
SELECT * FROM Teachers;