#include <iostream>

#include "data_structures.hpp"


int main(){
	data_structures::d_list<int> l;
	l.push_back(10);
	l.push_back(112);
	l.push_back(113);
	l.push_back(110);
	l.push_back(34);
	l.push_back(55);
	l.push_back(665);
	l.push_back(565);
	l.push_back(599);
	l.push_back(511);
	//l.get_first(); 
	//l.print(2);
	std::cout << l.train_() << std::endl;




	return 0;

}

