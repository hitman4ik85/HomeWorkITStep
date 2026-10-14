INSERT INTO Orders
VALUES
(
 (SELECT Id FROM Products WHERE ProductName = 'Iphone 12'),
 (SELECT Id FROM Customers WHERE FirstName = 'Tom'),
 GETDATE(),
 2
),

(
 (SELECT Id FROM Products WHERE ProductName = 'Galaxy S22'),
 (SELECT Id FROM Customers WHERE FirstName = 'Bob'),
 GETDATE(),
 1
),

(
 (SELECT Id FROM Products WHERE ProductName = 'Pixel 8 Pro'),
 (SELECT Id FROM Customers WHERE FirstName = 'Alice'),
 GETDATE(),
 1
),

(
 (SELECT Id FROM Products WHERE ProductName = 'MacBook Air M1'),
 (SELECT Id FROM Customers WHERE FirstName = 'Sam'),
 GETDATE(),
 1
),

(
 (SELECT Id FROM Products WHERE ProductName = 'Sony WH-1000XM4'),
 (SELECT Id FROM Customers WHERE FirstName = 'John'),
 GETDATE(),
 3
);