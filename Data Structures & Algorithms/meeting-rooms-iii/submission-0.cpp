class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Meetings must be processed by start time
        sort(meetings.begin(), meetings.end());

        // Available rooms: smallest room number first
        priority_queue<
            int,
            vector<int>,
            greater<int>
        > available;

        for (int room = 0; room < n; room++) {
            available.push(room);
        }

        // Busy rooms:
        // {endTime, roomNumber}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        // store the freq meetings of each room
        vector<int> count(n, 0);

        for (auto& meeting : meetings) {

            long long start = meeting[0];
            long long end = meeting[1];

            long long duration = end - start;

            // Free all rooms whose meetings
            // have already ended
            while (!busy.empty() &&
                   busy.top().first <= start) {

                int room = busy.top().second;

                busy.pop();

                available.push(room);
            }

            // Case 1: A room is available
            if (!available.empty()) {

                int room = available.top();
                available.pop();

                busy.push({end, room});

                count[room]++;
            }

            // Case 2: No room is available
            else {

                // Room that becomes available earliest
                auto [freeTime, room] = busy.top();
                busy.pop();

                // Meeting waits until freeTime
                long long newEnd = freeTime + duration;

                busy.push({newEnd, room});

                count[room]++;
            }
        }

        // Find room with maximum meetings.
        // If tie, smaller room number wins.
        int answer = 0;

        for (int room = 1; room < n; room++) {

            if (count[room] > count[answer]) {
                answer = room;
            }
        }

        return answer;
    }
};