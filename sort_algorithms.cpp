#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void display_vector(vector<int> M){
	for (auto const &i: M) {
        cout << i << " " ;
    }
	cout << endl;
}

void display_array(int* T, int n){	
	for (int* i = T; i < T+n; i++){
		cout << *i << " ";
	}
		cout << endl;
}

void naive_sort(int* T, int n){
	for (int i = 0; i < n-1; i++){
		int minimum_j = i;
		for (int j = i+1; j < n; j++){
			if (T[j] < T[minimum_j]){
				minimum_j = j;
			}
		}		
		if (minimum_j != i){
			swap(T[i], T[minimum_j]);
		}
	}
}

void bubble_sort(int* T, int n){	
	for (int i = n-1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (T[j+1] < T[j]){
				swap(T[j], T[j+1]);
			}
		}
	}
}

void insertion_sort(int* T, int n){
	for (int i = 1; i < n; i++){
		int x = T[i];
		int j = i;
		while(j > 0 && T[j-1] > x){
			T[j] = T[j-1];
			j--;
		}
		T[j] = x;
	}
}

vector<int> quick_sort(vector<int> L){
	int n = L.size();
	
	if (n > 2){
		int pivot = L.back();
		vector<int> L_inf;
		vector<int> L_sup;
		vector<int> L_inf_2;
		vector<int> L_sup_2;
		for(int i = 0; i < L.size() - 1; i++){
			//cout << *it << " " << pivot << endl;
			if (L[i] > pivot){
				L_sup.push_back(L[i]);
			} else{
				L_inf.push_back(L[i]);
			}
		}
		
		if (L_inf.size()>1){
			L_inf_2 = quick_sort(L_inf);
		} else{
			L_inf_2 = L_inf;
		}
		if (L_sup.size()>1){
			L_sup_2 = quick_sort(L_sup);
		} else{
			L_sup_2 = L_sup;
		}
		/*
		cout << "L_inf_ : "<< endl;
		display_vector(L_inf_2);
		cout << "L_sup_2 : "<< endl;
		display_vector(L_sup_2);
		*/

		L_inf_2.push_back(pivot);
		L_inf_2.insert(L_inf_2.end(), L_sup_2.begin(), L_sup_2.end());
		return L_inf_2;
		
	} else {
		return L;
	}
}




void operation (int * T, int n, void (*function)(int*, int)){
	printf("array before sorting \n");
	display_array(T, n);
	auto start = high_resolution_clock::now();
	function(T, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	printf("array after sorting \n");
	display_array(T, n);
	printf("computed in %.3f nanoseconds \n", duration.count()*1.0);
	cout << endl;
	}


int main(){
	int T[] = {15, 8, 2, 9, 4, 1, 5, 17, 2, 16, -5};
	int n = sizeof(T)/sizeof(int);	
	vector<int> L(T, T+n);
	cout << "L before sort : "<< endl;
	display_vector(L);
	vector<int> M = quick_sort(L);
	cout << "M after sort : "<< endl;
	display_vector(M);
	 
	

	
	
	int U[n];
	copy(T, T+n, U);
	int V[n];
	copy(T, T+n, V);

	/*
	cout << "naive sort" << endl;
	operation(T, n, &naive_sort);
	*/
	/*
	cout << "bubble sort" << endl;
	operation(U, n, &bubble_sort);

	cout << "insetion sort" << endl;
	operation(V, n, &insertion_sort);
	*/

	
return 0;
}
