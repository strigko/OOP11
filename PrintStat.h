#pragma once
#include <string>
#include <iostream>

struct PrintStat {
    std::string user;
    std::string time;
};

inline std::ostream& operator<<(std::ostream& os, const PrintStat& ps) {
    os << "User: " << ps.user << "; Time: " << ps.time;
    return os;
}
