#include <iostream>
#include <iomanip>
int main(){
	int T;
	std::cin>>T;
	for(int t=0;t<T;t++){
		long Destination;
		long HorsesCount;
		double MaximumTime = 0;
		std::cin>>Destination>>HorsesCount;
		for(int i=0;i<HorsesCount;i++){
			int temp1,temp2;
			std::cin>>temp1>>temp2;
			if((static_cast<double>(Destination-temp1) / temp2) > MaximumTime)
				MaximumTime = static_cast<double>(Destination-temp1)/temp2;
		}
		std::cout<<"Case #"<<t+1<<": "<<std::fixed<<std::setprecision(6)<<static_cast<double>(Destination)/MaximumTime<<std::endl;
	}
	return 0;
}
