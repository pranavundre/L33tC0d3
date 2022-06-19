class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n = searchWord.length();
        vector<vector<string>> ret;
        // ret.reserve(n);
        
        sort(products.begin(), products.end());
        
        for(int i = 0; i < n; i++){
            vector<string> temp;
            int c = 0;
            for(int j = 0; j < products.size(); j++){
                if((products[j].compare(0, i+1, searchWord, 0, i+1))==0 && c!=3){
                    temp.push_back(products[j]);
                    c++;
                }
            }
            ret.push_back(temp);
        }
        
        return ret;
    }
};