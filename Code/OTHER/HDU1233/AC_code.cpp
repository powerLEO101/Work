#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

class edge
{
public:
    int u,v,weight;
};

int father[101];

void init()
{
    for(int i = 0;i<101;i++)father[i] = i;
}

bool operator< (const edge& a,const edge& b)
{
    return a.weight<b.weight;
}

int get_father(int u)
{
    if(father[u]==u)return u;
    return father[u] = get_father(father[u]);
}

void merge(int u,int v)
{
    father[get_father(u)] = get_father(v); 
}

std::vector<edge> edges;

int main()
{
    int n;
    std::cin>>n;
    while(n!=0)
    {
        edges.clear();
        init();
        for(int i = 0;i<(n*(n-1))/2;i++)
        {
            int u,v,x;
            std::cin>>u>>v>>x;
            edges.push_back((edge){u,v,x});
        }
        std::sort(edges.begin(),edges.end());
        int ans = 0;
        for(int i = 0;i<(n*(n-1))/2;i++)
        {
            if(get_father(edges[i].u)==get_father(edges[i].v))continue;
            ans += edges[i].weight;
            merge(edges[i].u,edges[i].v);
        } 
        std::cout<<ans<<std::endl;
        std::cin>>n;
    }
    return 0;
}
