# Dev Documentation
- [Architecture ECS](#architecture)
- [Doxygen](#doxygen)
- [Network](#network)

===========================================

## Architecture
![alt text](/Assets/github/ARCHITECTURE.png)

## Doxygen
[Here the link](https://pavlouis.github.io/index.html) to access our doxygen documentation

## Network
the communication between the server and the client works by a command system, whereas the client only sends what it does the server sends the entities.

### Connection
The server starts by sending a player then a command in the form of an ```sf::int8```
and the following arguments
the customer to receive them according to the type of order received
everything is in one sf::packet

### Command

#### Move the players:
    j >> MOVE(124) >> x >> y
'j' is the id.</br>
'MOVE' is the commande (124) because that's the value she has.</br>
'x' is an argument of the command move it represents the position in x.</br>
'y' is an argument of the command move it represents the position in y.</br>

#### Spawn and update an enemy:
    id >> enemy_e(5) >> x >> y >> live >> type
'id' is the id.</br>
'enemy_e' is the commande (5) because that's the value she has.</br>
'x' is an argument of the command move it represents the position in x.</br>
'y' is an argument of the command move it represents the position in y.</br>
'live' it's his status he's on 0 if the enemy is dead.</br>
'type' he will define the form of the enemy.</br>

#### Spawn and update an shoot:
    id >> projectile_e(1) >> x >> y
'id' is the id.</br>
'projectile_e' is the commande (1) because that's the value she has.</br>
'x' is an argument of the command move it represents the position in x.</br>
'y' is an argument of the command move it represents the position in y.</br>

For more detail https://www.sfml-dev.org/faq.php#networking talk about communication between no SFML CLIENT
