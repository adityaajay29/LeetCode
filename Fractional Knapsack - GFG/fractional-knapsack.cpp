// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

static bool myComp(Item x, Item y)
{
    double wt1 = (double)x.weight;
    double val1 = (double)x.value;
    double wt2 = (double)y.weight;
    double val2 = (double)y.value;
    
    return (val1/wt1 > val2/wt2);
}


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, myComp);
        
        double maxProfit = 0;
        double wt = W;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight <= wt)
            {
                maxProfit += arr[i].value;
                wt -= arr[i].weight;
            }
            else 
            {
                double part = ((double)arr[i].value/(double)arr[i].weight )* wt;
                maxProfit += part;
                wt -= wt;
            }
        }
        return maxProfit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends