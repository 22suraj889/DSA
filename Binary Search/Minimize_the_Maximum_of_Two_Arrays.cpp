// leetcode 2513 Minimize the Maximum of Two Arrays

/*
Here x represents the count of numbers that are divisible by d1 from 1 to mid. Ex- let say mid is 50 and d1 is 7 now 50/7 is 7 it means we have 7 multiples of 7 till 50. And now as per question for array1 those numbers are not part of array1 so they got subtracted from mid. So as per above ex we have 50-7=43 numbers can be possible members of array1.
Same for y, it represents the count of numbers which are part of array2 i.e. count of numbers that are not divided by d2 till mid.
Now we need to find the numbers which are divisible by both d1 and d2 and they cannot be part of any array. So for that we need to find lcm (lowest common multiple) because those numbers are multiple of lcm.
*/

class Solution
{
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2)
    {
        long long low = 1, high = INT_MAX;
        long long lcm = (((long long)d1 * d2) / __gcd(d1, d2));
        long long ans = INT_MAX;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long x = mid - (mid / d1);
            long long y = mid - (mid / d2);
            long long z = mid - (mid / lcm);
            if (x >= uc1 && y >= uc2 && z >= uc1 + uc2)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
