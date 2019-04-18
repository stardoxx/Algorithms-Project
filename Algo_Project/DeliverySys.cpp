#include<bits/stdc++.h>
using namespace std;
#define ipair pair<int,int>

class city; //class for internal parts of a city
class country;  // class for connecting cities across country

class graph{
        int vertices;
        //int ** adj;
        list<ipair> * adjlist;
        map<string,int> indexMap;
        map<int,string> nameMap;
    public:
        friend class city;
        friend class country;
        graph()
        {

        }
        graph(int v){
            this->vertices = v;
            adjlist = new list < ipair >[v];
            //adj = new int *[v];
            //for(int i =0;i<v;i++){
            //    adj[i] = new int [v];
            //    memset(adj[i], 0, v * sizeof(int));
            //}
        }
        void constructorhelper(int v)
        {
            this->vertices = v;
            adjlist = new list < ipair >[v];
            //adj = new int *[v];
            //for(int i =0;i<v;i++){
            //    adj[i] = new int [v];
            //    memset(adj[i], 0, v * sizeof(int));
            //}
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
        void addEdge(int u,int v,int weight)
        {
            adjlist[u].push_back(make_pair(weight,v));
            adjlist[v].push_back(make_pair(weight,u));
        }
        void printGraph()
        {
            list<ipair>::iterator it;
            for(int i=0;i<vertices;i++)
            {
                cout<<nameMap[i]<<" ";
                for(it = adjlist[i].begin();it!=adjlist[i].end();++it)
                {
                    cout<<i<<" "<<it->second<<endl;
                }
            }
        }
        /*void formNetwork(){
            for(int i =0;i<vertices;i++){
                cout<<"enter name of place: "<<endl;
                string placeName;
                cin>>placeName;
                indexMap.insert(make_pair(placeName,i));//mapping places with index
                nameMap.insert(make_pair(i,placeName));//mapping index with places
            }
            for(int i=0;i<vertices;i++){
                for(int j =0;j<vertices;j++){
                    map<int,string>:: iterator itr1,itr2;
                    itr1 = nameMap.find(i);
                    itr2 = nameMap.find(j);
                    cout<<"connect between "<<itr1->second<<" "<<itr2->second<<endl;
                    int k;
                    cout<<"enter -1 for no connections "<<endl;
                    cin >> k;
                    if(k == -1){
                        adj[i][j] = INT_MAX;
                    }
                    else{
                        adj[i][j] = k;
                    }
                }
            }
        }*/
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
        }

};

int main(){
    city *c1;
    c1 = new city;
    c1->addNameAndPlaces("abc",9);
    c1->addAllCityName();
    c1->addEdge(0,1,1);
     c1->addEdge(1,2,4);
    c1->addEdge(1,5,3);
    c1->addEdge(2,4,1);
    c1->addEdge(2,3,2);
    c1->addEdge(3,8,1);
    c1->addEdge(7,8,3);
    c1->addEdge(6,8,5);
    c1->addEdge(0,6,2);
    c1->addEdge(6,7,2);
    c1->printGraph();
    return 0;
}
