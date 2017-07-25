
#include <iostream>

std::string Flip(std::string input,int width,int startingPoint)
{
    for(int i = startingPoint; i < startingPoint +  width ; i++){
            input[i] = (input[i]=='-'?'+':'-');
    }
    return input;
}
bool isHappyStack(std::string input, int width)
{
    for(int i = input.size() - width; i < input.size() ; i++){
        if(input[i] == '-'){
            return false;
        }
    }
    return true;
    
}
int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++){
        std::string pancakes;
        int K; //width of pancake flipper
        int flipCounter = 0;
        std::cin >> pancakes;
        std::cin >> K;
        for(int i = 0; i <= pancakes.size() - K; i++){
            if(pancakes[i] == '-'){
                pancakes = Flip(pancakes,K,i);
                flipCounter++;
            } 
        }
        std::cout << "Case #" << t << ": ";
        if(isHappyStack(pancakes,K) == true){
            std::cout << flipCounter << std::endl;
        } else {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
    }
    return 0;
}