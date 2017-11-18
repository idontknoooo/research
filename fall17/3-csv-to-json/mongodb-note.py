# Show databases
show dbs

# Show collections
show collections

# Create Database
use database-name

# Create Collection
db.createCollection('collection-name')

# Remove Documents from collection
db.collection.remove({"xx":"xx"})

# Remove All Documents from collection
db.collection.remove({})
e.g. db.qz.remove({})

# Remove Collection
db.collection.drop()
e.g. db.qz.drop()

# Remove Database
use database-name
db.dropDatabase();

# Search record
db.collection.find({})
e.g. db.qz.find({'name':/Aman/})

# Multiple Condition Search
db.qz.find( { $and: [{name:/Aman/},{title:/Worker/}] })
db.qz.find( { $and: [{name:/Aman/},{title:/Worker/}, {year:{$lt:1990}}] })

