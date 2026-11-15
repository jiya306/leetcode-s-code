class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<int>st;

        for(int i = 0; i < num.length(); i++)
        {
            while(!st.empty() && st.top() > num[i] - '0' && k > 0)
            {
                st.pop();
                k--;
            }

            st.push(num[i] - '0');
        }

        while(k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;

        while(i < ans.length() && ans[i] == '0')
        {
            i++;
        }

        ans = ans.substr(i);

        if(ans == "")
        {
            return "0";
        }

        return ans;
    }
};
