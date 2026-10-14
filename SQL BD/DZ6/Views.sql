--Zagalne Info pro tovaru
CREATE VIEW ViewProductsSummary AS
SELECT 
    Products.ProductName,
    Products.Price,
    ProductConditions.ConditionName AS 'Condition',
    Products.AverageRating
FROM Products
JOIN ProductConditions ON Products.ConditionId = ProductConditions.ConditionId;
GO

--Vidgyku klienta
CREATE VIEW ViewCustomerReviews AS
SELECT 
    Customers.FirstName,
    Customers.LastName,
    Products.ProductName,
    Reviews.Rating,
    Reviews.ReviewText,
    Reviews.ReviewDate
FROM Reviews
JOIN Customers ON Reviews.CustomerId = Customers.CustomerId
JOIN Products ON Reviews.ProductId = Products.ProductId;
GO

--Pidsymku zamovlen
CREATE VIEW ViewOrdersSummary AS
SELECT 
    Orders.OrderDate,
    Customers.FirstName AS 'CustomerFirstName',
    Customers.LastName AS 'CustomerLastName',
    Products.ProductName,
    Orders.Quantity,
    Orders.TotalPrice
FROM Orders
JOIN Customers ON Orders.CustomerId = Customers.CustomerId
JOIN Products ON Orders.ProductId = Products.ProductId;
GO

SELECT * FROM ViewProductsSummary
SELECT * FROM ViewCustomerReviews
SELECT * FROM ViewOrdersSummary