#include <iostream>

#include "tut_11.hpp"

// ----------------- Node class ------------------ //

Node::Node( int new_value, Node *new_next )
: value_ {new_value}
, next_ {new_next} {
    // empty constructor
}

int Node::value() const {
    return value_;
}

Node *Node::next() const {
    return next_;
}

// -------------- Linked_list class --------------- //
Linked_list::Linked_list()
: p_head_ { nullptr } 
, p_tail_ { nullptr } {
    // Empty constructor
}

Linked_list::~Linked_list() {
    clear();
}

int Linked_list::front() const {
    if ( p_head_ != nullptr ) {
        return p_head_->value(); 
    } else {
        throw std::out_of_range{ "The linked list is empty" };
    }
}

int Linked_list::back() const {
    if ( p_head_ != nullptr ) {
        return p_tail_->value(); 
    } else {
        throw std::out_of_range{ "The linked list is empty" };
    }
}

void Linked_list::push_front( int const &value ) {
    p_head_ = new Node{ value, p_head_ };

    if ( p_tail_ == nullptr ) {
        p_tail_ = p_head_;
    }
}

void Linked_list::push_back( int const &value ) {
    if ( p_tail_ == nullptr ) {
        push_front( value );
    } else {
        p_tail_->next_ = new Node{ value, nullptr };

        p_tail_ = p_tail_->next();
    }
}

Node *Linked_list::find( int const &value ) const {
    
    for( Node *search{ p_head_ }; search != nullptr; search = search->next() ) {
        if ( search->value() == value ) {
            return search;
        }
    }

    return nullptr;
}

std::size_t Linked_list::erase( int const &value ) {

    std::size_t num_erased{0};
    
    // Outer while loop ensures we
    // erase ALL nodes with given value
    while ( true ) {
        Node *search{ find(value) };

        if ( search == nullptr ) {
            break; // No more nodes with given value
        }

        Node *prev{ nullptr };
    
        if ( search == p_head_ ) {
            p_head_ = p_head_->next();
        } else {
            prev = p_head_;

            while ( prev->next() != search ) {
                prev = prev->next();
            }

            prev->next_ = search->next();
        }

        // Case 1: erased item was only item in list, so
        //         search == (old) p_head_ == p_tail_ and prev == nullptr
        // Case 2: erased item was last item, so search == p_tail_
        //         and prev correctly stores node before search
        if ( search == p_tail_ ) {
            p_tail_ = prev;
        }
        
        delete search;
        search = nullptr;

        ++num_erased;
    }

    return num_erased;
}

void Linked_list::clear() {
    while ( p_head_ != nullptr ) {
        Node *p_old_head { p_head_ };
        
        p_head_ = p_head_->next();

        delete p_old_head;
        p_old_head = nullptr;
    }

    p_tail_ = nullptr;
}

// Overload << so we can use cout on a linked list!
std::ostream &operator<<( std::ostream &out, Linked_list const &list ) {
    out << "head -> ";

    for ( Node *p_node{ list.p_head_ }; p_node != nullptr; p_node = p_node->next() ) {
        out << "( " << p_node->value() << " ) -> ";
    }

    out << "nullptr";

    return out;
}
