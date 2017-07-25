#include <iostream>
#include <vector>

int BarberNumber(int N,const std::vector<int>& BarberTimes)
{
	auto ServedCustomersCount = [&](long Time) {
		if(Time<=0)
			return 0;
		int ServedCustomers = 0;
		for(int Barber = 0; Barber<BarberTimes.size();Barber++)
			ServedCustomers += Time / BarberTimes[Barber] +1;
		return ServedCustomers;
	};
	long long low = -1, high = 10000L*N;
	while(low+1<high){
		long mid = (low+high)/2;
		if(ServedCustomersCount(mid)<N)
			low = mid;
		else
			high = mid;
	}
	long T = high;
	int CustomersServedBefore = ServedCustomersCount(T-1);
	int CustomersToBeServed = N - CustomersServedBefore;
	for(int Barber = 0;Barber<BarberTimes.size();Barber++)
		if(T%BarberTimes[Barber] == 0){
			if(--CustomersToBeServed == 0)
				return Barber;
		}
}	

int main() {
	int T;
	std::cin>>T;
	for(int t = 1;t<=T;t++){
		int N,B,Temp,BarberIndex;
		std::cin>>B>>N;
		std::vector<int> Barbers;
		while(B-->0){
			std::cin>>Temp;
			Barbers.push_back(Temp);
		}

		std::cout<<"Case #"<<t<<": "<<BarberNumber(N,Barbers)<<std::endl;
	}
	return 0;
}
