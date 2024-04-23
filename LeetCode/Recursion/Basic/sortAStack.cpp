#include <bits/stdc++.h> 

void sortStackHelper(stack<int> &s, int ele){
	if(s.empty()){
		s.push(ele);
		return;
	}

	int topEle = s.top();

	if(ele < topEle){
		s.pop();
		sortStackHelper(s, ele);
		s.push(topEle);
	}
	else{
		s.push(ele);
		return;
		
	}

}



stack<int> sortStack(stack<int> &s)
{
	// Write code here.

	if(s.empty()){
		return s;
	}

	int topEle = s.top();

	s.pop();

	sortStack(s);

	sortStackHelper(s, topEle);

	return s;
}