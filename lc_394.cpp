class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<char>s1;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='[' || (s[i]>='a' && s[i]<='z')){
                s1.push(s[i]);
            }else if(isdigit(s[i])){
                string num="";
                while(isdigit(s[i])){
                     num+=s[i];
                     i++;
                }
                nums.push(stoi(num));
                i--;
            }else{
                string a="";
                while(!s1.empty() && s1.top()!='['){
                    a+=s1.top();
                    s1.pop();
                }
                if(!s1.empty() && s1.top()=='[')s1.pop();
                reverse(a.begin(),a.end());
                int k=nums.top();
                nums.pop();
                string final="";
                for(int i=0;i<k;i++){
                    final+=a;
                }
                for(int i=0;i<final.length();i++){
                    s1.push(final[i]);
                }
            }
        }
        while (!s1.empty()) {
            ans = s1.top() + ans; 
            s1.pop();
        }
        return ans;
    }
};