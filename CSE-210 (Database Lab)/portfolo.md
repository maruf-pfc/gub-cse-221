# Database Course Portfolio

## Topics

- Database Indexing
- Database Hashing
- Database Transaction
- Database Triggering

## Database Indexing

Database indexing is a data structure technique that improves the speed of data retrieval operations on a database table at the cost of additional writes and storage space to maintain the index data structure. Indexes are used to quickly locate data without having to search every row in a database table every time a database table is accessed. Indexes can be created using one or more columns of a database table, providing the basis for both rapid random lookups and efficient access of ordered records.

### Types of Indexing

- Primary Index: Created automatically on the primary key. It is usually a clustered index, meaning the physical order of data in the table corresponds to the index order.
- Secondary Index: Created on non-primary key columns. These can be non-clustered indexes, meaning the physical order of the data is independent of the index order.
- Unique Index: Ensures that the values in the indexed column(s) are unique across the table.
- Composite Index: An index on multiple columns of a table. It helps with queries involving multiple columns.
- Clustered Index: Alters the way records are stored in a database. Only one clustered index per table is allowed.
- Non-clustered Index: Does not alter the physical storage of the table's records. Multiple non-clustered indexes can be created per table.

### Primary / Ordered Indexing is of two types:

- Dense Index: Contains an index entry for every search key value in the data file.
- Sparse Index: Contains index entries for only some of the search key values.

In dense index, there is an index record for every search key value in the database. This makes searching faster but requires more space to store index records itself. Index records contain search key value and a pointer to the actual record on the disk.

In sparse index, index records are not created for every search key. An index record here contains a search key and an actual pointer to the data on the disk. To search a record, we first proceed by index record and reach at the actual location of the data. If the data we are looking for is not where we directly reach by following the index, then the system starts sequential search until the desired data is found.

### Clustered Index vs. Non-Clustered Index

| Clustered Index                                  | Non-Clustered Index                               |
| ------------------------------------------------ | ------------------------------------------------- |
| Changes the order of records in the table        | Does not change the order of records in the table |
| Only one clustered index per table               | Multiple non-clustered indexes per table          |
| Faster for retrieval operations                  | Slower for retrieval operations                   |
| Slower for insert, update, and delete operations | Faster for insert, update, and delete operations  |

### There are multiple types of data structure that are used to build indexes. The common indexes types are:

- B-Tree Index: A balanced tree data structure that keeps data sorted and allows searches, sequential access, insertions, and deletions in logarithmic time.
- Bitmap Index: A special kind of index that stores the bulk of its data in bit arrays. It is most effective for low-cardinality data.
- Hash Index: A data structure that stores keys in a hash table. It is most effective for point lookups.
- Sparse Index: An index with an entry for each block of the data file, rather than for each record. It is most effective for indexing on a non-unique key.

### B+ Tree

A B+ tree is a balanced tree data structure that keeps data sorted and allows searches, sequential access, insertions, and deletions in logarithmic time. The B+ tree is a data structure that is commonly used in database systems. It is a type of tree data structure in which each internal node can have a variable number of child nodes. The B+ tree is a balanced tree, meaning that the height of the tree is always kept as small as possible. This makes the B+ tree an efficient data structure for storing and retrieving data.

### B+ Tree Structure

A B+ tree is a tree data structure that consists of a root node, internal nodes, and leaf nodes. The root node is the topmost node in the tree, and it contains pointers to the child nodes. Internal nodes are nodes that contain pointers to other nodes in the tree. Leaf nodes are nodes that contain the actual data entries. The leaf nodes are linked together in a linked list to allow for efficient sequential access to the data.

### B+ Tree Operations

The B+ tree supports the following operations:

- Insert: Inserts a key into the tree.
- Delete: Deletes a key from the tree.

### B+ Tree Insertion

To insert a key into a B+ tree, we start at the root node and traverse the tree to find the leaf node where the key should be inserted. If the leaf node has enough space to accommodate the new key, we insert the key into the leaf node. If the leaf node is full, we split the leaf node into two leaf nodes and promote the middle key to the parent node. We continue this process until we reach the root node.

```markdown
    B+ trees are filled from bottom and each entry is done at the leaf node.
    If a leaf node overflows −

        Split node into two parts.

        Partition at i = ⌊(m+1)/2⌋.

        First i entries are stored in one node.

        Rest of the entries (i+1 onwards) are moved to a new node.

        ith key is duplicated at the parent of the leaf.

    If a non-leaf node overflows −

        Split node into two parts.

        Partition the node at i = ⌈(m+1)/2⌉.

        Entries up to i are kept in one node.

        Rest of the entries are moved to a new node.
```

### B+ Tree Deletion

