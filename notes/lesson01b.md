# Introduction to Database Management Systems 1: Fundamental Concepts

Video can be found [here](https://www.youtube.com/watch?v=6u2zsJOJ_GE)

## Overview

- Applications of DB technology
- Definitions
- File based vs DB based approach to data management
- Elements of a DB system
  - Data model
  - Schemas and instances
  - The three-schema architecture
  - Data dictionary (catalog)
  - DBMS languages
- Advantages of DB design

## Applications of DB Technology

- Storage & retrieval of "traditional" numeric & alphanumeric data
  - Stock administration: keeping track of the number of products in stock
- Storage & retrieval of multimedia data (images, video, sound, etc.)
  - YouTube
- Monitor data, autonomously take action when required
  - High-frequency trading: constantly maintain a database of stock prices,
    process updates in less than 1 ms, including buying/selling stocks
- Storage & retrieval of Web content (HTML, PDF, etc.)
  - Google
- Storage of large datasets for analysis (data warehouses)
  - Walmart: collection & analysis of customer purchasing behavior for shop
    floor optimization

## Definitions

- Database: collection of interrelated data, which
  - represents some aspects of (a subset of) the real world
  - is logically coherent with some inherent meaning
  - has an intended group of users & applications
- Database Management Systems (DBMS): a collection of programs that enables us
  to create & maintain a DB. It is a general-purpose software system that
  facilitates the process of *defining*, *constructing*, and *manipulating* DBs
  for various applications
- Database system: consists of the combination of a DBMS & a DB

## File-Based Approach to Data Management

- Results in duplicated data

- Querying the data example
  -- File-based (pseudo-code)
```
find person(name: input, record: output)
begin
open people
repeat while people has next
  people -> go to next record
  record := people -> current record
  if record -> person is name
    done
  else
    continue
  end
end
record := invalid
end
```

  - Database (SQL)

```sql
SELECT *
FROM people
WHERE
name = $NAME
```

- Waste of storage space because of duplicates
  - inconsistent data
- Strong dependency between applications and data
  - Change in data definition necessitates changes in a ll applications that
    use the data
- Difficult to integrate various applications
  - High difficulty -> high cost
- A DB-Oriented Approach to Data Management
  - Advantages
    - Database:
      - The DBMS contains both the data & a description of the DB structure &
        constraints (stored in the *catalog*)
      - Changing the structure of the DBMS would require updating the catalog, 
        but not the applications (*program-data independence*)
      - Different views over (a subset of) the data can be defined which allows
        different users w/different needs to use the same data
      - Multiple users can access the same data at the same time (DBMS includes
        *concurrency control* to ensure no conflicting operations are executed)
    - File-based
      - Only the data is stored in a file & the structure of the data is stored 
        in the *applications* that will access the file
      - Changing the structure of a file would require changing each 
        application that accesses it
      - Different views would require copying (parts of ) some files & any 
        changes made to those duplicates should be carefully merged in all other
        duplicates
      - It's impossible to have multiple people or applications working on the 
        same file at the same time (no concurrency)

## Elements of a DB System

- Data model
- Schemas & instances
- The three-schema architecture
- Data dictionary (catalog)
- DBMS languages

### Data Model

- Definition: collection of concepts that can be used to describe the structure
  of a DB (i.e., the data types, relationships, constrains, etc.)
- Types of data models
  - *Conceptual*: high-level concepts, a representation of (part of) reality,
    close to how the user perceives the data
  - *Implementation*: concepts that may be understood by end users, but are not
    too far removed from physical data organization (hide some details of data
    storage, but can be implemented on a computer system in a direct way)
    - E.g., the hierarchical model, network model, relation model, ODMG model
  - *Physical*: low-level concepts that describe the data's physical storage
    details

### Schemas, Instances, DB State

- In any data model, it's important to distinguish between the *description* of 
  the data and the *data itself*
- *DB schema*: description of a DB, which is specified during DB design & is
  not expected to change too frequently (i.e., the catalog)
- *DB state*: the data in the DB at a particular moment, also called the current
  set of *instances* (i.e., the data currently in the DB)

#### Sample Extract of a University DB

- DB schema

```
STUDENT  (number, name, address, email)
COURSE   (number, name)
BUILDING (number, address)
...
```

- DB state

```
STUDENT
------------------------------------------------------------------
Number    Name          Address           Email
0165854   Jane Doe      154 West Str      jane.doe@school.edu
0168975   Fred Astere   7 Scene Field Str fred.astere@school.edu
0157895   Kyara Welton  89 5th Ave        kyara.welton@school.edu
------------------------------------------------------------------

COURSE
------------------------------------------------------------------
Number    Name
D0I69A    ICT Service Management
D0R04A    Strategic Management
D0T21A    Macro Economics
------------------------------------------------------------------

BUILDING
------------------------------------------------------------------
Number    Address
0589      Street 69
0365      Street 78
0589      Avenue 115
------------------------------------------------------------------
```

