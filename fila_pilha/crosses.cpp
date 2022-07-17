#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    char alpha = 64; // letra antecessora do A na tabela ASCII
    queue<char> teams;
    char winner;
    do
        teams.push(++alpha);
    while(alpha != 80);

    pair<int, int> scores { 0, 0 };

    while (teams.size() != 1)
    {
        cin >> scores.first;
        cin >> scores.second;

        pair<char, char> game { teams.front(), teams.front() };
        teams.pop();
        teams.pop();

        scores.first > scores.second ? 
            teams.push(game.first) : 
            teams.push(game.second);
    }

    winner = teams.front();
    cout << winner;

    return 0;
}