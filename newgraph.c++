#include<bits/stdc++.h>

using namespace std;

class edge
{
public:
int destvertexid;
int weight;
edge(int des,int w){
    destvertexid=des;
    weight=w;


}
int getdestination(){
    return destvertexid;
}
int getweight(){
    return weight;

}
void setweight(int newweight){
    weight=newweight;
    
}

};

class vertex{

public:
int stateid;
list<edge> edgelist;
string statename;

vertex(){
    stateid=0;
    statename="";
}
vertex(int sid,string n){

 stateid=sid;
    statename=n;
    cout<<"state ID is :"<<stateid<<endl;
    cout<<"state name is :"<<statename<<endl;
    
}
list<edge> getlist(){
    return edgelist;
    
}
int getstateid(){
    return stateid;
}
string getstatename(){
    return statename;

}
void printedgelist(){
    cout<<"[";
    for(auto it=edgelist.begin();it!=edgelist.end();it++){
        cout<<it->getdestination()<<"("<<it->getweight()<<")->";
    }
    cout<<"]";
    cout<<endl;
    
}
};
class graph{
public:
vector<vertex> vertices;

void addvertex(vertex v){
    bool check=checkvertexexist(v.getstateid());
    if(check==true){
        cout<<"vertex exist already"<<endl;
    }
    else{
        vertices.push_back(v);
        cout<<" new vertex added successfully that is:"<<v.stateid<<endl;
    }
    
    }

bool checkvertexexist(int vid){
    bool flag=false;
    for(int i=0;i<vertices.size();i++){
            if(vertices.at(i).getstateid()==vid){
                flag= true;
            }
    }
    return flag;
    
}
vertex getvertexbyid(int sourcev){
    vertex temp;
    for(int i=0;i<vertices.size();i++){
    temp=vertices.at(i);
    if(temp.getstateid()==sourcev){
        return temp;
    }
    }
    return temp;
}

bool checkifedgeexist(int sourcev,int destinationv){
    vertex v=getvertexbyid(sourcev);
    list<edge> e;
    e=v.getlist();                                                      //(*it)->dereferencing of pointer 
     for(auto it=e.begin();it!=e.end();it++){  //here it is an pointer which points to the blocks of our list #if we want to print the values which is in our list we can print easily by dereferencing the pointer valueby doing (*it)->dereferencing of pointer 
        if(it->getdestination()==destinationv){
            
            return true;
            break;
        }
    }
    return false;
}

void addedge(int sourcev,int destinationv,int weight){
    bool check1=checkvertexexist(sourcev);
    bool check2=checkvertexexist(destinationv);

    if(check1 && check2== true){
    bool check3=checkifedgeexist(sourcev,destinationv);
    if(check3==true){
        cout<<"edge already exits in this graph"<<endl;
    }
 else{
        for(int i=0;i<vertices.size();i++){
        if(vertices.at(i).getstateid()==sourcev){
            edge e(destinationv,weight);
            vertices.at(i).edgelist.push_back(e);
        }
        else if(vertices.at(i).getstateid()==destinationv){
            edge e(sourcev,weight);
            vertices.at(i).edgelist.push_back(e);
        }
        }
        cout<<"edge between  "<<sourcev<<"  and  "<<destinationv<<" is inserted with WEIGHT :"<<weight<<endl;
       
        

    }
}
else{
    cout<<"invalid vertex ID entered"<<endl;
}
}
void printgraph(){
     vertex temp;
    for(int i=0;i<vertices.size();i++){
    temp=vertices.at(i);
    cout<<temp.getstatename()<<"("<<temp.getstateid()<<")-->";
    temp.printedgelist();
    }
    }
void updateedge(int sourcev,int destinationv,int nweight){
     bool check=checkifedgeexist(sourcev,destinationv);
        if(check==true){
             for(int i=0;i<vertices.size();i++){
             vertex temp=vertices.at(i);
             if(temp.getstateid()==sourcev){
             for(auto it=temp.edgelist.begin();it!=temp.edgelist.end();it++){
                 if(it->getdestination()==destinationv){
                    it->setweight(nweight);
                    break;
                 }  }
              
             }
              if(temp.getstateid()==destinationv){
             for(auto it=temp.edgelist.begin();it!=temp.edgelist.end();it++){
                 if(it->getdestination()==sourcev){
                    it->setweight(nweight);
                    break;
                 }  }
              
             }
             
               
            


            }
            cout<<"the edge  is updated successfully"<<endl;


        }
        else{
            cout<<"the edge does not exist"<<endl;
        }
     }
     void deleteedge(int sourcev,int destinationv){
        bool check=checkifedgeexist(sourcev,destinationv);
        if(check==true){
            for(int i=0;i<vertices.size();i++){
             vertex temp=vertices.at(i);
             if(temp.getstateid()==sourcev){
             for(auto it=temp.edgelist.begin();it!=temp.edgelist.end();it++){
                 if(it->getdestination()==destinationv){
                    temp.edgelist.erase(it);
                    break;
                 }  }
              
             }
             else if(temp.getstateid()==destinationv){
             for(auto it=temp.edgelist.begin();it!=temp.edgelist.end();it++){
                 if(it->getdestination()==sourcev){
                    temp.edgelist.erase(it);
                    break;
                 }  }}

        }
     }}
            
};


int main(){
    vertex v1(1,"MH");
    vertex v2(2,"goa");
    vertex v3(3,"RAJ");
    vertex v4(4,"guj");

    graph g;
    g.addvertex(v1);
    g.addvertex(v2);
    g.addvertex(v3);
    g.addvertex(v4);
g.addedge(1,3,40);
g.addedge(1,2,20);
g.addedge(4,2,50);
g.printgraph();

g.updateedge(4,2,10);
g.deleteedge(1,2);
g.printgraph();
    return 0;

}






