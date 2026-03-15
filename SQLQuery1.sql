--Wybierz nazwy i adresy wszystkich klientów maj¹cych siedziby w Londynie.
SELECT CompanyName, Address
FROM Customers
WHERE City = 'London'

-- Wybierz nazwy i adresy wszystkich klientów maj¹cych siedziby we Francji lub w Hiszpanii.
SELECT CompanyName, Address
FROM Customers
WHERE Country in  ('France','Spain')

--Wybierz nazwy i ceny produktów o cenie jednostkowej pomiêdzy 20.00 a 30.00.
SELECT ProductName, UnitPrice
FROM Products
WHERE UnitPrice BETWEEN 20 AND 30

--Wybierz nazwy produktów, których nie ma w magazynie
SELECT ProductName
FROM Products
WHERE UnitsInStock = 0

--Szukamy informacji o produktach sprzedawanych w butelkach (‘bottle’).
SELECT *
FROM Products
WHERE QuantityPerUnit LIKE '%bottle%'

--Wyszukaj informacje o stanowisku pracowników, których nazwiska zaczynaj¹ siê na literê z zakresu od B do L.
SELECT *
FROM Employees
WHERE LastName LIKE '[B-L]%'

--Wyszukaj informacje o stanowisku pracowników, których nazwiska zaczynaj¹ siê na literê B lub L.
SELECT *
FROM Employees
WHERE LastName LIKE '[BL]%'

--ZnajdŸ nazwy kategorii, które w opisie zawieraj¹ przecinek.
SELECT CategoryName
FROM Categories
WHERE Description LIKE '%,%'

--ZnajdŸ klientów, którzy w swojej nazwie maj¹ w którymœ miejscu s³owo 'Store'
SELECT *
FROM Customers
WHERE CompanyName LIKE '%Store%'

--Szukamy informacji o produktach o cenach mniejszych ni¿ 10 lub wiêkszych ni¿ 20.
SELECT *
FROM Products
WHERE UnitPrice <10 OR UnitPrice>20

--Wybierz zamówienia z³o¿one w 1997 roku
SELECT *
FROM Orders
WHERE Year(OrderDate) = 1997

--Wybierz nazwy i kraje wszystkich klientów, wyniki posortuj wed³ug kraju, w
--ramach danego kraju nazwy firm posortuj alfabetycznie.
SELECT Country, CompanyName
FROM Customers
ORDER BY Country, CompanyName

--Wybierz nazwy i kraje wszystkich klientów maj¹cych siedziby we Francji lub
--w Hiszpanii, wyniki posortuj wed³ug kraju, w ramach danego kraju nazwy firm posortuj alfabetycznie.
SELECT Country, CompanyName
FROM Customers
WHERE Country in ('France','Spain')
ORDER BY Country, CompanyName

--Wybierz zamówienia z³o¿one w 1997 r. Wynik po sortuj malej¹co wg numeru
--miesi¹ca, a w ramach danego miesi¹ca rosn¹co wed³ug ceny za przesy³kê.
SELECT *
FROM Orders
WHERE Year(OrderDate) = 1997
ORDER BY Month(OrderDate) DESC, Freight

-- Napisz instrukcjê select tak aby wybraæ numer zlecenia, datê zamówienia, 
--numer klienta dla wszystkich niezrealizowanych  zleceñ, dla których 
 --krajem odbiorcy jest Argentyna
 SELECT OrderID, OrderDate, CustomerID
 FROM Orders
 WHERE ShipCountry = 'Argentina' AND ShippedDate IS NULL

--Napisz polecenie, które oblicza wartoœæ ka¿dej pozycji zamówienia o numerze 10250.
SELECT OrderID,
       ProductID,
       UnitPrice * Quantity * (1 - Discount) AS WartoscPozycji
FROM [Order Details]
WHERE OrderID = 10250;
--!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11

