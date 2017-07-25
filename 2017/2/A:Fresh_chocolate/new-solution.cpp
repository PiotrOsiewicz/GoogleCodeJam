#include <iostream>
#include <vector>
#include <cmath>
int main(){
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int N,temp,P,solution=0;
		std::cin>>N>>P;
		std::vector<int> groups(P,0);
		for(int i=0;i<N;i++){
			std::cin>>temp;
			groups[temp%P]++;
		}
		switch(P){
			case 2:
				solution = std::ceil(groups[1]/2)+groups[0];
				break;
			case 3:
				solution = std::min(groups[1],groups[2])+std::ceil(std::abs(groups[1]-groups[2])/3)+groups[0];
				break;
			case 4:
				solution = std::floor(groups[2]/2) + std::min(groups[1],groups[3])+std::ceil(2*(groups[2]%2)+std::abs(groups[1]-groups[3])/4) + groups[0];
				break;
		}

		std::cout<<"Case #"<<t<<": "<<solution<<std::endl;
	}
	return 0;
}
