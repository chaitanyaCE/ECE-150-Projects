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
    clear(); // To implement
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
    // To implement
}

void Linked_list::push_back( int const &value ) {
    // To implement
}

Node *Linked_list::find( int const &value ) const {
    // To implement
    return nullptr; // placeholder
}

std::size_t Linked_list::erase( int const &value ) {
    // To implement
    return 0; // placeholder
}

void Linked_list::clear() {
    // To implement
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
