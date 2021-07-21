#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Matrix{
    vector<vector<int>>vec;
    public:
        

        vector<vector<int>> inputMat(int a,int b){
            vector<vector<int>>v;
            for(int i=0;i<a;i++){
                vector<int>p(b);
                for(int j=0;j<b;j++){
                    cin >> p[j];
                }
                v.push_back(p);
            }
            return v;
        }
        void printMat(){
            for(vector<int> i:vec){
                cout << "|";
                for(int j:i){
                    cout << j << " ";
                }
                cout << "|" << endl;
            }
        }
        
        //add two Square Matrix and return new matrix
        void addMat(vector<vector<int>>a,vector<vector<int>>b){
            int n = a.size(), m = a[0].size();
            for(int i=0;i<n;i++){
                vector<int>sub_v(m);
                for(int j=0;j<m;j++){
                    sub_v[j]=a[i][j] + b[i][j];
                }
                vec.push_back(sub_v);
            }

        }
        //subtract two Square Matrix and return new matrix
        vector<vector<int>> subtractMat(vector<vector<int>>a,vector<vector<int>>b){
            int n = a.size(), m = a[0].size();
            for(int i=0;i<n;i++){
                vector<int>sub_v(n);
                for(int j=0;j<n;j++){
                    sub_v[j]=a[i][j] - b[i][j];
                }
                vec.push_back(sub_v);
            }

        }
        //Matrix multiplication of n x m and p x l matrices return n x l multiplied matrix
        //if m==p else generate error
        void multiplyMat(vector<vector<int>>a,vector<vector<int>>b){
            int n = a.size(), m = a[0].size(), p = b.size(), l = b[0].size();
                for(int i=0;i<n;i++){
                    vector<int>v(l);
                    for(int j=0;j<l;j++){
                        int sum=0;
                        for(int k=0;k<m;k++){
                            sum+=a[i][k]*b[k][j];
                        }
                        v[j] = sum;
                    }
                    vec.push_back(v);
                }
        }
        



};
int main(){
    bool process = false;
    cout << "Welcome!\n";
    while(!process){
        Matrix m1;
        cout << "What do you want to do\n"
             << "1) Matrices Multiplication\n"
             << "2) Matrices Addition\n"
             << "3) Matrices Subtraction\n"
             << "4) End\n"
             << "Choose :";
        int a;cin >> a;if(a==4)break;
        cout << "First Matrix\n";
        cout << "Enter order for first matrix saparated by space :";
        int n,m;cin >> n >> m;
        vector<vector<int>>v1 = m1.inputMat(n,m);
        cout << "Second Matrix\n";
        cout << "Enter order for second matrix saparated by space :";
        int nn,mm;cin >> nn >> mm;
        vector<vector<int>>v2 = m1.inputMat(nn,mm);
    
        switch (a)
        {
        case 1:
	    cout << "Multiplied Matrix is\n";
            m1.multiplyMat(v1,v2);
            m1.printMat();
            break;
        case 3:
	    cout << "Subtracted Matrix is\n";
            m1.subtractMat(v1,v2);
            m1.printMat();
            break;
        case 2:
	    cout << "Added Matrix is\n";
            m1.addMat(v1,v2);
            m1.printMat();
            break;
    }
}
}