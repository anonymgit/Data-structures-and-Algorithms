#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue
{
	vector<int> pq;
	public:
	PriorityQueue()
	{

	}
	bool isEmpty()
	{
		return pq.size()==0;
	}
	int getSize()
	{
		return pq.size();
	}
	int getMin()
	{
		if(isEmpty())
		{
			return 0;
		}
		return pq[0];
	}
	void insert(int element)
	{
		pq.push_back(element);
		int childIndex=pq.size()-1;
		while(childIndex>0)
		{
			int parentIndex=(childIndex-1)/2;
			if(pq[childIndex]<pq[parentIndex])
			{
				int temp=pq[childIndex];
				pq[childIndex]=pq[parentIndex];
				pq[parentIndex]=temp;
			}
			else
			{
				break;
			}
			childIndex=parentIndex;
		}
	}
	int removeMin()
	{
	    if(isEmpty())
        {
            return 0;
        }
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq[pq.size()-1]=ans;
		pq.pop_back();    //here is removing part rest of the rearrangement part
		int parentIndex=0;
		int leftChildIndex=2*parentIndex+1;
		int rightChildIndex=2*parentIndex+2;
		while(leftChildIndex<pq.size())   //checking edge cases
		{
			int minIndex=parentIndex;
			if(pq[minIndex]>pq[leftChildIndex])
			{
				minIndex=leftChildIndex;
			}
			if(rightChildIndex<pq.size() && pq[rightChildIndex]<pq[minIndex])
			{
				minIndex=rightChildIndex;
			}
			if(minIndex==parentIndex)
			{
				break;
			}
			int temp=pq[minIndex];
			pq[minIndex]=pq[parentIndex];
			pq[parentIndex]=temp;

			parentIndex=minIndex;   //new parent after swapping

			leftChildIndex=2*parentIndex+1;   //calculating new parents children
			rightChildIndex=2*parentIndex+2;
		}
		return ans;

	}
	void print()
	{
		for(int i=0;i<pq.size();i++)
		{
			cout<<pq[i]<<",";
		}
		cout<<endl;
	}
};
int main()
{
	PriorityQueue p;
	p.insert(12);
	p.insert(6);
	p.insert(5);
	p.insert(100);
	p.insert(1);
	p.insert(9);
	p.insert(14);


	cout<<p.getSize()<<endl;
	cout<<p.getMin()<<endl;

    p.print();
	while(!p.isEmpty())
	{
		cout<<p.removeMin()<<" ";
	}
	cout<<endl;
}



