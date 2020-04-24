# Introduction to Databases

The video lecture can be found [here](https://www.youtube.com/watch?v=4Z9KEBexzcM)

## Topic Objectives

- Know the potential problems with lists
- Understand the reasons for using a DB
- Understand how related tables avoid the problems associated with lists
- Learn the components of a database system
- Learn the elements of a database
- Learn the purpose of a DMBS
- Understand the functions of a database application

## Purpose of a Database

- The purpose of a DB is to
  - store data
  - provide an organization structure for the data
    - in business, there are many natural, hierarchical relation among data
      - a customer can have many orders
      - a department can have many employees
      - an employee can only work in one department
  - provide a mechanism for querying, creating, modifying, & deleting data
    - Create, Read, Update, & Delete (C.R.U.D.) operations
- A database can store information & relationships that are more complicated
  than a list

## Problems with Lists

### Redundancy

- In a list, each row is intended to stand on its own. As a result, the same 
  information may entered several times

### Multiple Themes

- In a list, each row may contain information on more than one theme or 
  business concept
  - As a result, certain information may appear in the list only if information 
    about other themes or business concepts is also present
      - E.g., a list of projects may include project manager info (name, ID, 
        etc.) and project info (name, ID, start date, budget) in the same row
 
### Modification Issues

- Redundancy & multiple themes in lists create modification problems
  - Deletion
  - Update
  - Insertion

## Addressing Information Complexities

- Relational DBs are designed to address many of the information complexity
  issues that arise in business

## Relational DBs

- Stores information in tables
    - Each informational "theme" (business concept) is stored in its own table
- Breaks up a list into several parts
  - One part for each theme in the list
    - E.g., a Project list may be divided into CUSTOMER, PROJECT, & 
      PROJECT_MANAGER tables

## Putting the Pieces Back Together

- Need to somehow join the tables back together
- In an RDB, tables are joined together using matched pairs of values (e.g.,
  using a customer ID)

## Sounds Like More Work, Not Less

- An RDB is more complicated than a list
- An RDB minimizes data redundancy, preserves complex relationships among 
  topics, & allows for partial data (NULL values)
- An RDB provides a solid foundation for creating user interface forms & 
  reports

## Structured Query Language (SQL)
- Is an international language for creating, processing, & querying DBs & their
  tables
- Vast majority of data-driven applications & websites use SQL to retrieve, 
  format, report, insert, delete, and/or modify data for users

## SQL Example

- Can use SQL to combine the data in the three tables in the Art Course Database
  to recreate the original list structure of the data
  - Do this with a SQL *SELECT* statement


## DB Systems

- Four components of a DB system
  1. Users
  2. DB application(s)
  3. DBMS
  4. DB

### Users

- A user of a DB system will
    - Use a DB system application to keep track of info
    - Use different UI forms to enter, read, delete, & query data
    - Produce reports

### The DB

- A DB is a self-describing collection of related records
- Self-describing
  - DB itself contains the definition of its structure
  - Metadata: data describing the structure of the data in the DB
- Tables w/in an RDB are related to each other in some way
- Contents
  - User data
  - Metadata
  - Indexes and other overhead data
  - Application metadata

## DB Management System (DBMS)

- Serves as an intermediary between DB applications & the DB
- Manages & controls DB activities
- Creates, processes, & administers the DB it controls

### Functions of DBMS

- Create DBs
- Create tables
- Create supporting structures
- CRUD operations
- Maintain DB structures
- Enforce rules
- Control concurrency
- Provide security
- Perform data backup & recovery

### Referential Integrity Constraints

- A DBMS can enforce many constraints
- **Referential integrity constraints** ensure that the values of a column in 
  one table are valid based on the values in another table
    - E.g., if a 5 was entered as a CustomerID in the PROJECT table, a Customer
    having CustomerID value of 5 **must** exist in the CUSTOMER table

### DB Applications

- A set of one or more computer programs or websites that serve as an 
  intermediary between the user & the DBMS
    - Don't interact w/DB directly, go through DBMS instead

### Personal DB Systems

- Typically
  - Support one application
  - Have only a few tables
  - Are simple in design
  - Involve only one computer
  - Support one user at a time

### Enterprise-Level DB Systems

- Typically
  - Support several users simultaneously
  - Support more than one application
  - Involve multiple computers
  - Are more complex in design
  - Have many tables
  - Have many databases


