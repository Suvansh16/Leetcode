class Solution {
public:
int n;
int t[101][101][101];
int solve(vector<int>&nums,int start,int op1,int op2,int k)
{
    if(start>=nums.size())
    {
        return 0;
    }
    if(t[start][op1][op2]!=-1)
    return t[start][op1][op2];
    int result=INT_MAX;
    //apply case 1 
    if(op1>0)
    {
        int apply_op1=ceil(nums[start]/2.0)+solve(nums,start+1,op1-1,op2,k);
        result=min(result,apply_op1);
    }
    //apply case 2
    if(op2>0)
    {
        if(nums[start]>=k)
        {
            int apply_op2=(nums[start]-k)+solve(nums,start+1,op1,op2-1,k);
            result=min(result,apply_op2);
        }
    }
    //apply case 3
    if(op1>0 && op2>0)
    {
        //apply op1 first
        int new_val=ceil(nums[start]/2.0);
        if(new_val>=k)
        {
            new_val-=k;
             int apply_op1_first=new_val+solve(nums,start+1,op1-1,op2-1,k);
             result=min(result,apply_op1_first);
        }
        //apply op2 first
        if(nums[start]>=k){
        new_val=nums[start]-k;
        new_val=ceil(new_val/2.0);
        int apply_op2_first=new_val+solve(nums,start+1,op1-1,op2-1,k);
        result=min(result,apply_op2_first);
        }
    }
    //apply skip operation
    int skipopr=nums[start]+solve(nums,start+1,op1,op2,k);
    result=min(result,skipopr);
    return t[start][op1][op2]=result;
}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
      n=nums.size();
      memset(t,-1,sizeof(t));
      return solve(nums,0,op1,op2,k);  
    }
};