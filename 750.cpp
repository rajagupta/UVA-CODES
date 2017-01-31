#include<bits/stdc++.h>
using namespace std;

vector<bool>row(9,false);
vector<bool>col(9,false);
vector<vector<int> >dia(9, vector<int>(9,-1));
vector<vector<int> >f_result;
int cn, rn;
void make_true(int i, int c){
    row[i]=true;
    col[c]=true;
    int d=0;
    for(int k=i;k>0;k--){
        if(c-d>0 and dia[k][c-d]==-1)
            dia[k][c-d]=c;
        if(c+d<=8 and dia[k][c+d]==-1)
            dia[k][c+d]=c;
        d++;
    }
    d=0;
    for(int k=i;k<=8;k++){
        if(c-d>0 and dia[k][c-d]==-1)
            dia[k][c-d]=c;
        if(c+d<=8 and dia[k][c+d]==-1)
            dia[k][c+d]=c;
        d++;
    }
}
void make_false(int i, int c){
    row[i]=false;
    col[c]=false;
    int d=0;
    for(int k=i;k>0;k--){
        if(c-d>0 and dia[k][c-d]==c)
            dia[k][c-d]=-1;
        if(c+d<=8 and dia[k][c+d]==c)
            dia[k][c+d]=-1;
        d++;
    }
    d=0;
    for(int k=i;k<=8;k++){
        if(c-d>0 and dia[k][c-d]==c)
            dia[k][c-d]=-1;
        if(c+d<=8 and dia[k][c+d]==c)
            dia[k][c+d]=-1;
        d++;
    }
}

void fun(int c, int count_, vector<int>&res){
    //cout<<c<<" "<<count_<<" "<<endl;
    if(count_==8){
        f_result.push_back(res);
        return ;
    }
    if(c>8)
        return;
    if(c==cn){
        res.push_back(rn);
        fun(c+1, count_+1, res);
        res.pop_back();
        return;
    }
    if(col[c]==false){
        for(int i=1;i<=8;i++){
            if(row[i]==false){
                if(dia[i][c]==-1){
                    make_true(i, c);
                    res.push_back(i);
                    fun(c+1, count_+1, res);
                    make_false(i, c);
                    res.pop_back();
                }
            }
        }
    }
    return;
}
int main(){
    int t;
    cin>>t;
    bool b=true;
    while(t--){
        //int r, c;
        cin>>rn>>cn;
        make_true(rn,cn);
        vector<int>res;
        fun(1,0,res);
        if(b==false){
            cout<<endl;
        }
        b=false;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for(int i=0;i<f_result.size();i++){
            printf("%2d      ",i+1);
            for(int j=0;j<f_result[i].size();j++){
                cout<<f_result[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int i=0;i<f_result.size();i++){
            f_result[i].clear();
        }
        f_result.clear();
        make_false(rn,cn);
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                dia[i][j]=-1;

    }
}
