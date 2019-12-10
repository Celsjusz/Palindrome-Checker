#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cout << "No arguments supplied.";

		return 0;
	}

	if (argc > 2) {
		std::cout << "This program does not support multiple arguments. Be sure to cover your string in quotes ex. \"Was it a cat I saw?\"";

		return 0;
	}

	int stringLenght;
	char char1, char2;
	bool isPalindrome = true;
	std::string userInput = argv[1];

	userInput.erase( //erase special chars, spaces, dots etc.
		std::remove_if(
			userInput.begin(),
			userInput.end(),
			[](char c) {
				return !std::isalnum(c);
			}), 
		userInput.end()
	);

	stringLenght = userInput.length();

	for (int i = 0; i < stringLenght; i++)
	{
		if (i >= stringLenght - i) break;

		char1 = std::tolower(userInput.at(i));
		char2 = std::tolower(userInput.at(stringLenght - 1 - i));

		if (char1 == char2) continue; //you could also use built-in functions like std::reverse() to compare whole strings

		isPalindrome = false;
		break;
	}

	std::cout << "\"" << argv[1] << "\" is " << (isPalindrome ? "" : "not ") << "a palindrome.\n";
}
