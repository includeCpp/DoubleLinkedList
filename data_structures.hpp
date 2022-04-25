#ifndef _ii_data_structures__
#define _ii_data_structures__

#include <iterator>
#include <string>


namespace data_structures{

template<typename T>
struct Node{
public:
	Node(const T& _value, Node<T>* _prev = nullptr, Node<T>* _next = nullptr);
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template<typename Q>
struct d_list{
public:
	d_list(Node<Q>* _first = nullptr);
	d_list(const d_list<Q>& copy);

	bool is_empty() const;
	void push_back(const Q& _value);
	void get_first() const;
	void print(const Q& num);
	void clear();
	d_list<Q>& operator=(const d_list<Q>& copy);
	~d_list();
	
private:
	template<typename T> 
	friend int train_(data_structures::d_list<T>& arglist);

	using iterator = Node<Q>*;

	Node<Q>* first;
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
	clear();
}

template<typename T>
int train_(d_list<T>& arglist){
	int x = 0;
	try{
		if(arglist.is_empty()){
			std::string str = "There is no train: ";
			throw str;
		}
		if(!arglist.first -> next){
			std::string str = "There is only one railway carriage: ";
			x = 1;
			throw str;
		}
	    Node<T>* g = arglist.first -> prev;
	    if(g -> prev == arglist.first){
	    	std::string str = "There is only two railway carriages: ";
	    	x = 2;
	        throw str;
	    }
	} catch(std::string str){
		std::cout << str;
		return x;
	}
	Node<T>* g = arglist.first -> prev;
    Node<T>* p = arglist.first;
    p -> value = 1;
    g -> value = 0;
	//iterator it1 = p;
	//iterator it2 = g;
	int fval = p -> value;
	int bval = g -> value;
	int light = 0;
	int dark = 0;
	int count_l = 0;
	int count_d = 0;
	int railway_carriage_count = 0;
	while(railway_carriage_count == 0){
		//while(light != count_l + 1){
            if(p -> value == fval){
                p = p -> next;
                if(p -> value != 1){
                    p -> value = 1;
                    //light++;
                    //break;
                }
                light++;
            }
            else{
            	std::cout << "Odd: ";
            	return railway_carriage_count = light + dark + 1;
            }
		//}
		count_l = light;
        fval = p -> value;
		if(dark != count_d + 1){
            if(g -> value == bval){
                g = g -> prev;
                if(g -> value != 0){
                    g -> value = 0;
                    //dark++;
                    //break;
                }
                dark++;
            }
            else{
            	std::cout << "Even: ";
            	return railway_carriage_count = light + dark + 1;
            }
		}
		count_d = dark;
        bval = g -> value;
	}
	return 0;
}

} // data_structures

#endif













