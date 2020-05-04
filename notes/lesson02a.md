# Data Models

The video can be found [here](https://www.youtube.com/watch?v=zTcUj4xTnnA)

## Overview

- Concepts of data modeling
- Hierarchical model (outdated)
- CODASYL model
- Entity-Relationship (ER) model
- Enhanced ER (EER) model
- Relational model UML model

## Concepts of Data Modeling

- Developing a conceptual schema to capture the specifications of the data and
  constraints to be represented in the DB
- The main focus of conceptual data modeling is to capture the semantics of the
  universe of discourse as accurately as possible, w/o being concerned with
  DBMS-related issues
- This purpose requires a high-level model, such as the EER model
- Different types of data models have been suggested throughout history

## Phases of DB Design

1. Universe of discourse
2. Requirement collection & analysis
3. DB requirements
4. Conceptual design
5. Conceptual schema (in a high-level data model)
6. Logical design (data model mapping)
7. Logical (conceptual) schema (in the data model of a specific DBMS)
8. Physical design
9. Internal schema

- Steps 1 through 5 are DBMS-independent & steps 6 through 9 are DBMS-specific

## Hierarchical Model

- Developed during the Apollo project (NASA)
- IBM developed the Information Management System (IMS) product (1966 - 1968)
- No original formal description available
  - Developed in an ad hoc way
- Lots of structural limitations & legacy!

### Record Types & Parent/Child Relationship Types

- Record type
  - Set of records describing similar entities
  - Has 0, 1, or more records
  - Consists out of fields & data items
- Relationship type
  - Models relationships between record types
  - Only 1:n relationship types (parent/child relationship types)
  - Can be nested
- Parent-record type vs. child-record type
- Record type can be parent in multiply parent/child relationship types
- Record type can only be child in one parent/child relationship type
- A child record type can itself be parent in another relationship type
  (hierarchical structures)
- Root-record type vs. leaf-record type
- Relationship type cardinalities
  - Parent record type: 1:1
    - Can have multiple children
  - Child record type: 0:n
    - Can only have one parent
- Record type at top of hierarchy is the root
- Record type at bottom of hierarchy is a leaf

### Structural Limitations of the Hierarchical Model

- All record data need to be retrieved by navigating from the root node of the
  hierarchical structure (procedural DML, explicitly program what you want &
  your query)
- No straightforward way to model n:m & 1:1 relationships
- n:m relationship types
  - Assign one record type
  - Transform network structure to tree structure
  - Creates redundancy
  - Redundancy dependent upon
    - Amount of data in the child record type
    - Value of maximum cardinality from the child record type to parent record
      type
  - Put relationship type attributes in child record type
- 1:1 relationship type
  - Special case of a 1:n relationship type
  - Cardinality cannot be enforced in the model, only in application programs
- Only relationship types of degree 2
  - Note: degree of a relationship type is the number of participating record
    types
  - Recursive relationship types (degree = 1) need to implemented using virtual
    child record type
- Maximum & minimum cardinality from child to parent is 1
  - Deleting a parent record has a cascading effect towards all child records
    (on delete cascade)

## CODASYL Model

- Developed by Data Base Task Group of the COnference on DAta SYstem Languages
  in 1969
- Network model
- Popular software implementations
  - IDMS
  - CA-IDMS
- Network model
  - Record types & links
  - 1:1, 1:n, & n:m relationship types

### Record Types & Set Types

- Record type
  - Set of records describing similar entities
  - Has 0, 1, or more records or record occurrences
  - Consists out of data items
  - Vectors & repeated groups also supported
    - An atomic data item for which a record can have multiple values (simple
      (atomic) multi-valued attribute type)
  - Repeated group is a composite data item for which a record can have multiple
    values (composite multi-valued attribute type)
- Set type
  - 1:n relationship type between two record types
  - Owner record type (parent) versus member record type (child)
  - Set occurrence for each record occurrence of the owner (parent) record type
  - Set occurrence has 1 owner record and 0, 1, or more member records
  - Is different from a mathematical set because
    - Different elements (members vs owner)
    - Members can be ordered

### Differences with Hierarchical Model

- Record type can be member record type in multiple set types
  - Create (simple) network structures
- Multiple set types are possible between the same record types
- Members can be disconnected from their owner (minimal cardinality = 0)

### Structural Limitations of the CODASYL Model

- 1:1 relationship types have to be enforced/modeled in application programs
- n:m relationship types
  - Member-record can only belong to one occurrence of a specific set, hence
    cannot just define a set type between the corresponding record types
  - Introduce dummy record type which is included as a member record type in two
    set types having as owners the record types of the original n:m relationship
    type
  - Dummy record type then also contains attributes of the relationship type
- No recursive set types
  - Dummy record type needs to be introduced
  - Dummy record type is defined as a member in two set types each having as
    owner record type the record type of the recursive relationship
  - This implies extensive navigation when manipulating the data
- No relationship types w/degree > 2
- Member records can be logically ordered
  - Can be useful for data manipulation
  - For the root member record type, the system can act as the owner (singular
    or system owned set type)
  - Only 1 set occurrence in a singular set type

### n:m Relationship Types in CODASYL

- Implications for data usage
  - Suppose a query asks for all projects and employee is working on
    1. Select a set w/in the set type employee-program
    2. For each member, determine the owner in the set type program-employee
    3. Go the other way around in case we need to find all employees working on
      a project
- Procedural DML

## The Entity-Relationship (ER) Model

- Formalized by Chen (1976)
- Entity types
  - Key attribute(s)
  - Weak entity types
- Attributes
  - Simple (atomic) vs. composite
  - Single-valued vs. multi-valued
- Relationship types
  - Degree: unary, binary, ternary
  - Cardinality ration: 1:1, 1:n, n:1, & m:n
  - Participation constraint: total, partial
  - Attributes of relationship types
- ER diagram: graphical notation of conceptual schema

### Entities and Attributes

- Entity: represents a "thing" or concept in the real world w/an independent
  existence
- Attribute: represents some property of interest that further describes an
  entity. A particular entity will have a value for each of its attributes.
  These values become a major part of the data stored in the DB

### Types of Attributes

- Simple (atomic) vs. composite
- Single-valued vs. multi-valued
- Stored vs. derived
- Null value

### Entity Types, Keys, & Domains

- Entity type: defines a collection of entities that have the same attributes
  & represent similar real-world objects. These entities are instances of that
  particular entity type
- Key attribute: an attribute whose values are distinct for each individual
  entity. Such attribute can be used to uniquely identify each entity
  - Can be a combination of attributes
- Domain: each simple attribute of an entity type is associated w/a domain,
  which specifies the set of values that may be assigned to that attribute for
  each individual entity. Domains are not displayed in ER diagrams


### Relationships & Relationship Types

- Relationship: represents the association between tow or more entities
- Relationship type: defines a set of relationships among instances of one,
  two, or more entity types. Each instance of a relationship type carries a
  similar semantic "meaning

### Degree of a Relationship Type & Role Names

- Degree of a relationship type: the number of entity types participating in
  the relationship type
  - Unary (recursive): degree = 1
  - Binary: degree = 2
  - Ternary: degree = 3
- Role names: in cases where the same entity type participates more than once
  in a relationship type, role names are used to distinguish the meaning of each
  participation. Such relationship types are called *recursive* relationship
  types

### Constraints on Relationship Types

- Cardinality ratio: specifies the minimum/maximum number of relationship
  instances that an entity can participate in
- Minimum cardinality
  - 0: entity can occur w/o being connected to another entity (partial
  participation)
  - 1: entity must be connected to at least one other entity (total
    participation, existence dependency)
- Maximum cardinality
  - 1: entity can be connected to at most 1 other entity
  - n: entity can be connected to at most n other entities
- Relationship types are often characterized by means of their maximum
  cardinalities

### Attributes of Relationship Types

- Relationships can also have attributes, similar to those of entity types
- Note that attributes of 1:1 or 1:n relationship types can be migrated to one
  of the participating entity types
- Attributes belonging to m:n relationship types cannot be determined by a
  single entity: they can only be specified as relationship attributes

### Weak Entity Types

- Entity types that do not have key attributes of their own
- Entities belonging to a weak entity type are identified by being related to
  specific entities from another entity type (the owner entity type) in
  combination w/some of their own attributes
- Its existence is always dependent on its owner entity type
- Note: existence dependency does not imply weak entity type

### Structural Limitations of the ER Model

- ER presents a temporary snapshot
  - Temporal aspects cannot be modeled
    - Examples
      - Project needs to be assigned to a department after 1 month
      - Employee can't return to the department of which he previously was a
        manager
      - Employee needs to be assigned to a department after 6 months
- ER can't guarantee consistency across multiple relationship types
  - An employee should work in the department that he/she manages
  - Employees should work on projects assigned to departments to which the
    employee belong
- Not possible to include integrity rules, trigger rules, & behavior
  - E.g., integrity rule: Worked has to be a positive integer

## The Enhanced ER (EER) Model

- The EER model includes all the modeling concepts of the ER model. In
  addition, incorporates the following additional semantic data modeling
  concepts
  - Specialization & generalization
  - Categorization
  - Aggregation