```markdown
    B+ tree entries are deleted at the leaf nodes.

    The target entry is searched and deleted.

        If it is an internal node, delete and replace with the entry from the left position.

    After deletion, underflow is tested,

        If underflow occurs, distribute the entries from the nodes left to it.

    If distribution is not possible from left, then

        Distribute from the nodes right to it.

    If distribution is not possible from left or from right, then

        Merge the node with left and right to it.
```

### Advantages of Indexing

- Faster search and retrieval of data.
- Efficient sorting of data.
- Enforces uniqueness in the database.

### Disadvantages of Indexing

- Requires additional storage space.
- Slows down data modification operations like insert, update, and delete.

Understanding database indexing is vital when working on the fundamental aspects of system design. Many improvements in our applications depend on this detailed knowledge. Selecting the right index can greatly enhance our application’s performance.

## Database Hashing

Hashing in DBMS is a technique to quickly locate a data record in a database irrespective of the size of the database. For larger databases containing thousands and millions of records, the indexing data structure technique becomes very inefficient because searching a specific record through indexing will consume more time. This doesn’t align with the goals of DBMS, especially when performance and date retrieval time are minimized. So, to counter this problem hashing technique is used. In this article, we will learn about various hashing techniques.

### 2 key components in hashing:

- Bucket: A bucket is a memory location (index) in the hash table that stores the data record. These buckets generally store a disk block which further stores multiple records. It is also known as the hash index.
- Hash Function: A hash function is a mathematical equation or algorithm that takes one data record’s primary key as input and computes the hash index as output.

### Types of Hashing

- Static Hashing: In static hashing, the hash table size is fixed and does not change. The hash function is used to map the data record to the hash index. If the hash index is already occupied, then the data record is stored in the next available bucket.
- Dynamic Hashing: In dynamic hashing, the hash table size is not fixed and can change. The hash function is used to map the data record to the hash index. If the hash index is already occupied, then the hash table size is increased, and the data record is stored in the next available bucket.

In static hashing, when a search-key value is provided, the hash function always computes the same address. For example, if mod-4 hash function is used, then it shall generate only 5 values. The output address shall always be same for that function. The number of buckets provided remains unchanged at all times.

#### Operations in Static Hashing

- Insertion − When a record is required to be entered using static hash, the hash function h computes the bucket address for search key K, where the record will be stored.
- Bucket address = h(K)
- Search − When a record needs to be retrieved, the same hash function can be used to retrieve the address of the bucket where the data is stored.
- Delete − This is simply a search followed by a deletion operation.

### Dynamic Hashing

Dynamic hashing is also known as extendible hashing, used to handle database that frequently changes data sets. This method offers us a way to add and remove data buckets on demand dynamically. This way as the number of data records varies, the buckets will also grow and shrink in size periodically whenever a change is made.

#### Operations in Dynamic Hashing

- Querying − Look at the depth value of the hash index and use those bits to compute the bucket address.
- Update − Perform a query as above and update the data.
- Deletion − Perform a query to locate the desired data and delete the same.
- Insertion − Compute the address of the bucket
  If the bucket is already full.
  Add more buckets.
  Add additional bits to the hash value.
  Re-compute the hash function.
  Else
  Add data to the bucket,
  If all the buckets are full, perform the remedies of static hashing.

### Advantages of Hashing

- Quick data retrieval due to direct access based on the computed hash code.
- Efficient for search operations, especially with large datasets.

### Disadvantages of Hashing

- Potential for collisions, which need to be managed efficiently.
- Inefficient for range queries.

Hashing is not favorable when the data is organized in some ordering and the queries require a range of data. When data is discrete and random, hash performs the best. Hashing algorithms have high complexity than indexing. All hash operations are done in constant time.

## Database Transaction

A database transaction is a sequence of multiple operations performed on a database, and all served as a single logical unit of work — taking place wholly or not at all. In other words, there’s never a case that only half of the operations are performed and the results saved. When a database transaction is in flight, the database state may be temporarily inconsistent, but when the transaction is committed or ends, the changes are applied.

### ACID Properties

- Atomicity: Either all operations of the transaction are properly reflected in the database or none are.
- Consistency: Execution of a transaction in isolation preserves the consistency of the database.
- Isolation: Although multiple transactions may execute concurrently, each transaction must be unaware of other concurrently executing transactions. Intermediate transaction results must be hidden from other concurrently executed transactions.

That is, for every pair of transactions Ti and Tj, it appears to Ti that either Tj, finished execution before Ti started, or Tj started execution after Ti finished.

- Durability: After a transaction completes successfully, the changes it has made to the database persist, even if there are system failures.

### Transaction State

- Active: the initial state; the transaction stays in this state while it is executing
- Partially committed: After the final statement has been executed.
- Failed: After the discovery that normal execution can no longer proceed.
- Aborted: After the transaction has been rolled back and the database restored to its state prior to the start of the transaction.Two options after it has been aborted:

  - Restart the transaction can be done only if no internal logical error
  - Kill the transaction

- Committed: After successful completion.
