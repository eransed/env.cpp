#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <cmath>

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
    void prettyPrint(const std::string& string);
    ScopedTimer();
    ScopedTimer(std::string name);
    ScopedTimer(std::string name, bool printAtScopeEnd);
    ~ScopedTimer();
};

class Sort {
public:
    static void insertion(int a[], int N);
    static void exch(int a[], int i, int j);
    static void print(int a[], int N);
    // static void binary(int a[], int N);
};

class Merge {
public:
    static int * aux;
    static void sort(int a[], int N);
    static void sort(int a[], int low, int mid);
    static void merge(int a[], int low, int mid, int high);
};

#endif