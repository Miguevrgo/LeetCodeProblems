#include "includeDir.h"

class Master {
    string secret;
public:
    Master(string secretWord){
        secret = secretWord;
    }
    int guess(string word){
        int counter = 0;
        for (int i = 0;i < 6; ++i){
            if (word[i] == secret[i]){
                counter++;
            }
        }
        if (counter == 6){
            cout << "Exito";
        }
        return counter;
    }
};

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        while(true){
            const string correctWord = words[words.size()/2];

            int points = master.guess(correctWord);
            if (points == 6){return;}
            words.erase(remove(words.begin(), words.end(), correctWord), words.end());

            for (auto it = words.begin(); it != words.end();){
                int matchCount = 0;
                for (int i = 0; i < 6; ++i){
                    if (correctWord[i] == (*it)[i]){
                        ++matchCount;
                    }
                }
                if (matchCount != points){
                    it = words.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
};

int main (){
    string correctWord = "acckzz";
    Solution solution;
    vector<string> words = {"ccaaaa","acckzz","ccbazz","eiowzz","abcczz"};
    Master maestro(correctWord);
    solution.findSecretWord(words,maestro);
    return 0;
}
