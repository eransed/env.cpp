#include "util.hpp"

#define log(a) std::cout << a
#define logn(a) std::cout << a << std::endl

int main(int argc, char* argv[]) {
    
    for (int i = 0; i < argc; i++) {
        logn (argv[i]);
    }

    char line[10];
    int count = 0;
    int N = 80000;
    int a[N];

    while( std::cin.good() ) {
        std::cin.getline(line, sizeof(line));
        a[count] = atoi(line);
        count++;
        if(count >= N){
            count--;
            break;
        }
    }
    // Sort::print(a, count);

    {
        ScopedTimer t("Empty scope", true);
    }

    {
        ScopedTimer t("Insertion sort", true);
        std::cout << "Sorting " << count << " values..." << std::endl;
        Sort::insertion(a, count);
    }

    {
        ScopedTimer t("Merge sort", true);
        std::cout << "Sorting " << count << " values..." << std::endl;
        Merge::sort(a, count);
    }
    
    // Sort::print(a, count);

    return 0;
}