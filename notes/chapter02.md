# Introduction to the Relational Model

- Relational model remains the primary data model for commercial 
  data-processing applications

## Structure of Relational Databases

- A relational DB consists of a collection of ***tables***, each of which is
  assigned a unique name
- In general, a row in a table represents a *relationship* among a set of values
- In the relational model the term ***relation*** is used to refer to a table,
  while the term ***tuple*** is used to refer to a row & an ***attribute*** is
  a column
- A ***relation instance*** refers to a specific instance of a relation, that
  is, containing a specific set of rows
- The order in which tuples appear in a relation is irrelevant since a relation
  is a *set* of tuples
- For each attribute of a relation, there is a set of permitted values, called
  the ***domain*** of that attribute
- We require that, for all relations *r*, the domains of all attributes of *r*
  be atomic (elements of the domain are considered to be indivisible units)
- The ***null value*** is a special value that signifies that the value is
  unknown or does not exist (can cause a number of difficulties when we access
  or update the DB, therefore should be eliminated if possible)
- The relatively strict structure of relations results in several important 
  practical advantages in the storage & processing of data
    - Good for well-defined & relatively static applications

## Database Schema

- When we talk about a DB, we must differentiate between the ***database 
  schema*** (the logical design of the DB) & the ***database instance*** which
  is a snapshot of the data in the DB at a given instant in time
- The concept of a relation corresponds to the programming-language notion of a
  variable, while the concept of a ***relation schema*** corresponds to the
  programming-language notion of type definition
- In general, a relation schema consists of a list of attributes & their
  corresponding domains
- The concept of a relation instance corresponds to the programming-language
  notion of a value of a variable
- Although it is important to know the difference between a relation schema & a
  relation instance, we often use the same name, such as *instructor* to refer
  to both the schema & the instance

## Keys

- We must have a way to specify how tuples w/in a given relation are 
  distinguished (this is expressed in terms of their attributes)
- A ***superkey*** is a set of one of more attributes that, taken collectively,
  allow us to identify uniquely a tuple in the relation
- Formally, let *R* denote the set of attributes in the schema of relation *r*
  - Let *K* ⊆ *R* be a *superkey* for *r* ⇒ {*t1*, *t2*, ..., *tn* ∈ *r*: *t1* ≠ *t2* ≠ ... ≠ *tn*}
