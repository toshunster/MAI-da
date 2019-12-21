#include <iostream>
#include <vector>
#include "utils.hpp"

int main()
{
    std::vector< std::vector<std::string> > match_pair = {
        { std::string("GEEKS FOR GEEKS"), std::string("GEEKS") },
        { std::string("baobab and catdogcatcat together cat"), std::string("cat") }
    };
    for (auto & pair : match_pair) {
        const std::string &text = pair[0];
        const std::string &pattern = pair[1];
        std::cout << "Try to find [" << pattern << "] in text [" << text << "]" << std::endl;
        size_t pos = utils::strstr_rk(text, pattern);
        while (pos != std::string::npos) {
            std::cout << "Found " << pattern << " at position " << pos << std::endl;
            pos = utils::strstr_rk(text, pattern, pos+1);
        } 
    }
    return 0;
}

