CREATE TRIGGER DELETE_ChiefBarberInfo
ON Barbers
INSTEAD OF DELETE
AS
BEGIN
    IF EXISTS (SELECT * FROM deleted WHERE Position = 'Чиф-барбер')
    BEGIN
        IF (SELECT COUNT(*) FROM Barbers WHERE Position = 'Чиф-барбер') = 1
        BEGIN
            PRINT 'Неможливо видалити чиф-барбера, якщо немає іншого чиф-барбера.'
            RETURN;
        END
    END
    DELETE FROM BarberServices WHERE BarberId IN (SELECT BarberId FROM deleted)
    DELETE FROM Feedbacks WHERE BarberId IN (SELECT BarberId FROM deleted)
    DELETE FROM Schedule WHERE BarberId IN (SELECT BarberId FROM deleted)
    DELETE FROM Visits WHERE BarberId IN (SELECT BarberId FROM deleted)
    DELETE FROM Barbers WHERE BarberId IN (SELECT BarberId FROM deleted)
END
GO

CREATE TRIGGER NO_ADD_YoungBarber
ON Barbers
AFTER INSERT
AS
BEGIN
    DECLARE @youngBarbersCount INT;

    SELECT @youngBarbersCount = COUNT(*)
    FROM inserted
    WHERE DATEDIFF(YEAR, BirthDate, GETDATE()) < 21;

    IF @youngBarbersCount > 0
    BEGIN
        DELETE FROM BarberServices
        WHERE BarberId IN (
            SELECT BarberId
            FROM inserted
            WHERE DATEDIFF(YEAR, BirthDate, GETDATE()) < 21
        );
        DELETE FROM Barbers
        WHERE BarberId IN (
            SELECT BarberId
            FROM inserted
            WHERE DATEDIFF(YEAR, BirthDate, GETDATE()) < 21
        );
        PRINT 'Барбери молодше 21 року не можуть бути додані.';
    END
END