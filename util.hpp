#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

#ifndef UTIL_H
#define UTIL_H

template <typename T>
std::string to_string (const T& t){
    std::stringstream ss;
    ss << t;
    return ss.str();
}

class ScopedTimer {
private:
    std::chrono::system_clock::time_point start, end;
    long long duration_us;
    std::string name_;
    bool printAtScopeEnd_;
    long long calculateDuration_us();
public:
    long long getDuration_us();
    std::string getDuration_pretty();
    ScopedTimer();
    ScopedTimer(std::string name);
    ScopedTimer(std::string name, bool printAtScopeEnd);
    ~ScopedTimer();
};

#endif