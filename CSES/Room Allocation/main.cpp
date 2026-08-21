#include <bits/stdc++.h>
using namespace std;

void minimumRooms(vector<vector<int>> &timings)
{

    int n = timings.size();

    vector<vector<int>> vec(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        vec[i][0] = timings[i][0];
        vec[i][1] = timings[i][1];
        vec[i][2] = i;
    }

    sort(vec.begin(), vec.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedRooms;

    int roomCnt = 0;

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int arrivalTime = vec[i][0];
        int departureTime = vec[i][1];
        int idx = vec[i][2];

        if (occupiedRooms.empty() || occupiedRooms.top().first >= arrivalTime)
        {
            roomCnt += 1;
            occupiedRooms.push({departureTime, roomCnt});
            ans[idx] = roomCnt;
        }
        else
        {
            int vacantRoom = occupiedRooms.top().second;
            occupiedRooms.pop();
            occupiedRooms.push(
                {departureTime, vacantRoom});
            ans[idx] = vacantRoom;
        }
    }

    cout << roomCnt << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> timings(n,vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin>>timings[i][0]>>timings[i][1];
        timings[i][2]=i;
    }
    minimumRooms(timings);
    return 0;
}