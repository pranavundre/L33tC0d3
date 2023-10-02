class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size(), cnt = 0, A = 0, B = 0;
        if(n < 3) return false;
        for(int i = 0; i < n; i++){
            if(colors[i] == 'A'){
                if(i != 0 && colors[i-1] == 'B'){
                    B += cnt > 1 ? (cnt - 2) : 0;
                    cnt = 0;
                }
                cnt++;
            }
            else{
                if(i != 0 && colors[i-1] == 'A'){
                    A += cnt > 1 ? (cnt - 2) : 0;
                    cnt = 0;
                }
                cnt++;
            }
        }
        if(colors[n-1] == 'A') A += cnt > 1 ? (cnt - 2) : 0;
        else B += cnt > 1 ? (cnt - 2) : 0;

        cout<<A<<" "<<B;

        return A > B;
    }
};
