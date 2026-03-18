#include <iostream>
#include <cassert>

//--->is_sorted function
std::size_t is_sorted( double array[], std::size_t capacity ){
    for( std::size_t k{0}; k < capacity-1; ++k ){
        if( array[k] > array[k+1] ){
            return k+1;
        }
    }
    return capacity;
}

//--->Selection Sort
std::size_t find_max( double array[], std::size_t capacity ){
    assert( capacity > 0 );
    std::size_t max_index = 0;

    for( std::size_t k{1}; k < capacity ; ++k ){
        if( array[k] > array[max_index] ){
            max_index = k;
        }
    }
    return max_index;
}

void swap( double &first, double &second ){
    double tmp = first;
    first = second;
    second = tmp;
}

void selection_sort( double array[], std::size_t capacity ){
    for( std::size_t k{ capacity-1 }; k > 0 ; --k ){
        std::size_t max_index{ find_max( array, capacity ) };
        swap( array[max_index], array[k] );
    }
    assert( is_sorted( array, capacity ) == capacity );
}

//--->Insertion Sort
void insert( double array[], std::size_t capacity ){
    assert( is_sorted( array, capacity-1 ) == capacity-1 );
    std::size_t value{ array[capacity-1] };
    std::size_t k{};

    for( k = capacity-1 ; (k > 0) && (array[k-1] > value); --k ){
        array[k] = array[k-1];
    }
    array[k] = value;
}

void insertion_sort( double array[], std::size_t capacity ){
    for( std::size_t k{ 2 }; k <= capacity; ++k ){
        insert( array, k );
    }
    assert( is_sorted( array, capacity ) == capacity );
}

class Node{
    private:
        int value_;
        Node *next_;

    public:
        Node( int new_value, Node *new_next );
        int value() const{
            return value_;
        }
        Node *next() const{
            return next_;
        }

        friend class Linked_list;
};

class Linked_list{
    private:
        Node *p_head_;
        Node *p_tail_;
    
    public:
        Linked_list();
        ~Linked_list();

        void push_front( int const &value );
        //-->Alternate Solution ( Push Front )
        void push_front( int new_value ){
            if( p_head_ == nullptr ){
                Node *newNode = new Node{ new_value, nullptr };
                p_head_ = newNode;
            } else{
                Node *newNode = new Node{ new_value, p_head_ };
                p_head_ = newNode;
            }
        }
        //-->Optimal Solution ( Push Front )
        void push_front( int new_value ){
            Node *newNode = new Node{ new_value, p_head_ };
            p_head_ = newNode;
        }

        //-->Find
        Node *find( int const &value ) const;
        Node *find( int new_value ){
        for( Node *ptr{ p_head_ }; ptr != nullptr; ptr = ptr->next() ){
            if( ptr->value() != new_value ){
                ptr = ptr->next();
            } else{
                return ptr;
            }
        }
        return nullptr;
        }

        //-->Erase
        std::size_t erase( int const &value );
        std::size_t erase( int new_value ){
            Node *current{ p_head_ };
            Node *previous{ nullptr };

            while( current != nullptr ){
                if( current->value() == new_value ){
                    if( previous == nullptr ){
                        p_head_ = current->next();
                    } else{
                        previous->next_ = current->next();
                    }
                
                delete current;
                return 1;
                } else{
                    previous = current;
                    current = current->next();
                }
            }
        }

        //-->Clear
        void clear();
        void clear(){
            while( p_head_ != nullptr ){
                Node *p_old_head_{ p_head_ };
                p_head_ = p_head_->next();

                delete p_old_head_;
                p_old_head_ = nullptr;
            }
            p_tail_ = nullptr;
        }

        //-->Push Back
        void push_back( int new_value ){
            if( p_head_ == nullptr ){
                push_front( new_value );
            } else{
                Node *newNode{ new Node{ new_value, nullptr } };
                p_tail_->next_ = newNode;
                p_tail_ = newNode;
            }
        }
};