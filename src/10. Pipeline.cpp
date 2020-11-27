/*
10. Pipeline
CLOSURES HIGHER ORDER FUNCTION   Hard 
As part of a data processing pipeline, complete the implementation of the makePipeline method:

The method should accept a vector of functions, and it should return a new function that accepts one parameter arg.
The returned function should call the first function in the makePipeline with the parameter arg, and call the second function with the result of the first function.
The returned function should continue calling each function in the makePipeline in order, following the same pattern, and return the value from the last function.
For example,

std::vector<std::function<int (int)>> functions;
functions.push_back([] (int x) -> int { return x * 3; });
functions.push_back([] (int x) -> int { return x + 1; });
functions.push_back([] (int x) -> int { return x / 2; });
std::function<int (int)> func = makePipeline(functions);
calling the func(3) should return 5.
*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template<class T>
std::function<T(T)> makePipeline(const std::vector<std::function<T(T)>>& funcs) {
    return [&funcs](const T& arg) {
        T t_arg = arg;
        for (auto& func : funcs)
        {
            t_arg = func(t_arg);
        }
        return t_arg;
    };
}

#ifndef RunTests
int main()
{
    std::vector<std::function<int(int)>> functions;
    functions.push_back([](int x) -> int { return x * 3; });
    functions.push_back([](int x) -> int { return x + 1; });
    functions.push_back([](int x) -> int { return x / 2; });

    std::function<int(int)> func = makePipeline(functions);
    std::cout << func(3); // should print 5
}
#endif
