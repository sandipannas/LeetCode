class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
    long maxi=0;
    sort(pizzas.begin(),pizzas.end());
    long n1=pizzas.size()/4;
    long n2=0;

    if(n1%2==0){n1=n1/2; n2=n1;}
    else{
        n1=(n1/2)+1; n2=n1-1;
    }

    for(int i=1;i<=n1;i++)
    {
            maxi+=pizzas.back();
            pizzas.pop_back();       
    }
    for(int i=1;i<=n2;i++)
    {
            pizzas.pop_back();
            maxi+=pizzas.back();
            pizzas.pop_back();
    }
    return maxi;
    }
};