#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void clean_std_string(string& target);
bool are_anagrams(string &str1, string &str2);
void swap_std_str(string& target, int index1, int index2);
void sort_string(string& str, int size);

int main()
{
	string str1, str2;

	// Get strings from user
	std::cout<<"Enter first string:"<<endl;
	getline(cin, str1);
	std::cout<<"Enter second string:"<<endl;
	getline(cin, str2);

	// Clean strings
	clean_std_string(str1);
	clean_std_string(str2);
	
	// Check to see if they are anagrams
	// Report if they are or not anagrams
	if (are_anagrams(str1, str2))
	{
		cout<<"The strings are anagrams."<<endl;
	}
	else
	{
		cout<<"The strings are not anagrams."<<endl;
	}


    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
void clean_std_string(string& target)
{
    string modified;
    for (int i = 0; i!=target.size(); ++i)
    {
        if (isalpha(target[i]))
        {
            modified+=tolower(target[i]);
        }
    }
    target = modified;
}

bool are_anagrams(string &str1, string &str2)
{
	bool result = true;
	if (str1.size() != str2.size())
	{
		result = false;
		return result;
	}

	sort_string(str1, str1.size());
	sort_string(str2, str2.size());
	for (int i = 0; i != str1.size(); ++i)
	{
		if (str1[i] != str2[i])
		{
			result = false;
			break;
		}
	}
	return result;
}

void swap_std_str(string& target, int index1, int index2)
{
    char temp = target[index1];
    target[index1] = target[index2];
    target[index2] = temp;
}

void sort_string(string& str, int size){
    for (int i = size-1; i>=0; --i){
        for (int j = 1; j<=i; j++)
        {
            if (str[j]<=str[j-1])
            {
                swap_std_str(str, j, j-1);
            }
        }
    }
}
