class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int count = 0;

        // try to pair the heviest person with the lightest one.
        // If they both can take a boat, then ok
        // If not, then the heviest takes the boat
        int l = 0, r = people.size() - 1;
        while (l <= r) {
            int remain = limit - people[r];
            r--;  // the right pointer always progresses, sicne they heviest person will take the
                  // boat.
            count++;
            // now that the heviest person took the boat, see if the lightest can also take it,
            // if not, increment the left pointer
            if (l <= r && remain >= people[l]) {
                l++;
            }
        }

        return count;
    }
};