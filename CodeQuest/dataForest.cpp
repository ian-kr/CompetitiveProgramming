#include <bits/stdc++.h>

using namespace std; 

int main(void){


    int tt;
    cin >> tt;

    while(tt--){

        // consume \n character
        cin.ignore();

        string s;
        getline(cin,s);

        string temp = "";
        vector<int> nums;
        vector<vector<int>> tree;

        // Tolkenize data
        for(auto c : s){
            if(c==' '){
                nums.push_back(stoi(temp));
                temp= "";
                break;
            }
            temp+=c;
        }
        nums.push_back(stoi(temp));

        // Main logic
        sort(nums.begin(),nums.end());
        

    }


    return 0;
}