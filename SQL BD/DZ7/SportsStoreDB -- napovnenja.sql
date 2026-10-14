INSERT INTO Products (ProductName, ProductCount, Manufacturer, Price, ProductType)
VALUES 
('Nike Air Zoom', 10, 'Nike', 1500, 'Взуття'),
('Adidas UltraBoost', 5, 'Adidas', 1800, 'Взуття'),
('Wilson Pro Staff', 7, 'Wilson', 2000, 'Ракетки'),
('Adidas Performance Tee', 15, 'Adidas', 800, 'Одяг'),
('Yonex Astrox 99', 4, 'Yonex', 2500, 'Ракетки'),
('Puma Running Shoes', 8, 'Puma', 1400, 'Взуття')


INSERT INTO Clients (FirstName, LastName, Email, RegistrationDate)
VALUES 
('John', 'Doe', 'john.doe@example.com', CONVERT(DATETIME, '2020-01-15', 102)),
('Jane', 'Smith', 'jane.smith@example.com', CONVERT(DATETIME, '2019-10-20', 102)),
('Alice', 'Johnson', 'alice.johnson@example.com', CONVERT(DATETIME, '2018-05-10', 102)),
('Bob', 'Brown', 'bob.brown@example.com', CONVERT(DATETIME, '2021-03-12', 102)),
('Charlie', 'Davis', 'charlie.davis@example.com', CONVERT(DATETIME, '2017-11-25', 102))


INSERT INTO Sellers (FirstName, LastName, TotalSales)
VALUES 
('Mark', 'Twain', 150000),
('Susan', 'Parker', 250000),
('Jim', 'Harvey', 175000)
GO
