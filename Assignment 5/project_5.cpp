#include <initializer_list>
#include <iostream>
#include <ostream>
#include <cassert>

// Class declarations
class Set;

// Function declarations
// Prints elements of the set (this code is given below)
// No forward-declaration here; the operator<< is declared as a friend inside class Set
// and defined after the class below.

// Class definitions
class Node {
    public:
        Node( int new_value, Node *new_next );
        int value() const;
        Node *next() const;
    private:
        int value_;
        Node *next_;
        // Allow any member function in the class
        // 'Set' to access or modify the member
        // variables of any instance of this class.
        friend class Set;
};

// provide simple inline definitions for Node methods
inline Node::Node( int new_value, Node *new_next )
    : value_{ new_value }, next_{ new_next } {}

inline int Node::value() const {
    return value_;
}

inline Node *Node::next() const {
    return next_;
}

class Set {
    public:
        // This is new and will be clearly explained
        Set( std::initializer_list<int> initial_values ): p_head_{ nullptr } {
            for ( int const &value : initial_values ) {
                insert( value );
            }
        }
        
        ~Set() {
            clear();
        }
        
        // The instructions will describe exactly what to do
        // The instructions will describe exactly what to do
        Set( Set const &orig );

        Set( Set &&orig ) noexcept;

        // The instructions will describe exactly what to do
        Set &operator=( Set const &orig );
        Set &operator=( Set &&orig ) noexcept;
        // Size operations
        bool empty() const {
            return (p_head_ == nullptr );
        }

        std::size_t size () const {
            std::size_t list_size{ 0 };
            for (Node *p_node{ p_head_} ; p_node != nullptr; p_node = p_node->next() ){
                ++list_size;
            }
            return list_size;
        }
                
        // Clear all items out of the set
        void clear() {
            while ( p_head_ != nullptr ) {
                Node *tmp = p_head_;
                p_head_ = p_head_->next();
                delete tmp;
            }
        }
        
        // Find the value item in the set
        // - Return the address of the node if found,
        // and nullptr otherwise.
        Node *find( int const &item ) const {
            Node *search = p_head_;
            while ( search != nullptr ){
                if ( search->value() == item ){
                    return search;
                }
                search = search->next();
            }
            return nullptr;
        }
        
        // Insert the item into the set if it
        // is not already in the set.
        // - Return 1 if the item is new,
        // and 0 otherwise.
        std::size_t insert( int const &item ) {
            if ( find( item ) != nullptr ){
                return 0;
            }
            Node *inserted_node = new Node{ item, p_head_ };
            p_head_ = inserted_node;
            return 1;
        }
        
        // Insert all the items in the array
        // from array[begin] to array[end - 1]
        // that are not already in the set.
        // - Return the number of items inserted
        // into the set.
        std::size_t insert( int const array[], std::size_t const begin, std::size_t const end ) {
            std::size_t count{ 0 };
            
            for( std::size_t i = begin; i < end; ++i) {
                if ( insert ( array[i] ) == 1 ) {
                    ++count;
                }
            }
            return count;
        }
        
        // Remove the item from the set and
        // return the number of items removed.
        std::size_t erase( int const &item ) {
            Node *current = p_head_;
            Node *previous = nullptr;

            while( current != nullptr ){
                if( current->value() == item ){
                    if( previous != nullptr ){
                        previous->next_ = current->next();
                    } else{
                        p_head_ = current->next();
                    }
                delete current;
                return 1;
                } else{
                    previous = current;
                    current = current->next();
                }
            }

            return 0;
        }
        
        // Move any items from 'other', whose values
        // do not appear in 'this', to 'this'.
        // Leave any items that already appear
        // in both sets, in both sets.
        std::size_t merge( Set &other ) {
            std::size_t count{ 0 };
            Node *current = other.p_head_;
            Node *previous = nullptr;
            
            while( current != nullptr ){
                Node *newNode = current->next();
                if( this->find( current->value() ) == nullptr ){
                    if( previous != nullptr ){
                        previous->next_ = newNode;
                    } else{
                        other.p_head_ = newNode;
                    }
                    current->next_ = p_head_;
                    p_head_ = current;
                    count++;
                } else{
                    previous = current;
                }
                current = newNode;
            }
            return count;
        }
        
        // Set operations (Automatic Assigment)
        Set &operator|=( Set const &other ) {       // union
            for ( Node *ptr{ other.p_head_ }; ptr != nullptr; ptr = ptr->next() ){
                insert ( ptr->value() );
            }
            return *this;
        }
        
