# include <iostream>
# include <cassert>


void pattern( unsigned int n ){


    std::cout << "n = " << n << ":" << std::endl;
    
    for (int i=0; i<n+1; i++){
        for (int j=1; j<i+1; j++){
           std::cout << " ";
        }        
        
        for (int j=0; j<=n-i; j++){
            std::cout << "*";
        }

        for (int j=n-i; j>=1; j--){
            std::cout << "*";
        }
        std::cout << std::endl;

    }

    for (int i=0; i<n; i++){
        for (int j=n-i-2; j>=0; j--){
            std::cout << " ";
        }

        for (int j=0; j<=i+1; j++){
            std::cout << "*";
        }

        for (int j=0; j<=i; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
}


unsigned int log10( unsigned int n ){
    assert (n != 0);
    int m = 0;
    while (10 <= n){
        n /= 10;
        m++;
    }
    return m;
}


unsigned int count( unsigned int n, unsigned int bit ){
    assert (bit == 0 || bit == 1);
    int counter = 0;

    while (n>0){
        int lastBit = n & 1;
        if (lastBit == bit){
            counter++;
        }
        n >>= 1;
    }
    return counter;
}

int swap_bytes( unsigned int n, unsigned int b0, unsigned int b1 ){
    assert(b0 <= 3 && b1 <= 3);
    
    if (b0 == b1){
        return n;
    }
    unsigned int byte0 = (n >> (b0*8)) & 0xFF;
    unsigned int byte1 = (n >> (b1*8)) & 0xFF; 

    n &= ~(0xFF << (b0*8));
    n &= ~(0xFF << (b1*8));

    n |= (byte0 << (b1*8));
    n |= (byte1 << (b0*8)); 

    return n;
}


int main(){
    pattern (8);

    std::cout << std::endl;
    std::cout << "log10(123456789) = " << log10(123456789) << std::endl;

    std::cout << std::endl;
    std::cout << "count (583648,0) = " << count(583648,0) << std::endl; 
    
    return 0;
}