USE Academy;
GO
-- 1. Вивести таблицю кафедр, але розташувати її поля у зворотному порядку.
SELECT Name, Financing, Id FROM Departments;

-- 2. Вивести назви груп та їх рейтинги, використовуючи, як назви полів, що виводяться, "Group Name" та "Group Rating" відповідно.
SELECT Name AS 'Group Name', Rating AS 'Group Rating' FROM Groups;

-- 3. Вивести для викладачів їхнє прізвище, відсоток ставки по відношенню до надбавки та відсоток ставки по відношенню до зарплати (сума ставки та надбавки).
SELECT Surname, 
       (Premium / Salary) * 100 AS 'Premium %', 
       (Salary / (Salary + Premium)) * 100 AS 'Salary %' 
FROM Teachers;

-- 4. Вивести таблицю факультетів у вигляді одного поля у форматі: "The dean of faculty [faculty] is [dean]."
SELECT 'The dean of faculty ' + Name + ' is ' + Dean AS FacultyInfo FROM Faculties;

-- 5. Вивести прізвища викладачів, які є професорами та ставка яких перевищує 1050.
SELECT Surname FROM Teachers WHERE IsProfessor = 1 AND Salary > 1050;

-- 6. Вивести назви кафедр, фонд фінансування яких менший за 11000 або більше 25000.
SELECT Name FROM Departments WHERE Financing < 11000 OR Financing > 25000;

-- 7. Вивести назви факультетів, окрім факультету "Computer Science".
SELECT Name FROM Faculties WHERE Name <> 'Computer Science';

-- 8. Вивести прізвища та посади викладачів, які не є професорами.
SELECT Surname, Position FROM Teachers WHERE IsProfessor = 0;

-- 9. Вивести прізвища, посади, ставки та надбавки асистентів, у яких надбавка у діапазоні від 160 до 550.
SELECT Surname, Salary, Premium FROM Teachers WHERE IsAssistant = 1 AND Premium BETWEEN 160 AND 550;

-- 10. Вивести прізвища та ставки асистентів.
SELECT Surname, Salary FROM Teachers WHERE IsAssistant = 1;

-- 11. Вивести прізвища та посади викладачів, які були прийняті на роботу до 01.01.2000.
SELECT Surname, Position FROM Teachers WHERE EmploymentDate < '2000-01-01';

-- 12. Вивести назви кафедр, які в алфавітному порядку розміщуються до кафедри "Software Development". Поле, що виводиться повинно мати назву "Name of Department".
SELECT Name AS 'Name of Department' FROM Departments WHERE Name < 'Software Development';

-- 13. Вивести прізвища асистентів, які мають зарплату (сума ставки та надбавки) не більше 1200.
SELECT Surname FROM Teachers WHERE IsAssistant = 1 AND (Salary + Premium) <= 1200;

-- 14. Вивести назви груп 5-го курсу, які мають рейтинг у діапазоні від 2 до 4.
SELECT Name FROM Groups WHERE Year = 5 AND Rating BETWEEN 2 AND 4;

-- 15. Вивести прізвища асистентів зі ставкою менше 550 або надбавкою менше 200.
SELECT Surname FROM Teachers WHERE IsAssistant = 1 AND (Salary < 550 OR Premium < 200);