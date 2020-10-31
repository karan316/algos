#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> min_vals;

public:
    void push(int x)
    {
        // keep the old minimum right below the new minimum
        if (st.empty() || x <= min_vals.top())
        {
            min_vals.push(x);
        }
        st.push(x);
    }

    void pop()
    {
        if (st.top() == min_vals.top())
        {
            min_vals.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_vals.top();
    }
};