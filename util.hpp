#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <cmath>

#define log(a) std::cout << a
#define logn(a) std::cout << a << std::endl

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
    static bool isSorted(int a[], int N);
    static void isSortedPrint(int a[], int N);
    static void isSortedPrettyPrint(int a[], int N);
    static void exch(int a[], int i, int j);
    static void print(int a[], int N);
    static void print(int a[], int low, int high);
};

class Selection {
public:
    static void sort(int a[], int N);
};

class Insertion {
public:
    static void sort(int a[], int N);
};

class Merge {
    static int * aux;
    static void sort(int a[], int low, int mid);
    static void merge(int a[], int low, int mid, int high);
public:
    static void sort(int a[], int N);
};

#endif