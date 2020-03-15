#include<bits/stdc++.h>
using namespace std ;

int find_minimum_distant_vertex(int dist[], bool visited[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<dist[i]<<" " ;
	}
	cout<<endl ;
	
	int min = INT_MAX ;
	int vertex ;
	
	for(int i=0; i<n; i++)
	{
		if(dist[i]<min and visited[i]==false)
		{
			min = dist[i] ;
			vertex = i ;
		}
	}
	return vertex ;
}


int main()
{
	int n ;
	cout<<"enter the number of vertices : " ;
	cin>>n ;
	
	int mat[n][n] ;
	
	cout<<"Enter the weight matrix : " ;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cin>>mat[i][j] ;
	}
	
	bool visited[n] ;
	memset(visited, false, sizeof(visited)) ;
	
	int distance[n] ;
	
	for(int i=0; i<n; i++)
	{
		distance[i] = INT_MAX ;
	} 
	
	int source_vertex ;
	cout<<"Enter the source vertex : " ;
	cin>>source_vertex ;
	
	distance[source_vertex] = 0 ;
	
	for(int i=0; i<n-1; i++)
	{
		cout<<"the source is : "<<source_vertex<<endl ;
		for(int j=0; j<n; j++)
		{
			if(visited[j]==false and mat[source_vertex][j] and distance[source_vertex]!=INT_MAX)             // Means that vertex should not be visited and there should be a dircet edge from "U" to the vertex "V" ...
			{
				int temp = distance[source_vertex] + mat[source_vertex][j] ;
				if(temp < distance[j])
				{
					distance[j] = temp ;
				} 
			}
		}
		
		visited[source_vertex] = true ;
		source_vertex  = find_minimum_distant_vertex(distance, visited, n) ;
		
	}
	
	cout<<"vertex "<<"            "<<"distance"<<endl ;
	for(int i=0; i<n; i++)
	{
		cout<<i<<"                   "<<distance[i]<<endl ;
	}
	
	
	
}
