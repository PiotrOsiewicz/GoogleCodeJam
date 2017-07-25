#include <iostream>
#include <algorithm>
#include <string>

int FindNeededFriends(const std::string& input)
{
	int PeopleCounter = 0;
	int FriendCounter = 0;
	for(int i = 0;i<input.size();i++){
			FriendCounter = std::max(FriendCounter,i-PeopleCounter);
			PeopleCounter+=(input[i]-'0');
	}

	return FriendCounter;
}

int main(){
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++){
		int MaxShy;
		std::string shyness;
		std::cin>>MaxShy;
		std::cin>>shyness;
		std::cout<<"Case #"<<t<<": "<<FindNeededFriends(shyness)<<std::endl;	
	}

	return 0;
}
