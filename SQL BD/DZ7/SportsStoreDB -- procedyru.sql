CREATE PROC ShowAllProducts AS
BEGIN
    SELECT * FROM Products
END
GO

CREATE PROC ShowProductsByType
    @productType NVARCHAR(30)
AS
BEGIN
    SELECT * 
    FROM Products
    WHERE ProductType = @productType
END
GO

CREATE PROC ShowTop3OldestClients AS
BEGIN
    SELECT TOP 3 *
    FROM Clients
    ORDER BY RegistrationDate ASC
END
GO

CREATE PROC ShowMostSuccessfulSeller AS
BEGIN
    SELECT TOP 1 *
    FROM Sellers
    ORDER BY TotalSales DESC
END
GO

CREATE PROC CheckProductByManufacturer
    @manufacturer NVARCHAR(100),
    @result NVARCHAR(3) OUTPUT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Products WHERE Manufacturer = @manufacturer)
    BEGIN
        SET @result = 'yes'
    END
    ELSE
    BEGIN
        SET @result = 'no'
    END
END
GO

CREATE PROC ShowMostPopularManufacturer AS
BEGIN
    SELECT TOP 1 Manufacturer
    FROM Products
    GROUP BY Manufacturer
    ORDER BY SUM(Price * ProductCount) DESC
END
GO

CREATE PROC DeleteClientsAfterDate
    @date DATETIME,
    @deletedCount INT OUTPUT
AS
BEGIN
    DELETE FROM Clients
    WHERE RegistrationDate > @date

    SET @deletedCount = @@ROWCOUNT
END
GO




EXEC ShowAllProducts

DECLARE @productType NVARCHAR(30) = 'Взуття'
EXEC ShowProductsByType @productType

EXEC ShowTop3OldestClients

EXEC ShowMostSuccessfulSeller

DECLARE @manufacturer NVARCHAR(100) = 'Adidas'
DECLARE @result NVARCHAR(3)
EXEC CheckProductByManufacturer @manufacturer, @result OUTPUT
PRINT 'Result: ' + @result

EXEC ShowMostPopularManufacturer

DECLARE @date DATETIME = '2020-01-01'
DECLARE @deletedCount INT
EXEC DeleteClientsAfterDate @date, @deletedCount OUTPUT
PRINT 'Deleted records: ' + CONVERT(NVARCHAR, @deletedCount)
GO



DROP PROC ShowAllProducts
GO
DROP PROC ShowProductsByType
GO
DROP PROC ShowTop3OldestClients
GO
DROP PROC ShowMostSuccessfulSeller
GO
DROP PROC CheckProductByManufacturer
GO
DROP PROC ShowMostPopularManufacturer
GO
DROP PROC DeleteClientsAfterDate
GO

