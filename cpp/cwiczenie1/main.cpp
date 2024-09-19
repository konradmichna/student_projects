#include <iostream>
#include <vector>

using namespace std;


void bubbleSort(std::vector<int>& vec){
	int n vec.size();
	bool swaped;
	
	for(int i = 0; i < n -1; i++){
	    swapped = false;
	    
	    
            for(int j = 0; j < n - i - 1; j++) {
	        if(vec[j] > vec[j + 1] {
		   std:swap(vec[j], vec[j + 1]);
		   swapped = true;
                }
	    }
	    if(!swapped) break;
	}
}

int main(){
	std:vector<int> vec = {64, 34, 25, 12, 22, 11, 90};

	std:cout << "Nieposortowany wektor: ";
	for(int i = 0; i < vec.size(); i++) {
	   std:cout << vec[i];
	}
	std::cout << std::endl;

	bubbleSort(vec);

	std:cout << "Posortowany wektor: ";
	for(int i = 0; i < vec.size(); i++){
	   std::cout << vec[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}
