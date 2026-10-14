-- 1
SELECT Departments.Building 
FROM Departments
WHERE Departments.Financing > 100000
GROUP BY Departments.Building

-- 2
SELECT Groups.Name 
FROM Groups 
JOIN Departments ON Groups.DepartmentId = Departments.Id 
JOIN GroupsLectures ON Groups.Id = GroupsLectures.GroupId 
WHERE Groups.Year = 5 AND Departments.Name = 'Software Development' 
GROUP BY Groups.Name 
HAVING COUNT(GroupsLectures.LectureId) > 10;

-- 3
SELECT Groups.Name 
FROM Groups 
JOIN GroupsStudents ON Groups.Id = GroupsStudents.GroupId 
JOIN Students ON GroupsStudents.StudentId = Students.Id 
GROUP BY Groups.Name 
HAVING AVG(Students.Rating) > (SELECT AVG(Rating) FROM Groups WHERE Name = 'D221');

-- 4
SELECT Teachers.Name, Teachers.Surname 
FROM Teachers 
WHERE Teachers.Salary > (SELECT AVG(Salary) FROM Teachers WHERE IsProfessor = 1);

-- 5
SELECT Groups.Name 
FROM Groups 
JOIN GroupsCurators ON Groups.Id = GroupsCurators.GroupId 
GROUP BY Groups.Name 
HAVING COUNT(GroupsCurators.CuratorId) > 1;

-- 6
SELECT Groups.Name 
FROM Groups 
JOIN GroupsStudents ON Groups.Id = GroupsStudents.GroupId 
JOIN Students ON GroupsStudents.StudentId = Students.Id 
GROUP BY Groups.Name 
HAVING AVG(Students.Rating) < (SELECT MIN(AverageRating) 
                               FROM (SELECT AVG(Students.Rating) AS AverageRating 
                                     FROM Groups 
                                     JOIN GroupsStudents ON Groups.Id = GroupsStudents.GroupId 
                                     JOIN Students ON GroupsStudents.StudentId = Students.Id 
                                     WHERE Groups.Year = 5 
                                     GROUP BY Groups.Name) AS Subquery);

-- 7
SELECT Faculties.Name 
FROM Faculties 
JOIN Departments ON Faculties.Id = Departments.FacultyId 
GROUP BY Faculties.Name 
HAVING SUM(Departments.Financing) > (SELECT SUM(Financing) 
                                      FROM Departments 
                                      WHERE FacultyId = (SELECT Id FROM Faculties WHERE Name = 'Computer Science'));

-- 8
SELECT TOP 1 Subjects.Name, Teachers.Name, Teachers.Surname 
FROM Lectures 
JOIN Subjects ON Lectures.SubjectId = Subjects.Id 
JOIN Teachers ON Lectures.TeacherId = Teachers.Id 
GROUP BY Subjects.Name, Teachers.Name, Teachers.Surname 
ORDER BY COUNT(Lectures.Id) DESC;

-- 9
SELECT TOP 1 Subjects.Name 
FROM Subjects 
JOIN Lectures ON Subjects.Id = Lectures.SubjectId 
GROUP BY Subjects.Name 
ORDER BY COUNT(Lectures.Id) ASC;

-- 10
SELECT 
    (SELECT COUNT(DISTINCT GroupsStudents.StudentId) 
     FROM Groups 
     JOIN GroupsStudents ON Groups.Id = GroupsStudents.GroupId 
     WHERE Groups.DepartmentId = (SELECT Id FROM Departments WHERE Name = 'Software Development')) AS TotalStudents, 
    (SELECT COUNT(DISTINCT Lectures.SubjectId) 
     FROM Lectures 
     JOIN GroupsLectures ON Lectures.Id = GroupsLectures.LectureId 
     JOIN Groups ON Groups.Id = GroupsLectures.GroupId 
     WHERE Groups.DepartmentId = (SELECT Id FROM Departments WHERE Name = 'Software Development')) AS TotalSubjects;