# include <iostream>
# include <cassert>

double power(double base, std::size_t exponent){
    double res = 1.0;
    for (std::size_t i=0; i<exponent; ++i){
        res *= base;
    }
    return res;
}

double *geometric( double a, double ratio, std::size_t cap ){
    double* array = new double[cap];
    for (unsigned int i=0; i<cap; i++){
        array[i] = a * power(ratio,i);
    }
    return array;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    assert(cap0 + cap1 >= 1);
    
    std::size_t capacity = cap0 + cap1 - 1;

    double* array = new double[capacity];
    

    for (unsigned int k=0; k<capacity; ++k){
        array[k] = 0;
    }
    
    for (unsigned int i=0; i<cap0; i++){
        for (unsigned int j=0; j<cap1; j++){
            array[i+j] += (array0[i] * array1[j]);
        }
    }

    return array;
}

std::size_t shift_duplicates( int array[], std::size_t capacity ){
    
    if (capacity == 0) return 0;
    
    std::size_t count = 0;
    
    for(std::size_t i=0; i<capacity; ++i){
        bool is_unique = true;
        for (std::size_t j=0; j<count; ++j){
            if (array[i] == array[j]){
                is_unique = false;
                break;
            }
        }
        if(is_unique){
            int final_array = array[count];
            array[count] = array[i];
            array[i] = final_array;
            count++;
        }
    }
    return count;
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0 ){
    if (is_array){
        for (std::size_t i=0; i<capacity; ++i){
            ptr[i] = 0;
        }
        delete[] ptr;
    }   else{
            *ptr = 0;
            delete ptr;
    }
    ptr = nullptr;
}

int main() {
    
    //Geometric series//

    std::size_t n;
    double a, r;

    std::cout << "Enter the first term (a): ";
    std::cin >> a;
    std::cout << "Enter the common ratio (r): ";
    std::cin >> r;
    std::cout << "Enter the number of terms (n): ";
    std::cin >> n;

    double* series = geometric(a, r, n);

    std::cout << "Geometric series: ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << series[i] << " ";
    }
    std::cout << std::endl;

    //Cross-correlation//

    std::size_t cap1, cap2;
    
    std::cout << "Enter the size of the first array : " << std::endl;
    std::cin >> cap1;
    double *array1 = new double[cap1];
    for (std::size_t i=0; i<cap1; ++i){
        std::cout << "Enter element ";
        std::cin >> array1[i];
    }

    std::cout << "Enter the size of the second array : " << std::endl;
    std::cin >> cap2;
    double *array2 = new double[cap2];
    for (std::size_t j=0; j<cap2; ++j){
        std::cout << "Enter element ";
        std::cin >> array2[j];
    }
    
    double* result = cross_correlation(array1, cap1, array2, cap2);

    std::size_t capacity = cap1 + cap2 - 1;
    std::cout << "Cross-correlation result: ";
    
    for (std::size_t i=0; i<capacity; ++i){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    //Shift duplicates//

    std::size_t cap;
    std::cout << "Enter the size of the integer array : " << std::endl;
    std::cin >> cap;

    int *array = new int[cap];
    std::cout << "Enter the elements of the array : " << std::endl;
    for (std::size_t i=0; i<cap; ++i){
        std::cin >> array[i];
    }

    std::size_t answer = shift_duplicates(array, cap);
    std::cout << "Array after removing duplicates: ";
    for (std::size_t i=0; i<answer; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    //Deallocation//

    bool is_array;
    std::cout << "Do you want to dellocate the array? (1 for yes, 0 for no): ";
    std::cin >> is_array;

    std::size_t capacity1 = 0;
    double *ptr = nullptr;

    if (is_array){
        std::cout << "Enter the capacity of the array : ";
        std::cin >> capacity1;
        ptr = new double [capacity1];
        for (std::size_t i=0; i<capacity1; ++i){
            std::cin >> ptr[i];
        }
    }   else{
            ptr = new double;
            std::cout << "Enter the value : ";
            std::cin >> *ptr;
    }

    deallocate(ptr, is_array, capacity1);

    if (ptr == nullptr){
        std::cout << "The pointer is now a null pointer." << std::endl;
    }

    return 0;
}