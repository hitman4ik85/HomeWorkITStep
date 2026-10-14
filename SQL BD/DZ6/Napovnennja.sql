-- Prodavci
INSERT INTO Sellers (StoreName, ContactPhone, Email) 
VALUES 
('TechStore', '+123456789', 'techstore@example.com'),
('GadgetWorld', '+987654321', 'gadgetworld@example.com'),
('FashionHub', '+380987123456', 'fashionhub@example.com'),
('BookZone', '+380999876543', 'bookzone@example.com'),
('HomeGoods', '+380555666777', 'homegoods@example.com');

-- Klientu
INSERT INTO Customers (FirstName, LastName, Phone, Email) 
VALUES 
('John', 'Doe', '+380123456789', 'john@example.com'),
('Jane', 'Smith', '+380987654321', 'jane@example.com'),
('Alice', 'Johnson', '+380321456987', 'alice@example.com'),
('Bob', 'Williams', '+380654987123', 'bob@example.com'),
('Emma', 'Brown', '+380777888999', 'emma@example.com');

-- Stan tovary
INSERT INTO ProductConditions (ConditionName) 
VALUES 
('New'),
('Used'),
('Refurbished'),
('Open Box'),
('Damaged');

-- Tovaru
INSERT INTO Products (ProductName, Price, ConditionId, SellerId, Description, AverageRating) 
VALUES 
('iPhone 12', 800, 1, (SELECT SellerId FROM Sellers WHERE StoreName = 'TechStore'), 'Brand new iPhone 12', 4.8),
('Samsung Galaxy S10', 500, 2, (SELECT SellerId FROM Sellers WHERE StoreName = 'GadgetWorld'), 'Used Samsung Galaxy S10', 4.0),
('Leather Jacket', 150, 1, (SELECT SellerId FROM Sellers WHERE StoreName = 'FashionHub'), 'New leather jacket', 4.5),
('The Great Gatsby', 20, 2, (SELECT SellerId FROM Sellers WHERE StoreName = 'BookZone'), 'Used classic book', 4.7),
('Sofa', 300, 3, (SELECT SellerId FROM Sellers WHERE StoreName = 'HomeGoods'), 'Refurbished sofa', 4.2);

-- Vidgyku
INSERT INTO Reviews (ProductId, CustomerId, Rating, ReviewText) 
VALUES 
((SELECT ProductId FROM Products WHERE ProductName = 'iPhone 12'), (SELECT CustomerId FROM Customers WHERE FirstName = 'John'), 5, 'Amazing product!'),
((SELECT ProductId FROM Products WHERE ProductName = 'Samsung Galaxy S10'), (SELECT CustomerId FROM Customers WHERE FirstName = 'Jane'), 4, 'Good phone, but battery life could be better.'),
((SELECT ProductId FROM Products WHERE ProductName = 'Leather Jacket'), (SELECT CustomerId FROM Customers WHERE FirstName = 'Alice'), 5, 'Great quality leather!'),
((SELECT ProductId FROM Products WHERE ProductName = 'The Great Gatsby'), (SELECT CustomerId FROM Customers WHERE FirstName = 'Bob'), 5, 'Loved the book!'),
((SELECT ProductId FROM Products WHERE ProductName = 'Sofa'), (SELECT CustomerId FROM Customers WHERE FirstName = 'Emma'), 4, 'Comfortable, but minor scratches.');

-- Zamovlennja
INSERT INTO Orders (CustomerId, ProductId, Quantity, TotalPrice) 
VALUES 
((SELECT CustomerId FROM Customers WHERE FirstName = 'John'), (SELECT ProductId FROM Products WHERE ProductName = 'iPhone 12'), 1, 800),
((SELECT CustomerId FROM Customers WHERE FirstName = 'Jane'), (SELECT ProductId FROM Products WHERE ProductName = 'Samsung Galaxy S10'), 1, 500),
((SELECT CustomerId FROM Customers WHERE FirstName = 'Alice'), (SELECT ProductId FROM Products WHERE ProductName = 'Leather Jacket'), 2, 300),
((SELECT CustomerId FROM Customers WHERE FirstName = 'Bob'), (SELECT ProductId FROM Products WHERE ProductName = 'The Great Gatsby'), 3, 60),
((SELECT CustomerId FROM Customers WHERE FirstName = 'Emma'), (SELECT ProductId FROM Products WHERE ProductName = 'Sofa'), 1, 300);