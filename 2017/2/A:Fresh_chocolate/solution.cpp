#include <iostream>
#include <algorithm>
#include <vector>

int P;

bool compare(int i, int j)
{
	return i%P < j%P;
}
int main(){
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int N,temp,counter = 0,leftover=0;
		std::vector<int> groups;
		std::cin>>N>>P;
		for(int i=0;i<N;i++){
			std::cin>>temp;
			groups.push_back(temp);
		}
		std::sort(groups.begin(),groups.end(),compare);
		for(int i=0;i<groups.size();i++){
			std::cout<<groups[i]<<std::endl;
			if(leftover == 0)
				counter++;
			leftover = (groups[i]+leftover)%P;
		}
		std::cout<<"Case #"<<t<<": "<<counter<<std::endl;
	}
	return 0;
}
