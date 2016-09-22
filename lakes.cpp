#include<iostream>
#include<string>
int main(){
	char lake = ' ';
	int numberDown = 0;
	int numberUps = 0;
	int quantity = 0;
	bool activeProgram = true;
	bool calculate = true;
	int tempVal = 0;
	std::string input = "";
	std::cout << "Input * to stop..!" << std::endl;
	while (activeProgram){
		std::cout << "Please, enter d[down], h[horizontal], u[up]..!" << std::endl;
		std::cin >> lake;
		if (numberDown == numberUps && numberDown != 0 && numberUps!=0){
			calculate = false;
			tempVal = 0;
			numberDown = 0;
			numberUps = 0;
		}
			switch (lake){
			case 'd':
				if (calculate){
					quantity += 500;
					quantity += numberDown * 1000;
					numberDown++;
					input += 'd';
				}
				else{
					tempVal--;
						if (tempVal == 0){
							calculate = true;
					}
				}
				break;
			case 'h':
				if (calculate){
					quantity += (numberDown - numberUps) * 1000;
					input += 'h';
				}
				else{
					//nothing
				}
				break;
			case 'u':
				if (calculate){
					input += 'u';
					numberUps++;
					quantity += 500;
					quantity += (numberDown - numberUps) * 1000;
				}
				else{
					tempVal++;
				}
				break;
			case '*':
				activeProgram = false;
				break;
			default:
				std::cout << "Please, enter valid symbol..!" << std::endl;
				std::cin >> lake;
				break;
			}
		}
	std::cout << input << std::endl;
	std::cout << quantity << std::endl;
	system("pause");
	return 0;
}