#include <iostream>
#include <iomanip>

int main()
{
	int T;
	std::cin >> T;
	for(int t = 1; t <= T; t++) {
		double C,F,X;
		std::cin >> C >> F >> X;
		double sum = 0;
		double CurrentProduction = 2.0;
		double cookieTime = C / CurrentProduction;
		double CurrentTotalTime = X / (CurrentProduction + F);
		double PreviousTotalTime = X / CurrentProduction;
		while( PreviousTotalTime >  CurrentTotalTime + cookieTime) {
			sum += cookieTime;
			PreviousTotalTime = CurrentTotalTime;
			CurrentProduction += F;
			CurrentTotalTime = X / (CurrentProduction + F);
			cookieTime = C / (CurrentProduction);
		}
		sum += PreviousTotalTime;
		std::cout<<"Case #"<<t<<": "<<std::fixed<<std::setprecision(10)<<sum<<std::endl;
	}
	return 0;
}
