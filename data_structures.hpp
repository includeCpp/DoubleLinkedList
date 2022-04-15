#ifndef _ii_data_structures__
#define _ii_data_structures__


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
	int train_();

private:
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
int d_list<T>::train_(){
	if(is_empty()){
		return 0;
	}
	if(!first -> next){
		return 1;
	}
	int light = 0;
	int dark = 0;
	int count_l = 0;
	int count_d = 0;
	int railway_carriage_count = 0;
	Node<T>* p;
	while(railway_carriage_count == 0){
		p = first;
		while(light != count_l + 1){
			p = p -> next;
			if(p -> value != 1){
			p -> value = 1;
			light++;
			break;
			}
			light++;
		}
		count_l = light;
		light = 0;
		p = first;
		while(dark != count_d + 1){
			p = p -> prev;
			if(p -> value != 0){
				p -> value = 0;
				dark++;
				break;
			}
			dark++;
		}
		if(count_d == dark || count_l == light){
			std::cout << count_l << " " << count_d << std::endl;
			return railway_carriage_count = count_l + count_d;
		}
		count_d = dark;
		dark = 0;
	}
	return 0;
}

} // data_structures

#endif













