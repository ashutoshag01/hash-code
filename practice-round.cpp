#include <bits/stdc++.h>
using namespace std;

void find_max_min(int pizzas[], int numpizzas, int max_slices){
	
	int max_till = 0;
	vector<int> result;
	
	for(int i=numpizzas-1; i>=0; i--){

		int sum = 0;
		vector<int> temp;

		for(int j=i; j>=0; j--){
			if(sum+pizzas[j] <= max_slices){
				sum+= pizzas[j];
				temp.push_back(j);
			}	
		}
		
		if(max_till < sum){
			max_till = sum;
			result.clear();
		 	for(int k=temp.size()-1; k>=0; k--)
		 		result.push_back(temp[k]); 
		}

		if(max_till == max_slices)
			break;
	}

	cout<<result.size()<<endl;
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
}

int main(){

	int max_slices, numpizzas;
	int pizzas[100001];

	scanf("%d%d",&max_slices,&numpizzas);

	for(int i=0; i<numpizzas; i++){
		scanf("%d",&pizzas[i]);
	}

	find_max_min(pizzas,numpizzas,max_slices);
	return 0;
}
