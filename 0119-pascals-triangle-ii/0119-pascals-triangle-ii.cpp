class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr(rowIndex+1, 1);
        int next = 1;
        int prev = next;
        for(int j=1; j<rowIndex; j++){
            for(int i=1; i<=j; i++){
                next = arr[i];
                arr[i] = arr[i] + prev;
                prev = next; 
            }
        }
        return(arr);
    }
};