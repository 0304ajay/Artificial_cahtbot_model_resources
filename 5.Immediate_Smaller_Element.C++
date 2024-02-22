//link -https://www.codingninjas.com/studio/problems/immediate-smaller-element-_1062597
#include<stack>
void immediateSmaller(vector<int>& a)
{
	//Declaration
	stack<int> stk;

	for(int itr=a.size()-1;itr>0;itr--)
	{
		stk.push(a[itr]);
	}

	for(int itr=0;itr<a.size()-1;itr++)
	{
		if(a[itr]>stk.top())
		{
			a[itr]=stk.top();
		}
		else
		{
			a[itr]=-1;
		}
		stk.pop();
	}
	a[a.size()-1]=-1;
	
}

