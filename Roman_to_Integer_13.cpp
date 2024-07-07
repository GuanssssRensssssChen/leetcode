#include <iostream>
#include <string>
#include <map>

using namespace std;

// Sol#1
class Solution1 {
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
// Sol#2 用map
class Solution2 {
public:
    int romanToInt(string s) {
        map<char, int> m;
        //unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
};

// Sol#3 最快
class Solution3 {
public:
    int romanToInt(string s) {
        int map[26]={0},ret=0;
        for(int i=0;i<s.size();i++){
            s[i]-='A';
        }
        map['M'-'A']=1000;
        map['D'-'A']=500;
        map['C'-'A']=100;
        map['L'-'A']=50;
        map['X'-'A']=10;
        map['V'-'A']=5;
        map['I'-'A']=1;
        
        
        for(int i=0;i<s.size();i++){
            if(map[s[i]]<map[s[i+1]]){
                ret-=map[s[i]];
            }
            else{
                ret+=map[s[i]];
            }
        }
        return ret; 
    }
};

int main(){

    Solution3 S1;
    cout << S1.romanToInt("MMCCCXCIX");
    return 0;
}