//pascal triangle

#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> generate(int numRows) {

    vector<vector<int>> returnVal(numRows);
    returnVal[0] = {1};
    returnVal[1] = {1, 1};

    for(int i = 2; i<numRows;i++) {
        returnVal[i].resize(i+1, 1);
        for(int j = 1; j<i; j++) {
            returnVal[i][j] = returnVal[i-1][j-1] + returnVal[i-1][j];
        }
    }

    return returnVal;
}
