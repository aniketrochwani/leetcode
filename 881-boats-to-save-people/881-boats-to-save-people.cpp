class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count=0, left=0, right=people.size()-1;
        
        while(left <= right){
            int sum = people[left]+people[right];
            
            if(sum<=limit){
                count++;
                left++;
                right--;
            }
            
            if(sum>limit){
                count++;
                right--;
            }
        }
        
        return count;
    }
};