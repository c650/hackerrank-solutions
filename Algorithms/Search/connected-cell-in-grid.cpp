#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    int n,m;
    std::cin >> n >> m;
    
    std::vector< std::vector<int> > grid(n, std::vector<int>(m));
    for (auto& row : grid)
        for (auto& elem : row)
            std::cin >> elem;
    
    int max = 0;
    for (int i = 0; i < n && i >= 0; i++) {
        for (int j = 0; j < m && j >= 0; j++) {
            if (grid[i][j]) {
                                
                int count = 1, right = j, left = j;
                
                /*
                    First: traverse left to right to find
                    initial inquiry range for subsequent rows
                */
                while(right < m - 1 && grid[i][++right])
                    count++;
                while(left > 0 && grid[i][--left])
                    count++;
                
                // original_right keeps track of offset
                int original_right = right;
               
                /*
                    Next: Starting from the row below row `i`,
                    scan from `left` to `right` to find connected
                    1's.
                */
                for (int k = i+1; k < n; k++) {
                    // to keep track of whether or not 1's were found
                    int right_most = -1, left_most = m;
                    
                    for (int l = left; l <= right; l++) {
                        // if we find a 1
                        if (grid[k][l]) {
                            
                            count++;
                            
                            // update ranges
                            if (left_most > l)
                                left_most = l;
                            if (right_most < l)
                                right_most = l;
                            
                            /*
                                Check for a connected right corner.
                                We do this because, if we are at
                                the end of a range, we need to see
                                if a top corner could connect to more
                                1's.
                            */
                            if (k > 0 && l == right && grid[k-1][l+1]) {
                                right = right+2 < m ? right+2 : m-1; // change by 2 becaues diagonal...
                                count++;
                            }
                            /*
                                Do the same, but for the left corner.
                            */
                            if (k > 0 && l == left && l > 0 && grid[k-1][l-1]) {
                                left = left-2 > 0 ? left-2 : 0; // change by 2 because diagonal
                                count++;
                                l = left - 1; // this way l++ --> l = left
                            }
                        }
                    }
                    /*
                        If right_most is still -1 or left_most is still m
                        then this will return 
                    */
                    if (right_most < left_most)
                        break;
                    
                    /*
                        See if the range for a certain row goes out more
                        (to either side) than anticipated from the last-traversed row.
                    */
                    while(right_most < m - 1 && grid[k][++right_most])
                        count++;
                    while(left_most > 0 && grid[k][--left_most])
                        count++;
    
                    /*
                        Update ranges for scanning the next row.
                    */
                    left = left_most;
                    right = right_most;
                }

                /*
                    We need only track the maximum connected area.
                */
                if (max < count)
                    max = count;

                /*
                    Offset to the right, so that we don't
                    repeat too much of what we have already
                    done.
                */
                j = original_right+1;
            }
        }
    }
    std::cout << max << std::endl;
    return 0;
}
