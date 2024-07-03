#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseBall
{
public:
	string guess(string guessNumber)
	{
        if (guessNumber.size() != 3)
            throw length_error("Should guess 3 digits");
        if (!isNumbers(guessNumber))
            throw invalid_argument("Only numbers allowed");
        if (isDuplicatedNumber(guessNumber))
            throw invalid_argument("Must not have same number");

        vector<int> num;
        for (const char a : guessNumber)
            num.push_back(a - '0');
	}
private:
    bool isNumbers(string text)
    {
        for (const char c : text)
        {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
    bool isDuplicatedNumber(string text)
    {
        if (text[0] == text[1]
            || text[0] == text[2]
            || text[1] == text[2])
            return true;
        return false;
    }
};
