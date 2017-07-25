#include <vector>
#include <iostream>

bool CanFallAsleep(std::vector<bool>& digits)
{
	for(int i=0;i<digits.size();i++)
		if(!digits[i])
			return false;
	return true;
}
void AddDigits(std::vector<bool>& digits,const long long Number)
{
	long long Temporary = Number;
	while(Temporary != 0){
		digits[Temporary%10]=true;
		Temporary/=10;
	}
}
int main(){
	int T ;
	long long N;
	long long CurrentNumber;
	std::cin>>T;
	for(int i=0;i<T;i++){
		std::vector<bool> digits(10,false);
		std::cin>>N;
		std::cout<<"Case #"<<i+1<<": ";
		if(N!=0){
			for(CurrentNumber=N;!CanFallAsleep(digits);CurrentNumber+=N){
				AddDigits(digits,CurrentNumber);
			}
			std::cout<<CurrentNumber-N<<std::endl;
		} else {
			std::cout<<"INSOMNIA"<<std::endl;
		}
	}
	return 0;
}
