#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream file("test.txt");
	string str, str1;
	int max_long_word = 0;
	string max_word;
	int i;
	int count = 0;
	while (getline(file, str))
	{
		i = 0;
		count = 0;
		str1.clear();
		while (str[i] != '\0' && str[i] != '\n')
		{
			if (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?')
			{
				count++;
				str1 += str[i];
			}
			else
			{
				if (count > max_long_word)
				{
					max_long_word = count;
					max_word = str1;
				}
				count = 0;
				str1.clear();
			}
			i++;
		}
		if (count > max_long_word)
		{
			max_long_word = count;
			max_word = str1;
		}
	}

	cout << "Longest word: "<<max_word << endl;
	file.clear();
	file.seekg(0);
	count = 0;
	while (getline(file, str))
	{
		i = 0;
		str1.clear();
		while (str[i] != '\0' && str[i] != '\n')
		{
			if (str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?')
			{
				str1 += str[i];
			}
			else
			{
				if (str1 == max_word)
				{
					count++;
				}
				str1.clear();
			}
			i++;
		}
		if (str1 == max_word)
		{
			count++;
		}
	}
	cout <<"Number of occurrences: "<< count;
	return 0;
}
