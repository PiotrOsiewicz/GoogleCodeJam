#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int main(){
	int T;
	std::cin>>T;
	for(int t = 1; t<=T;t++){
		int D,temp,minimum,moves;
		std::vector<int> pancakes;
		std::cin>>D;
		for(int i=0;i<D;i++){
			std::cin>>temp;
			pancakes.push_back(temp);
		}
		const int max_pancake = *std::max_element(pancakes.begin(),pancakes.end());
		minimum = max_pancake;
		for(int x=1;x<max_pancake;++x){
			moves=0;
			for(auto a : pancakes){
				moves += (a-1)/x;
			}
			minimum = std::min(minimum,moves+x);
		}
		std::cout<<"Case #"<<t<<": "<<minimum<<std::endl;
	}
	return 0;
}
