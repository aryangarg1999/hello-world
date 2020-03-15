#include<bits/stdc++.h>
using namespace std ;


bool is_safe(int r, int c, int i, int j)
{
	if(i>=0 and j>=0 and i<r and j<c)
	return true ;
	return false ;
}

int main() 
{
	int r,c ;
	cin>>r>>c ;
	
	int mat[r][c] ;
	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		cin>>mat[i][j] ;
	}
	
	bool visited[r][c] ;
	memset(visited, false, sizeof(visited)) ;
	
	queue<pair<int, int> >q ;
	
	int source_x, source_y, dest_x, dest_y ;
	
	cout<<"Enter source vertex : " ;
	cin>>source_x>>source_y ;
	pair<int, int>p = make_pair(source_x, source_y) ;
	q.push(p) ;
	visited[source_x][source_y] = true ;
	
	cout<<"Enter destination : " ;
	cin>>dest_x>>dest_y ;
	
	pair<int, int>dest = make_pair(dest_x, dest_y) ;
	
	int count =0 ;
	
	if(mat[source_x][source_y]==1 or mat[dest_x][dest_y]==1)
	cout<<0<<endl ;
	
	else
	{
		while(!q.empty())
		{
			pair<int, int>temp = q.front() ;
			int a = temp.first ;
			int b = temp.second ;
			q.pop() ;
			
			if(is_safe(r,c,a+1,b) and mat[a+1][b]==0 and visited[a+1][b]==false)
			{
				pair<int, int>test = make_pair(a+1,b) ;
				visited[a+1][b] = true ;
				if(test==dest)                                   // Means if the destination is reached but the surronded coordinates 	// are not supporting the ball to be get stopped at that point then also our answer is false... 
				{
					int count1 =0, count2=0, count3 =0 ;
					int x = test.first, y = test.second ; 
					if(is_safe(r,c,x,y-1))
					{
						if(mat[x][y-1]==0)                    // 0 means blank cell if neighbours of the destination are 0's then that can be problematic for us...
							break ;
						else
							count1++ ;
					}
					else
						count1++ ;
					if(is_safe(r,c,x,y+1))
					{
						if(mat[x][y+1]==0)
							break ;
						else
							count2++ ;
					}
					else                         // Means might be that coordinate does not lies in the grid ...
						count2++ ;
					
					if(is_safe(r,c,x+1,y))
					{
						if(mat[x+1][y]==0)
							break ;
						else
						count3++ ;
					}
					else
						count3++ ;
					
					if(count1 and count2 and count3)           // Means 
					{
						count++ ;
						break ;
					}
					else
					{
						break ;
					}
				}
				
				else
				{
					q.push(test) ;
				} 
			}
			
			if(is_safe(r,c,a-1,b) and mat[a-1][b]==0 and visited[a-1][b]==false)
			{
				pair<int, int>test = make_pair(a-1,b) ;
				visited[a-1][b] = true ;
				if(test==dest)                                   // Means if the destination is reached but the surronded coordinates 	// are not supporting the ball to be get stopped at that point then also our answer is false... 
				{
					int count1 =0, count2=0, count3 =0 ;
					int x = test.first, y = test.second ; 
					if(is_safe(r,c,x,y-1))
					{
						if(mat[x][y-1]==0)
							break ;
						else
							count1++ ;
					}
					else
					count1++ ;
					if(is_safe(r,c,x,y+1))
					{
						if(mat[x][y+1]==0)
							break ;
						else
							count2++ ;
					}
					else
					count2++ ;
					
					if(is_safe(r,c,x-1,y))
					{
						if(mat[x-1][y]==1)
							break ;
						else
						count3++ ;
					}
					else
					count3++ ;
					
					if(count1 and count2 and count3)
					{
						count++ ;
						break ;
					}
					else
						break ;
				}
				
				else
				{
					q.push(test) ;
				} 
			}
			
			if(is_safe(r,c,a,b+1) and mat[a][b+1]==0 and visited[a][b+1]==false)
			{
				pair<int, int>test = make_pair(a,b+1) ;
				visited[a][b+1] = true ;
				if(test==dest)                                   // Means if the destination is reached but the surronded coordinates 	// are not supporting the ball to be get stopped at that point then also our answer is false... 
				{
					int count1 =0, count2=0, count3 =0 ;
					int x = test.first, y = test.second ; 
					if(is_safe(r,c,x-1,y))
					{
						if(mat[x-1][y]==0)
							break ;
						else
							count1++ ;
					}
					else
					count1++ ;
					if(is_safe(r,c,x+1,y))
					{
						if(mat[x+1][y]==0)
							break ;
						else
							count2++ ;
					}
					else
					count2++ ;
					
					if(is_safe(r,c,x,y+1))
					{
						if(mat[x][y+1]==1)
							break ;
						else
						count3++ ;
					}
					else
					count3++ ;
					
					if(count1 and count2 and count3)
					{
						count++ ;
						break ;
					}
					else
						break ;
				}
				
				else
				{
					q.push(test) ;
				} 
			}
			
			if(is_safe(r,c,a,b-1) and mat[a][b-1]==0 and visited[a][b-1]==false)
			{
				pair<int, int>test = make_pair(a,b-1) ;
				visited[a][b-1] = true ;
				if(test==dest)                                   // Means if the destination is reached but the surronded coordinates 	// are not supporting the ball to be get stopped at that point then also our answer is false... 
				{
					int count1 =0, count2=0, count3 =0 ;
					int x = test.first, y = test.second ; 
					if(is_safe(r,c,x,y-1))
					{
						if(mat[x][y-1]==0)
							break ;
						else
							count1++ ;
					}
					else
					count1++ ;
					if(is_safe(r,c,x+1,y))
					{
						if(mat[x+1][y]==0)
							break ;
						else
							count2++ ;
					}
					else
					count2++ ;
					
					if(is_safe(r,c,x-1,y))
					{
						if(mat[x-1][y]==1)
							break ;
						else
						count3++ ;
					}
					else
					count3++ ;
					
					if(count1 and count2 and count3)
					{
						count++ ;
						break ;
					}
					else
						break ;
				}
				
				else
				{
					q.push(test) ;
				} 
			}
		
		}
		
		if(count)
		cout<<1<<endl ;
		else
		cout<<0<<endl ;
	}
	
	
	
	
	
	
}
