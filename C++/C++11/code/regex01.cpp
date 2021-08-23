#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

    std::regex r(pattern);
    std::smatch results;

    std::string test_str = "receipt freind itself receive";

    if (std::regex_search(test_str, results, r))
        std::cout << results.str() << std::endl;

    std::cout << "Hello World!\n";
}
