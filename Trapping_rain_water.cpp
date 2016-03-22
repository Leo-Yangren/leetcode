class Solution {
public:
    int trap(vector<int>& height) {
    int len = height.size();
    if(len <=2) return 0;
    int max = 0;
    int count = 0;
    int total = 0;
    for(int i =0; i< len ; i++)
    {
        total = total - height[i];
        if(height[i] > max){
            max = height[i];
            count = i;
        }
    }
    int count1 = count;
    for(int i = count; i<len ; i++)
    {
        if(height[i] >= max){
            max = height[i];
            count1 = i;
        }
    }
    total += max * len;
    int current = height[0];
    for(int i = 1; i<=count;i++){
        total = total - (max-current);
        if(height[i] > current)
            current = height[i];
    }
    current = height[len-1];
    for(int i = len-1;i > count1;i--){
        if(height[i] > current)
            current = height[i];
        total = total - (max - current);
    }
    return total;
}
};