--Napisz polecenie które dla ka¿dego dostawcy (supplier) poka¿e pojedyncz¹
--kolumnê zawieraj¹c¹ nr telefonu i nr faksu w formacie (numer telefonu i
--faksu maj¹ byæ oddzielone przecinkiem)
SELECT CONCAT(Phone,',',Fax) AS Kontakt
FROM Suppliers
--!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

-------------------------------------------------------------------------------------------------------------------------------------------------------------
--Podaj maksymaln¹ cenê produktu dla produktów o cenach poni¿ej 20.
SELECT MAX(UnitPrice)
FROM Products
WHERE UnitPrice<20

--Podaj maksymaln¹ i minimaln¹ i œredni¹ cenê produktu dla produktów sprzedawanych w butelkach (‘bottle’).
SELECT MAX(UnitPrice), MIN(UnitPrice), AVG(UnitPrice)
FROM Products
WHERE QuantityPerUnit LIKE '%bottle%'

--Wyœwietl informacje o wszystkich produktach o cenie powy¿ej œredniej.
SELECT *
FROM Products
WHERE UnitPrice> (  select AVG(UnitPrice) 
                    from products)
--!!!!!!!!!!!!!!!!!!!!!!!!!

--Podaj sumê/wartoœæ zamówienia o numerze 10250.
SELECT SUM(Quantity * UnitPrice * (1 - Discount)) AS wartosc_zamowienia
FROM [Order Details]
WHERE OrderID = 10250;

--Podaj maksymaln¹ i minimaln¹ cenê zamawianego produktu dla ka¿dego zamówienia.
SELECT 
    OrderID,
    MAX(UnitPrice) AS MaxPrice,
    MIN(UnitPrice) AS MinPrice
FROM [Order Details]
GROUP BY OrderID;

--Posortuj zamówienia wg maksymalnej ceny produktu.
SELECT OrderID, Max(UnitPrice)
FROM [Order Details]
GROUP BY OrderID
ORDER BY Max(UnitPrice)

--Podaj liczbê zamówieñ dostarczanych przez poszczególnych spedytorów (przewoŸników).
SELECT COUNT(OrderID), ShipVia
FROM Orders
GROUP BY ShipVia

--Wyœwietl zamówienia dla których liczba pozycji zamówienia jest wiêksza ni¿ 5. 
SELECT 
    OrderID,
    COUNT(*) AS ItemsCount
FROM [Order Details]
GROUP BY OrderID
HAVING COUNT(*) > 5;

--Wyœwietl klientów dla których w 1998 roku zrealizowano wiêcej ni¿ 8 zamówieñ (wyniki posortuj malej¹co wg ³¹cznej kwoty za dostarczenie zamówieñ dla ka¿dego z klientów).
SELECT CustomerID, COUNT(OrderID) AS liczba_zam, SUM(Freight) AS laczna_kwota
FROM Orders
WHERE YEAR(OrderDate)=1997 
GROUP BY CustomerID
HAVING COUNT(OrderID) >8
ORDER BY SUM(Freight) DESC

--Napisz polecenie, które oblicza wartoœæ sprzeda¿y dla ka¿dego zamówienia w tabeli ORDER DETAILS i zwraca wynik posortowany w malej¹cej kolejnoœci (wg wartoœci sprzeda¿y).
SELECT (Quantity * UnitPrice * (1 - Discount)) AS kwota
FROM [Order Details]
ORDER BY kwota DESC


--Zmodyfikuj zapytanie z poprzedniego punktu, tak aby zwraca³o pierwszych 10 wierszy.
SELECT TOP 10 (Quantity*UnitPrice-(1-Discount)) as kwota
FROM [Order Details]
ORDER BY (Quantity*UnitPrice-Discount) DESC

-- Podaj liczbê zamówionych jednostek produktów dla produktów, dla których productid jest mniejszy ni¿ 3.
SELECT ProductID,SUM(Quantity) AS liczba_zamowionych
FROM [Order Details]
WHERE ProductID < 3
GROUP BY ProductID;

