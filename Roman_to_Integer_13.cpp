#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution {
private:
        int ret = 0, cur = 0, flag = 0;
        string S1[9] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
        string S2[9] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string S3[9] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string S4[9] = {"M","MM","MMM","SS","S","SS","SSS","SSSS","SS"};
        char map[9] = {7,2,6,1,3,5,8,0,4};
        void cal(string *StrArr, string str, int scale){
           
            for(int i=0;i<9;i++){
                flag = 0;
                for(int j=0;j<StrArr[map[i]].size();j++){ 
                    
                    if(str[j+cur]!=StrArr[map[i]][j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    
                    ret = ret + scale * (map[i]+1);
                    cur = cur + StrArr[map[i]].size();
                    break;
                }
            }
        } 
public:
    int romanToInt(string s) {
        cal(S4, s, 1000);
        cal(S3, s, 100);
        cal(S2, s, 10);
        cal(S1, s, 1);
        return ret;
    }
};

int main(){

    Solution S1;
    cout << S1.romanToInt("MMCCCXCIX");
    return 0;
}