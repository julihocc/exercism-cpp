#include <iostream>
#include <string>

namespace log_line {
    std::string message(const std::string& line) {
        size_t index = line.find(' ');
        return line.substr(index + 1);
    }

    std::string log_level(const std::string& line){
        size_t start = line.find('[');
        size_t end = line.find(']');
        return line.substr(start + 1, end - start - 1);
    }

    std::string reformat(const std::string& line) {
        return message(line) + " (" + log_level(line) + ")";
    }

}  

int main() {
    std::cout << log_line::message("[ERROR]: Stack overflow") << std::endl;
    std::cout << log_line::log_level("[ERROR]: Stack overflow") << std::endl;
    std::cout << log_line::reformat("[ERROR]: Stack overflow") << std::endl;
}