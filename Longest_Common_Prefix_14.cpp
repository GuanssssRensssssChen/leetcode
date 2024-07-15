class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int flag=0;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                ret+=strs[0][i];
            }
        }
        return ret;
    }
};