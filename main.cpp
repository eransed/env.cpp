#include "util.hpp"

#define log(a) std::cout << a
#define logn(a) std::cout << a << std::endl

int main(int argc, char* argv[]) {
    std::string hello = "hello";
    logn(hello);
    
    for (int i = 0; i < argc; i++) {
        logn (argv[i]);
    }

    {
        ScopedTimer t;
        for (int i = 0; i < 5; i++) {
            logn(t.getDuration_pretty());
        }
        
    }

    return 0;
}