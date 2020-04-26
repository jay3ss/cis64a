# The Relational Model

The video can be found [here](https://www.youtube.com/watch?v=kyGVhx5LwXw)

## Topics

- Learn the conceptual foundation
- Understand how relations differ from non-relational tables
- Learn basic relational terminology
- Learn the meaning & importance of keys, foreign keys, & related terminology
- Understand how foreign keys represent relationships
- Learn the purpose & use of surrogate keys
- Learn the meaning of functional dependencies
- Learn to apply a process for normalizing relations

## Entity

- An entity is something of importance to a user or organization that needs to
  be represented in a DB
- An entity represents one theme, topic, or business concept
- In the entity-relationship model, entities are restricted to things that can
  be represented using a single table

## Relation

- A relation is a 2D table that has specific characteristics
- The table dimensions, like a matrix, consist of rows & columns

### Characteristics of a Relation

- Rows contain data about instances of an entity
- Columns contain data about attributes of the entity
- Cells of the table hold a single value
- All values in a column are of the same kind (data type)
- Each column has a unique name
- The order of the columns is unimportant
- The order of the rows is unimportant
- No two rows can be identical (identical values in a column is ok)

## Keys

- A key is one (or more) column(s) of a relation whose values are used to
  identify a row

### Uniqueness of Keys

- Unique key
  - Data value is unique for each row which then uniquely identifies a row
- Non-unique key
  - Data value may be shared among several rows which identifies a *set* of rows

### Composite Key

- A unique key that is composed of two or more attributes (columns)
- For a key to be unique, it must often become a composite key

### Candidate Key

- A unique key that has the potential to become the primary key

### Primary Key

- A unique key that is a candidate key chosen to be the main key for the
  relation
- If you know the value of the primary key, you will be able to uniquely
  identify a single row (instance) w/in the table

### Surrogate Key

- A unique key w/a numeric value that is added to a relation to serve as the
  primary key
- Values have no meaning to users & are usually hidden on forms, queries, &
  reports
- Often used in place of a composite primary key

## Relationships Between Tables

- A table may be related to other tables
- E.g.,
  - An Employee works in a Department
  - A Manager controls a Project

### Foreign Key

- To establish relationships, we need to implement a ***foreign key***
- A primary key from one table that is placed into another table
- Called a foreign key in the table that receives the key

## Referential Integrity

- Every value of a foreign key *must* match a value of an existing primary key

## Null Values

- Means that no data exists, like an empty cell in the table
- Different from any other character

### Problem of Null Values

- Often ambiguous. Can potentially mean
  - The column value is not appropriate for the specific row
  - The column value has not been decided
  - The column value is unknown
- Each may have entirely different implications

## Functional Dependency

- A relationship between attributes in which one attribute (or group of
  attributes) determines the value of another attribute in the same table

### Determinants

- The attribute(s) that we use as the starting point (the variable on the left
  side of the equation)
  - `CookiePrice` in the below example

```
(CookiePrice, Qty) --> BoxPrice
```

## Candidate/Primary Keys & Functional Dependency

- By definition:
  - A candidate key of a relation will functionally determine all other non-key
    attributes in the row
  - A primary key of a relation will functionally determine all other non-key
    attributes in the row

## Data Normalization

- A process of analyzing a relation to ensure that it is *well-formed* (i.e.,
  not susceptible to deletion, update, & insertion anomalies)
- Normalization involves decomposing relations w/anomalies to produce smaller,
  well-structured relations
- More specifically, if a relation is normalized (well-formed), rows can be
  inserted, deleted, or modified w/o creating anomalies

### Normalization Principles

- Relation design principles for normalized relations
  - To be a well-formed relation, every determinant must be a candidate key
  - Any relation that is not well-formed should be broken into two or more
    well-formed relations
- Tip: as a general rule, a well-formed relation will not encompass more than
  one business concept

### Normalization Example

```
(StudentID) --> (StudentName, DormName, DormCost)
(DormName)  --> (DormCost)
```

Then `DormCost` should be placed into its own relation, resulting in the
relations

```
(StudentID) --> (StudentName, DormName)
(DormName)  --> (DormCost)
```

### Normalization Steps

1. Table w/multi-valued attributes
2. Remove multi-valued attributes
3. First normal form (1NF)
4. Remove partial dependencies
5. Second normal form (2NF)
6. Remove transitive dependencies
7. Third normal form (3NF)

### First Normal Form

- Table contains no multi-valued attributes
  - Every attribute is atomic
- *All relations* are in 1st Normal Form (by definition)

### Second Normal Form

- 1NF PLUS every non-key attribute is fully functionally dependent on the ENTIRE
  primary key
  - Every non-key attribute must be defined by the entire key, not by only part
    of the key
  - No partial dependencies

### Third Normal Form

- 2NF PLUS no *transitive* dependencies (functional dependencies on
  non-primary-key attributes)
  - Called transitive because the primary key is a determinant for another
    attribute, which in turn is a determinant for a third
- Solution: Non-key determinant w/transitive dependencies goes into a new table,
  non-key determinant becomes primary key in the new table & remains as a
  foreign key in the old table
