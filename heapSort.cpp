using namespace std;

void heapify(vector <int> &v, int n, int root){
    int largo = root;
    int l = 2*root+1;
    int r = 2*root+2;

    if(l < n && v[l] > v[largo]){
        largo = l;
    }

    if(r < n && v[r] > v[largo]){
        largo = r;
    }

    if(largo != root){
        swap(v[root], v[largo]);
        heapify(v, n, largo);
    }
}

void heapSort(vector <int> &v){
    int n = v.size();    

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}