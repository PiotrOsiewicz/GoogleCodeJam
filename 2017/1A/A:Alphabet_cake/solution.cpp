#include <iostream>
#include <vector>
#include <string>

bool IsEmpty(std::string line)
{
	for(auto& a : line){
		if(a!='?')
			return false;
	}
	return true;
}
int main(){
	int T;
	std::cin>>T;
	for(int i = 0; i<T;i++){
		int R,C;
		std::vector<std::string> Cake;
		std::cin >> R >> C;
		for(int j=0;j<R;j++){
			std::string temp;
			std::cin>>temp;
			Cake.push_back(temp);
		}
		for(int j=0;j<R;j++){
			for(int z = 0;z<C;z++){
				if(Cake[j][z]!='?'){
					for(int w=z+1;w<C&&Cake[j][w]=='?';w++){
							Cake[j][w]=Cake[j][z];
					}
				}
			}
		}
		for(int j=0;j<R;j++){
			for(int z=0;z<C;z++){
				if(Cake[j][z]!='?'){
					for(int w=z-1;w>=0;w--)
						Cake[j][w]=Cake[j][z];
					break;
				}
			}
		}
		for(int j=1;j<R;j++){
			if(IsEmpty(Cake[j])){
				Cake[j]=Cake[j-1];
			}
		}
		for(int j=R-1;j>=0;j--){
			if(IsEmpty(Cake[j])){
				Cake[j]=Cake[j+1];
			}
		}
		std::cout<<"Case #"<<i+1<<":"<<std::endl;
		for(int j=0;j<Cake.size();j++)
			std::cout<<Cake[j]<<std::endl;
	}
	return 0;
}
