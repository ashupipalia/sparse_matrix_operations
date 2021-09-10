#include<bits/stdc++.h>
using namespace std;

int n,m,p,v_size;
float sp;//sparsity of the matrix

//it will generate random value and random coordinates of the matrix
void random_gen_matrix(vector<vector<pair<int,int>>> &matrixA,vector<vector<pair<int,int>>> &matrixB,vector<vector<pair<int,int>>>  &transmatrixB){

    int matA_size = n*m;
    int matB_size = m*p;
    int nonzero_sizeA = matA_size*sp;
    int nonzero_sizeB = matB_size*sp;
    vector<pair<int,int>> input_coord_A;
    vector<pair<int,int>> input_coord_B;
    set<string> rand_coord;
    set <string>::iterator itr;   

    //#############for matrix A random coordinates generated ####################
    while(rand_coord.size() < nonzero_sizeA){

        string s1 = to_string(rand()%n);
        string s2 = to_string(rand()%m);
        string s3 = s1 + "," + s2;
        rand_coord.insert(s3); 
    }
    for (itr = rand_coord.begin(); itr != rand_coord.end(); itr++)
    {
        string str = *itr;
        stringstream ss(str);
        int two_num_arr[2];
        int i=0;
        while (ss.good())   
        {
            string substr;
            getline(ss, substr, ',');
            two_num_arr[i] = stoi(substr);
            i++;
            
        }
        input_coord_A.push_back({two_num_arr[0],two_num_arr[1]});
    }
    for(int i=0;i<nonzero_sizeA;i++){
        int value = rand()%v_size+1;
        matrixA[input_coord_A[i].first].push_back({input_coord_A[i].second,value});
    }
    rand_coord.clear();

//############# for matrix B random coordinates generated #######################
    while(rand_coord.size()<nonzero_sizeB){
        string s1 = to_string(rand()%m);
        string s2 = to_string(rand()%p);
        string s3 = s1 + "," + s2; 
        rand_coord.insert(s3); 
    }
    for (itr = rand_coord.begin(); itr != rand_coord.end(); itr++)
    {
        string str = *itr;
        stringstream ss(str);
        int two_num_arr[2];
        int i=0;
        while (ss.good())   
        {
            string substr;
            getline(ss, substr, ',');
            two_num_arr[i] = stoi(substr);
            i++;
            
        }
        input_coord_B.push_back({two_num_arr[0],two_num_arr[1]});
    }
    for(int i=0;i<nonzero_sizeB;i++){
        int value = rand()%v_size+1;
        matrixB[input_coord_B[i].first].push_back({input_coord_B[i].second,value});
        transmatrixB[input_coord_B[i].second].push_back({input_coord_B[i].first,value});
    }

    /*for(auto x : input_coord_A)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }*/

    /*cout<<"matrix B"<<endl;
    for(auto x : input_coord_B)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    */
   rand_coord.clear();
   input_coord_A.clear();
   input_coord_B.clear();
}

//########## for addition of the matrix A and matrix B ###########
void add_matrix(vector<vector<pair<int,int>>> &matrixA,vector<vector<pair<int,int>>> &matrixB,vector<vector<pair<int,int>>> &addmatrix){

    for(int i=0;i<n;i++){
        map<int,int> addmatrixmap_row;
        for(int j=0;j<matrixA[i].size();j++){
            pair<int,int> matA_value;
            matA_value = matrixA[i][j];
            addmatrixmap_row[matA_value.first] = matA_value.second;
        }
        for(int j=0;j<matrixB[i].size();j++){
            pair<int,int> matB_value;
            matB_value = matrixB[i][j];
            auto it = addmatrixmap_row.find(matB_value.first);
            if(it == addmatrixmap_row.end()){
            }
            else{
                int temp = (*it).second;
                temp = temp + matB_value.second;
                addmatrixmap_row[matB_value.first] = temp;
            }
        }
        for(auto ptr : addmatrixmap_row){
          addmatrix[i].push_back({ptr.first, ptr.second});
        }    
        addmatrixmap_row.clear();   
    }
}

//########## for multiplication of the matrix A and matrix B ###########
void mul_matrix(vector<vector<pair<int,int>>> &matrixA,vector<vector<pair<int,int>>> &transmatrixB,vector<vector<pair<int,int>>> &mulmatrix){

    for(int i=0;i<n;i++){
        int sizeA = matrixA[i].size();
        if(sizeA==0){
                continue;
        }
        vector<pair<int,int>> tempA;
        tempA = matrixA[i];
        for(int j=0;j<p;j++){
            int sum = 0;
            int mul = 1;
            int sizeB = transmatrixB[j].size();
            if(sizeB==0){
                continue;
            }
            int k=0;
            while(k<sizeA){
                vector<pair<int,int>> tempB;
                tempB = transmatrixB[j];
                int colA = tempA[k].first;
                int valueA = tempA[k].second;
                for(int l=0; l<sizeB; l++){
                    if(colA==tempB[l].first){
                        mul = valueA*tempB[l].second;
                        sum = sum + mul; 
                        break;       
                    }
                }
                k++;
            }
            if(sum!=0){
                    mulmatrix[i].push_back({j,sum});
                }
        }
    }
}

