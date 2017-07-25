#include <iostream>
#include <vector>
#include <string>

int main(){
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++){
		std::string input;
		std::string output;
		std::cin>>input;
		output+=input[0];
		for(int j=1;j<input.size();j++){
			if(input[j]>=output.front())
				output.insert(0,1,input[j]);
			else if(input[j]<=output.front())
				output.push_back(input[j]);
		}
		std::cout<<"Case #"<<i+1<<": "<<output<<std::endl;
	}
	return 0;
}
