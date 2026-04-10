#include <iostream>
#include <algorithm>

int main()
{
    auto add = [](int a, int b) -> int
    {
        return a + b;
    };

    auto sum = add(3, 5);

    auto print_sum = [sum]() -> void
    {
        std::cout << "这个数字为：" << sum << std::endl;
    };

    print_sum();

    return 0;
}