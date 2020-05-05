## SQL: The Strcutured Query Language

The video can be found [here](https://www.youtube.com/watch?v=kqUIoOM3WEs)

## Topic Objects

- Learn
    - basic SQL statements for creating DB structures
    - SQL statements to add data to a DB
    - basic SQL SELECT statements
        - and options for querying a single table
        - for querying multiple tables with subqueries
        - for querying multiple tables with joins
    - basic SQL statements to modify & delete data from DB
    - SQL statements to modify & delete data from a DB
    - SQL statements to modify & delete data from DB tables & constraints

## Structured Query Language

- Originally developed by IBM as the SEQUEL language in the '70s
- Designed to support Edgar Codd's relational model
- Based on relational algebra
- ANSI/ISO standard

## SQL Defined

- Not a programming language, but rather a data sub-language
- Comprised of a
    - data definition language (DDL)
        - Used to define & manage DB structures
    - data manipulation language (DML)
        - data definition & updating
        - data retrieval (queries)
        - i.e., CRUD operations
    - data control language (DCL)
        - For creating user accounts, managing permissions, etc.

### SQL for Data Definition

- SQL data definition statements include
    - CREATE
        - to create DB objects
    - ALTER
        - to modify the structure and/or characteristics of existing DB objects
    - DROP
        - to delete existing DB objects

#### SQL for Data definition: CREATE

- Creating DB tables
    - the SQL CREATE TABLE statement

```sql
CREATE TABLE Employee (
    empId       Integer     NOT NULL,
    empName     Char(25)    NOT NULL
);
```

#### SQL for Data Definition: CREATE with CONSTRAINT 1

- Creating DB tables with PRIMARY KEY constraints
    - the SQL CREATE TABLE statement
    - the SQL CONSTRAINT keyword

```sql
CREATE TABLE Employee (
    empId       Integer     NOT NULL,
    empName     Char(25)    NOT NULL,
    CONSTRAINT  empPk       PRIMARY KEY(empId)
);
```

- this tells the DB that we want to use the `empId` attribute as the primary
  key which must be unique

#### SQL for Data Definition: CREATE with CONSTRAINT 2

- Creating DB tables with composite primary keys using PRIMARY KEY constraints
    - the SQL CREATE TABLE statement
    - the SQL CONSTRAINT keyword

```sql
CREATE TABLE Employee (
    empId       Integer     NOT NULL,
    skillId     Integer     NOT NULL,
    skillLevel  Integer     NULL,
    CONSTRAINT  empSkillPk  PRIMARY KEY(empId, skillId)
);
```

#### SQL for Data Definition: CREATE with CONSTRAINT 3

- Creating DB tables using PRIMARY KEY and FOREIGN KEY constraints
    - the SQL CREATE TABLE statement
    - the SQL CONSTRAINT keyword

```sql
CREATE TABLE Employee (
    empId       Integer     NOT NULL,
    skillId     Integer     NOT NULL,
    skillLevel  Integer     NULL,
    CONSTRAINT  empSkillPk  PRIMARY KEY(empId, skillId),
    CONSTRAINT  empFk       FOREIGN KEY(empId)   REFERENCES Employee(empId),
    CONSTRAINT  skillFk     FOREIGN KEY(skillId) REFERENCES Skill(skillId)
);
```

#### SQL for Data Definition: CREATE with CONSTRAINT 4

- Creating DB tables using PRIMARY KEY and FOREIGN KEY constraints
    - the SQL CREATE TABLE statement
    - the SQL CONSTRAINT keyword
    - ON UPDATE CASCADE and ON DELETE CASCADE

```sql
CREATE TABLE Employee (
    empId       Integer     NOT NULL,
    skillId     Integer     NOT NULL,
    skillLevel  Integer     NULL,
    CONSTRAINT  empSkillPk  PRIMARY KEY(empId, skillId),
    CONSTRAINT  empFk       FOREIGN KEY(empId)
        REFERENCES Employee(empId) ON DELETE CASCADE,
    CONSTRAINT  skillFk     FOREIGN KEY(skillId)
        REFERENCES Skill(skillId) ON UPDATE CASCADE
);
```

- `ON DELETE CASCADE`: used to help maintain maintain integrity & quality of
  data in DB
  - when one record in the `Employee` table is deleted, all associated records
    in the `EmployeeSkill` table are deleted (a cascaded delete) automatically
    by the DB
- `ON UPDATE CASCADE`: used to help maintain maintain integrity & quality of
  data in DB
  - e.g., if a primary key value in the `Skill` table is changed, it will
    automatically update the value in the `EmployeeSkill` table

#### Primary Key Constraint: ALTER 1

- Adding primary key constraints to an existing table
  - the SQL ALTER statement

```sql
ALTER TABLE Employee ADD CONSTRAINT empPk PRIMARY KEY(empId);
```

#### Primary Key Constraint: ALTER 2

- Adding a composite primary key constraint to an existing table
  - the SQL ALTER statement

```sql
ALTER TABLE EmployeeSkill ADD CONSTRAINT empSkillPk PRIMARY KEY(empId, skillId);
```

#### Primary Key Constraint: ALTER 3

- Adding foreign key constraints to an existing table
  - the SQL ALTER statement

```sql
ALTER TABLE Employee ADD CONSTRAINT empFk FOREIGN KEY(deptId)
    REFERENCES Department(deptId);
```

### Modifying Data Using SQL

- INSERT INTO
  - will add a new row to a table
- UPDATE
  - will update the rows in a table which match the specified criteria
- DELETE FROM
  - will delete the rows in a table which match the specified criteria

#### Adding Data: INSERT INTO

- To add a row to an existing table, use the `INSERT INTO` statement
- Non-numeric data must be enclosed in single quotes (`'`)

```sql
INSERT INTO Employee (empId, salaryCode, lastName) VALUES (62, 11, 'Halpert');
```

#### Modifying Data Using SQL: Changing Data Values: UPDATE

- To change the data values in an existing row (or a set of rows), use the SQL
  `UPDATE` statement

```sql
UPDATE    Employee
SET       phone = '657-278-1234'
WHERE     empId = 29;

UPDATE    Employee
SET       deptId = 4
WHERE     empName LIKE `Da%';

UPDATE    Employee
SET       deptId = 3;
```

- often, the shortest statement can cause the most changes (e.g., the last
  `UPDATE` statement)

#### Modifying Data Using SQL: Deleting Data: DELETE

- To delete a row (or a set of rows) from a table, use the `DELETE FROM`
  statement

```sql
DELETE FROM Employee
WHERE  empId = 29;

DELETE FROM Employee
WHERE  empName LIKE `Da%';

DELETE FROM Employee;
```

### SQL for Data Retrieval: Queries

- `SELECT` is the best known SQL statement
- `SELECT` will retrieve info from the DB that matches the specified criteria
  using a `SELECT`/`FROM`/`WHERE` framework

```sql
SELECT    empName
FROM      Employee
WHERE     empId = 33;

SELECT    empName
FROM      Employee;
```

#### SQL for Data Retrieval: The Resultset is a Relation

- A query pulls information from one or more relations & creates (temporarily) a
  new relation
- This allows the query to
  - create a new relation
  - feed information into another query (as a *subquery*)
- The resultset may7 not be in 3NF
  - especially when performing a *join*

#### SQL for Data Retrieval: Displaying Multiple Columns

- To show values for two or more specific columns, use a comma-separated list
  of column names

```sql
SELECT  empId, empName
FROM    Employee;
```

#### SQL for Data Retrieval: Displaying All Columns

- To show all of the column values for the rows that match the specified
  criteria, use an asterisk (`*`)

```sql
SELECT  *
FROM    Employee;
```

#### SQL for Data Retrieval: Each Row Only Once

- The `DISTINCT` keyword may be added to the `SELECT` statement to suppress the
  display of duplicate rows

```sql
SELECT  DISTINCT deptId
FROM    Employee;
```

#### SQL for Data Retrieval: Specifying Search Criteria

- The `WHERE` cause specifies the matching or filtering criteria for the records
  (rows) that are to be displayed

```sql
SELECT  empName
FROM    Employee
WHERE   deptId = 15;
```

#### SQL for Data Retrieval: Match Criteria

- `WHERE` clause comparisons may include
  - Equals `=`
  - Not equals `!=`
  - Greater than `>`
  - Less than `<`
  - Greater than or equal to `>=`
  - Less than or equal to `<=`

#### SQL for Data Retrieval: Match Operators

- Multiple matching criteria may be specified using
  - `AND`: representing an intersection of the data sets
  - `OR`: representing a union of the data sets
  - Concepts such as intersection & union are derived from relational algebra

#### SQL for Data Retrieval: Operator Examples

```sql
SELECT  empName
FROM    Employee
WHERE   deptId < 7 OR deptId > 12;

SELECT  empName
FROM    Employee
WHERE   deptId = 9 AND salaryCode <= 13;
```

#### SQL for Data Retrieval: A List of Values

- The `WHERE` clause may include the `IN` keyword to specify a particular
  column value must match one of the values in a list
  - This is much more convenient than using a series of `OR` operators

```sql
SELECT  empName
FROM    Employee
WHERE   deptId IN (4, 8, 9);
```

- Compare to

```sql
WHERE deptId = 4 OR deptId = 8 OR deptId = 9;
```

#### SQL for Data Retrieval: The Logical NOT Operator

- Any criteria statements can be preceded by a `NOT` operator in order to invert
  the results
  - Using `NOT` will return all information *except* the information matching
    the specified criteria

```sql
SELECT  empName
FROM    Employee
WHERE   deptId NOT IN (4, 8, 9);
```

#### SQL for Data Retrieval: Finding Data in a Range of Values

- SQL provides a `BETWEEN` keyword that allows a user to specify a minimum and
  maximum value on one line
  - it is *inclusive*

```sql
SELECT  empName
FROM    Employee
WHERE   salaryCode BETWEEN 10 AND 45;
```

- compare to

```sql
WHERE   salaryCode >= 10 AND salaryCode <= 45;
```

#### SQL for Data Retrieval: Wildcard Searches

- The SQL `LIKE` keyword allows for searches on partial data values
- `LIKE` can be paired with wildcards to find rows that partially match a string
  value
  - The multiple character wildcard character is `%`
  - The single character wildcard character is `_`

#### SQL for Data Retrieval: Wildcard Search Examples

```sql
SELECT  empId
FROM    Employee
WHERE   empName LIKE `Da%';

SELECT  empName
FROM    Employee
WHERE   phone LIKE `657-278-____';
```

#### SQL for Data Retrieval: Sorting the Resultset

- Query results may be sorted using the `ORDER BY` clause
  - ascending (default) vs descending sorts

```sql
SELECT  *
FROM    Employee
WHERE   ORDER BY empName;
```

- use `ASC` or `DESC` to specify ascending or descending sort, respectively

#### SQL for Data Retrieval: Built-in Numeric Functions

- SQL provides several build-in numeric functions
  - `COUNT`: counts the number of rows that match the specified criteria
  - `MIN`: finds the minimum value for a specific column for those rows matching
    the criteria
  - `MAX`: finds the maximum value for a specific column for those rows matching
    the criteria
  - `SUM`: calculates the sum for a specific column for those rows matching the
    criteria
  - `AVG`: calculates the numerical average (mean) for a specific column for
    those rows matching the criteria
  - `STDEV`: calculates the standard deviation of the values in a specific
    numeric column for those rows matching the criteria

#### SQL for Data Retrieval: Built-in Function Examples

```sql
SELECT  COUNT(*)
FROM    Employee;

SELECT  MIN(hours) AS minimumHours,
        MAX(hours) AS maximumHours,
        AVG(hours) AS averageHours,
FROM    Project
WHERE   ProjectID > 7;
```

#### SQL for Data Retrieval: Providing Subtotals: GROUP BY

- Categorized results can be retrieved by using the `GROUP BY` clause

```sql
SELECT    deptId,
          COUNT(*) AS numberOfEmployees
FROM      Employee
GROUP BY  deptId;
```

#### SQL for Data Retrieval: Providing Subtotals: GROUP BY with HAVING

- The `HAVING` clause may optionally be used with a `GROUP BY` clause in order
  to restrict which categories are displayed
  - serves the same purpose of a `WHERE` clause, but with a `GROUP BY`
    statement

```sql
SELECT    salespersonId, salespersonLastName,
          SUM(saleAmount) as totalSales
FROM      Sales
GROUP BY  salespersonId, salespersonLastName
HAVING    SUM(saleAmount) >= 10000;
```

#### SQL for Data Retrieval: Retrieving Information from Multiple Tables

- Subqueries
  - the result of a query is a *relation*. The results from one query may
    therefore be used as input for another query (i.e., a *subquery*)
    - Noncorrelated & correlated subqueries

#### SQL for Data Retrieval: Noncorrelated Subquery Example

- In a noncorrelated subquery, the inner query only needs to run once in order
  for the DB engine to solve the problem

```sql
SELECT  empName
FROM    Employee
WHERE   (SELECT deptId
         FROM   Department
         WHERE  deptName LIKE 'Account%');
```

#### SQL for Data Retrieval: Correlated Subquery Example

- In a correlated subquery, the inner query needs to be run many times in order
  for the DB engine to solve the problem
  - the inner query needs a value from the outer query in order to run

```sql
SELECT  empName
FROM    Employee e
WHERE   empSalary >
        (SELECT AVG(empSalary)
         FROM   Employee
         WHERE  deptId e.deptId);
```

- Note that `e` is an alias for the `Employee` table and allows us to refer to
  the `Employee` table in the outer query just by using the letter `e`

#### SQL for Data Retrieval: Retrieving Information from Multiple Tables

- Joins
  - Another way of combining data from multiple tables
  - Inner joins
  - Outer joins
    - left
    - full
    - right

#### SQL for Data Retrieval: WHERE Clause Inner Join Example

- Implicit inner join in the `WHERE` clause

```sql
SELECT  empName, depName
FROM    Employee AS E, Department AS D
WHERE   E.deptId = D.deptId;
```

#### SQL for Data Retrieval: JOIN... ON Example

- The `JOIN... ON` syntax can be also used to perform a join
  - has the advantage of moving the `JOIN` syntax into the `FROM` clause
    so that it can be used for other filtering purposes

```sql
SELECT  empName, depName
FROM    Employee e INNER JOIN Department d
        ON e.deptId = d.deptId
WHERE   d.deptName NOT LIKE 'Account%';
```

#### SQL for Data Retrieval: LEFT OUTER JOIN Example

- The `OUTER JOIN` syntax can be used to obtain data that exists in one table
  without matching dta in the other table
- `Employee` is the left table & `Department` is the right table
  - "Give me a list of all the employees, regardless if they have a matching
    department, but if they have a matching department include it as well"
  - this will include all employees, whether or not they have an associated
    department

```sql
SELECT  empName, deptName
FROM    Employee e LEFT OUTER JOIN Department d
        ON e.deptId = d.deptId;
```

#### SQL for Data Retrieval: RIGHT OUTER JOIN Example

- The unmatched data displayed can come from either table, depending on whether
  `RIGHT OUTER JOIN` or a `LEFT OUTER JOIN` is used
- Include all the departments regardless of whether or not there's an employee
  assigned to the department

```sql
SELECT  empName, deptName
FROM    Employee e RIGHT OUTER JOIN Department d
        ON e.deptId = d.deptId;
```

#### SQL for Data Retrieval: FULL OUTER JOIN Example

- The unmatched data displayed from either table are included in the results if
  a `FULL OUTER JOIN` is used
-

```sql
SELECT  empName, deptName
FROM    FULL OUTER JOIN Department d
             ON e.deptId = d.deptId;
```

#### Modifying Data Using SQL: Deleting Database Objects: DROP

- To remove unwanted DB objects from the DB, use the SQL `DROP` statement
- **WARNING**: the `DROP` statement will permanently remove the object and all
  of its associated data

```sql
DROP TABLE Employee;
```

#### Modifying Data Using SQL: Removing a Constraint: ALTER & DROP

- To change the constraints on existing tables, you may beed to remove the
  existing constrains before new constraints can be added

```sql
ALTER TABLE Employee DROP CONSTRAINT empFk;
```

#### Modifying Data Using SQL: The CHECK Constraint

- The `CHECK` constraint can be used to create restrictions on the values that
  are allowed to appear in a column

```sql
ALTER TABLE Project
      ADD CONSTRAINT projectCheckDates
            CHECK (startDate < endDate);
```

## SQL Views

- *virtual table* created by a DBMS-stored `SELECT` statement which can combine
  access to data in multiple tables & even other views

```sql
CREATE VIEW SalesDepartment AS
SELECT *
FROM Employee
WHERE deptId = (SELECT deptId FROMDepartment WHERE deptName = 'Sales');
```

- You can run a query against a view in the same way that you run a query
  against a table

```sql
SELECT empName FROM SalesDepartment;
```
