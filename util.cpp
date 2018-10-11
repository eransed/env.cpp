
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
    double us = (double) getDuration_us();
    std::string unit = "_not_set_";

    if (us < 1000) {
        unit = (std::string) "us";
    }else if (us < 1000 * 1000) {
        us /= 1000;
        unit = (std::string) "ms";
    }else if (us < 1000 * 1000 * 1000) {
        us /= 1000 * 1000;
        unit = (std::string) "s";
    }else if (us < 1000.0 * 1000.0 * 1000.0 * 60.0) {
        us /= 1000.0 * 1000.0 * 60.0;
        unit = (std::string) "m";
    }else{
        us /= 1000.0 * 1000.0 * 60.0 * 60.0;
        unit = (std::string) "h";
    }

    std::string out = name_;
    out.append(", time: ");
    out.append(to_string(us));
    out.append(unit);
    return out;
}

void ScopedTimer::prettyPrint(const std::string& string){
    std::cout << string << std::endl;
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
        prettyPrint(getDuration_pretty());
    }
}

void Sort::insertion(int a[], int N){
    for (int i = 1; i < N; i++){
        for (int j = i; j > 0; j--){
            // print(a, N);
            if (a[j] < a[j - 1]) {
                exch(a, j, j - 1);
            }
        }
    }
}

// void Sort::binary(int a[], int N){

//     if (N == 2) {
//         if (a[0] > a[1]){
//             exch(a, 0, 1);
//         }
//     } else {
//         Sort::binary(a, (int) N / 2);
//         Sort::binary(a, (int) N / 2);
//     }

// }

void Sort::exch(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void Sort::print(int a[], int N){
    std::cout << "[";
    for (int i = 0; i < N - 1; i++) {
        std::cout << a[i] << ", ";
    }
    std::cout << a[N - 1] << "]" << std::endl;
}


int* Merge::aux;

void Merge::sort(int a[], int N){
    Merge::aux = new int[N];
    sort(a, 0, N - 1);
    delete[] Merge::aux;
}


void Merge::sort(int a[], int low, int high){
    if (high <= low) {
        return;
    }
    int mid = low + (high - low)/2;
    sort(a, low, mid);
    sort(a, mid + 1, high);
    merge(a, low, mid, high);
}


void Merge::merge(int a[], int low, int mid, int high){
    for (int n = low; n < high; n++){
        Merge::aux[n] = a[n];
    }

    int i = low; 
    int j = mid + 1;

    for (int n = low; n < high; n++) {

        if(i > mid) {
            a[n] = Merge::aux[j++];

        } else if (j > mid) {
            a[n] = Merge::aux[i++];

        } else if (Merge::aux[j] < Merge::aux[i]) {
            a[n] = Merge::aux[j++];

        } else {
            a[n] = Merge::aux[i++];
        }

    }

}