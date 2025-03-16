#include <string>

unsigned int hashString(const std::string& s, int m) {
    unsigned int hash = 0;
    int b = 37;
    for (char c : s) {
        hash = (hash * b + c) % m;
    }
    return hash;
}