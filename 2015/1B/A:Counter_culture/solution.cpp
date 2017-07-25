#include <iostream>
#include <vector>
#include <algorithm>

static long long ReverseNumber(const long long  number)
{
	long long reversed = 0,temp = number;
	while(temp != 0){
		reversed = reversed*10 + temp%10;
		temp/=10;
	}
	return reversed;
}
long long Decision(const long long number,const long long target)
{
	int temp = ReverseNumber(number);
	return temp>number && temp <= target? temp: number;
}
int main(){
	int T;
	std::cin>>T;
	for(int t = 1; t <= T; t++){
		long long N,counter = 1,number = 1;
		long long temp_number;
		std::cin>>N;
		while(number < N){
			temp_number = number;
			int add = 1;
			while(Decision(temp_number,N) != temp_number) {
				temp_number = Decision(temp_number,N);
				add = 2;
			}
			number = temp_number;
			number++;
			counter+=add;
		}
		std::cout<<"Case #"<<t<<": "<<counter<<std::endl;
	}
	return 0;
}
