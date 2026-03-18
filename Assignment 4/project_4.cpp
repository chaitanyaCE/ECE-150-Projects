#include <iostream>
#include <cassert>
#include <algorithm>
#include <climits>
#include <fstream>
#include "p_4_header.hpp"



// Function declarations for functions expected in project_4.cpp
std::size_t     length( char const *a );                                        // 2.1
int             compare( char const *str1, char const *str2 );                  // 2.2
void            assign( char *str1, char const *str2 );                         // 2.3
unsigned int    distance( char const *str1, char const *str2 );                 // 2.4
std::size_t     is_sorted( char *array[], std::size_t capacity );               // 2.5
void            insert( char *array[], std::size_t capacity );                  // 2.6
void            insertion_sort( char *array[], std::size_t capacity );          // 2.7
std::size_t     remove_duplicates( char *array[], std::size_t capacity );       // 2.8
std::size_t     find( char *array[], std::size_t capacity, char const *str);    // 2.9
void            free_word_array( char** word_array );                           // 2.11

std::size_t length( char const *a ){
    std::size_t count = 0;
    while (a[count] != '\0'){
        count++;
    }
    return count;
}

int compare( char const *str1, char const *str2 ){
    int k  = 0;
    while (true){
        if(str1[k] == '\0' && str2[k] == '\0') return 0;
        if(str1[k] == '\0') return -1;
        if(str2[k] == '\0') return 1;
        if (str1[k] < str2[k]) return -1;
        if (str1[k] > str2[k]) return 1;
        ++k;
    }
    return 0;
}

void assign( char *str1, char const *str2 ){
    int i = 0;
    while(str2[i] != '\0'){
        str1[i] = str2[i];
        ++i;
    }
    str1[i] = '\0';
}

unsigned int distance( char const *str1, char const *str2 ){
    unsigned int minimum = 0;
    if (str1[0] == '\0') return length(str2);
    if (str2[0] == '\0') return length(str1);

    if (str1[0] == str2[0]) return distance(str1+1, str2+1);

    if (str1[0] != str2[0]){
        int del = distance(str1+1, str2);
        int ins = distance(str1, str2+1);
        int sub =  distance(str1+1, str2+1);
        minimum = std::min<int>({del, ins, sub});
    }
    return (minimum+1);
}

std::size_t is_sorted( char *array[], std::size_t capacity ){
    for (std::size_t i=1; i<capacity; ++i){
        if (compare(array[i], array[i-1]) < 0){
            return i;
        }
    }
    return capacity;
}

void insert( char *array[], std::size_t capacity ){
    char *value = new char [length(array[capacity-1]) + 1];
    assign(value, array[capacity-1]);
    std::size_t i;
    for (i=capacity-1; i>0; --i){        
        if (compare(array[i-1], value) > 0){
            array[i] = array[i-1];
        }   else{
                break;
        }
        }
    array[i] = value;
}

void insertion_sort( char *array[], std::size_t capacity ){
    for (std::size_t i = 2; i < capacity; ++i){
        insert(array, i);
    }
}

std::size_t remove_duplicates(const char *array[], std::size_t capacity ){
    std::size_t unique = 0;
    if (capacity == 0) return 0;

    for (std::size_t i=1; i<capacity; ++i){
        if (compare(array[unique], array[i]) != 0){
            ++unique;
            array[unique] = array[i];
        }
    }
    return (unique+1);
}

std::size_t find( char *array[], std::size_t capacity, char const *str ){
    std::size_t min_distance{INT_MAX};
    std::size_t min_index{0};

    for (std::size_t i=0; i<capacity; ++i){
        if (compare(array[i], str) == 0){
            return i;
        }
        else{
            std::size_t dist = distance(array[i], str);
            if( dist < min_distance ){
                min_distance = dist;
                min_index = i;
            }
        }
    }
    return min_index;
}

std::size_t numwords = 0;

void read_words_from_file( char const *filename, char **&word_array, std::size_t max_length ){
    std::ifstream file{ filename };
    if (!file.is_open()) {
        std::cout << "[ERROR] " << filename << " not found or could not open file" << std::endl;
    }
    assert( file.is_open() );

    // Read the number of words from the first line of the file
    file >> numwords;

    // Ignore the newline '\n' character after the number
    file.ignore();
    /// Allocate memory and initialize the word array
    // pointers to individual words
    word_array = new char*[numwords];
    for (std::size_t k = 0; k < numwords; ++k) {
        word_array[k] = new char[max_length + 1];
        file >> word_array[k];
    }
    
    file.close();
    }

void free_word_array( char** word_array ){
    for (std::size_t i=0; i<numwords; ++i){
        delete [] word_array[i];
    }
    delete[] word_array;
}


// int main(){
//     //Length of String
//     char const *string = "Chaitanya";
//     std::cout << "Length of string : " << length(string) << std::endl;

//     //Comparing Strings
//     char const *str1 = "Chaitanya";
//     char const * str2 = "Patel";
//     std::cout << compare(str1, str2) << std::endl;

//     //Assign
//     char string1[21] = "Chaitanya";
//     char const *string2 = "Patel";
//     assign(string1, string2);

//     //Distance
//     char const *st1 = "act";
//     char const *st2 = "cat";
//     std::cout << "Distance between the two strings is : " << distance(st1, st2) << std::endl;

//     return 0;
// }