'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
def dfs(graph, visited, i,j):
    visited[i][j]=True
    count_=1
    lx=[0,-1,0,1]
    ly=[-1,0,1,0]
    for k in range(4):
        x_=i+lx[k]
        y_=j+ly[k]
        
        if(x_>0 and x_<len(graph) and y_>0 and y_<len(graph)):
            if(visited[x_][y_]==False and graph[x_][y_]==graph[i][j]):
                count_+=dfs(graph,visited, x_,y_)
                #print count_,x_, y_, i
    return count_
def main():
    while True:
        n=int(input())
        if(n==0):
            return
        graph=[]
        visited=[]
        b=False
        for i in range(n+1):
            ll=[n]*(n+1)
            graph.append(ll)
            ll1=[False]*(n+1)
            visited.append(ll1)
        for i in range(1,n):
            ll=list(map(int, input().split()));
            for j in range(0,len(ll),2):
                graph[ll[j]][ll[j+1]]=i
        for i in range(1,n+1):
            for j in range(1,n+1):
                if(visited[i][j]==False):
                    m=dfs(graph, visited,i, j)
                    #print m
                    if(m!=n):
                        b=True
                        break;
            if(b):
                break
        if(b):
            print("wrong")
        else:
            print("good")
if __name__=="__main__":
    main()
    