--Zmodyfikuj zapytanie z poprzedniego punktu, tak aby podawa³o liczbê zamówionych jednostek produktu dla wszystkich produktów.
SELECT ProductID,SUM(Quantity) AS liczba_zamowionych
FROM [Order Details]
GROUP BY ProductID;

--Podaj nr zamówienia oraz wartoœæ zamówienia, dla zamówieñ, dla których ³¹czna liczba zamawianych jednostek produktów jest wiêksza ni¿ 250.
SELECT 
    OrderID,
    SUM(Quantity) AS liczba_zamowionych,
    SUM(Quantity * UnitPrice * (1 - Discount)) AS wartosc_zamowienia
FROM 
    [Order Details]
GROUP BY 
    OrderID
HAVING 
    SUM(Quantity) > 250
ORDER BY 
    wartosc_zamowienia DESC;

-- Dla ka¿dego pracownika podaj liczbê obs³ugiwanych przez niego zamówieñ.
SELECT COUNT(*), EmployeeID
FROM Orders
GROUP BY EmployeeID

-- Dla ka¿dego spedytora/przewoŸnika podaj ³¹czn¹ wartoœæ „op³at za przesy³kê” dla przewo¿onych przez niego zamówieñ.
SELECT ShipVia, SUM(Freight)
FROM Orders
GROUP BY ShipVia

-- Dla ka¿dego spedytora/przewoŸnika podaj ³¹czn¹ wartoœæ „op³at za przesy³kê” przewo¿onych przez niego zamówieñ w latach od 1996 do 1997.
SELECT ShipVia, SUM(Freight)
FROM Orders
WHERE YEAR(OrderDate) between 1996 and 1997
GROUP BY ShipVia

--Dla ka¿dego pracownika podaj liczbê obs³ugiwanych przez niego zamówieñ z podzia³em na lata i miesi¹ce.
SELECT EmployeeID, MONTH(OrderDate) as miesiac, YEAR(OrderDate) as rok, count(*)
FROM Orders
GROUP BY EmployeeID, MONTH(OrderDate), YEAR(OrderDate)

-- Dla ka¿dej kategorii podaj maksymaln¹ i minimaln¹ cenê produktu w tej kategorii.
SELECT CategoryID, MAX(UnitPrice) as maxim, MIN(UnitPrice) as minim
FROM Products
GROUP BY CategoryID

--ZnajdŸ nazwy miast w Brazylii, w których mamy wiêcej ni¿ jednego klienta.
SELECT City, COUNT(CustomerID)
FROM Customers
WHERE Country='Brazil'
Group by City
HAVING COUNT(CustomerID)>1

--Napisz zapytanie, które policzy pracowników ze wzglêdu na stanowisko i kraj zatrudnienia.
SELECT Country, Title, COUNT(EmployeeID)
FROM Employees
GROUP BY Title, Country

--Podaj œredni wiek (AVG) pracownika w ramach stanowiska i kraju pochodzenia, a tak¿e informacjê o najstarszym (MIN) i najm³odszym z nich (MAX) – wykorzystaj funkcjê (GATEDATE)
SELECT Country, Title, COUNT(EmployeeID) as ilosc_prac, 
avg(datediff(year, BirthDate, GETDATE())) , 
MIN(YEAR(GETDATE())-YEAR(BirthDate)) as min_age, 
MAX(YEAR(GETDATE())-YEAR(BirthDate)) as max_age 
FROM Employees
GROUP BY Title, Country

--albo

SELECT Country, Title, COUNT(EmployeeID) AS ilosc_prac, 
       AVG(DATEDIFF(year, BirthDate, GETDATE())) AS wiek_sredni, 
       MIN(DATEDIFF(year, BirthDate, GETDATE())) AS min_age, 
       MAX(DATEDIFF(year, BirthDate, GETDATE())) AS max_age
FROM Employees
GROUP BY Country, Title;
