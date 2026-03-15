--Wybierz nazwy i ceny produktów (baza northwind) o cenie jednostkowej pomiêdzy 20.00 a 30.00, dla ka¿dego produktu podaj dane adresowe dostawcy.
SELECT ProductName, UnitPrice, Address
FROM Products as p
INNER JOIN Suppliers as s
ON p.SupplierID=s.SupplierID
WHERE UnitPrice between 20 and 30

--Wybierz nazwy produktów oraz inf. o stanie magazynu dla produktów dostarczanych przez firmê ‘Tokyo Traders’.
SELECT ProductName, UnitsInStock
FROM Products
INNER JOIN Suppliers 
ON Products.SupplierID=Suppliers.SupplierID
WHERE CompanyName='Tokyo Traders'

--Czy s¹ jacyœ klienci którzy nie z³o¿yli ¿adnego zamówienia w 1997 roku, jeœli tak to poka¿ ich dane adresowe.
SELECT c.CustomerID, c.Address
FROM Customers as c
LEFT JOIN Orders as o
ON C.CustomerID=O.CustomerID
AND  Year(o.OrderDate)=1997
WHERE OrderID IS NULL
  
--Wybierz nazwy i numery telefonów dostawców, dostarczaj¹cych produkty, których aktualnie nie ma w magazynie.
SELECT CompanyName, Phone
from Suppliers as s
LEFT JOIN Products as p
ON s.SupplierID=p.SupplierID
WHERE UnitsInStock=0
--left join i warunek where daje inner join?

--Wybierz nazwy i ceny produktów o cenie jednostkowej pomiêdzy 20.00 a 30.00, dla ka¿dego produktu podaj dane adresowe dostawcy, 
--interesuj¹ nas tylko produkty z kategorii ‘Meat/Poultry’
SELECT ProductName, UnitPrice, s.Address
FROM Products as p
INNER JOIN Suppliers as s
ON p.SupplierID=s.SupplierID
INNER JOIN Categories as c
ON p.CategoryID=c.CategoryID
WHERE ( UnitPrice between 20 and 30 ) and CategoryName='Meat/Poultry'

--Wybierz nazwy i ceny produktów z kategorii „Confections” dla ka¿dego produktu podaj nazwê dostawcy.
SELECT ProductName, UnitPrice, CompanyName
FROM Products as p
INNER JOIN Suppliers as s
ON p.SupplierID=s.SupplierID
INNER JOIN Categories as c
ON p.CategoryID=c.CategoryID
WHERE CategoryName='Confections'

-- Wybierz nazwy i numery telefonów klientów , którym w 1997 roku przesy³ki dostarcza³a firma ‘United Package’.
SELECT DISTINCT c.CompanyName, c.Phone
FROM Customers c
INNER JOIN Orders o
    ON c.CustomerID = o.CustomerID
INNER JOIN Shippers s
    ON o.ShipVia = s.ShipperID
WHERE YEAR(o.OrderDate) = 1997
  AND s.CompanyName = 'United Package';

-- Wybierz nazwy i numery telefonów klientów, którzy kupowali produkty z kategorii „Confections”.
SELECT DISTINCT c.CompanyName, c.Phone
FROM Customers AS c
INNER JOIN Orders as o 
ON c.CustomerID=o.CustomerID 
INNER JOIN [Order Details] as od 
ON o.OrderID=od.OrderID 
INNER JOIN Products as p 
ON od.ProductID=p.ProductID
INNER JOIN Categories as cc
ON p.CategoryID=cc.CategoryID
WHERE cc.CategoryName='Confections'

-- Dla ka¿dego zamówienia podaj ³¹czn¹ liczbê zamówionych jednostek towaru oraz nazwê klienta.
SELECT od.OrderID, c.CompanyName, SUM(od.Quantity)
FROM Customers AS c
INNER JOIN Orders as o
ON c.CustomerID=o.CustomerID
INNER JOIN [Order Details] AS od
ON od.OrderID=o.OrderID
GROUP BY od.OrderID, c.CompanyName

--Zmodyfikuj poprzedni przyk³ad, aby pokazaæ tylko takie zamówienia, dla których ³¹czna liczbê zamówionych jednostek jest wiêksza ni¿ 250.
SELECT od.OrderID, c.CompanyName, SUM(od.Quantity)
FROM Customers AS c
INNER JOIN Orders as o
ON c.CustomerID=o.CustomerID
INNER JOIN [Order Details] AS od
ON od.OrderID=o.OrderID
GROUP BY od.OrderID, c.CompanyName
HAVING SUM(od.Quantity) >250

-- Dla ka¿dego zamówienia podaj ³¹czn¹ wartoœæ tego zamówienia oraz nazwê klienta.
SELECT o.OrderID, c.CompanyName, SUM(od.UnitPrice*od.Quantity*(1-od.Discount)) as kwota
FROM Customers as c
INNER JOIN Orders as o
ON c.CustomerID=o.CustomerID
INNER JOIN [Order Details] as od
ON od.OrderID=o.OrderID
GROUP BY o.OrderID, c.CompanyName

