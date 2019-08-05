#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ifstream fin("report.txt");
	ofstream fout("report.txt");
	int n;
	int max = 0;
	int index = 0;

	fin >> n;
	if (n > 1)
	{
		int **mass = new int*[n + 1];
		for (int i = 0; i < 4; i++)
		{
			mass[i] = new int[n + 1];
		}
		for (int i = 1; i < n + 1; i++)
		{
			int a;

			fin >> a;

			mass[0][i] = a;
			//fout << mass[0][i] << " ";
			mass[1][i] = 1;
			mass[2][i] = 1;
		}
		//fout << endl;

		//if (n > 2)

		for (int i = 2; i < n + 1; i++)
		{

			for (int j = 1; j < i; j++)
			{
				//fout << "work" << endl;
				if (mass[0][j] < mass[0][i] && mass[1][j] >= mass[1][i])
				{
					mass[1][i] = mass[1][j] + 1;
					//fout << "work1" << endl;
				}


			}


		}

		for (int i = n - 1; i > 0; i--)
		{
			for (int j = n; j > i; j--)
			{
				//fout << "work2" << endl;
				if (mass[0][i] > mass[0][j] && mass[2][i] <= mass[2][j])
				{
					//fout << "work3" << endl;
					mass[2][i] = mass[2][j] + 1;
				}
			}
		}

		for (int i = 1; i < n + 1; i++)
		{
			//fout << "work4" << endl;
			mass[3][i] = min(mass[1][i], mass[2][i]);
			if (max < mass[3][i])
			{
				//fout << "work5" << endl;
				max = mass[3][i];
				index = i;
			}
		}

	
	

	
		//fout << "work7" << endl;
		int count = 0;
		int maxl = mass[0][index];
		vector<int> resh;
		int indexcount = 0;
		int maxcountl = max - 1;
		fout << max - 1 << endl;
		//fout << index  << " " << max << endl;
		//for (int j = 1; j <= indexcount; j++)
		
			for (int i = index - 1; i >= 1; i--)
			{
				if (count == (max - 1))
				{
					break;
				}
				else
				{
					if (maxl > mass[0][i] && mass[1][i] == maxcountl)
					{
						resh.push_back(i);
						count++;
						maxl = mass[0][i];
						indexcount = i;
						maxcountl--;
						//fout << i << " ";
					}

				}

			}
		
		//fout << resh.size();
		for (int i = resh.size() - 1; i >= 0; i--)
		{
			fout << resh[i] << " ";
		}
		fout << index;
		int maxr = mass[0][index];
		int maxcountr = max - 1;
		//fout << max << " " << indexcount1 << endl;
		int count1 = 0;
		//for (int j = indexcount1; j < n + 1; j++)
		
		for (int i = index + 1; i < n + 1; i++)
		{	
			if (count1 == (max - 1))
			{
					break;
			}
			else
			{
				if (maxr > mass[0][i] && mass[2][i] == maxcountr)
				{
					resh.push_back(i);
					count1++;
					maxr = mass[0][i];
					maxcountr--;
					fout << " " << i;
				}
			}
		}
		
	}
	else
	{
		fout << 0 << endl;
		fout << 1;
	}
		/*if (n > 2)
		{
			for (int i = (max - 2); i >= 0; i--)
			{
				fout << resh[i] << " ";
			}
			fout << index << " ";
			for (int i = (max - 1); i < resh.size() - 1; i++)
			{
				fout << resh[i] << " ";
			}

			fout << resh[resh.size() - 1];
		}
		else
		{
			fout << index;
		}*/

	//else
	/*{
		if (n == 1)
		{
			fout << 0 << endl;
			fout << 1;
		}
		if (n == 2)
		{
			fout << 0 << endl;
			fout << 1;
		}
	}*/
	//fout/* << "dcfvrfre" */<< endl;
	//for (int i = 1; i < n + 1; i++)
	//{
	//	fout << mass[1][i] << " ";
	//	
	//}
	//fout << endl;
	//for (int i = 1; i < n + 1; i++)
	//{
	//	fout << mass[2][i] << " ";

	//}
	//fout << endl;
	//for (int i = 1; i < n + 1; i++)
	//{
	//	fout << mass[3][i] << " ";

	//}
	//fout << endl;
	//fout << max << " " << index;
	return 0;



}