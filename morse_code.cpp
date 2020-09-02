#include<iostream>
#include <vector>
#include <cctype>
using std::string;

string encode(string);
string decode(string);
string encoder(char);
char decoder(string);

int main()
{
	while(true)
	{
	int choice;
	std::cout << " \'#\' means unconvertable character" << std::endl;
	std::cout << "1. Encode morse code."<<std::endl;
	std::cout << "2. Decode morse code."<<std::endl;
	std::cout << "3. Exit."	<<std::endl;
	std::cin >> choice;
	
	if (choice == 2)	
	{
		string input;
		std::cout << "Please enter the morse code:\n";
		std::cin.ignore(999999,'\n');
		getline(std::cin,input);
		std::cout << "Decoded as below: " <<std::endl;
		std::cout << decode(input) << std::endl;
		std::cout << std::endl;
	}
	else if (choice == 1)
	{
		string input;
		std::cout << "Please enter the word(s):\n";
		std::cin.ignore(999999,'\n');
		getline(std::cin,input);
		std::cout << "Encoded as below:" << std::endl;
		std::cout << encode(input) << std::endl;
		std::cout << std::endl;

	}
	else if (choice == 3)
		break;
	}
	std::cout << "exited successfully" << std::endl;
	return 0;
}

string encode(string input)
{
	string temp;
	string output;
	for(int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			output += "   ";
		else 
		{
			output += encoder(input[i]);
			output += ' ';
		}
	}
	return output;		
}

string decode(string input)
{
	string temp;
	string output;
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] != ' ')
			temp += input[i];
		
		else if(input[i] == ' ' && input[i+1] != ' ')
		{
			output += decoder(temp);
			temp.clear();
		}
		else if(input[i] == ' ' && input[i+1] == ' ' && input[i+2] == ' ')
		{
			output += decoder(temp);
			output += ' ';
			i+=3;
			temp.clear();
		}
		
		if(i == input.length() - 1)// convert the last one
			output += decoder(temp);
		
	}
	return output;		
}

//converts letter into morse code
string encoder(char morse_code)
{
	int index;
	
	//array for A to Z
	string letter_set[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
							"--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	//array for 0 to 9
	string digit_set[] = {"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
	if (isalpha(morse_code))
	{
		morse_code = toupper(morse_code);
		index = morse_code - 65;//refer ASCII table
		return letter_set[index];
	}
	else if(isdigit(morse_code))
	{
		index = morse_code - 48;//refer ASCII table
		return digit_set[index];
	}
	return "#";
}

// converts morse code into letter
char decoder(string morse_code)
{
	//letters
	if(morse_code == ".-")
		return 'A';
	else if(morse_code == "-...")
		return 'B';
	else if(morse_code == "-.-.")
		return 'C';
	else if(morse_code == "-..")
		return 'D';
	else if(morse_code == ".")
		return 'E';
	else if(morse_code == "..-.")
		return 'F';
	else if(morse_code == "--.")
		return 'G';
	else if(morse_code == "....")
		return 'H';
	else if(morse_code == "..")
		return 'I';
	else if(morse_code == ".---")
		return 'J';
	else if(morse_code == "-.-")
		return 'K';
	else if(morse_code == ".-..")
		return 'L';
	else if(morse_code == "--")
		return 'M';
	else if(morse_code == "-.")
		return 'N';
	else if(morse_code == "---")
		return 'O';
	else if(morse_code == ".--.")
		return 'P';
	else if(morse_code == "--.-")
		return 'Q';
	else if(morse_code == ".-.")
		return 'R';
	else if(morse_code == "...")
		return 'S';
	else if(morse_code == "-")
		return 'T';
	else if(morse_code == "..-")
		return 'U';
	else if(morse_code == "...-")
		return 'V';
	else if(morse_code == ".--")
		return 'W';
	else if(morse_code == "-..-")
		return 'X';
	else if(morse_code == "-.--")
		return 'Y';
	else if(morse_code == "--..")
		return 'Z';
	//numbers
	else if(morse_code == ".----")
		return '1';
	else if(morse_code == "..---")
		return '2';
	else if(morse_code == "...--")
		return '3';
	else if(morse_code == "....-")
		return '4';
	else if(morse_code == ".....")
		return '5';
	else if(morse_code == "-....")
		return '6';
	else if(morse_code == "--...")
		return '7';
	else if(morse_code == "---..")
		return '8';
	else if(morse_code == "----.")
		return '9';
	else if(morse_code == "-----")
		return '0';
	
	return '#';
}

























