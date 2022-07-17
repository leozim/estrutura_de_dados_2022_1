#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
using matrix = vector<string>;

const char DOT = '.';

int limits(int limit)
{
    srand((unsigned int)time(0));
    return rand() % limit + 1;
}

void distance(string& line, int limit, int index, int size)
{
    if (index >= size)
        return;
    
    int random = limits(limit);
    if (line[index] == DOT)
        line[index] = random + '0';

    distance(line, limit, ++index, size);
}

int main(int argc, char* argv[])
{
    string line = { 0 };
    int limit = { 0 };
    stringstream(argv[1]) >> line;
    stringstream(argv[2]) >> limit;

    distance(line, limit, 0, line.size());
    cout << line;

    return 0;
}
