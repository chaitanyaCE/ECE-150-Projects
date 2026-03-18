#include <iostream>

#include "tut_11.hpp"

/*

To compile and run: 

Option 1: Using command line
   
   g++ -std=c++17 main.cpp tut_11.cpp -o tut_11.exe; ./tut_11.exe
   (or clang++ instead of g++ depending on what you have installed)

Option 2: Using VS code's Run button (for easier visual debugging)

   In .vscode/tasks.json, replace the args: [...] section with

   "args": [
        "-fdiagnostics-color=always",
        "-g",
        "main.cpp",
        "tut_11.cpp",
        "-o",
        "${fileDirname}/tut_11.exe"
    ],

-------------------------------------------------------------------------

Expected output when everything has been correctly implemented:

>>> Inserting 3
>>> Inserting 5
>>> Inserting -10
>>> Inserting 3
>>> Inserting 30

head -> ( 30 ) -> ( 3 ) -> ( -10 ) -> ( 5 ) -> ( 3 ) -> nullptr
------------------------------------------------------------------ 
>>> Verifying p_tail_ is correct

p_tail_->value() == 3
------------------------------------------------------------------ 
>>> Finding node with value 5

Found node with value 5
------------------------------------------------------------------ 
>>> Erasing all nodes with value 3

Erased 2 nodes

head -> ( 30 ) -> ( -10 ) -> ( 5 ) -> nullptr
------------------------------------------------------------------ 
>>> Verifying p_tail_ is correct

p_tail_->value() == 5
------------------------------------------------------------------ 
>>> Clearing list

head -> nullptr
------------------------------------------------------------------ 
>>> Verifying p_tail_ is correct

p_tail_ is nullptr
------------------------------------------------------------------ 
>>> Inserting -15
>>> Inserting 7
>>> Inserting 5

head -> ( -15 ) -> ( 7 ) -> ( 5 ) -> nullptr
------------------------------------------------------------------ 
>>> Verifying p_tail_ is correct

p_tail_->value() == 5
------------------------------------------------------------------ 
*/

void verify_list_tail( Linked_list const &list );
void verify_push_front( Linked_list &list, std::initializer_list<int> const &nums_to_push_front );
void verify_erase( Linked_list &list, std::initializer_list<int> const &nums_to_erase );
void verify_clear( Linked_list &list );
void verify_push_back( Linked_list &list, std::initializer_list<int> const &nums_to_push_back );
void verify_find( Linked_list &list, int const &value );
int main();

int main() {
    Linked_list test{};

    std::initializer_list<int> nums_to_push_front { 3, 5, -10, 3, 30 };
    verify_push_front( test, nums_to_push_front );

    // Un-comment once push_front() has been updated to handle p_tail_
    // verify_list_tail( test );

    int to_find { 5 };
    verify_find( test, to_find );

    std::initializer_list<int> nums_to_erase { 3 };
    verify_erase( test, nums_to_erase );

    // Un-comment once push_front() has been updated to handle p_tail_
    // verify_list_tail( test );

    // Un-comment once clear() has been implemented
    // verify_clear( test );
    // verify_list_tail( test );

    // Un-comment once push_back() has been implemented
    // std::initializer_list<int> nums_to_push_back { -15, 7, 5 };
    // verify_push_back( test, nums_to_push_back );
    // verify_list_tail( test );

    return 0;
}

void verify_erase( Linked_list &list, std::initializer_list<int> const &nums_to_erase ) {

    for ( int const &value : nums_to_erase ) {
        std::cout << ">>> Erasing all nodes with value " << value << std::endl
                  << "\nErased " << list.erase(value) << " nodes" << std::endl;

        std::cout << std::endl << list << std::endl
                  << "------------------------------------------------------------------ " << std::endl;
    }
    
}

void verify_push_front( Linked_list &list, std::initializer_list<int> const &nums_to_push_front ) {

    for( int const &value : nums_to_push_front ) {

        std::cout << ">>> Inserting " << value << std::endl;
        list.push_front( value );

    }

    std::cout << std::endl << list << std::endl
              << "------------------------------------------------------------------ " << std::endl;

}

void verify_list_tail( Linked_list const &list ) {
    std::cout << ">>> Verifying p_tail_ is correct\n" << std::endl;

    try {
        int p_tail_value { list.back() };
        std::cout << "p_tail_->value() == " << p_tail_value << std::endl;
    } catch ( ... ) {
        std::cout << "p_tail_ is nullptr" << std::endl;;
    }
    
    std::cout << "------------------------------------------------------------------ " << std::endl;
}

void verify_clear( Linked_list &list ) {
    std::cout << ">>> Clearing list" << std::endl;

    list.clear();

    std::cout << std::endl << list << std::endl
              << "------------------------------------------------------------------ " << std::endl;
}

void verify_push_back( Linked_list &list, std::initializer_list<int> const &nums_to_push_back ) {

    for( int const &value : nums_to_push_back ) {

        std::cout << ">>> Inserting " << value << std::endl;
        list.push_back( value );

    }

    std::cout << std::endl << list << std::endl
              << "------------------------------------------------------------------ " << std::endl;
}

void verify_find( Linked_list &list, int const &value ) {
    std::cout << ">>> Finding node with value " << value << std::endl;

    Node *found_node { list.find(value) };

    if ( found_node == nullptr ) {
        std::cout << "\nNode with value " << value << " not found" << std::endl;
    } else {
        std::cout << "\nFound node with value " << found_node->value() << std::endl;
    }

    std::cout << "------------------------------------------------------------------ " << std::endl;
}