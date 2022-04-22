class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> x;
        sort(deck.begin(),deck.end());
        x.insert(x.begin(),deck[deck.size()-1]);
        for(int i=deck.size()-2; i>=0; i--){
            int tmp=x[x.size()-1];
            x.erase(x.end()-1);
            x.insert(x.begin(),tmp);
            x.insert(x.begin(),deck[i]);
        }
        return x;
    }
};