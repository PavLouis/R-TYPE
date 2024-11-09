/*
** EPITECH PROJECT, 2022
** B-CPP-500-BDX-5-1-rtype-matheo.pons
** File description:
** Registry.hpp
*/

#include "SparseArray.hpp"
#include <unordered_map>
#include <typeindex>
#include <any>
#include <functional>

#include <iostream>

#pragma once

namespace rt
{
    class Registry
    {
    public:
        Registry() noexcept = default;
        ~Registry() noexcept = default;

        /**
         * @brief Delete the entity specified from the given component
         * @param r adress of the register from where we will delete the entity
         * @param entity read-only adress of the entity that will be deleted
         **/
        template <class Component>
        void deleteEntityFromComponent(Registry &r, Entity const &entity)
        {
            r.getComponents<Component>()[entity] = std::nullopt;
        }

        /**
         * @brief Take a component and create a new sparse array inside the register
         * @return Read/Write adress of the sparse array that was created
         **/
        template <class Component>
        sparse_array<Component> &registerComponent()
        {

            holderDeleteFunctions.emplace_back([](Registry &r, Entity const &entity) {
                if (r.getComponents<Component>().size() > entity)
                r.getComponents<Component>()[entity] = std::nullopt;
            });

            std::any value = std::make_any<sparse_array<Component>>();
            components_arrays[std::type_index(typeid(Component))] = value;
            return *std::any_cast<sparse_array<Component>>(&value);
        };

        /**
         * @brief Take a component and find his sparse array inside the register
         * @return Read/Write adress of the sparse array that was found
         * @throw std::out_of_range If no such data is present.
         **/
        template <class Component>
        sparse_array<Component> &getComponents()
        {
            auto &sparseArray = components_arrays.at(std::type_index(typeid(Component)));
            return *std::any_cast<sparse_array<Component>>(&sparseArray);
        };

        /**
         * @brief Take a component and find his sparse array inside the register
         * @return Read-only (const) adress of the sparse array that was found
         * @throw std::out_of_range If no such data is present.
         **/
        template <class Component>
        sparse_array<Component> const &getComponents() const
        {
            auto &sparseArray = components_arrays.at(std::type_index(typeid(Component))); // use of at because [] is not const
            return *std::any_cast<sparse_array<Component>>(&sparseArray);
        };

        /**
         * @brief Delete the Entity from all the components
         * @param e Read-only (const) adress of the entity that will be deleted
         * @throw std::out_of_range if Entity is inferior to 0
         **/
        void killEntity(Entity const &e)
        {
            if (e < 0)
                throw std::out_of_range("ERROR killEntity : Entity need to be superior to 0");
            for (size_t i = 0; i < holderDeleteFunctions.size(); i++)
            {
                holderDeleteFunctions[i](*this, e);
            }
        }

        /**
         * @brief Assign a new id each time a new entity is spawned
         * @return Entity that spawned
         **/
        Entity spawnEntity()
        {
            Entity newEntity(tabEntities.size());
            tabEntities.push_back(newEntity);
            return newEntity;
        }

        /**
         * @brief Remove last entity created but do not set is component to std::nullopt
         **/
        void removeEntity()
        {
            tabEntities.pop_back();
        }

        /**
         * @brief get the total numbers of entity created
         * @return Return the nbr of entity
         **/
        size_t getNbrEntity()
        {
            return tabEntities.size();
        }

        /**
         * @brief Take index and return Entity from the vector
         * @return Entity that was found
         * @throw std::out_of_range if Entity is inferior to 0 or entity not exist
         **/
        Entity entityFromIndex(std::size_t idx)
        {
            if (idx < 0 || idx > tabEntities.size())
                throw std::out_of_range("ERROR entityFromIndex : Entity need to be superior to 0 or lesser than the size of the total of entity");
            return tabEntities.at(idx);
        }

        /**
         * @brief Take index and return if Entity exist
         * @return True if Entity exist, and false if not
         **/
        bool isEntityCreated(std::size_t idx)
        {
            if (tabEntities.size() > idx)
                return true;
            return false;
        }
        

        /**
         * @brief Add component to the entity inside the sparse array specified
         * @return Nothing for the moment but need to be changed
         * @throw std::out_of_range if Entity is inferior to 0
         **/
        template <typename Component>
        typename sparse_array<Component>::reference_type addComponent(Entity const &to,
                                                                       Component &&c)
        {
            if (to < 0)
                throw std::out_of_range("ERROR addComponent : Entity need to be superior to 0");
            std::any &holderSparseArray = components_arrays.at(std::type_index(typeid(Component)));
            sparse_array<Component> &sparseArray = *std::any_cast<sparse_array<Component>>(&holderSparseArray);
            return sparseArray.insert_at(to, c);
        }
        // template < typename Component , typename ... Params >
        // typename sparse_array < Component >:: reference_type emplace_component ( Entity const & to
        // , Params &&... p ) ;

        /**
         * @brief Delete one component for one entity
         * @param from Read-only (const) adress of the entity that will have one component removed
         * @throw std::out_of_range if Entity is inferior to 0
         **/
        template <typename Component>
        void removeComponent(Entity const &from)
        {
            if (from < 0)
                throw std::out_of_range("ERROR removeComponent : Entity need to be superior to 0");
            deleteEntityFromComponent<Component>(*this, from);
        }

    private:
        std::unordered_map<std::type_index, std::any> components_arrays;
        std::vector<std::function<void(Registry &, Entity const &)>> holderDeleteFunctions;
        std::vector<Entity> tabEntities;
    };
}