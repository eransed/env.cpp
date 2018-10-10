#include "util.hpp"

long long ScopedTimer::calculateDuration_us() {
    end = std::chrono::system_clock::now();
    duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return duration_us;
}

long long ScopedTimer::getDuration_us(){
    return calculateDuration_us();
}

std::string ScopedTimer::getDuration_pretty(){
    std::string us = name_;
    us.append(", time: ");
    us.append(to_string(getDuration_us()));
    us.append("us");
    return us;
}

ScopedTimer::ScopedTimer(){
    name_ = "Unnamed";
    printAtScopeEnd_ = false;
    start = std::chrono::system_clock::now();
}

ScopedTimer::ScopedTimer(std::string name){
    name_ = name;
    printAtScopeEnd_ = false;
    start = std::chrono::system_clock::now();
}

ScopedTimer::ScopedTimer(std::string name, bool printAtScopeEnd){
    name_ = name;
    printAtScopeEnd_ = printAtScopeEnd;
    start = std::chrono::system_clock::now();
}

ScopedTimer::~ScopedTimer(){
    end = std::chrono::system_clock::now();
    if (printAtScopeEnd_){
        std::cout << getDuration_pretty() << std::endl;
    }
}