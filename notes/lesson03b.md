# Data Languages in a Relational Environment

The video can be found [here](https://www.youtube.com/watch?v=vO7A3kkvdJ8)

## Overview

- Intro to relational DB systems
- SQL data definition language
- SQL data manipulation language
- SQL views
- SQL indices
- SQL privileges
- Embedded SQL

## Intro to Relational DB Systems

- Relational DBs are maintained by relational DB management systems (RDBMS),
  which implement the relational model
- SQL is used both for data definition & manipulation
  - is *set-oriented*: can retrieve many records at once
  - *delcarative*: only need to specify *which* data to retrieve
- SQL as a data definition language (DDL)
  - logical schema: `CREATE TABLE`
  - Physical schema: `CREATE DATABASE`, `CREATE TABLESPACE`, `CREATE INDEX`
  - External schema: `CREATE VIEW`
- SQL as a data manipulation language (DML)
  - `SELECT ... FROM ... WHERE ...`
  - `INSERT ... INTO ...`
  - `UPDATE ... WHERE ...`
  - `DELETE ... WHERE ...`
- Also: specifying security, transaction control, ...
- SQL language specifics
  - free form
  - most SQL implementations are case *insensitive*
  - several commercial implementations w/their own SQL dialects exist
  - DDL
  - DML

## SQL Data Definition Language (DDL)

- A schema is a grouping of tables & other constructs (constraints, views, etc.)
  that logically belong together
  - identified by a *schema name* & includes an *authorization identifier* to
    indicate the user or account who owns the schema

```sql
CREATE SCHEMA PURCHASE AUTHORIZATION JAYESS;
```

- A table implements a relation from the relational model & can have multiple
  columns (attribute types) & multiple rows (tuples)
  - identified by a table name & can be created using the `CREATE TABLE`
    statement

```sql
CREATE TABLE PRODUCT ...
CREATE TABLE PURCHASE.PRODUCT ...
```

- A *domain* is a user-defined data type
  - improves maintainability in case the domain can be reused by multiple
    attributes
  - *note*: **not** supported in MySQL

```sql
CREATE DOMAIN PRODTYPE_DOMAIN AS VARCHAR(15)
CHECK (VALUE IN ('white', 'red', 'rose', 'sparkling'));
```

- Referential integrity constrains specify what to do upon update or deletion of
  a referenced DB object (e.g., a tuple, table, view, etc.)

| Command                        | Effect                                                          |
| ------------------------------ | --------------------------------------------------------------- |
| `ON UPDATE/DELETE CASCADE`     | Cascades the update/delete to the referring objects             |
| `ON UPDATE/DELETE RESTRICT`    | Restricts the update/delete in case referring objects exist     |
| `ON UPDATE/DELETE SET NULL`    | Sets the referring values to `NULL` in case of update/delete    |
| `ON UPDATE/DELETE SET DEFAULT` | Sets the referring values to `DEFAULT` in case of update/delete |

- `DROP SCHEMA PURCHASE CASCADE`: automatically drop objects (tables, views,
  indices, etc.) that are contained in the schema
- `DROP SCHEMA PURCHASE RESTRICT`: refuse to drop the schema if it contains any
  objects (this is the default behavior)
- `DROP TABLE PURCHASE CASCADE`: automatically drop objects (tables, views,
  indices, etc.) that depend on the table
- `DROP TABLE PURCHASE RESTRICT`: refuse to drop the table if it contains any
  objects (this is the default behavior)

- Table column definitions can be modified using the `ALTER TABLE` statement
- Common actions are
  - adding/dropping column
  - changing a column definition
  - adding/dropping table constraints

```sql
ALTER TABLE PRODUCT ADD PRODIMAGE BLOB;
ALTER TABLE SUPPLIER ALTER SUPSTATUS SET DEFUALT '10';
```
