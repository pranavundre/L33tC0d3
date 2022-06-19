class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ret;        
        sort(products.begin(), products.end());
        for(int i = 0; i < searchWord.length(); i++){
            vector<string> temp;
            for(int j = 0; j < products.size(); j++)
                if((products[j].compare(0, i+1, searchWord, 0, i+1))==0 && temp.size()!=3)
                    temp.push_back(products[j]);
            ret.push_back(temp);
        }
        return ret;
    }
};