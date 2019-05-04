#include<bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>

class city; //class for internal parts of a city
class country;  // class for connecting cities across country

class graph{
        int vertices;
        list<ipair> * adjlist;
        map<string,int> indexMap;
        map<int,string> nameMap;
        int mini;
        int *minipath;
        int **adjmatrix;
        int **dist;
        int **path;
        int lastvertex;
        int *finalpathforTSP;
        int final_res;
        int * visitedforTSP;
    public:
        friend class city;
        friend class country;
        graph(){}
        /*
			Check if all Must Visited nodes are traversed or not
				true -> All must visited are traversed
				false -> otherwise
        */
        bool isAllVisited(bool visit[],vector<int>mustvisit)
        {
                for(int i=0;i<mustvisit.size();i++)
                {
                    if(visit[mustvisit[i]] == false )
                        return false;
                }
                return true;
        }

        /*
			By Backtracking find all the path
			when all mustvisit nodes are visit compare it with all previous computed path if less then save
        */

        void startthegame(int parent,bool visit[],int path[],vector<int>mustvisit,int cost)
        {
        	visit[parent] = true;
        	if(isAllVisited(visit,mustvisit) == true)
        	{
        		if(dist[parent][0] + cost<mini)
        		{
        			mini = cost+dist[parent][0];

        			lastvertex = parent;
        			for(int i=0;i<vertices;i++)
        				minipath[i] = path[i];
        		}
        	}else{
        		for(auto it = adjlist[parent].begin();it!=adjlist[parent].end();it++)
        		{
        			if(visit[it->first] == false)
        			{
        				path[it->first] = parent;
        				startthegame(it->first,visit,path,mustvisit,cost+it->second);
        				path[it->first] = -1;
        			}
        		}
        	}
        	visit[parent] = false;
        	return;
        }
        /*
			following function helps in initiate the startthegamefunction
        */

        void pathfinder()
        {
        	FloydWarshell();
        	mini = INT_MAX;
        	vector<int>mustvisit;
        	mustvisit.push_back(2);mustvisit.push_back(6);mustvisit.push_back(7);mustvisit.push_back(1);
        	bool visit[vertices] = {false};
        	int path[vertices];
        	for(int i=0;i<vertices;i++)
        		path[i] = -1;
        	int startingNode = 0;
        	path[startingNode] = -2;
        	visit[startingNode] = true;
        	for(auto it = adjlist[startingNode].begin();it!=adjlist[startingNode].end();++it)
        	{
        		path[it->first] = startingNode;
        		startthegame(it->first,visit,path,mustvisit,it->second);
        		path[it->first] = -1;
        	}
        	cout<<endl<<endl;
        	//cout<<"minimum => "<<mini<<endl<<endl;
        	int temp = lastvertex;
        	stack<int>printingpath;
        	while(temp != -2)
        	{
        		printingpath.push(temp);
        		temp = minipath[temp];
        	}
        	while(!printingpath.empty())
        	{
        		cout<<nameMap[printingpath.top()]<<" >> ";
        		printingpath.pop();
        	}
        	cout<<endl<<"Delivery Done"<<endl<<"Return Back"<<endl;
        	cout<<nameMap[lastvertex]<<" >> ";
        	printPath(lastvertex,0);
        	cout<<nameMap[0]<<endl;
        }

        


        graph(int v){
            this->vertices = v;
            adjlist = new list < ipair >[v];
            mini = INT_MAX;
            minipath = new int [v];
            adjmatrix = new int * [v];
            dist = new int *[v];
            path = new int *[v];
            final_res = INT_MAX;
         	finalpathforTSP = new int [v+1];  
         	visitedforTSP = new int[v];
            for(int i=0;i<v;i++)
            {
            	adjmatrix[i] = new int[v];
            	dist[i] = new int [v];
            	path[i] = new int [v];
            }
         	for(int i=0;i<v;i++)
         	{
         		for(int j=0;j<v;j++)
         			adjmatrix[i][j] = INT_MAX;
         	}
        }
        void constructorhelper(int v)
        {
            this->vertices = v;
            adjlist = new list < ipair >[v];
            mini = INT_MAX;
            minipath = new int [v];
            adjmatrix = new int * [v];
            dist = new int *[v];
            path = new int *[v];
            final_res = INT_MAX;
            finalpathforTSP = new int [v+1];
            visitedforTSP = new int[v];
            for(int i=0;i<v;i++)
            {
            	adjmatrix[i] = new int[v];
            	dist[i] = new int [v];
            	path[i] = new int [v];
            }
         	for(int i=0;i<v;i++)
         	{
         		for(int j=0;j<v;j++)
         			adjmatrix[i][j] = INT_MAX;
         	}
         	 
        }
        void addEdge(int u,int v,int weight)
        {
            adjlist[u].push_back(make_pair(v,weight));
            adjlist[v].push_back(make_pair(u,weight));
            adjmatrix[u][v] = adjmatrix[v][u] = weight;
        }

