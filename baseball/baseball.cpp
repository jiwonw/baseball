#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct GameResult
{
    bool solved;
    int strikes;
    int balls;
};

class Baseball
{
public:
    Baseball(string numbers)
        : question {numbers}
    {
        for (const char ch : numbers)
            answerNumbers.push_back(ch - '0');
    }

    void checkInputCondition(const string & numbers)
    {
        if (numbers.size() != 3)
            throw length_error("Should guess 3 digits");
        if (!isNumbers(numbers))
            throw invalid_argument("Only numbers allowed");
        if (isDuplicatedNumber(numbers))
            throw invalid_argument("Must not have same number");
    }

    GameResult guess(string guessNumber)
	{
        GameResult ret = { false, 0, 0 };
        checkInputCondition(guessNumber);

        vector<int> nums;
        for (const char ch : guessNumber)
            nums.push_back(ch - '0');

        for (int num : nums)
        {
            for (int ans : answerNumbers)
                if (ans == num)
                    ret.balls++;
        }
        for (int i = 0; i < 3; i++)
        {
            if (answerNumbers[i] == nums[i])
                ret.strikes++;
        }
        ret.balls -= ret.strikes;
        if (ret.strikes == 3)
            ret.solved = true;
        return ret;
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
    vector<int> answerNumbers;
    string question;
};
