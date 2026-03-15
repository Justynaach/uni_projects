CREATE TABLE Pracownicy_Stacjonarni(
ID INT PRIMARY KEY,
Nazwisko VARCHAR(30),
Dzial VARCHAR(40) 
);

CREATE TABLE Pracownicy_Zdalni(
ID INT PRIMARY KEY,
Nazwisko VARCHAR(30),
Dzial VARCHAR(40) 
);

CREATE TABLE Dzialy(
Dzial VARCHAR(40) PRIMARY KEY,
Lokalizacja VARCHAR(50)
);

INSERT INTO Pracownicy_Stacjonarni 
(ID, Nazwisko, Dzial) 
VALUES
(101, 'Kowalski', 'IT'), 
(102, 'Nowak', 'HR'), 
(103, 'Wiœniewski', 'Sprzeda¿'), 
(104, 'D¹browski', 'IT'); 

INSERT INTO Pracownicy_Zdalni (ID, Nazwisko, Dzial) VALUES
(201, 'Kowalczyk', 'HR'), 
(202, 'Nowak', 'HR'),
(203, 'Lewandowski', 'Marketing'), 
(101, 'Kowalski', 'IT')


INSERT INTO Dzialy (Dzial, Lokalizacja) 
VALUES 
('IT', 'Kraków'), 
('HR', 'Warszawa'), 
('Sprzeda¿', 'Gdañsk'), 
('Marketing', 'Wroc³aw');

--Pobierz kompletn¹ listê unikalnych nazwisk wszystkich pracowników, zarównostacjonarnych, jak i zdalnych.
SELECT Nazwisko
FROM Pracownicy_Stacjonarni
UNION 
SELECT Nazwisko
FROM Pracownicy_Zdalni

-- Pobierz pe³n¹ listê wszystkich dzia³ówz etabel(Pracownicy_Stacjonarni i Pracownicy_Zdalni), wliczaj¹c w to duplikaty.wszystkich
SELECT dzial
FROM Pracownicy_Stacjonarni
UNION ALL
SELECT dzial
FROM Pracownicy_Zdalni

-- ZnajdŸ nazwiska pracowników, którzy maj¹ to samo nazwisko ORAZ pracuj¹ wtym samym dziale, ale figuruj¹ zarówno w tabeli Pracownicy_Stacjonarni,
--jak i Pracownicy_Zdalni. (Chcemy znaleŸæ wiersze, które s¹ identyczne wewszystkich kolumnach, poza ID).
SELECT Nazwisko, Dzial
FROM Pracownicy_Stacjonarni
INTERSECT
SELECT Nazwisko, Dzial
FROM Pracownicy_Zdalni;


-- ZnajdŸ nazwiska i dzia³y pracowników, którzy pracuj¹ wy³¹cznie w biurze, tj.s¹ w tabeli Pracownicy_Stacjonarni, ale nie ma ich w tabeli
--Pracownicy_Zdalni.
SELECT Nazwisko, Dzial
FROM Pracownicy_Stacjonarni
EXCEPT
SELECT Nazwisko, Dzial
FROM Pracownicy_Zdalni

-- Wygeneruj wszystkie mo¿liwe kombinacje ka¿dego pracownika z tabeli Pracownicy_Stacjonarni z ka¿d¹ lokalizacj¹ z tabeli Dzia³y
SELECT ps.*, dz.Lokalizacja
FROM Pracownicy_Stacjonarni as ps
CROSS JOIN Dzialy as dz 