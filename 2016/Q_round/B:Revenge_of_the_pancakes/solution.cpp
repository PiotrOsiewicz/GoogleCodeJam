#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++){
		std::string pancakes;
		std::cin>>pancakes;
		std::string::size_type pos = -1;
		int grouped_height = 1;
		while((pos = pancakes.find("+-",pos+1))!= std::string::npos){
			grouped_height++;
		}
		pos = -1;
		while((pos = pancakes.find("-+",pos+1)) != std::string::npos)
			grouped_height++;
		if(pancakes.at(pancakes.size()-1) == '+')
			grouped_height--;
		std::cout<<"Case #"<<i+1<<": "<<grouped_height<<std::endl;
		pancakes.clear();
	}
	return 0;
}
