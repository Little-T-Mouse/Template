for(int i=1; i<=N+1; i++) {
    while(!st.empty() && h[st.top()] > h[i]) {
        ll l = h[st.top()]; st.pop();
        ll w = (st.empty() ? 1LL * i - 1 : 1LL * i - st.top() - 1);
    }
    st.push(i);
 }
