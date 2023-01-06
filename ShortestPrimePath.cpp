/*You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only one single digit at a time. Every number obtained after changing a digit should be a four digit prime number with no leading zeros.

Example 1:

Input:

Num1 = 1033 

Num2 = 8179

Output: 6

Explanation:

1033 -> 1733 -> 3733 -> 3739 -> 3779

                 -> 8779 -> 8179.

There are only 6 steps required to reach

Num2 from Num1, and all the intermediate

numbers are 4 digit prime numbers.

Example 2:

Input:

Num1 = 1033 

Num2 = 1033

Output:

0

Your Task:  

You don't need to read input or print anything. Your task is to

Complete the constructor of the class Solution to precompute a list of prime numbers.  

Complete function shortestPath() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

Expected Time Complexity: O(NlogN)

Expected Auxiliary Space: O(N)

Constraints:

1000 ≤ Num1,Num2 ≤ 9999

Num1 and Num2 are prime numbers.*/

class Solution{   

  public:

     is_prime(int n) {

    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0) return false;

    }

    return true;

}

 

// Function to find the distance of the shortest path from Num1 to Num2

int shortestPath(int Num1, int Num2) {

    // Initialize a queue and a set to store the numbers we have visited

    queue<int> q;

    unordered_set<int> visited;

 

    // Add Num1 to the queue and set the distance to 0

    q.push(Num1);

    visited.insert(Num1);

    int distance = 0;

 

    // Perform a breadth-first search to find the shortest path from Num1 to Num2

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            int num = q.front();

            q.pop();

 

            // Check if we have reached Num2

            if (num == Num2) {

                return distance;

            }

 

            // Convert the number to a string so we can alter individual digits

            string str_num = to_string(num);

 

            // Alter each digit and check if the resulting number is prime

            for (int j = 0; j < 4; j++) {

                for (char c = '0'; c <= '9'; c++) {

                    if (c == str_num[j]) continue;

                    str_num[j] = c;

                    int new_num = stoi(str_num);

                    if (new_num >= 1000 && new_num <= 9999 && is_prime(new_num) && visited.count(new_num) == 0) {

                        q.push(new_num);

                        visited.insert(new_num);

                    }

                }

                // Reset the altered digit back to its original value

                str_num[j] = to_string(num)[j];

            }

        }

        // Increase the distance by 1 after processing all numbers at the current distance

        distance++;

    }

 

    // If we reach this point, it means that we were unable to find a path from Num1 to Num2

    return -1;

}

};
