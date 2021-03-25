#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2)
{
    const int ROWSIZE = s1.length()+1;
    const int COLSIZE = s2.length()+1;
    
    //int array2d[ROWSIZE][COLSIZE];
    
    int **array2d = new int*[ROWSIZE];
    for(int i = 0; i<ROWSIZE; i++)
    {
        array2d[i] = new int[COLSIZE];
    }
    
    for( int i = 0; i <ROWSIZE; i++)
    {
        for( int j = 0; j<COLSIZE; j++)
        {
            if(i == 0 || j == 0)
            {
                array2d[i][j] = 0;
            }else
            {
                //if(i<ROWSIZE-1 && j< COLSIZE-1)
                //{
                    if(s1[i-1] == s2[j-1])
                    {
                        array2d[i][j] = array2d[i-1][j-1] +1;
                    }else
                    {
                        array2d[i][j] = max(array2d[i-1][j], array2d[i][j-1]);
                    }
                //}

            }

        }
    }


    return array2d[ROWSIZE-1][COLSIZE-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
