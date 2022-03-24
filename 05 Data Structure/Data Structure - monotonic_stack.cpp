for(int i=1; i<=N+1; i++){
    while(!st.empty() && arr[st.top()] <= arr[i]){ ritm[st.top()] = i; st.pop(); }
    st.push(i);
}
for(int i=N; i>=0; i--){
    while(!st.empty() && arr[st.top()] < arr[i]){ lftm[st.top()] = i; st.pop(); }
    st.push(i);
}
