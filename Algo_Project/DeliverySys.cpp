#include<bits/stdc++.h>
using namespace std;

class city; //class for internal parts of a city
class country;  // class for connecting cities across country

class graph{
        int vertices;
        int ** adj;
        map<string,int> indexMap;
        map<int,string> nameMap;
    public:
        friend class city;
        friend class country;
        graph(int v){
            this->vertices = v;
            adj = new int *[v];
            for(int i =0;i<v;i++){
                adj[i] = new int [v];
                memset(adj[i], 0, v * sizeof(int));
            }
        }
        void formNetwork(){
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
        void floydWarshall(){
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
            }
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
        city(string name,int places){
            this->name = name;
            this->places = places;
            g(places);
            g->formNetwork();
        }



};



int main(){
    

    return 0;
}