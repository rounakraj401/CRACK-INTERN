class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>m;
        for(auto &it:wordList)m.insert(it);        
        if(!m.count(endWord))return 0;
        queue<string>q;
        q.push(beginWord);
        int ans=0;
        q.push(beginWord);
        while(!q.empty()){
            int n=q.size();
            ans++;
            for(int p=0;p<n;p++){
                string word=q.front();
                q.pop();                
                for(int i=0;i<word.size();i++){
                    char c=word[i];
                    for(int j=0;j<26;j++){
                        word[i]='a'+j;
                        if(m.count(word)){
                            if(word==endWord)return ans+1;
                            m.erase(word);
                            q.push(word);
                        }
                    }
                    word[i]=c;
                }
            }
        }
        return 0;        
    }
};