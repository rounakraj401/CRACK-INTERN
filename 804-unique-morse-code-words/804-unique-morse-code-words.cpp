class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morses = { 
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
            "..-", "...-", ".--", "-..-", "-.--", "--.." 
            };
        map<string, bool> m;
        for (int i = 0; i < words.size(); i++) {
            string morse = "";
            for (int j = 0; j < words[i].size(); j++) {
                morse += morses[words[i][j] - 'a'];
            }
            m[morse] = true;
        }
        return m.size();
    }
};