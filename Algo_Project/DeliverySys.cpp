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

        void startthegame(int parent,bool visit[],int path[],vector<int>mustvisit,int cost)
        {
        	visit[parent] = true;
        	if(isAllVisited(visit,mustvisit) == true)
        	{
        		if(cost<mini)
        		{
        			mini = cost;
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

        void pathfinder()
        {
        	mini = INT_MAX;
        	vector<int>mustvisit;
        	mustvisit.push_back(2);mustvisit.push_back(6);mustvisit.push_back(7);mustvisit.push_back(1);
        	bool visit[vertices] = {false};
        	int path[vertices];
        	for(int i=0;i<vertices;i++)
        		path[i] = -1;
        	bool startingNode = 0;
        	path[startingNode] = -2;
        	visit[startingNode] = true;
        	for(auto it = adjlist[startingNode].begin();it!=adjlist[startingNode].end();++it)
        	{
        		path[it->first] = startingNode;
        		startthegame(it->first,visit,path,mustvisit,it->second);
        		path[it->first] = -1;
        	}
        	cout<<endl<<endl;
        	cout<<mini<<endl<<endl;
        	for(int i=0;i<vertices;i++)
        		cout<<i<<" "<<minipath[i]<<"  "<<endl;
        }

        


        graph(int v){
            this->vertices = v;
            adjlist = new list < ipair >[v];
            mini = INT_MAX;
            minipath = new int [v];
        }
        void constructorhelper(int v)
        {
            this->vertices = v;
            adjlist = new list < ipair >[v];
            mini = INT_MAX;
            minipath = new int [v];
        }
        void addEdge(int u,int v,int weight)
        {
            adjlist[u].push_back(make_pair(v,weight));
            adjlist[v].push_back(make_pair(u,weight));
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
        /*
            void showPath(int path[][v],int u,int w){
                if(path[u][w] == u){
                return ;
              }
                showPath(path,u,path[u][w]);
                cout<<path[u][w]<<" ";
            }
        */

        //function for floyd Warshall
        /*void floydWarshall(){
            int dist[vertices][vertices], i, j, k;//distance matrix
            int path[vertices][vertices];         //path matrix for path finding
            for (i = 0; i < vertices; i++)
            {
                for (j = 0; j < vertices; j++)
                {
                    dist[i][j] = adj[i][j];
                    if (i == j)
                    {
                        path[i][j] = 0;
                    }
                    else if (dist[i][j] != INT_MAX)
                    {
                        path[i][j] = i;
                    }
                    else
                    {
                        path[i][j] = -1;
                    }
                }
            }
            for (k = 0; k < vertices; k++)
            {
                for (i = 0; i < vertices; i++)
                {
                    for (j = 0; j < vertices; j++)
                    {
                        if (dist[i][k] + dist[k][j] < dist[i][j])
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                            path[i][j] = path[k][j];
                        }
                    }
                }
            }*/
            /*
                for extracting paths
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (i != j && path[i][j] != -1)
                    {
                        showPath(path, i, j);
                        cout << endl;
                    }
                }
            }*/
        //}
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
