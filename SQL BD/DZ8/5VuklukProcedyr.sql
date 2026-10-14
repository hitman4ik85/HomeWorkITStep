EXEC GetAll_PIB_Barbers;

EXEC GetSeniorInfoBarbers;

EXEC GetBarbersInfoForTradishShaving;

DECLARE @service NVARCHAR(50) = 'Традиційне гоління';
EXEC GetBarbersByService @service;

DECLARE @years INT = 3;
EXEC GetBarbersPonadKilkistRokiv @years;

EXEC GetBarberCounts;

DECLARE @visitCount INT = 1;
EXEC GetPermanentClients @visitCount;