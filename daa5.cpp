#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool placequeen(int r2, int c2, vector<int>& ptr)
{
    int r1, c1;
    for (r1 = 0; r1 < r2; r1++)
    {
        c1 = ptr[r1];
        if (c1 == c2 || abs(r1 - r2) == abs(c1 - c2)) // same column or diagonally adjacent
            return false; // queen cannot be placed
    }
    return true;
}

void print(int n, vector<int>& ptr)
{
    for (int i = 0; i <= 2 * n + 1; i++)
        cout << "-";
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "|";
            if (j == ptr[i])
                cout << "Q";
            else
                cout << " ";
        }
        cout << "|" << endl;
        for (int k = 0; k <= 2 * n + 1; k++)
            cout << "-";
        cout << endl;
    }
}

int iterative(int n, int sol)
{
    vector<int> ptr(n, -1);
    int r = 0, cnt = 0;

    while (r != -1)
    {
        ptr[r]++;
        if (ptr[r] < n)
        {
            if (placequeen(r, ptr[r], ptr))
            {
                if (r == n - 1)
                {
                    cout << "\nSolution number " << ++cnt << " for " << n << "-Queen Problem ->\n";
                    print(n, ptr);
                    if (sol == 1)
                        return 0;
                }
                else
                    r++;
            }
        }
        else
        {
            ptr[r] = -1;
            r--;
        }
    }
    return cnt;
}

void recursive(int n, int sol, vector<int>& ptr, int& pt, int r)
{
    static bool found = false;

    for (int c = 0; c < n; c++)
    {
        if (placequeen(r, c, ptr))
        {
            ptr[r] = c;
            if (r == n - 1)
            {
                pt++;
                cout << "\nSolution number " << pt << " for " << n << "-Queen Problem ->\n";
                print(n, ptr);
                if (sol == 1)
                {
                    found = true;
                    return;
                }
            }
            else
            {
                recursive(n, sol, ptr, pt, r + 1);
            }
        }
        if (found)
            return;
    }
}

int main()
{
    int choice1, choice2, n, count, p;
    vector<int> ptr;

    do
    {
        cout << "\nN-Queen Problem using Backtracking";
        cout << "\n1.Iterative Solution";
        cout << "\n2.Recursive Solution";
        cout << "\n3.Exit";
        cout << "\n\nEnter your choice::";
        cin >> choice1;

        switch (choice1)
        {
            case 1:
                do
                {
                    cout << "\nN-Queen Problem using Iterative Algorithm";
                    cout << "\n1.Print All Solutions";
                    cout << "\n2.Print Single Solution";
                    cout << "\n3.Return to main menu";
                    cout << "\n\nEnter your choice::";
                    cin >> choice2;

                    switch (choice2)
                    {
                        case 1:
                            cout << "\nEnter the number of queens::";
                            cin >> n;
                            if (n < 4)
                                cout << "\nSolution not possible!!!";
                            else
                            {
                                count = iterative(n, 0);
                                cout << "\nThe total number of solutions in " << n << "-Queen Problem is " << count << "\n";
                            }
                            break;

                        case 2:
                            cout << "\nEnter the number of queens::";
                            cin >> n;
                            if (n < 4)
                                cout << "\nSolution not possible!!!";
                            else
                                iterative(n, 1);
                            break;
                    }
                } while (choice2 != 3);
                break;

            case 2:
                do
                {
                    cout << "\nN-Queen Problem using Recursive Algorithm";
                    cout << "\n1.Print All Solutions";
                    cout << "\n2.Print Single Solution";
                    cout << "\n3.Return to main menu";
                    cout << "\n\nEnter your choice::";
                    cin >> choice2;

                    switch (choice2)
                    {
                        case 1:
                            cout << "\nEnter the number of queens::";
                            cin >> n;
                            if (n < 4)
                                cout << "\nSolution not possible!!!";
                            else
                            {
                                p = 0;
                                ptr.assign(n, -1);
                                recursive(n, 0, ptr, p, 0);
                                cout << "\nThe total number of solutions in " << n << "-Queen Problem is " << p << "\n";
                            }
                            break;

                        case 2:
                            cout << "\nEnter the number of queens::";
                            cin >> n;
                            if (n < 4)
                                cout << "\nSolution not possible!!!";
                            else
                            {
                                p = 0;
                                ptr.assign(n, -1);
                                recursive(n, 1, ptr, p, 0);
                            }
                            break;
                    }
                } while (choice2 != 3);
                break;

            case 3:
                break;
        }
    } while (choice1 != 3);

    return 0;
}
