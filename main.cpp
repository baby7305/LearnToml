#include <toml.hpp>
#include <iostream>

int main()
{
    auto data = toml::parse("example.toml");

    // find a value with the specified type from a table
    std::string title = toml::find<std::string>(data, "title");

    // convert the whole array into any container automatically
    std::vector<int> nums = toml::find<std::vector<int>>(data, "nums");

    // access with STL-like manner
    if(not data.at("a").contains("b"))
    {
        data["a"]["b"] = "c";
    }

    // pass a fallback
    std::string name = toml::find_or<std::string>(data, "name", "not found");

    // width-dependent formatting
    std::cout << std::setw(80) << data << std::endl;

    return 0;
}