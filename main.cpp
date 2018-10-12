#include "util.hpp"

int main(int argc, char* argv[]) {

    char line[6];
    int count = 0;
    int N = 33000;
    int a[N];

    {
        ScopedTimer t("File read", true);
        while( std::cin.good() ) {
            std::cin.getline(line, sizeof(line));
            a[count] = atoi(line);
            count++;
            if(count >= N){
                count--;
                break;
            }
        }
    }

    Sort::isSortedPrettyPrint(a, count);

    int sel[N], ins[N], mer[N]; 
    for (int i = 0; i < N; i++){
        sel[i] = ins[i] = mer[i] = a[i];
    }

    std::cout << "\nSelection sorting " << count << " values..." << std::endl;
    {
        ScopedTimer t("Selection sort", true);
        Selection::sort(sel, count);
    }
    Sort::isSortedPrettyPrint(sel, count);


    std::cout << "\nInsertion sorting " << count << " values..." << std::endl;
    {
        ScopedTimer t("Insertion sort", true);
        Insertion::sort(ins, count);
    }
    Sort::isSortedPrettyPrint(ins, count);


    
    std::cout << "\nMerge sorting " << count << " values..." << std::endl;
    {
        ScopedTimer t("Merge sort", true);
        Merge::sort(mer, count);
    }

    {
        ScopedTimer t("\nLinear sort check and print", true);
        Sort::isSortedPrettyPrint(mer, count);
    }


    {
        ScopedTimer t("\nTimer overhead", true);
    }

    return 0;
}