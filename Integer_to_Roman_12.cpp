// my solution
class Solution {
public:
    
    string intToRoman(int num) {
        int remainder = 0, count = 0;
        string ret_s;
        vector<int> stack;
        
        while(num){
            stack.push_back(num%10);
            num=num/10;
            count++;
        }
        while(count){
            remainder = stack.back();
            stack.pop_back();
            switch(remainder){
                
                case 4:
                    if(count==3){
                        ret_s += "CD";
                    }
                    else if(count==2){
                        ret_s += "XL";
                    }
                    else{
                        ret_s += "IV";
                    }
                    break;
                case 9:
                    if(count==3){
                        ret_s += "CM";
                    }
                    else if(count==2){
                        ret_s += "XC";
                    }
                    else{
                        ret_s += "IX";
                    }
                    break;
                    
                default:
                    if(count==4){
                        while(remainder--){ret_s += "M";}
                    }
                    else if(count==3){
                        
                        if(remainder>4){
                            ret_s += "D";
                            remainder-=5;
                        }
                        while(remainder--){ret_s += "C";}
                    }
                    else if(count==2){
                        if(remainder>4){
                            ret_s += "L";
                            remainder-=5;
                        }
                        while(remainder--){ret_s += "X";}
                    }
                    else{
                        if(remainder>4){
                            ret_s += "V";
                            remainder-=5;
                        }
                        while(remainder--){ret_s += "I";}
                    }
                    break;    
            }
            count--;
        }
        return ret_s;       
    }
};


//other solution
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};