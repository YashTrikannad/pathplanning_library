//
// Created by yash on 8/4/19.
//

#pragma once

#include <array>
#include <ostream>
#include <boost/functional/hash.hpp>

namespace pl::common
{

struct NodeIndex2d
{
    NodeIndex2d() = default;

    NodeIndex2d(size_t row_index, size_t column_index) : row_index_(row_index), column_index_(column_index)
    {
    }

    NodeIndex2d(size_t row_index, size_t column_index, size_t obstacle) : row_index_(row_index), column_index_(column_index), obstacle_(obstacle)
    {
    }

    friend std::size_t hash_value(NodeIndex2d const& node)
    {
        std::size_t seed = 0;
        boost::hash_combine(seed, node.row_index_);
        boost::hash_combine(seed, node.column_index_);
        return seed;
    }

    friend std::ostream& operator<<(std::ostream& os, const NodeIndex2d& node)
    {
        os << "(" << node.row_index_ << ", " << node.column_index_ <<")";
    }

    size_t obstacle_;
    size_t row_index_;
    size_t column_index_;
};

inline bool operator==(const NodeIndex2d& lhs, const NodeIndex2d& rhs)
{
    return lhs.row_index_ == rhs.row_index_ && lhs.column_index_ == rhs.column_index_;
}

inline bool operator!=(const NodeIndex2d& lhs, const NodeIndex2d& rhs)
{
    return lhs.row_index_ != rhs.row_index_ || lhs.column_index_ != rhs.column_index_;
}

struct direction
{
};

struct up
{
    static constexpr size_t change_rows = -1;
    static constexpr size_t change_cols = 0;
    using type = direction;
};

struct down
{
    static constexpr size_t change_rows = +1;
    static constexpr size_t change_cols = 0;
    using type = direction;
};

struct left
{
    static constexpr size_t change_rows = 0;
    static constexpr size_t change_cols = -1;
    using type = direction;
};

struct right
{
    static constexpr size_t change_rows = 0;
    static constexpr size_t change_cols = +1;
    using type = direction;
};

struct top_right
{
    static constexpr size_t change_rows = -1;
    static constexpr size_t change_cols = +1;
    using type = direction;
};

struct top_left
{
    static constexpr size_t change_rows = -1;
    static constexpr size_t change_cols = -1;
    using type = direction;
};

struct bottom_right
{
    static constexpr size_t change_rows = +1;
    static constexpr size_t change_cols = +1;
    using type = direction;
};

struct bottom_left
{
    static constexpr size_t change_rows = +1;
    static constexpr size_t change_cols = -1;
    using type = direction;
};


struct cell_type
{
    using type = double;
};

} // namespace pl::common

// Include hash for NodeIndex2d in std namespace
namespace std
{
    template<> struct hash<::pl::common::NodeIndex2d> : boost::hash<::pl::common::NodeIndex2d> {};
}