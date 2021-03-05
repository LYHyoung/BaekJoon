#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M, r, c, d;


int map[50][50];
bool map2[50][50];

int dx[] = { -1, 0, 1, 0 };     // 위(0), 오른쪽(1), 아래(2), 왼쪽(3)
int dy[] = { 0, 1, 0, -1 };

int stack;
int result = 0;


void bfs(int x, int y, int c)
{
    while (1)
    {
        if (map[x][y] == 0)
        {
            map[x][y] = 2;
            result = result + 1;
        }

        stack = 0;
        for (int i = 0; i < 4; i++)
        {
            c = (3 + c) % 4;
            int newX = x + dx[c];
            int newY = y + dy[c];

            if (map[newX][newY] == 0)
            {
                x = newX;
                y = newY;
                stack = 1;
                break;
            }
        }
        if (stack == 1)
        {
            continue;
        }

        x = x - dx[c];
        y = y - dy[c];

        if (map[x][y] == 1)
        {
            break;
        }
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs(r, c, d);

    cout << result << endl;                        // 결과 출력

    return 0;
}