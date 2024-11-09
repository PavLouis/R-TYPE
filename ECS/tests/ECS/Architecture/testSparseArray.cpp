/*
** EPITECH PROJECT, 2022
** rTYPE
** File description:    
** TestEntity
*/

#include "SparseArray.hpp"
#include <gtest/gtest.h>

TEST(SparseArray, assertionBegin)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);

    EXPECT_EQ(*arr.begin().base(), 1);
    EXPECT_EQ(*(arr.begin() + 1).base(), 2);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());
}


TEST(SparseArray, assertionEnd)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);

    EXPECT_EQ(*(arr.end()- 1).base(), 2);
    EXPECT_EQ(*(arr.end() - 2).base(), 1);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());
}

TEST(SparseArray, assertionSize)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());

    EXPECT_EQ(arr.size(), 2);
}

TEST(SparseArray, assertionInsertAt)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
}

TEST(SparseArray, assertionErase)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);

    arr.erase(0);
    EXPECT_FALSE(!retInsertOne.has_value());
}


TEST(SparseArray, assertionGetIndexFirstElement)
{
    sparse_array<int> arr;

    std::optional<int> retInsertOne = arr.insert_at(0, 1);
    const auto retInsertTwo = arr.insert_at(1, 2);
    const auto retInsertThree = arr.insert_at(2, 3);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());
    EXPECT_TRUE(retInsertThree.has_value());
    EXPECT_EQ(arr[0], retInsertOne.value());
    EXPECT_EQ(arr[1], retInsertTwo.value());
    EXPECT_EQ(arr[2], retInsertThree.value());

    size_t index = arr.get_index(arr[0]);
    EXPECT_EQ(index, 0);
}


TEST(SparseArray, assertionGetIndexAnyElement)
{
    sparse_array<int> arr;

    auto retInsertOne = arr.insert_at(0, 1);
    auto retInsertTwo = arr.insert_at(1, 2);
    auto retInsertThree = arr.insert_at(2, 3);

    EXPECT_TRUE(retInsertOne.has_value());
    EXPECT_TRUE(retInsertTwo.has_value());
    EXPECT_TRUE(retInsertThree.has_value());
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);

    size_t index = arr.get_index(arr[1]);
    EXPECT_EQ(index, 1);
}

