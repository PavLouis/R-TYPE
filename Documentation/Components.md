# Component Documentation

This documentation describes the behavior of each component. It describe which data the **component** store and use.

## Table of Content
- [Component Documentation](#component-documentation)
  - [Table of Content](#table-of-content)
  - [Collision Component](#collision-component)
      - [Definition](#definition)
  - [Controllable Component](#controllable-component)
      - [Definition](#definition-1)
  - [Drawable Component](#drawable-component)
      - [Definition](#definition-2)
  - [Health Component](#health-component)
  - [Hitbox Component](#hitbox-component)
  - [Movement Compenent](#movement-compenent)
  - [Position Component](#position-component)
  - [Shoots Component](#shoots-component)
  - [Size Component](#size-component)

## Collision Component

The collision component is used to define what are the "layers" of collision of an *Entity*.

#### Definition

```C++
    typedef struct Collision_s {
        std::vector<std::string> belong;
        std::vector<std::string> collide;
    } Collision_t;
```
- **belong**: vector of collision the entity belong to.
- **collide**: vector of collision the entity collide to.



## Controllable Component

The controllable component is used to define the different inputs to control an *Entity*.

#### Definition

```C++
    typedef struct Controllable_s {
        sf::Keyboard::Key upKey;
        sf::Keyboard::Key downKey;
        sf::Keyboard::Key leftKey;
        sf::Keyboard::Key rightKey;
        sf::Keyboard::Key shootKey;
        sf::Keyboard::Key interactKey;
    } Controllable_t;
```

- **upKey**: key to move the entity up.
- **downKey**: key to move the entity down.
- **leftKey**: key to move the entity left.
- **rightKey**: key to move the entity right.
- **shootKey**: key to trigger shoot system.
- **interactKey**: key to interact with other entities around.

## Drawable Component

Component that store the drawables and the options of these drawables.

#### Definition

```C++
class Drawable {
    private:
        sf::Vector2f size;
        sf::IntRect textureRect;
        sf::Sprite sprite;
        sf::Clock clock;
        unsigned int nbFrame;
        sf::Int32 frameRate;
        unsigned short layer;

    public:
        Drawable() noexcept = default;
        Drawable(Drawable const &) noexcept = default;
        Drawable(Drawable &&) noexcept = default;
        Drawable& operator=(Drawable const &) noexcept = default;
        Drawable& operator=(Drawable &&) noexcept = default;
        ~Drawable() noexcept = default;
    
        Drawable(sf::Texture const &, sf::IntRect const &, sf::Int32 const &, unsigned short const &layer, sf::Vector2f const &size);
        sf::Sprite getSprite() noexcept;
        sf::Time getElapsedTime() const noexcept;
        sf::Int32 getFrameRate() const noexcept;
        unsigned short getLayer() const noexcept;
        void restartClock() noexcept;
        void setSpriteRect(sf::IntRect const &) noexcept;
        void setLayer(unsigned int const) noexcept;
        void setPosition(sf::Vector2i const &) noexcept;
}
```
- **size**:
- **textureRext**:
- **sprite**:
- **clock**:
- **nbFrame**:
- **frameRate**:
- **layer**:

## Health Component

## Hitbox Component

## Movement Compenent

## Position Component

## Shoots Component

## Size Component

R-Type - Epitech Project 2022