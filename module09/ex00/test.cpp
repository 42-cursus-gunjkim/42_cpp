#include <iostream>
#include <ctime>

int main() {
    std::string dateString = "2023-12-212";
    struct tm timeStruct;

    if (strptime(dateString.c_str(), "%Y-%m-%d", &timeStruct) != nullptr) {
        std::cout << "날짜: " << timeStruct.tm_year + 1900 << "-"
                  << timeStruct.tm_mon + 1 << "-"
                  << timeStruct.tm_mday << std::endl;
    } else {
        std::cerr << "날짜 변환 실패" << std::endl;
    }

    return 0;
}