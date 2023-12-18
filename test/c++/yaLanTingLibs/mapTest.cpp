#include <iostream>
#include <map>
#include <string>

class str {
public:
    str(const std::string &s) : str_(s) {}
    void print() {
        std::cout << str_ << std::endl;
    }
private:
    std::string str_;
};

int main() {
    std::map<std::string, std::string> m;
    std::string k = "hello";
    m[k] = "hello";

    std::map<std::string, std::string>::iterator it = m.find(k);
    if (it != m.end()) {
        m[k] = "war";
        std::cout << it->second << std::endl;
    }
    return 0;   
}