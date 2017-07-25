#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
int main(){
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++){
		std::map<int,int> heights;
		int temp,N;
		std::cin>>N;
		for(int j=0;j<(2*N-1)*N;j++){
			std::cin>>temp;
			heights[temp]++;
		}
		std::vector<int> MissingValues;
		for(auto&& a : heights){
			if(a.second%2)
				MissingValues.push_back(a.first);
		}
		std::sort(MissingValues.begin(),MissingValues.end());
		std::cout<<"Case #"<<i+1<<":";
		for(auto&& a : MissingValues)
			std::cout<<" "<<a;
		std::cout<<std::endl;
	}
}
