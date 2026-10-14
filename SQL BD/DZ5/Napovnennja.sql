INSERT INTO Faculties (Name) VALUES 
('Computer Science'), 
('Mathematics'), 
('Engineering')

INSERT INTO Departments (Name, Building, Financing, FacultyId) VALUES 
('Software Development', 1, 150000, 1), 
('Data Science', 1, 120000, 1), 
('Pure Mathematics', 2, 100000, 2), 
('Applied Mathematics', 2, 110000, 2), 
('Mechanical Engineering', 3, 140000, 3)

INSERT INTO Groups (Name, Year, DepartmentId) VALUES 
('D221', 2, 1), 
('D222', 2, 1), 
('M101', 1, 3), 
('E301', 3, 5)

INSERT INTO Students (Name, Surname, Rating) VALUES 
('Ivan', 'Petrov', 4.5), 
('Olga', 'Sidorova', 3.9), 
('Sergey', 'Ivanov', 4.0), 
('Anna', 'Koval', 4.7), 
('Max', 'Semenov', 4.3)

INSERT INTO Teachers (Name, Surname, Salary, IsProfessor) VALUES 
('Igor', 'Sergienko', 5000, 1), 
('Olga', 'Fedorova', 4500, 0), 
('Alex', 'Smirnov', 5500, 1), 
('Natalia', 'Petrova', 4800, 0)

INSERT INTO Subjects (Name, DepartmentId) VALUES 
('Programming', 1), 
('Statistics', 2), 
('Calculus', 3), 
('Linear Algebra', 4), 
('Thermodynamics', 5)

INSERT INTO Lectures (SubjectId, TeacherId, LectureDate) VALUES 
(1, 1, '2024-09-01'), 
(2, 2, '2024-09-02'), 
(3, 1, '2024-09-03'), 
(4, 3, '2024-09-04'), 
(5, 4, '2024-09-05')

INSERT INTO GroupsStudents (GroupId, StudentId) VALUES 
(1, 1), 
(1, 2), 
(2, 3), 
(2, 4), 
(3, 5)

INSERT INTO GroupsLectures (GroupId, LectureId) VALUES 
(1, 1), 
(1, 2), 
(2, 3), 
(2, 4), 
(3, 5)

INSERT INTO GroupsCurators (GroupId, CuratorId) VALUES 
(1, 1), 
(2, 2), 
(3, 3)