/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 
MinWeightTriangulation
*/
#include <iostream>
using namespace std;

template<class Type>
void MinWeightTriangulation(int n, Type** t, int** s)
{ //Time O(n3) Space O(n2)
	for (int i = 1; i <= n; i++)
		t[i][i] = 0;
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			t[i][j] = t[i + 1][j] + w(i - 1, i, j);
			s[i][j] = i;
			for (int k = i + 1; k < i + r - 1; k++)
			{
				int u = t[i][k] + t[k + 1][j] + w(i - 1, k, j);
				if (u < t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
}
int main(int argc, char* argv[])
{

}