#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
int main(){
	char symbols[256];
	int temp;
	char replace[10];
	for (int i = 0; i < 256; i++){
		symbols[i] = char(i);
	}
	int frequency[256] = { 0 };
	int unsortedFreq[256] = { 0 };
	std::string input = "";
	getline(std::cin, input);
	for (int i = 0; i < 256; i++){
		for (int j = 0; j < strlen(input.c_str()); j++){
			if (symbols[i] == input[j]){
				frequency[i]++;
			}
		}
	}
	for (int i = 0; i < 256; i++){
		unsortedFreq[i] = frequency[i];
	}
	//sort the array
	for (int i = 0; i < 256; i++){
		for (int j = 0; j < 256; j++){
			if (frequency[i]>frequency[j]){
				temp = frequency[i];
				frequency[i] = frequency[j];
				frequency[j] = temp;
			}
		}
	}
	int index = 0;

	for (int j = 0; j <10; j++){
		for (int i = 0; i < 256; i++){
			if (unsortedFreq[i] == frequency[j]){
				replace[index] = symbols[i];
				index++;
			}
		}
	}
	char buff[1];
	for (int j = 9; j >=0;j--){
		for (int i = 0; i < strlen(input.c_str()); i++){
			if (input[i] == replace[j]){
				input[i] = char(48+9-j);
			}
		}
	}
	std::cout << input << std::endl;
	 unsigned long long sum = 0;
	std::string tempStr = "";
	for (char ch : input)
	{
		if (isdigit(ch))
			tempStr += ch;
		else
		{
			sum += atoi(tempStr.c_str());
			std::cout <<sum<<" "<<tempStr << std::endl;
			tempStr = "";
		}
	}
	
	std::cout << sum + atoi(tempStr.c_str()) << std::endl;
	system("pause");
	return 0;
}