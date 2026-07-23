class Solution {
public:

    void insertAtBottom(stack<int> &st, int x) {

        // Base case
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    void reverseStack(stack<int> &st) {

        // Base case
        if (st.empty())
            return;

        int temp = st.top();
        st.pop();

        // Reverse remaining stack
        reverseStack(st);

        // Insert current element at bottom
        insertAtBottom(st, temp);
    }
};