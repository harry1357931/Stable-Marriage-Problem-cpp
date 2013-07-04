/** StableMarriage -- Recursive Version
 *  StableMarriageRecursion.cpp
 *     
 *  Fall, 2011
 *
 *  Problem: Stable Marriage Problem-- Best Match Men & Women after listening to their preferences 
 *        
 *  For More Description & Example of Problem:
 *     Check File: 'stable marriage using backtrack assignment.pdf'
 *      
 *  Input Format: 
 *      You can't input straight away, however, you can edit 'mp' and 'wp' arrays to change the 
 *      input in different way
 *
 *  OutPut Format:
 *      This program will output the best possible men and women matches
 *
 * This program matches 3 men with 3 women in a best way possible acc. to men and women preferences
 *                                          
 * @param mp mp: stands for Men's Preferences, holds preferences of 3 mens's
 *               For eg. in 'int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}};'
 *               First men Preferences are: 0, 2, 1        (here each of 0, 2, 1 represents a women)
 *               Third men Preferences are: 1, 2, 0
 * @param wp wp stands for Women's Preferences
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013  
 * @author Gurpreet Singh
 */
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

bool ok(int* q, int col)
{
	int mp[3][3] = {{0,2,1},{0,2,1},{1,2,0}};
	int wp[3][3] = {{2,1,0},{0,1,2},{2,0,1}};

	for(int i=0; i<col; i++)
	{
		if(q[i] == q[col])
		{   
			return false;
		}
	}

	for(int i=0; i<col; i++)
	{
		if((mp[i][q[col]]<mp[i][q[i]])&&(wp[q[col]][i]<wp[q[col]][col]))
		{
			return false;
		}

		if((mp[col][q[i]]<mp[col][q[col]])&&(wp[q[i]][col]<wp[q[i]][i]))
		{
			return false;
		}
		/*if((mp[col][q[col]]<mp[i][q[i]])&&(wp[q[col]][col]<wp[q[i]][i]))
		{
		return false;
		}*/
	}

	return true;
}

void print(int* q)
{
	static int count = 0;
        count++;
        for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                        if(q[i] == j)
                        {
                                cout<<"Man "<<i<<" is matched with Women "<<j<<endl;
                        }
                }
                cout<<endl;
        }
        cout<<endl;

}

void move(int* q, int i)
{
	if(i == 3)
	{
		print(q);
		return;
	}

	for(int j=0; j<3; j++)
	{
		q[i] = j;
		if(ok(q,i))
		{
			move(q,i+1);
		}
	}
};

int main()
{
	int q[3];
	move(q,0);
	
	system("PAUSE");
	return 0;
}
