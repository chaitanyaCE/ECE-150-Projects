#ifndef TUT_11
#define TUT_11

class Node;
class Linked_list;

std::ostream &operator<<( std::ostream &out, Linked_list const &list );

class Node {
    private:
        int value_;
        Node *next_;

    public:
        Node( int new_value, Node *new_next );
        // No destructor because the Node class
        // does not dynamically allocate memory

        int value() const;
        Node *next() const;

    friend class Linked_list;
};

class Linked_list {
    private:
        Node *p_head_;
        Node *p_tail_;
    public:
        Linked_list();
        ~Linked_list();

        // To be able to know value of first and last item in list
        // 
        // front() included for consistency but only back() is used 
        // in main.cpp to verify list tail is correctly handled :P
        int front() const;
        int back() const;

        void push_front( int const &value );
        void push_back( int const &value );

        Node *find( int const &value ) const;

        std::size_t erase( int const &value );

        void clear();

        // Using friend allows this function from outside the class 
        // to access private member variables of this class
        friend std::ostream &operator<<( std::ostream &out, Linked_list const &list );
};

#endif