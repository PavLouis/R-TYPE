/*
** EPITECH PROJECT, 2022
** rTYPE
** File description:
** TestEntity
*/

#include "Entity.hpp"
#include <gtest/gtest.h>

TEST(EntityTest, BasicAssertion)
{
    Entity v(10);

    size_t conv = v;

    EXPECT_EQ(conv, 10);
}

