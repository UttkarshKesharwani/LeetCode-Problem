typedef long long ll;
class Solution {
public:

    // checking is it possible to make all cars within given time (which is mid here)
    bool possibleToMakeAllCarsWithinTime(vector<int>& ranks, int cars, ll mid) {

        ll count = 0; // total cars we can make within given time (mid in this case)

        for (auto rank : ranks) {

            // calculating how many cars a mechanic with given rank can make within 'mid' time
            // Formula: time = rank * (cars^2)  =>  cars = sqrt(time / rank)
            ll carCanMake = (ll)sqrt((long double)mid / rank);

            count += carCanMake;

            if (count >= cars) return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {

        // Intuition :- We are checking for all possible minute values in a range 
        // using Binary Search to find the minimum time required to repair all cars.

        ll lo = 1;
        ll hi = (ll)*max_element(ranks.begin(), ranks.end()) * cars * cars;
        ll result = 0;

        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;

            if (possibleToMakeAllCarsWithinTime(ranks, cars, mid)) {
                result = mid;   
                hi = mid - 1;   
            } else {
                lo = mid + 1;   
            }
        }

        return result;
    }
};
