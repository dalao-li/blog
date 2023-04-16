#include <iostream>
#include <map>

int main(void) {
    std::map<std::string, int32_t> m = {
        {"Wang", 20},
        {"Li", 22},
        {"Deng", 19}
    };

    for (auto &[k, v] : m) {
        std::cout << k << ", " << v << std::endl;
    }
}