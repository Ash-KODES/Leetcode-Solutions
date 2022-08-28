class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //THIS APPROACH ONLY VALID IN CASE OF "The first integer of each row is greater than the last integer of the previous row."
        int m=matrix[0].size();
        int n=matrix.size();
        int low=0;
        int high=n-1;
        int mid;
        int row;
        while(high-low>1)
        {
            mid=(low+high)/2;
            if(matrix[mid][0]>target)
            {
                   high=mid-1;
            }
            else
            {
                low=mid;
            }
        }
        if(matrix[high][0]>target)
            row=low;
        else
            row=high;
        //cout<<row<<endl;
        high=m-1;
        low=0;
        while(high-low>1)
        {
            mid=(low+high)/2;
            if(matrix[row][mid]>target)
            {
                   high=mid-1;
            }
            else
            {
                low=mid;
            }
        }
        if(matrix[row][low]==target)
            return true;
        if(matrix[row][high]==target)
            return true;
        else
            return false;
        
    }
};