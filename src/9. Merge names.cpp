/*
Implement the unique_names method. When passed two vectors of names, it will return a vector 
containing the names that appear in either or both vectors. The returned vector should have no duplicates.

For example, calling unique_names(std::vector<std::string>{"Ava", "Emma", "Olivia"}, 
std::vector<std::string>{"Olivia", "Sophia", "Emma"}) should return a vector containing Ava, Emma, Olivia, and Sophia in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::vector<std::string> v_unique;

    for (auto& name : names1)
    {
        auto it = std::find(v_unique.begin(), v_unique.end(), name);
        if (it == v_unique.end())
        {
            v_unique.push_back(name);
        }
    }

    for (auto& name : names2)
    {
        auto it = std::find(v_unique.begin(), v_unique.end(), name);
        if (it == v_unique.end())
        {
            v_unique.push_back(name);
        }
    }

    return v_unique;
    //throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    //std::vector<std::string> names1 = { "Ava", "Emma", "Olivia" };
    //std::vector<std::string> names2 = { "Olivia", "Sophia", "Emma" };
    std::vector<std::string> names1 = { "Olivia", "Ava", "Emma", "Olivia" };
    std::vector<std::string> names2 = { "Sophia", "Emma" };

    std::vector<std::string> result = unique_names(names1, names2);
    for (auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif
