/*
** EPITECH PROJECT, 2022
** rTYPE [WSL : Ubuntu]
** File description:
** Entity
*/

#include <cstddef>

class Entity {
    public:

        /**
        *  @brief Explicit constructor.
        *  Don't give twice the same that may cause some problems if you use the sparse array
        *  @param val The id that would be attributed to the entity
        */
        explicit Entity(size_t val) noexcept : id(val) {};


        /**
        *  @brief Conversion from Entity to size_t 
        *  @return id of the entity
        */
        operator size_t() const {return id;};
        ~Entity() noexcept = default;
    private:
        std::size_t id;
};
