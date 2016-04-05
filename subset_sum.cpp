#include <iostream>
/*   problem: Given a set of non-negative  integers ai.......an , and a sum
*   find whether a subset of the given set exists having the required sum
*/


/* This problem can be solved using recursion and dynamic programming
*   (refer to the link for an intuition-http://www.geeksforgeeks.org/dynamic-*  programming-subset-sum-problem/)
*   Here we will use a space-optimized version of the solution of the problem
*/

using namespace std;
bool subsetSum(const int& n , const int& sum , const int a[])
{
    int total_sum = 0;
    for ( int i = 0; i < n ; i ++ )
    {
        total_sum += a[i];
    }
    bool subset[total_sum + 10];
    subset[0] = true;
    for(int i = 1;i < total_sum + 10 ; i++)
    {
        subset[i] = false;
    }
    for( int i=0 ;i < n;i ++)
    {
        for( int j = total_sum;j>=a[i];j--)
        {
            subset[j] |=subset[j-a[i]];
        }
    }
    return subset[sum];
}

int main(void)
{
  int set[] = { 1,2,3 4,5,6,7};
  int sum = 8;
  int n = sizeof(set)/sizeof(set[0]);
  if (subsetSum(n, sum, set))
     cout<<"Found subset with given sum\n";
  else
     cout<<"No such subset exits\n";

}
