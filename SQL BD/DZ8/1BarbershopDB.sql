CREATE DATABASE BarbershopDB
GO

USE BarbershopDB
GO

CREATE TABLE Barbers (
    BarberId INT IDENTITY PRIMARY KEY,
    FullName NVARCHAR(50) NOT NULL,
    Gender NVARCHAR(10),
    Phone NVARCHAR(20),
    Email NVARCHAR(30),
    BirthDate DATE,
    HireDate DATE NOT NULL,
    Position NVARCHAR(20)
)
GO

CREATE TABLE Services (
    ServiceId INT IDENTITY PRIMARY KEY,
    ServiceName NVARCHAR(50) NOT NULL,
    Price MONEY,
    Duration INT
)
GO

CREATE TABLE BarberServices (
    BarberId INT FOREIGN KEY REFERENCES Barbers(BarberId),
    ServiceId INT FOREIGN KEY REFERENCES Services(ServiceId),
    PRIMARY KEY (BarberId, ServiceId)
)
GO

CREATE TABLE Clients (
    ClientId INT IDENTITY PRIMARY KEY,
    FullName NVARCHAR(50) NOT NULL,
    Phone NVARCHAR(20),
    Email NVARCHAR(30)
)
GO

CREATE TABLE Feedbacks (
    FeedbackId INT IDENTITY PRIMARY KEY,
    BarberId INT FOREIGN KEY REFERENCES Barbers(BarberId),
    ClientId INT FOREIGN KEY REFERENCES Clients(ClientId),
    FeedbackText NVARCHAR(MAX),
    Rating NVARCHAR(20)
)
GO

CREATE TABLE Schedule (
    ScheduleId INT IDENTITY PRIMARY KEY,
    BarberId INT FOREIGN KEY REFERENCES Barbers(BarberId),
    AvailableDate DATE,
    AvailableTime TIME,
    ClientId INT FOREIGN KEY REFERENCES Clients(ClientId) NULL
)
GO

CREATE TABLE Visits (
    VisitId INT IDENTITY PRIMARY KEY,
    ClientId INT FOREIGN KEY REFERENCES Clients(ClientId),
    BarberId INT FOREIGN KEY REFERENCES Barbers(BarberId),
    ServiceId INT FOREIGN KEY REFERENCES Services(ServiceId),
    VisitDate DATE,
    TotalPrice MONEY,
    Rating NVARCHAR(20),
    Feedback NVARCHAR(MAX)
)
GO