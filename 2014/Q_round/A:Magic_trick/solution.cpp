#include <iostream>
#include <vector>
#include <string>
void ReadIntoVector(std::istream& stream,std::vector<std::vector<int>>& target,int amount)
{
	std::vector<int> temporary;
	int temp = 0;
	for(int i=0;i<amount;i++){
		for(int j=0;j<amount;j++){
			stream>>temp;
			temporary.push_back(temp);
		}
		target.push_back(temporary);
		temporary.clear();
	}
}

std::string JudgeTheMagician(const std::vector<int>& a,const std::vector<int>& b)
{
	int SameElementsCount = 0;
	int Element = 0;
	std::string verdict;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i] == b[j]){
				if(SameElementsCount==0)
					Element = a[i];
				SameElementsCount++;
			}
		}
	}
	switch(SameElementsCount){
		case 1:
			verdict = std::to_string(Element);
			break;
		case 0:
			verdict = "Volunteer cheated!";
			break;
		default:
			verdict = "Bad magician!";
			break;
	}
	return verdict;
}

int main(){
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int before,after,temp;
		std::vector<std::vector<int>> initial;
		std::vector<std::vector<int>> shuffled;
		std::vector<int> temporary;
		std::cin>>before;
		ReadIntoVector(std::cin,initial,4);
		std::cin>>after;
		ReadIntoVector(std::cin,shuffled,4);
		std::cout<<"Case #"<<t<<": "<<JudgeTheMagician(initial[before-1],shuffled[after-1])<<std::endl;
		initial.clear();
		shuffled.clear();
	}
	return 0;
}
