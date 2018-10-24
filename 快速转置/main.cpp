#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a, b, c;
}t[1010], T;

int main(void)
{
    int n, m, p;

    while(cin >> n >> m >> p)
    {
        for(int i = 0; i < p; i++)
        {
            cin >> t[i].a >> t[i].b >> t[i].c;
        }

        for(int i = 0; i < p - 1; i++)
        {
            for(int j = 0; j < p - i - 1; j++)
            {
                if(t[j].b > t[j + 1].b)
                {
                    T = t[j];
                    t[j] = t[j + 1];
                    t[j + 1] = T;
                }

                if(t[j].b == t[j + 1].b)
                {
                    if(t[j].a > t[j + 1].a)
                    {
                        T = t[j];
                        t[j] = t[j + 1];
                        t[j + 1] = T;
                    }
                }
            }
        }

        for(int i = 0; i < p; i++)
        {
            cout << t[i].b << " " << t[i].a << " " << t[i].c << endl;
        }
    }
}
