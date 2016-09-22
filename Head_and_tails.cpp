#include<iostream>
using namespace std;
int main(){
	int Hcounter = 0, Tcounter = 0; // Hcounter for H, Tcounter for T
	int maxH = 0, maxT = 0;

	char coin = ' ';
	bool activeGame = true;
	bool first = true;
	char streakLetter = ' ';
	std::cout << "Please enter * to stop the game..TAILS win by default..!" << std::endl;
	std::cout << "This is a coin flip game..!" << std::endl;
	do{
		std::cout << "Please enter H for HEADS and T for TAILS...!" << std::endl;
		std::cin >> coin;
		if (first){
			streakLetter = coin;
			first = false;
		}
		if (coin == 'H'){
			if (streakLetter = 'H'){
				Hcounter++;
			}
			else{
				if (Tcounter>maxT){
					maxT = Tcounter;
					Tcounter = 0;
					streakLetter = coin;
					Hcounter++;
				}
			}
		}
		else if (coin == 'T'){
			if (streakLetter == 'T'){
				Tcounter++;
			}
			else{
				if (Hcounter>maxH){
					maxH = Hcounter;
					Hcounter = 0;
					streakLetter = coin;
					Tcounter++;
				}
			}
		}
		else if(coin == '*'){
			activeGame = false;
		}
		else{
			std::cout << "Please enter valid coin side..!" << std::endl;
			std::cin >> coin;
		}
	} while (activeGame);
	std::cout << "The game has stopped..!" << std::endl;

	if (maxH > maxT){
		std::cout << "The winner is H" << std::endl;
	}
	else if (maxH == maxT){
		std::cout << "Its draw..!" << std::endl;
	}
	else{
		std::cout << "The winner is T"  << std::endl;
	}
	system("pause");
	return 0;
}