        void addAllCityName()
        {
            int i=0;
            string placeName = "zero";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=1;placeName="first";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=2;placeName="second";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=3;placeName="third";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=4;placeName="fourth";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=5;placeName="fifth";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=6;placeName="sixth";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=7;placeName="seventh";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
            i=8;placeName="eight";
            indexMap.insert(make_pair(placeName,i));//mapping places with index
            nameMap.insert(make_pair(i,placeName));
        }
        
        void printGraph()
        {
            list<ipair>::iterator it;
            for(int i=0;i<vertices;i++)
            {
                cout<<nameMap[i]<<endl;
                for(it = adjlist[i].begin();it!=adjlist[i].end();++it)
                {
                    cout<<i<<" "<<it->first<<endl;
                }
            }
        }
        // function for taking paths commented so that you use according to your use case
        
        void printPath(int v, int u)
		{
			if (path[v][u] == v)
				return;

			printPath(v, path[v][u]);
			cout << nameMap[path[v][u]] << " >> ";
		}
        
        void FloydWarshell()
		{
			for (int v = 0; v < vertices; v++) 
			{
				for (int u = 0; u < vertices; u++) 
				{
					// initally cost would be same as weight 
					// of the edge
					dist[v][u] = adjmatrix[v][u];

					if (v == u)
						path[v][u] = 0;
					else if (dist[v][u] != INT_MAX)
						path[v][u] = v;
					else
						path[v][u] = -1;
				}
			}
			
			// run Floyd-Warshell
			for (int k = 0; k < vertices; k++) 
			{
				for (int v = 0; v < vertices; v++) 
				{
					for (int u = 0; u < vertices; u++) 
					{
						// If vertex k is on the shortest path from v to u,
						// then update the value of dist[v][u], path[v][u]

						if (dist[v][k] != INT_MAX && dist[k][u] != INT_MAX
							&& dist[v][k] + dist[k][u] < dist[v][u]) 
						{
							dist[v][u] = dist[v][k] + dist[k][u];
							path[v][u] = path[k][u];
						}
					}

					// if diagonal elements become negative, the
					// graph contains a negative weight cycle
					if (dist[v][v] < 0) 
					{
						cout << "Negative Weight Cycle Found!!";
						return;
					}
				}
			}

			// Print the shortest path between all pairs of vertices
			
		}


 
		void copyToFinal(int curr_path[]) 
		{ 
		    for (int i=0; i<vertices; i++) 
		        finalpathforTSP[i] = curr_path[i]; 
		    finalpathforTSP[vertices] = curr_path[0]; 
		} 
		  
		 
		int firstMin( int i) 
		{ 
		    int min = INT_MAX; 
		    for (int k=0; k<vertices; k++) 
		        if (adjmatrix[i][k]<min && i != k) 
		            min = adjmatrix[i][k]; 
		    return min; 
		} 
		  

