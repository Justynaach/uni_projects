 --Wybierz nazwy i numery telefonów klientów , którym w 1997 roku przesy³ki dostarcza³a firma United Package.
 SELECT Phone, CompanyName
 FROM Customers
 WHERE CustomerID IN (
 SELECT o.CustomerID
    FROM Orders o
    JOIN Shippers s ON o.ShipVia = s.ShipperID
    WHERE s.CompanyName = 'United Package'
      AND YEAR(o.ShippedDate) = '1997'
)

--Wybierz nazwy i numery telefonów klientów, którzy kupowali produkty z kategorii Seafood.
SELECT CompanyName, Phone
FROM Customers
WHERE CustomerID IN (
SELECT o.CustomerID FROM Orders as o
INNER JOIN [Order Details] as od
ON o.OrderID=od.OrderID
INNER JOIN Products as p
ON od.ProductID=p.ProductID
INNER JOIN Categories as c
ON p.CategoryID=c.CategoryID
WHERE c.CategoryName='Seafood')

SELECT c.CompanyName, c.Phone
FROM Customers c
WHERE EXISTS (
    SELECT CustomerID
    FROM Orders o
    INNER JOIN [Order Details] od ON o.OrderID = od.OrderID
    INNER JOIN Products p ON od.ProductID = p.ProductID
    INNER JOIN Categories cat ON p.CategoryID = cat.CategoryID
    WHERE o.CustomerID = c.CustomerID
      AND cat.CategoryName = 'Seafood'
);


--Wybierz nazwy i numery telefonów klientów, którzy nie kupowali produktów z kategorii Seafood
SELECT CompanyName, Phone
FROM Customers
WHERE CustomerID NOT IN (
SELECT o.CustomerID FROM Orders as o
INNER JOIN [Order Details] as od
ON o.OrderID=od.OrderID
INNER JOIN Products as p
ON od.ProductID=p.ProductID
INNER JOIN Categories as c
ON p.CategoryID=c.CategoryID
WHERE CategoryName='Seafood')

--Poka¿ wszystkie produkty których cena jest mniejsza ni¿ œrednia cena produktu.
SELECT UnitPrice
FROM Products p
WHERE UnitPrice < (SELECT AVG(UnitPrice) FROM Products ps WHERE p.ProductID=ps.ProductID)

--Podaj wszystkie produkty których cena jest mniejsza ni¿ œrednia cena produktu danej kategorii.
SELECT p.UnitPrice
FROM Products as p
WHERE p.UnitPrice < ( SELECT AVG(p2.UnitPrice)
    FROM Products p2
    WHERE p2.CategoryID = p.CategoryID)


--Podaj ³¹czn¹ wartoœæ zamówienia o numerze 10250 (uwzglêdnij cenê zaprzesy³kê).
SELECT Freight+(SELECT SUM(UnitPrice*Quantity*(1-Discount) ) 
FROM [Order Details] WHERE OrderID=10250) as koszt
FROM Orders
WHERE OrderID=10250

--Podaj ³¹czn¹ wartoœæ ka¿dego zamówienia (uwzglêdnij cenê za przesy³kê).
SELECT Freight+(SELECT SUM(UnitPrice*Quantity*(1-Discount) ) 
FROM [Order Details]) as koszt
FROM Orders

--Czy s¹ jacyœ klienci którzy nie z³o¿yli ¿adnego zamówienia w 1997 roku, jeœli
--tak to poka¿ ich dane adresowe.
SELECT Address
FROM Customers
WHERE CustomerID NOT IN ( SELECT CustomerID
FROM Orders
WHERE Year(OrderDate) = '1997')

--Poka¿ produkty, które s¹ dro¿sze ni¿ jakikolwiek produkt z kategorii „Beverages”.
SELECT *
FROM Products
WHERE UnitPrice > (
    SELECT MAX(p.UnitPrice)
    FROM Products p
    INNER JOIN Categories c 
    ON p.CategoryID = c.CategoryID
    WHERE c.CategoryName = 'Beverages'
);

--Dla ka¿dego produktu podaj maksymaln¹ wartoœæ zakupu tego produktu (dla
--wszystkich zamówieñ tego produktu).



