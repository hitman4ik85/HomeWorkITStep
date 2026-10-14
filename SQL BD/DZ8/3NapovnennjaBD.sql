INSERT INTO Barbers (FullName, Gender, Phone, Email, BirthDate, HireDate, Position)
VALUES 
('John Smith', 'Чоловік', '+380 50 364 61 22', 'john.smith@barbershop.com', '1980-06-15', '2021-01-01', 'Чиф-барбер'),
('Jane Doe', 'Жінка', '+380 97 765 94 38', 'jane.doe@barbershop.com', '1983-08-20', '2022-06-15', 'Синьйор-барбер'),
('Tom Hardy', 'Чоловік', '+380 67 123 45 67', 'tom.hardy@barbershop.com', '1991-03-30', '2023-03-01', 'Джуніор-барбер'),
('Emma Stone', 'Жінка', '+380 98 876 54 32', 'emma.stone@barbershop.com', '1990-01-25', '2023-04-10', 'Синьйор-барбер'),
('Alex Brown', 'Чоловік', '+380 93 352 20 16', 'alex.brown@barbershop.com', '1982-04-15', '2018-05-20', 'Синьйор-барбер'),
('Nina White', 'Жінка', '+380 95 473 87 12', 'nina.white@barbershop.com', '1991-09-10', '2019-08-15', 'Джуніор-барбер'),
('Michael Green', 'Чоловік', '+380 91 521 47 31', 'michael.green@barbershop.com', '1985-12-01', '2022-12-01', 'Синьйор-барбер')
GO

INSERT INTO Services (ServiceName, Price, Duration)
VALUES 
('Стрижка', 300, 45),
('Гоління', 150, 30),
('Стрижка бороди', 200, 40),
('Традиційне гоління', 250, 50),
('Масаж голови', 100, 20)
GO

INSERT INTO BarberServices (BarberId, ServiceId)
VALUES 
(1, 1),  -- Чиф-барбер (John Smith) робить стрижку
(1, 4),  -- Чиф-барбер робить традиційне гоління
(2, 1),  -- Синьйор-барбер (Jane Doe) робить стрижку
(2, 3),  -- Синьйор-барбер робить стрижку бороди
(3, 5),  -- Джуніор-барбер (Tom Hardy) робить масаж голови
(4, 1),  -- Синьйор-барбер (Emma Stone) робить стрижку
(4, 2)  -- Синьйор-барбер робить гоління
GO

INSERT INTO Clients (FullName, Phone, Email)
VALUES 
('Michael Johnson', '+380 99 888 77 66', 'michael.johnson@client.com'),
('Sarah Parker', '+380 96 123 45 67', 'sarah.parker@client.com'),
('Chris Evans', '+380 63 555 44 33', 'chris.evans@client.com'),
('Emily Watson', '+380 92 111 22 33', 'emily.watson@client.com')
GO

INSERT INTO Feedbacks (BarberId, ClientId, FeedbackText, Rating)
VALUES 
(1, 1, 'Чудова стрижка, рекомендую!', 'Чудово'),
(2, 2, 'Стрижка бороди пройшла добре.', 'Добре'),
(3, 3, 'Масаж голови не сподобався.', 'Погано'),
(4, 4, 'Супер стрижка!', 'Чудово')
GO

INSERT INTO Schedule (BarberId, AvailableDate, AvailableTime, ClientId)
VALUES 
(1, '2024-10-15', '10:00', NULL),  -- John Smith вільний
(2, '2024-10-15', '12:00', 2),     -- Jane Doe зайнята з Sarah Parker
(3, '2024-10-16', '14:00', 3),     -- Tom Hardy зайнятий з Chris Evans
(4, '2024-10-16', '16:00', NULL)   -- Emma Stone вільна
GO

INSERT INTO Visits (ClientId, BarberId, ServiceId, VisitDate, TotalPrice, Rating, Feedback)
VALUES 
(1, 1, 1, '2024-10-01', 300, 'Чудово', 'Чудова стрижка, рекомендую!'),
(2, 2, 3, '2024-10-02', 200, 'Добре', 'Стрижка бороди пройшла добре.'),
(3, 3, 5, '2024-10-03', 100, 'Погано', 'Масаж голови не сподобався.'),
(4, 4, 2, '2024-10-04', 150, 'Чудово', 'Супер стрижка!')
GO