		int secondMin( int i) 
		{ 
		    int first = INT_MAX, second = INT_MAX; 
		    for (int j=0; j<vertices; j++) 
		    { 
		        if (i == j) 
		            continue; 
		  
		        if (adjmatrix[i][j] <= first) 
		        { 
		            second = first; 
		            first = adjmatrix[i][j]; 
		        } 
		        else if (adjmatrix[i][j] <= second && 
		                 adjmatrix[i][j] != first) 
		            second = adjmatrix[i][j]; 
		    } 
		    return second; 
		} 
		  
		 
		void TSPRec(int curr_bound, int curr_weight, 
		            int level, int curr_path[]) 
		{ 
		     
		    if (level==vertices) 
		    { 
		     
		        if (adjmatrix[curr_path[level-1]][curr_path[0]] != 0) 
		        { 
		     
		            int curr_res = curr_weight + 
		                    adjmatrix[curr_path[level-1]][curr_path[0]]; 
		  
		     
		            if (curr_res < final_res) 
		            { 
		                copyToFinal(curr_path); 
		                final_res = curr_res; 
		            } 
		        } 
		        return; 
		    } 
		  
		     
		    for (int i=0; i<vertices; i++) 
		    { 
		      
		        if (adjmatrix[curr_path[level-1]][i] != 0 && 
		            visitedforTSP[i] == false) 
		        { 
		            int temp = curr_bound; 
		            curr_weight += adjmatrix[curr_path[level-1]][i]; 
		  
		      
		            if (level==1) 
		              curr_bound -= ((firstMin(curr_path[level-1]) + firstMin(i))/2); 
		            else
		              curr_bound -= ((secondMin(curr_path[level-1]) + firstMin( i))/2); 
		  
		      
		            if (curr_bound + curr_weight < final_res) 
		            { 
		                curr_path[level] = i; 
		                visitedforTSP[i] = true; 
		  
		     
		                TSPRec(curr_bound, curr_weight, level+1, 
		                       curr_path); 
		            } 
		  
		      
		            curr_weight -= adjmatrix[curr_path[level-1]][i]; 
		            curr_bound = temp; 
		  
		      
		            memset(visitedforTSP, false, sizeof(visitedforTSP)); 
		            for (int j=0; j<=level-1; j++) 
		                visitedforTSP[curr_path[j]] = true; 
		        } 
		    } 
		}  
		void TSP() 
		{ 
		    int curr_path[vertices+1]; 
		    int curr_bound = 0; 
		    memset(curr_path, -1, sizeof(curr_path)); 
		    memset(visitedforTSP, 0, sizeof(curr_path)); 
		  

		    for (int i=0; i<vertices; i++) 
		        curr_bound += (firstMin(i) + 
		                       secondMin(i)); 
		  

		    curr_bound = (curr_bound&1)? curr_bound/2 + 1 : 
		                                 curr_bound/2; 
		  
		 
		    visitedforTSP[0] = true; 
		    curr_path[0] = 0; 
		  
		 
		    TSPRec(curr_bound, 0, 1, curr_path); 
		} 
        
};

class country{
        string name;
        graph * g;
        int places;

    public:
        friend class graph;
        void addNameAndPlaces(string name,int places){
            g = new graph;
            this->name = name;
            this->places = places;
            g->constructorhelper(places);
//            g->formNetwork();
        }
        country(string name,int places){
            g = new graph;
            this->name = name;
            this->places = places;
            g->constructorhelper(places);
 //           g->formNetwork();
        }

        country(){}
        void addAllCityName()
        {
            g->addAllCityName();
        }
        void addEdge(int u,int v,int weight)
        {
            g->addEdge(u,v,weight);
        }
        void printGraph(){
            g->printGraph();
            g->pathfinder();
        }

};




// class for intracity network
class city{
        string name;
        graph * g;
        int places;

    public:
        friend class graph;
        friend class country;
        void addNameAndPlaces(string name,int places){
            g = new graph;
            this->name = name;
            this->places = places;
            g->constructorhelper(places);
//            g->formNetwork();
        }
        city(string name,int places){
            g = new graph;
            this->name = name;
            this->places = places;
            g->constructorhelper(places);
 //           g->formNetwork();
        }

        city(){}
        void addAllCityName()
        {
            g->addAllCityName();
        }
        void addEdge(int u,int v,int weight)
        {
            g->addEdge(u,v,weight);
        }
        void printGraph(){
            g->printGraph();
            g->pathfinder();
        }

};

int main(){
    city *c1;
    c1 = new city;
    c1->addNameAndPlaces("abc",9);
    c1->addAllCityName();
    c1->addEdge(0,1,1);
    c1->addEdge(0,2,1);
    c1->addEdge(0,3,1);
    c1->addEdge(1,2,1);
    c1->addEdge(1,4,1);
    c1->addEdge(2,3,1);
    c1->addEdge(2,4,1);
    c1->addEdge(3,5,1);
    c1->addEdge(4,6,1);
    c1->addEdge(4,7,1);
    c1->addEdge(5,7,1);
   	c1->addEdge(6,8,1);
   	c1->addEdge(7,8,1);
    c1->printGraph();
    return 0;
}
