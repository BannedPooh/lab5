#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap_std_str(string& target, int index1, int index2);
void sort_string(string& str, int size);
void clean_std_string(string& target);
void print_freq(string& str, int size);

int main()
{
    string sentence;
    cout<<"Enter sentence :";
    getline(cin, sentence);

    
    // sentence = clean_std_string(sentence);

    sort_string(sentence, sentence.size());
    print_freq(sentence, sentence.size());

	return 0;
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
    clean_std_string(str);
}

void print_freq(string& str, int size)
{
    cout<<"Sorted and cleaned-up sentence :"<<str<<endl;
    string checked;
    for (int i = 0; i != size; ++i)
    {
        if (checked.find(str[i]) != string::npos)
        {
            continue;
        }

        int count = 0;
        int found = i;

        while (found!=string::npos)
        {
            ++count;
            found = str.find(str[i], found+1);   
        }
        cout<<str[i]<<": "<<count<<endl;
        checked+=str[i];
    }
}

void clean_std_string(string& target)
{
    string modified;
    for (int i = 0; i!=target.size(); ++i)
    {
        if (isalpha(target[i]))
        {
            modified+=target[i];
        }
    }
    target = modified;
}