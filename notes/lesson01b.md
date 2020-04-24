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

