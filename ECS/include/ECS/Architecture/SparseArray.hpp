#include "Entity.hpp"
#include <vector>
#include <cstddef>
#include <optional>
#include <any>
#include <iostream>

template <typename Component>
class sparse_array
{
public:
    using value_type = std::optional<Component> ; // optional component type
    using reference_type = value_type &;
    using const_reference_type = value_type const &;
    using container_t = std ::vector<value_type>; // optionally add your allocator template here.
    using size_type = typename container_t::size_type;
    using iterator = typename container_t ::iterator;
    using const_iterator = typename container_t ::const_iterator;

public:
    /**
     * @brief Default constructor, set the vector to default value
     * 
    **/
    sparse_array() noexcept = default;

    /**
     * @brief Copy constructor, set the vector to class to copy
     * @param toCpy An allocator object.
    **/
    sparse_array(sparse_array const &toCpy) = default;

    /**
     * @brief Move constructor. The newly-created sparse array contains the exact contents of the moved instance.
     * @param toMove An allocator object.
    **/
    sparse_array(sparse_array &&toMove) noexcept = default;

    /**
     * @brief Default destructor
    **/
    ~sparse_array() noexcept = default;

    /**
     * @brief Sparse array assignement operator
     * @param toAssign an allocator object
    **/
    sparse_array &operator=(sparse_array const &toAssign) = default;

    /**
     * @brief Sparse array assignement operator
     * @param toAssign an allocator object
    **/
    sparse_array &operator=(sparse_array &&toAssign) noexcept = default;

    /**
     * @brief Get data at specified index
     * @param idx The index of the element for which data should be accessed
     * @return Read/write reference to data
     * @throw std::out_of_range if Entity is inferior to 0 or greater than the size of the tab
    **/
    reference_type operator[](size_t idx)
    {
        return this->data.at(idx);
    }

    /**
     * @brief Get data at specified index
     * @param idx The index of the element for which data should be accessed
     * @return Read reference to data
     * @throw std::out_of_range if Entity is inferior to 0 or greater than the size of the tab
    **/
    const_reference_type operator[](size_t idx) const
    {
        return this->data.at(idx);
    }

    /**
     * @return Read/write iterator that points to the first
     * element in the sparse array
    **/
    iterator begin()
    {
        return this->data.begin();
    }

    /**
     * @return Read-only (const) iterator that points to the first
     * element in the sparse array.
    **/
    const_iterator begin() const
    { 
        return this->data.begin();
    }

    /**
     * @return Read-only (const) iterator that points to the first
     * element in the sparse array
    **/
    const_iterator cbegin() const
    {
        return this->data.cbegin();
    }

    /**
     * @return Read/write iterator that points to the end
     * element in the sparse array
    **/
    iterator end()
    {
        return this->data.end();
    }

    /**
     * @return Read-only (const) iterator that points to the end
     * element in the sparse array
    **/
    const_iterator end() const
    {
        return this->data.end();
    }

    /**
     * @return Read-only (const) iterator that points to the end
     * element in the sparse array
    **/
    const_iterator cend() const
    {
        return this->data.cend();
    }


    /**
     * @return Size of the sparse array
    **/
    size_type size() const
    {
        return this->data.size();
    }

    /**
     * @brief Insert the data inside the sparse array at the posistion. If the position is not in range the sparse array is resized.
     * @param pos Position in the sparse array where data will be inserted
     * @param val Read-only adress to the data
     * @return Adress of the position which data was inserted
     * @throw std::out_of_range if Entity is inferior to 0 or greater than the size of the tab
    **/
    reference_type insert_at(size_type pos, Component const &v)
    {
        if (pos < 0)
                throw std::out_of_range("ERROR insert_at : Pos need to be superior to 0");
        if (pos >= this->data.size()) {
            this->data.resize(pos + 1);
        }
        this->data.at(pos) = v;
        return this->data[pos];
    }

    /**
     * @brief Insert the data inside the sparse array at the posistion
     * @param pos Position in the sparse array where data will be inserted
     * @param val Adress to the data
     * @return Adress of the position which data was inserted
    **/
    reference_type insert_at(size_type pos, Component &&v)
    {
        if (pos < 0)
                throw std::out_of_range("ERROR insert_at : Pos need to be superior to 0");
        if (pos >= this->data.size()) {
            this->data.resize(pos + 1);
        }
        this->data.at(pos) = std::move(v);
        return this->data[pos];
    }

    // template <class... Params>
    // reference_type emplace_at(size_type pos, Params &&...); // optional

    /**
     * @brief Erase the data at the position and data will be replace by std::nullopt
     * @param pos Position in the sparse array where data will be erased
    **/
    void erase(size_type pos)
    {
        if (pos < 0)
                throw std::out_of_range("ERROR insert_at : Pos need to be superior to 0");
        if (pos < this->data.size()) {
            this->data[pos] = std::nullopt;
        }
    }


    /**
     * @brief get the index with the data
     * @param needle data that need to be found on the sparse array
     * @return index where data was found
    **/
    size_type get_index(value_type const &needle) const // need to check if error
    {
        return std::addressof(needle) - std::addressof(*this->data.begin());
    }

private:
    container_t data;
};