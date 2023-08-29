#include<iostream>
using namespace std;

class item{
    public:
    int weight;
    int profit;
    double ratio;
};

int main(){
    cout<<"Enter the number of items: ";
    int n;
    cin>>n;
    item arr[n];
    cout<<"Enter the weights and profits of the items: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].weight>>arr[i].profit;
        arr[i].ratio = (double)arr[i].profit/arr[i].weight;
    }
    cout<<"Enter the capacity of the knapsack: ";
    int capacity;
    cin>>capacity;
    int currentWeight = 0;
    double currentProfit = 0;
    for(int i=0;i<n;i++){
        if(currentWeight+arr[i].weight<=capacity){
            currentWeight+=arr[i].weight;
            currentProfit+=arr[i].profit;
        }
        else{
            int remainingWeight = capacity-currentWeight;
            currentProfit+=arr[i].ratio*remainingWeight;
            break;
        }
    }
    cout<<"The maximum profit is: "<<currentProfit<<endl;
    // sorting the array of objects
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].ratio<arr[j].ratio){
                item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"The items taken are: "<<endl;

    for(int i=0;i<n;i++){
        if(currentWeight+arr[i].weight<=capacity){
            currentWeight+=arr[i].weight;
            currentProfit+=arr[i].profit;
            cout<<"Item "<<i+1<<endl;
        }
        else{
            int remainingWeight = capacity-currentWeight;
            currentProfit+=arr[i].ratio*remainingWeight;
            cout<<"Item "<<i+1<<endl;
            break;
        }
    }
    return 0;
}
