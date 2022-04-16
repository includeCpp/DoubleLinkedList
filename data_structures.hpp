#ifndef _ii_data_structures__
#define _ii_data_structures__

#include <iterator>


namespace data_structures{

template<typename T>
struct Node{
public:
	Node(const T& _value, Node<T>* _prev = nullptr, Node<T>* _next = nullptr);
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
struct d_list{
public:
	d_list(Node<T>* _first = nullptr);
	d_list(const d_list<T>& copy);

	bool is_empty() const;
	void push_back(const T& _value);
	void get_first() const;
	void print(const T& num);
	void clear();
	d_list<T>& operator=(const d_list<T>& copy);
	~d_list();

	using iterator = Node<T>*;

//private:
	Node<T>* first;
};

template<typename T>
Node<T>::Node(const T& _value, Node<T>* _next, Node<T>* _prev) : value(_value), next(_next), prev(_prev) {}

template<typename T>
d_list<T>::d_list(Node<T>* _first) : first(_first) {}

template<typename T>
bool d_list<T>::is_empty() const {
	return nullptr == first;
}

template<typename T>
void d_list<T>::push_back(const T& _value){
	Node<T>* element = new Node<T>(_value);
	if(is_empty()){
		first = element;
		return;
	}
	if(first -> prev == nullptr){
		first -> prev = element;
		first -> next = element;
		element -> next = first;
		element -> prev = first;
		return;
	}
	Node<T>* p = first -> prev;
	first -> prev = element;
	p -> next = element;
	element -> next = first;
	element -> prev = p;
	return;
}

template<typename T>
void d_list<T>::get_first() const {
	std::cout << first -> value << std::endl;
}

template<typename T>
void d_list<T>::print(const T& num){
	Node<T>* p = first;
	int i = 0;
	while(i < num){
		p = p -> next;
		i++;
	}
	//std::cout << "prev: " << p -> prev << std::endl;
	std::cout << "p: " << p -> value << std::endl;
	//std::cout << "next : " << p -> next << std::endl;
}

template<typename T>
void d_list<T>::clear(){
    Node<T>* p = first;
    while(p){
        p = p -> next;
        delete first;
        first = p;
    }

}

template<typename T>
d_list<T>& d_list<T>::operator=(const d_list<T>& copy){
    if(this == &copy){
        return *this;
    }
    if(!first || !copy.first){
        if(!first){
            Node<T>* m = copy.first;
            while(m){
                push_back(m -> value);
                m = m -> next;
            }
            return *this;
        }
        clear();
        std::cout << "The argument was empty.";
        return *this;
    }
    Node<T>* p = first;
    Node<T>* m = copy.first;
    Node<T>* last = p;
    while(m && p){
        p -> value = m -> value;
        last = p;
        p = p -> next;
        m = m -> next;
    }
    while(p){
        Node<T>* j = p;
        p = p -> next;
        delete j;
    }
    if(last){
        last -> next = nullptr;
    }
    while(m){
        last -> next = new Node<T>(m -> value);
        last = last -> next;
        m = m -> next;
    }
    return *this;
}

template<typename T>
d_list<T>::~d_list(){
	Node<T>* p = first -> next;
	Node<T>* g = p;
	while(p != first){
		p = p -> next;
		delete g;
		g = p;
		if(p == first){
			delete p;
		}
	}
}

} // data_structures

#endif













