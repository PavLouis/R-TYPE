# ECS

## Classes

### Entity

Entity represent a element of the game, its represented by a
- size_t that is equivalent to his id in the game.
The id permit us to bind Components and Entity with no problems.

### SparseArray

SparseArray represent the components, its represented by a 
- vector of std::optionnal that hold a undetermined type("Components") thanks to Template.
The sparse array is similar to vector except that at one index, a value can exist or not thanks to std::optionnal.

### Registry

Registry represent the holder of all the components and the binder of Entity/Components, its represented by
- unordered_map that stock all the sparse array of Components
- vector of std::function that stock a function, for each Components created, who is capable of deleting an entity for one Component
- vector of Entity that stock all the Entity ever Created

## API
