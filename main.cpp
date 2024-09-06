#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Rules: Visit every city only once, then return back to the city you started in.
//We are given the distances from each city to every other city
//Stored as vector<vector<int>> 
//Starting always from city A and ending at A
//For each city we need to go to one of the cities it has a path to until we reach A again 
//Then we go to a different city 
//n = # of cities connected to A
//T(n) = (n-1)!

//Algorithm:
//Start at A
//Loop over each city connected to A, call it B
//Loop over each city connected B that is not A, call it C
//Loop over each city connected to C that is not B or A, call it D
//Loop over each city connected to D this is not A,B,C, call it E
//Go back to A


void findRoute(vector<vector<int>> cities) {
    int distance = 0;
    int minDistance = 100000;
    string minPath;
    string actualMinPath;
    int distance_C = 0;
    int distance_D = 0;

    for (int i = 1; i < cities[0].size(); i++) {
        // Reset path for each iteration
        string currentPath = "0, ";  //4
        int distance_B = cities[0][i];
        currentPath += to_string(i) + ", ";

        for (int j = 1; j < cities[i].size(); j++) {
            if (j != i) {            //3
                distance_C = cities[i][j];
                currentPath += to_string(j) + ", ";
            } else {
                continue;
            }

            for (int k = 1; k < cities[j].size(); k++) {
                if (k != j && k != i) {   //2
                    distance_D = cities[j][k];
                    currentPath += to_string(k) + ", ";
                } else {
                    continue;
                }

                for (int r = 1; r < cities[j].size(); r++) {
                    if (r != k && r != j && r != i) {  //1
                        int distance_E = cities[k][r];
                        int distance_A = cities[r][0];
                        distance = distance_B + distance_C + distance_D + distance_E + distance_A;
                        currentPath += to_string(r) + ", 0"; // Complete the cycle back to city 0

                        if (distance < minDistance) {
                            actualMinPath = currentPath;                           
                            minDistance = distance; 
                        }
                    } else {
                        continue;
                    }
                }
                currentPath = "0, " + to_string(i) + ", " + to_string(j) + ", ";  
            }
        }
    }

    cout << "Minimum Distance: " << minDistance << endl;
    cout << "Path: " << actualMinPath << endl;
}

int main() {
    vector<vector<int>> distances = {
        {0, 2, 2, 5, 9}, // Distances from city 0
        {2, 0, 4, 6, 7}, // Distances from city 1
        {2, 4, 0, 8, 6}, // Distances from city 2
        {5, 6, 8, 0, 4}, // Distances from city 3
        {9, 7, 6, 4, 0}  // Distances from city 4
    };

    findRoute(distances);

    return 0;
}
