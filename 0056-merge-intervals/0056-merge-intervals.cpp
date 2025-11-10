class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        /*
            Intution:- Just checking whether the next starting time is less than the current end time then overlapping exits , then merge the array 
        */
        vector<vector<int>> merged;


        sort(intervals.begin(),intervals.end());

        merged.push_back(intervals[0]);

        for(const auto& val:intervals){
  
            // there is overlap , then merge it
            if( merged.back()[1] >= val[0] ){
                merged.back()[1] = max(merged.back()[1],val[1]);  // ya jo pichle submission me max() wala likha hai vahi sahi (val[i] galat hai kuch testcase k liye)
            }else{ // there is no overlap
                merged.push_back(val);
            }
        }

        return merged;
    }
};