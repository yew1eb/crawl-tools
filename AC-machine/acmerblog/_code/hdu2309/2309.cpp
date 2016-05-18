/*Memory: 716K  Time: 0MS 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> scores;
    int score;
    double sumScore;
    int aveScore;
    int n;
    while(cin >> n, n !=0) {
        scores.clear();

        for(int i = 0; i < n; i++) {
            cin >> score;
            scores.push_back(score);
        }

        sort(scores.begin(), scores.end());

        scores.erase(scores.end() - 1, scores.end());
        scores.erase(scores.begin(), scores.begin() + 1);

        sumScore = 0.0;
        for(vector<int>::iterator iter = scores.begin();
            iter != scores.end(); iter++) {
            sumScore += *iter;
        }
        aveScore = (int)(sumScore / scores.size());

        cout << aveScore << endl;
    }

    return 0;
}