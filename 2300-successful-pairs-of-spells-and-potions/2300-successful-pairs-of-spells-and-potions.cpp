class Solution {
public:
    int findSuccessPairs(vector<int>& potions, int val, long long success){

        int lo = 0;
        int hi = potions.size()-1;
        int pairCount=0;

        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if((long long)val*potions[mid] >= success){
                pairCount += (hi-mid)+1 ;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return pairCount;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        vector<int> ans;

        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++){
            int pairs = findSuccessPairs(potions,spells[i],success);
            ans.push_back(pairs);
        }

        return ans;
    }
};