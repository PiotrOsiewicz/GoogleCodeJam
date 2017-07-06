#include <iostream>
#include <algorithm>
#include <vector>
#include <ostream>
#include <cmath>
class Number{
	public:
		bool IsTidy(void);
		Number* Reduce();
		friend std::ostream& operator<<(std::ostream& output,const Number& A);
		Number(unsigned long long);
	private:
		int LastCorrectIndex;
		unsigned long long number;
		std::vector<short> digits;
		std::vector<short> BreakIntoDigits(unsigned long long);
};

bool Number::IsTidy(void)
{
	for(int i=0;i<digits.size()-1;i++){
		if(digits[i+1]<digits[i]){
			LastCorrectIndex = i;
			return false;
		}
	}
	return true;
}
Number* Number::Reduce(void)
{
	int temp = digits.size()-1;
	number = number - std::pow(10,(digits.size()-1)-LastCorrectIndex);
	digits = BreakIntoDigits(number);
	LastCorrectIndex = LastCorrectIndex - (temp - digits.size());
	if(LastCorrectIndex<0 || digits.size() == 0){
		 std::vector<short> temporary(temp,9);
		 digits = temporary;
	}else{
		for(int i=LastCorrectIndex;i<digits.size();i++){
			digits[i] = 9;
		}
	}
	number = 0;
	for(int i=0;i<digits.size();i++)
		number = number*10 + digits[i];
	return IsTidy()?this:Reduce();
}

std::ostream& operator<<(std::ostream& output,const Number& A){
	output << A.number;
	return output;
}

Number::Number(unsigned long long number){
	digits = BreakIntoDigits(number);
	LastCorrectIndex=0;
	this->number = number;
}

std::vector<short> Number::BreakIntoDigits(unsigned long long number)
{
	std::vector<short> temporary;
	unsigned long long temp = number;
	while(temp != 0){
		temporary.push_back(temp%10);
		temp/=10;
	}
	std::reverse(temporary.begin(),temporary.end());
	return temporary;
}

int main(void)
{
	unsigned long long N = 0;
	int T = 0;
	std::cin>>T;
	for(int i=0;i<T;i++){
		std::cin>>N;
		Number A(N);
		if(!A.IsTidy()){
			A.Reduce();
		}
		std::cout<<"Case #"<<i+1<<": "<<A<<std::endl;
	}
	return 0;
}
