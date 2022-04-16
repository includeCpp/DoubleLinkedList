#include <iostream>

#include "data_structures.hpp"

template<typename T>
bool is_empty(T arg_list){
	return nullptr == arg_list.first;
}

template<typename T>
int train_(T& arg_list){
	if(is_empty(arg_list)){
		std::cout << "There is no train: ";
		return 0;
	}
	if(!arg_list.first -> next){
		std::cout << "There is only one railway carriage: ";
		return 1;
	}
    data_structures::Node<T>* g = arg_list.first -> prev;
    if(g -> prev == arg_list.first){
    	std::cout << "There is only two railway carriages: ";
        return 2;
    }
    data_structures::Node<T>* p = arg_list.first;
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
		while(light != count_l + 1){
            if(p -> value == fval){
                p = p -> next;
                if(p -> value != 1){
                    p -> value = 1;
                    light++;
                    break;
                }
                light++;
            }
            else{
            	std::cout << "Odd: ";
            	return railway_carriage_count = light + dark + 1;
            }
		}
		count_l = light;
        fval = p -> value;
		while(dark != count_d + 1){
            if(g -> value == bval){
                g = g -> prev;
                if(g -> value != 0){
                    g -> value = 0;
                    dark++;
                    break;
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


int main(){
	data_structures::d_list<int> l;
	l.push_back(44);
	l.push_back(31);
	l.push_back(22);
	l.push_back(114);
	l.push_back(667);
	l.push_back(15);
	l.push_back(665);
	l.push_back(565);
	l.push_back(599);
	l.push_back(511);
	//l.get_first(); 
	//l.print(2);
	std::cout << train_(l) << std::endl;




	return 0;

}

