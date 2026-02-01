
/*
This was the first question that was asked, time given was around 7-8 minutes.

There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after drawing such a vertical line.


Example 1:

Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2

Example 2:

Input: wall = [[1],[1],[1]]
Output: 3

Constraints:

n == wall.length
1 <= n <= 104
1 <= wall[i].length <= 104
1 <= sum(wall[i].length) <= 2 * 104
sum(wall[i]) is the same for each row i.
1 <= wall[i][j] <= 231 - 1
*/

/*
Solution:
    - Keep prefix sum, except for last element of each row
    - Keep track of freq of sum
    - The sum with max freq is answer

    for example,
    1,2,2,1     prefix sum - 1,3,5
    3,1,2                    3,4
    1,3,2                    1,4
    2,4                      2
    3,1,2                    3,4
    1,3,1,1                  1,4,5

    sum -> freq
    1 -> 3
    3 -> 3
    4 -> 4 - max = answer
    5 -> 2

    Final answer = 6 - 4 = 2
*/



class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> freq;
        int maxSum = 0;
        for (auto& row : wall) {
            long long sum = 0;
            for(int i = 0; i < row.size()-1; i++) {
                sum += row[i];
                freq[sum]++;
                maxSum = max(maxSum, freq[sum]);
            }
        }
        return wall.size() - maxSum;
    }
};