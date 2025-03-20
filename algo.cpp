#include <bits/stdc++.h>
#include <vector>
using namespace std;

int user_count=0;
int getMin(const vector<int> &v){
    int minInd = 0;
    for (int i = 1; i < user_count; i++){
        if (v[i] < v[minInd]){
            minInd = i;
        }
    }
    return minInd;
}

int getMax(const vector<int> &v){
    int maxInd = 0;
    for (int i = 1; i < user_count; i++){
        if (v[i] > v[maxInd]){
            maxInd = i;
        }
    }
    return maxInd;
}

void minCashFlowRec(vector<int> &amount)
{
    int maxLend = getMax(amount);
    int maxLoan = getMin(amount);

    if (amount[maxLend] == 0 && amount[maxLoan] == 0){
        return;
    }

    int min =(-amount[maxLoan] < amount[maxLend]) ? -amount[maxLoan] : amount[maxLend];
    amount[maxLend] -= min;
    amount[maxLoan] += min;

    cout << "Person " << maxLoan << " pays " << min<< " to "<< "Person " << maxLend << endl;
    minCashFlowRec(amount);
}


void minCashFlow(vector<vector<int>> &graph){
    vector<int> amount;
    for(int i=0;i<user_count;i++){
        amount.push_back(0);
    }
    for (int person = 0; person < user_count; person++){
        for (int i = 0; i < user_count; i++){
            amount[person] += (-graph[person][i] + graph[i][person]);
        }
    }
    minCashFlowRec(amount);
}


int main(){
    user_count=4;
    vector<vector<int>> graph={};
    for(int i=0;i<user_count;i++){
        vector<int> temp;
        for(int j=0;j<user_count;j++){
            temp.push_back(0);
        }
        graph.push_back(temp);
    }
    
    //hardcoding values
    graph[0][1] = 1000;
    graph[0][2] = 2000;
    graph[1][2] = 5000; 
    graph[0][3] = 4000;
    graph[2][3] = 1000;

    minCashFlow(graph);
    return 0;
}