void print_addmatrix(vector<vector<pair<int,int>>> &addmatrix){

    cout<<"addition of matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<addmatrix[i].size();j++){
            pair<int,int> temp;
            temp = addmatrix[i][j];
            cout<<"row-"<<i<<" col-"<<temp.first<<" value-"<<temp.second<<"  ";
        }
        cout<<endl;
    }
}

void print_mulmatrix(vector<vector<pair<int,int>>> &mulmatrix){

    cout<<"result"<<endl;
    for(int i=0;i<n;i++){
        vector<pair<int,int>> temp;
        temp = mulmatrix[i];
        for(int j=0;j<temp.size();j++){
            cout<<"row-"<<i<<" col-"<<temp[j].first<<" value-"<<temp[j].second<<"  ";
        }
        cout<<endl;
    }
}

void print_input_matrix(vector<vector<pair<int,int>>> &matrixA,vector<vector<pair<int,int>>> &matrixB,vector<vector<pair<int,int>>> &transmatrixB){

    cout<<"matrixA"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<matrixA[i].size();j++){
            pair<int,int> temp;
            temp = matrixA[i][j];
            cout<<"row-"<<i<<" col-"<<temp.first<<" value-"<<temp.second<<"  ";
        }
        cout<<endl;
    } 
    cout<<"matrixB"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<matrixB[i].size();j++){
            pair<int,int>temp;
            temp = matrixB[i][j];
            cout<<"row-"<<i<<" col-"<<temp.first<<" value-"<<temp.second<<"  ";
        }
        cout<<endl;
    }

    cout<<"transmatrixB"<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<transmatrixB[i].size();j++){
            pair<int,int>temp;
            temp = transmatrixB[i][j];
            cout<<"row-"<<i<<" col-"<<temp.first<<" value-"<<temp.second<<"  ";
        }
        cout<<endl;
    }
}

void reset(vector<vector<pair<int,int>>> &matrixA,vector<vector<pair<int,int>>> &matrixB,vector<vector<pair<int,int>>> &addmatrix,vector<vector<pair<int,int>>> &mulmatrix,vector<vector<pair<int,int>>> &transmatrixB){

    matrixA.clear();
    matrixB.clear();
    addmatrix.clear();
    transmatrixB.clear();
    mulmatrix.clear();
    
}

int main(int argc, char* argv[])
{   
    cout<<"enter n value ";
    cin>>n;
    cout<<"enter m value ";
    cin>>m;
    cout<<"enter p value ";
    cin>>p;
    cout<<"enter sp value ";
    cin>>sp;
    v_size = 30;
    vector<vector<pair<int,int>>> matrixA(n);
    vector<vector<pair<int,int>>> matrixB(m);
    vector<vector<pair<int,int>>> addmatrix(n);
    vector<vector<pair<int,int>>> mulmatrix(n);
    vector<vector<pair<int,int>>> transmatrixB(p);
    
    srand(time(0));

    random_gen_matrix(matrixA,matrixB,transmatrixB);
    
    clock_t start, stop;
    start = clock();
    add_matrix(matrixA,matrixB,addmatrix);
    stop = clock();
    double runtime_of_add = double(stop - start)/CLOCKS_PER_SEC;
     
    start = clock();
    mul_matrix(matrixA,transmatrixB,mulmatrix);
    stop = clock();
    double runtime_of_mul = double(stop - start)/CLOCKS_PER_SEC;

    cout<<"matrix A size is "<<n<<" x "<<m<<" sparsity is "<<sp<<endl;
    cout<<"matrix B size is "<<m<<" x "<<p<<" sparsity is "<<sp<<endl;
    cout<<"resultant matrix of addition size is "<<n<<" x "<<m<<" sparsity is "<<sp<<" runtime is (in sec) "<<runtime_of_add<<endl;
    cout<<"resultant matrix of multiplication size is "<<n<<" x "<<p<<" sparsity is "<<sp<<" runtime is (in sec) "<<runtime_of_mul<<endl; 
    //print_input_matrix(matrixA,matrixB);
    //print_addmatrix(addmatrix);
    //print_mulmatrix(mulmatrix);
   // print_input_matrix(matrixA,matrixB,transmatrixB);
    reset(matrixA,matrixB,addmatrix,mulmatrix,transmatrixB);
    return 0;
}

 