-- Zmodyfikuj poprzedni przyk³ad, aby pokazaæ tylko takie zamówienia, dla których ³¹czna wartoœæ zamówienia jest wiêksza ni¿ 1000.
SELECT o.OrderID, c.CompanyName, SUM(od.UnitPrice*od.Quantity*(1-od.Discount)) as kwota
FROM Customers as c
INNER JOIN Orders as o
ON c.CustomerID=o.CustomerID
INNER JOIN [Order Details] as od
ON od.OrderID=o.OrderID
GROUP BY o.OrderID, c.CompanyName
HAVING SUM(od.UnitPrice*od.Quantity*(1-od.Discount))>1000

--dodane orderid bo przez group by companyid pokazywalo zamowieia dla danego klienta !!!!!!
--!!!!!!!!!!!!!!

-- Zmodyfikuj poprzedni przyk³ad tak ¿eby dodaæ jeszcze imiê i nazwisko pracowników (wyœwietlone razem w jednej kolumnie) obs³uguj¹cych zamówienia.
SELECT o.OrderID, c.CompanyName, SUM(od.UnitPrice*od.Quantity*(1-od.Discount)) as kwota, e.FirstName +' '+e.LastName as imienazwisko
FROM Customers as c
INNER JOIN Orders as o
ON c.CustomerID=o.CustomerID
INNER JOIN [Order Details] as od
ON od.OrderID=o.OrderID
INNER JOIN Employees as e
ON o.EmployeeID=e.EmployeeID
GROUP BY o.OrderID, c.CompanyName,  e.FirstName +' '+e.LastName
HAVING SUM(od.UnitPrice*od.Quantity*(1-od.Discount))>1000

-- Dla ka¿dego przewoŸnika (nazwa) podaj liczbê zamówieñ, które przewieŸli w 1997r.
SELECT s.CompanyName, COUNT(o.OrderID)
FROM Shippers as s
LEFT JOIN Orders as o
ON s.ShipperID=o.ShipVia AND YEAR(o.OrderDate)=1997
GROUP BY s.CompanyName

-- Dla ka¿dego pracownika (imiê i nazwisko) podaj ³¹czn¹ wartoœæ zamówieñ obs³u¿onych przez tego pracownika.
SELECT e.FirstName+' '+e.LastName as imie_nazw, SUM(od.UnitPrice*od.Quantity*(1-od.Discount)) as kwota
FROM Employees as e
INNER JOIN Orders as o
ON e.EmployeeID=o.EmployeeID
INNER JOIN [Order Details] as od
ON o.OrderID=od.OrderID
GROUP BY e.EmployeeID, e.FirstName, e.LastName;

--Który z pracowników obs³u¿y³ najwiêksz¹ liczbê zamówieñ w 1997r, podaj imiê i nazwisko takiego pracownika.
SELECT TOP 1 e.FirstName+' '+e.LastName as imie_nazw, COUNT(DISTINCT o.OrderID) AS liczba_zamowien
FROM Employees as e
INNER JOIN Orders as o
ON e.EmployeeID=o.EmployeeID
INNER JOIN [Order Details] as od
ON o.OrderID=od.OrderID AND YEAR(o.OrderDate)=1997
GROUP BY e.FirstName+' '+e.LastName
ORDER BY COUNT(DISTINCT o.OrderID) DESC

--Napisz polecenie, które wyœwietla pracowników oraz ich podw³adnych (baza northwind).
SELECT 
    szef.FirstName + ' ' + szef.LastName AS Szef,
    pracownik.FirstName + ' ' + pracownik.LastName AS Podwladny
FROM Employees szef
LEFT JOIN Employees pracownik
    ON pracownik.ReportsTo = szef.EmployeeID;

--Napisz polecenie, które wyœwietla pracowników, którzy nie maj¹ podw³adnych
SELECT 
 szef.FirstName + ' ' + szef.LastName AS Szef
FROM Employees as szef
LEFT JOIN Employees as  pracownik
ON pracownik.ReportsTo=szef.EmployeeID
WHERE pracownik.EmployeeID IS NULL;

-- Dla ka¿dego pracownika (imiê i nazwisko) podaj ³¹czn¹ wartoœæ zamówieñ obs³u¿onych przez tego pracownika. 
--Ogranicz wynik tylko do pracowników którzy maj¹ podw³adnych

--nie ogarniam tego w ogole
SELECT 
    e.FirstName + ' ' + e.LastName AS Pracownik,
    SUM(od.UnitPrice * od.Quantity * (1 - od.Discount)) AS kwota
FROM Employees e
INNER JOIN Employees p
    ON p.ReportsTo = e.EmployeeID       -- e ma podw³adnych
INNER JOIN Orders o
    ON o.EmployeeID = e.EmployeeID      -- zamówienia SZEFa
INNER JOIN [Order Details] od
    ON od.OrderID = o.OrderID
GROUP BY e.EmployeeID, e.FirstName, e.LastName;


