
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BSTree.cpp"

using namespace std;

void print_result();
void checkWord(string &);
int getAvg(vector<int> vec);

BSTree<string> T1;
int TotalChar = 0;
int NumofWord = 0;
int NumofSentence = 0;
int temp = 0;
int UniqueWord;
int AvgSentenceLength;
vector<int> s_temp;


int main()
{
   
    string item;
    ifstream infile;
    infile.open("Numbers.txt");
    if(T1.isEmpty()){
        while(!infile.eof())
        {
            infile >> item;
            checkWord(item);
            T1.insertItem(item);
            NumofWord ++;
            temp ++;
        }
    }
    
    UniqueWord = T1.getUnique();
    AvgSentenceLength = getAvg(s_temp)/NumofSentence;
    print_result();

    return 0;
}

void checkWord(string &str)
{
    for (int i=0; i<str.length();i++)
    {
        TotalChar ++;
        if(str[i]==','||str[i]==';'||str[i]==':')
        {
            str.erase(i);
            i--;
            TotalChar --;
        }
        else if(str[i]=='!'||str[i]=='?'||str[i]=='.')
        {
            NumofSentence ++;
            str.erase(i);
            i--;
            TotalChar --;
            s_temp.push_back(temp);
            temp = 0;
        }
    }
}

int getAvg(vector<int> vec)
{
    int sum = 0;
    for(int i=0; i<vec.size();i++)
    {
        sum += vec[i];
    }
    return sum;
}


void print_result()
{
    cout << "\n------------------------------------------------------\n";
    cout << "\t\t STATISTICAL SUMMARY\n\n";
    cout << "TOTAL NUMBER OF WORDS: " << NumofWord << endl;
    cout << "TOTAL NUMBER OF UNIQUE WORDS:" << UniqueWord << endl;
    cout << "TOTAL NUMBER OF UNIQUE WORDS OF MORE THAN THREE LETTERS:" << T1.getRealWord() << endl;
    cout << "AVERAGE WORD LENGTH: " << TotalChar/NumofWord << endl;
    cout << "AVERAGE SENTENCE LENGTH: " << AvgSentenceLength << endl;
    
    cout << "\n\t\t STLE WARNINFS\n\n";
    T1.printRepeat();
    cout << "\n\t\t INDEX OF UNIQUE WORDS\n\n";
    for(char index='A';index <'Z'; index++)
    {
        cout << index << endl;
        T1.printInorder(index);
    }
    cout << endl;
}
