#include <iostream>

int main() {
    
    int n = 4;
    // TOP
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            std::cout << " ";
        }

        std::cout << "*";

        if (i!=0){
            for (int j=0; j<2*i-1; j++){
                std::cout << " ";
            }
        std::cout << "*";
        }

        std::cout << std::endl;
    }


    // BOTTOM
    for (int i=0; i<n-1; i++){
        for (int j=0; j<i+1; j++){
            std::cout << " ";
        }

        std::cout << "*";

        if (i!= n-2){
            for (int j=0; j<2*(n-2-i); j++){
            std::cout << " ";
            }
        
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}