        Set &operator&=( Set const &other ) {       // intersection
            Node *current = p_head_;
            Node *previous = nullptr;

            while( current != nullptr ){
                Node *newNode = current->next();
                if( other.find( current->value() ) == nullptr ){
                    if( previous == nullptr ){
                        p_head_ = newNode;
                    } else{
                        previous->next_ = newNode;
                    }
                } else{
                    previous = current;
                }
                current = newNode;
            }
            return *this;
        }

        Set &operator^=( Set const &other ) {       // symmetric difference
            for ( Node *ptr{ other.p_head_ }; ptr != nullptr; ptr = ptr->next() ) {
                if ( find( ptr->value() ) != nullptr ){
                    erase( ptr->value() );
                } else {
                    insert( ptr->value() );
                }
            }
            return *this;
        }

        Set &operator-=( Set const &other ) {       // minus
            for ( Node *ptr{ other.p_head_ }; ptr != nullptr; ptr = ptr->next() ) {
                erase ( ptr->value() );
            }
            return *this;
        }
        
        // Set operations (Binary)
        Set operator|( Set const &other ) const {       // union
            Set tmp{ *this };
            tmp |= other;
            return tmp;
        }

        Set operator&( Set const &other ) const {       // intersection
            Set tmp{ *this };
            tmp &= other;
            return tmp;
        }

        Set operator^( Set const &other ) const {       // symmetric difference
            Set result{ *this };
            result ^= other;
            return result;
        }
        
        Set operator-( Set const &other ) const {       // minus
            Set result{ *this };
            result -= other;
            return result;
        }
        
        // Returns 'true' if 'this' set is a
        // superset of 'other' set; that is,
        // all entries in the 'other' set are
        // also in this set.
        bool operator>=( Set const &other ) const {
            for ( Node *ptr{ other.p_head_ }; ptr != nullptr; ptr = ptr->next() ) {
                if ( find( ptr->value() ) == nullptr ) {
                    return false;
                }
            }
            return size() >= other.size();
        }
        
        // A superset but not equal to.
        bool operator>( Set const &other ) const {
        return (*this >= other) && (size() > other.size());
        }
        
        // Is 'this' a subset of the other set?
        bool operator<=( Set const &other ) const {
            return other >= *this;
        }
        
        // A subset but not equal to.
        bool operator<( Set const &other ) const {
            return other > *this;
        }

        bool operator==( Set const &other ) const {
            if( size() != other.size() ){
                return false;
            }
            for( Node *ptr{ p_head_ }; ptr != nullptr; ptr = ptr->next() ){
                if( other.find( ptr->value() ) == nullptr ){
                    return false;
                }
            }
            return true;
        }

        bool operator!=( Set const &other ) const {
            return !( *this == other );
        }

    private:
        Node *p_head_;
        friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};
    
// You are given this function that prints out
// Explicit definitions for Set copy/move operations
inline Set::Set( Set const &orig ) : p_head_{ nullptr } {
    for ( Node *p_node{ orig.p_head_ }; p_node != nullptr; p_node = p_node->next() ) {
        insert( p_node->value() );
    }
}

inline Set::Set( Set &&orig ) noexcept : p_head_{ orig.p_head_ } {
    orig.p_head_ = nullptr;
}

inline Set &Set::operator=( Set const &orig ) {
    if ( this != &orig ) {
        clear();
        for ( Node *p_node{ orig.p_head_ }; p_node != nullptr; p_node = p_node->next() ) {
            insert( p_node->value() );
        }
    }
    return *this;
}

inline Set &Set::operator=( Set &&orig ) noexcept {
    if ( this != &orig ) {
        clear();
        p_head_ = orig.p_head_;
        orig.p_head_ = nullptr;
    }
    return *this;
}

// You are given this function that prints out
// a set to the output stream.
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
if ( !rhs.empty() ) {
    out << rhs.p_head_->value();
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
    out << ", " << ptr->value();
    }
  }
  out << "}";
  return out;
}

int main() {
    Set my_data_1{ 1, 3, 5, 2, 4, 8, 5, 3, 1 };
    // This should print '6'
    std::cout << my_data_1.size() << std::endl;
    // This should print '0' ('false')
    std::cout << my_data_1.empty() << std::endl;
    assert( my_data_1.find( 0 ) == nullptr );
    assert( my_data_1.find( 1 )->value() == 1 );
    assert( my_data_1.find( 5 )->value() == 5 );
    assert( my_data_1.find( 6 ) == nullptr );
    assert( my_data_1.find( 8 )->value() );
}