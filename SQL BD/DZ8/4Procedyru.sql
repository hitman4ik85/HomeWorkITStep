CREATE PROCEDURE GetAll_PIB_Barbers AS
BEGIN
    SELECT FullName 
    FROM Barbers
END
GO

CREATE PROCEDURE GetSeniorInfoBarbers AS
BEGIN
    SELECT * 
    FROM Barbers 
    WHERE Position = 'Синьйор-барбер'
END
GO

CREATE PROCEDURE GetBarbersInfoForTradishShaving AS
BEGIN
    SELECT Barbers.FullName
    FROM Barbers
    JOIN BarberServices ON Barbers.BarberId = BarberServices.BarberId
    JOIN Services ON BarberServices.ServiceId = Services.ServiceId
    WHERE Services.ServiceName = 'Традиційне гоління'
END
GO

CREATE PROCEDURE GetBarbersByService
    @serviceName NVARCHAR(50)
AS
BEGIN
    SELECT Barbers.FullName
    FROM Barbers
    JOIN BarberServices ON Barbers.BarberId = BarberServices.BarberId
    JOIN Services ON BarberServices.ServiceId = Services.ServiceId
    WHERE Services.ServiceName = @serviceName
END
GO

CREATE PROCEDURE GetBarbersPonadKilkistRokiv
    @years INT
AS
BEGIN
    SELECT FullName, DATEDIFF(YEAR, HireDate, GETDATE()) AS Experience
    FROM Barbers
    WHERE DATEDIFF(YEAR, HireDate, GETDATE()) > @years
END
GO

CREATE PROCEDURE GetBarberCounts AS
BEGIN
    SELECT 
        (SELECT COUNT(*) FROM Barbers WHERE Position = 'Синьйор-барбер') AS SeniorBarbers,
        (SELECT COUNT(*) FROM Barbers WHERE Position = 'Джуніор-барбер') AS JuniorBarbers
END
GO

CREATE PROCEDURE GetPermanentClients
    @minVisits INT
AS
BEGIN
    SELECT Clients.FullName
    FROM Clients
    JOIN Visits ON Clients.ClientId = Visits.ClientId
    GROUP BY Clients.FullName
    HAVING COUNT(Visits.VisitId) >= @minVisits
END
GO