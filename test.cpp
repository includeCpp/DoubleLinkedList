#include <iostream>

#include "data_structures.hpp"


int main(){
	data_structures::d_list<int> l;
	l.push_back(44);
	l.push_back(31);
	//l.push_back(22);
	//l.push_back(114);
	//l.push_back(667);
	//l.push_back(15);
	//l.push_back(665);
	//l.push_back(565);
	//l.push_back(599);
	//l.push_back(511);
	//l.get_first(); 
	//l.print(2);
	std::cout << train_(l) << std::endl;




	return 0;

}

