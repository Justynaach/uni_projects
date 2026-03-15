--Wyœwietl wszystkie identyfikatory firm (CompanyName), które s¹ klientami (Customers) lub dostawcami (Suppliers), bez powtórzeñ.
SELECT CompanyName
FROM Customers
UNION
SELECT CompanyName
FROM Suppliers

--Wyœwietl wszystkie miasta wystêpuj¹ce wœród klientów i dostawców.
SELECT City
FROM Customers
UNION
SELECT City
FROM Suppliers

--Wyœwietl miasta, które wystêpuj¹ jednoczeœnie ( s¹ wspólne) u klientów, jak i dostawców.
SELECT City
FROM Customers
INTERSECT
SELECT City
FROM Suppliers

--Wyœwietl miasta, które wystêpuj¹ u klientów ale nie u dostawców.
SELECT City
FROM Customers
EXCEPT
SELECT City
FROM Suppliers

--Wyœwietl kraje zaczynaj¹ce siê na literê U, z których pochodz¹ klienci i pracownicy. Wyeliminuj duplikaty.
SELECT Country
FROM Customers
WHERE Country LIKE 'U%'
INTERSECT
SELECT Country
FROM Employees
WHERE Country LIKE 'U%';

--Wyœwietl identyfikatory pracowników, którzy s¹ przypisani do zamówieñ i jednoczeœnie maj¹ podw³adnych (czyli wystêpuj¹ jako Reports To).
SELECT EmployeeID
FROM Employees
WHERE ReportsTo IS NOT NULL
INTERSECT
SELECT EmployeeID
FROM Orders
--!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


--Poka¿ wszystkie kraje z tabeli Customers i Suppliers. Wyeliminuj duplikaty.
SELECT Country
FROM Customers
UNION
SELECT Country
FROM Suppliers

--Wyœwietl kraje, z których pochodz¹ klienci ale nie dostawcy.
SELECT Country
FROM Customers
EXCEPT
SELECT Country
FROM Suppliers

--Wyœwietl listê miast, w których znajduj¹ siê klienci, dostawcy lub pracownicy.
SELECT City
FROM Customers
UNION
SELECT City
FROM Suppliers
UNION 
SELECT City
FROM Employees

--Wyœwietl listê klientów, którzy nigdy nie z³o¿yli zamówieñ.
SELECT CustomerID
FROM Customers
EXCEPT
SELECT CustomerID
FROM Orders

--Wyœwietl wszystkie kombinacje pracowników i regionów (RegionDescription), do których mog¹ byæ przydzieleni.
SELECT e.EmployeeID, r.RegionDescription
FROM Employees as e
CROSS JOIN Region as r;
