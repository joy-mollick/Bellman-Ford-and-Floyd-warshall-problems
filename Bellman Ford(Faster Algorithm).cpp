    bool update=false;
    E=(int)edge.size();
    dist[src]=0;
    /// V-1 times relaxation of every edge
    for(int i=0;i<V-1;++i)
    {
        update=false;
        for(int j=0;j<E;++j)
        {
            int now=edge[j].u;
            int to =edge[j].v;
            int Weight=edge[j].weight;
           ///if recent node (now) has been relaxed already i.e. dist[now]!=inf,then we will proceed further by its children
            if(dist[now]!=inf && dist[now]+Weight<dist[to])
            {
                dist[to]=dist[now]+Weight;
                update=true;
            }
        }
        if(!update) break;/// there is no need to iterate again,as all node has been relaxed already assuming src as our source node .It will make less consuming time complexity.
    }
