https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
//this function normalises all the words and pattern into a similar format
//so that we can compare them and find the solution
    void createUpdateMapping(string& str) {
        //find mappping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        //update the string
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        //firstly normalise the pattern
        createUpdateMapping(pattern);
        
        //saare words k sath khelna h 
        for(string s: words) {
            string tempString = s;         
            //normalise tempString
            createUpdateMapping(tempString);
            if(tempString == pattern) {
                //it means, that "s" wali string was a valid answer
                ans.push_back(s);
            }
        }
    return ans;
        
    }
};

https://leetcode.com/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        //create mapping
        char start = 'a';
        char mapping[1000] = {0};

        for(auto ch: key) {
            if(ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }   
        //use mapping
        string ans;

        for(auto ch: message) {
            if(ch == ' ') {
                ans.push_back(' ');
            }
            else {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
    return ans;
    }
};


https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        int lastP = 0;
        int lastG = 0;
        int lastM = 0;

        //calculate pick time and travel time
        for(int i=0; i<garbage.size(); i++) {
            string curr = garbage[i];
            
            for(int j=0; j<curr.length(); j++) {
                char ch = curr[j];

                if(ch =='P') {
                    pickP++;
                    lastP = i;
                }
                else if(ch =='G') {
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M' ) {
                    pickM++;
                    lastM = i;
                }

            }
            
        }

        //calculate travel time
        for(int i=0; i<lastP; i++) {
            travelP += travel[i];
        }

        for(int i=0; i<lastG; i++) {
            travelG += travel[i];
        }

         for(int i=0; i<lastM; i++) {
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }
};

https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    //custom comparator
    static string str;
    static bool compare(char char1, char char2) {
        
        //this will return true, if position of character1 in str string is
        //less than the position of character2 in str string

        //when true is returned, then char1 will be placed before char2 in 
        //output string
        return (str.find(char1) < str.find(char2));

    }
    string customSortString(string order, string s) {
        
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
string Solution::str;