/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flattenList;
    int cur_index = -1;
    void helper(NestedInteger& i, vector<int>& flattenList)
    {
        if(i.isInteger())
            flattenList.push_back(i.getInteger());
        else
            for(auto& c : i.getList())
                helper(c,flattenList);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
       for(NestedInteger& i : nestedList)
        helper(i, flattenList);
    }
    
    int next() {
        return flattenList[cur_index];
    }
    
    bool hasNext() {
        if(flattenList.size() == 0)
            return false;
        if(cur_index == -1)
        {
            cur_index = 0;
            return true;
        }
        cur_index++;
        if(cur_index == flattenList.size())
            return false;
        return true;

    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */