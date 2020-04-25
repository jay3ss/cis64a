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
- *A1*, *A2*, ..., *An* are attributes
- *R* = (*A1*, *A2*, ..., *An*) is a ***relation schema***

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
- A superkey may contain extraneous attributes & if *K* is a superkey, then so
  is any superset of *K*
- ***Candidate keys*** is a superkey for which no proper subset is a superkey
- it is possible that several distinct sets of attributes could serve as a
  candidate key
- ***Primary key*** denotes a candidate key that is chosen by the DB engineer
  as the principal means of identifying tuples w/in a relation & are also
  referred to as ***primary key constraints***
- It's customary to list the primary key attributes of a relation schema before
  the other attributes & are also underlined
- Primary keys must be chose w/care because certain attributes may not be unique
  - The primary key should be chose such that its attribute values are never,
    or are very rarely, changed
- A ***foreign-key constraint*** from attribute(s) *A* of relation *r1* to the
  primary-key *B* of relation *r2* states that on any DB instance, the value of
  *A* for each tuple in *r1* must also be the value of *B* for some tuple in
  *r2*
  - *r1* is also called the ***referencing relation*** of the foreign-key
      constraint
  - *r2* is called the ***referenced relation***
  - The referenced attribute(s) must be in the primary key of the referenced
    relation
    - In general, a ***referential integrity constraint*** requires that the
      values appearing in specified attributes of any tuple in the referencing
      relation also appear in specified attributes of at least one tuple in the
      referenced relation

## Schema Diagrams

- A DB schema, along w/primary key & foreign-key constraints, can be depicted by
  ***schema diagrams***
  - Primary-key attributes are shown underlined
  - Foreign-key constraints appear as arrows from the foreign-key attributes of
    the referencing relation to the primary key of the referenced relation
  - A two-headed arrow, instead of a single-headed arrow, to indicate a
    referential integrity constraint that is not a foreign-key constraint (this
    is introduced by the book & is not supported by any known industry tool)
- Many DB systems provide design tools w/a graphical UI for creating schema
  diagrams

## Relational Query Languages

- ***Query language***: a language in which a user requests info from the DB
  - categorized as 
    - imperative: user instructs the system to perform a specific sequence of
      operations on the DB to compute the desired result
    - functional: computation expressed as the evaluation of functions that may
      operation on data in the DB or on results of other functions
    - declarative: user describes the desired information w/o giving a specific
      sequence of steps or function calls for obtaining that info (typically
      described using mathematical logic & DB system figures out how to obtain
      the desired info)

## The Relational Algebra

- Relational algebra consists of a set of operations that take one or two
  relations as input & produce a new relation as their result
- *Unary operations* operate on one relation
  - select, project, & rename
- *Binary operations* operate on pairs of relations
  - union, Cartesian product, & set difference
- Although relational operations form the basis for SQL, DB systems don't allow
  users to write queries in relational algebra
- Since a relation is a set of tuples, relations can't contain duplicates

### The Select Operation

- ***Select*** selects tuples that satisfy a give predicate (σ denotes 
  selection)
  - Selection predicate
    - Allow comparisons using =, ≠, <, ≤, >, & ≥ in the selection predicate,
      in general
    - Can chain several predicates into a larger predicate using the ^, ∨, & ¬
      connectives
    - May include comparisons between two attributes

### The Project Operation

- Unary operation that returns its argument relation, w/certain attributes left
  out (П denotes projection)

### Composition of Relational Operations

- The fact that the result of a relational operation is itself a relation is
  important
  - In general, since the result of a relational-algebra operation is of the
    same type (relation) as its inputs, relational-algebra operations can be
    composed together into a ***relational-algebra expression*** just like
    composing arithmetic operations (+, -, `*`, & ÷)

### The Cartesian-Product Operation

- Allows us to combine information from any two relations (denoted by ×)
- Cartesian product between relations *r1* & *r2* is written as *r1* × *r2*
- A Cartesian product of DB relations differs in its definition slightly from
  the mathematical definition of a Cartesian product of sets
  - Mathematical: produces pairs (*t1*, *t2*) of tuples from *r1* & *r2*
  - Relational algebra: concatenates *t1* & *t2* into a single tuple
- Since the same attribute name may appear in the schemas of both *r1* & *r2*,
  we need to devise a naming schema to distinguish between these attributes
  - use <schema_name>.<attribute_name> convention
- Relation schema for *r* = *r1* × *r2* can be large
  - if they're *n1* tuples in *r1* & *n2* tuples in *r2*, then there are 
    *n1* `*` *n2* tuples in *r*

### The Join Operation

- Combines a selection & a Cartesian product into a single operation (denoted by 
  ⋈ )
  - r ⋈  s = σ(r × s) (the predicate is not shown)

### Set Operations

- ***Union***: all tuples from both sets (denoted by ∪)
  - In general, for a set to make sense (or be ***compatible*** relations):
    1. We must ensure that the input relations to union operation have the same
      ***arity*** (number of attributes of a relation)
    2. When the attributes have associated types, the ith types of both input
      relations are the same for each i
- ***Intersection***: find all tuples that are in both input relations (denoted
  by ∩)
  - Must ensure that it is done between compatible relations (like union)
- ***Set-difference***: finds the tuples that are in one relation but not the
  other (denoted by −)
  - As with union & intersection, must be done w/compatible relations


### The Assignment Operation

- Assigns parts of a relational-algebra expression to a temporary relation
  variable (denoted by ←)
- Allows a query to be written as a sequential program consisting of a series
  of assignments followed by an expression whose value is displayed as a result
  of the query
- Always done to a *temporary* variable, otherwise its a DB modification

### The Rename Operation

- Allows the result of a relational-algebra expression (denoted by ρ)

### Equivalent Queries

- There's often more than one way to write a query in relational algebra

## Summary

- The relational data model is based on a collection of tables
  - The user of the DB system may
    - query these tables
    - insert new tuples
    - delete tuples
    - update (modify) tuples
- The schema
  - of a relation refers to its logical design (an instance of the relation
    refers to its contents at a point in time)
  - of a DB & an instance of a DB are similarly defined
  - of a relation includes its attributes, & optionally the types of the
    attributes & constraints on the relation such as primary & foreign-key
    constraints
- A superkey of a relation is a set of one or more attributes whose values are
  guaranteed to identify tuples in the relation uniquely
  - A candidate key is a minimal superkey (a set of attributes that forms a
    superkey, but none of whose subsets is a superkey)
    - One of the candidate keys of a relation is chosen as its primary key
- A foreign-key constraint from attribute(s) *A* of relation *r1* to the
  primary-key *B* of relation *r2* states that the value of *A* for each tuple
  in *r1* must also be the value of *B* for some tuple in *r2*
  - The relation *r1* is called the referencing relation, & *r2* is called the
    referenced relation
- A schema diagram is a pictorial depiction of the schema of a DB that shows
  the relations in the DB, their attributes, & primary keys & foreign keys
- The relational query languages define a set of operations that operate on
  tables & output tables as their results
  - These operations can be combined to get expressions that express desired
    queries
- The relational algebra provides a set of operations that take one or more
  relations as input & return a relation as an output
  - Practical query languages such as SQL are based on the relational algebra,
    but they add a number of useful syntactic features
- The relational algebra defines a set of algebraic operations that operate on
  tables, & output tables as their results
  - These operations can be combined to get expressions that express desired
    queries
  - The algebra defines the basic operations used w/in relational query 
    languages like SQL
