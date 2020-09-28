#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	vector <int> A;

	A = { 69, 0, 32, 23 };

	A.push_back(13);
	A.push_back(13);
	A.push_back(13);// Adding element to the vector

	for (int i = 0; i < A.size(); i++) //printing the vector in conventional way
	{
		cout << A[i] << "\t";
	}

	cout << "\n";
	cout << "\n";

	sort(A.begin(), A.end()); // Ascending sort O(NlogN)

	cout << "After sorting...";

	cout << "\n";
	cout << "\n";

	for (vector<int>::iterator i = A.begin(); i < A.end(); i++) //used to print the vector using iterator, begin() and end()
	{
		cout << *i << "\t";						
	}

	cout << "\n";
	cout << "\n";

	
	//Binary Search O(logN)
	

	//iterator is a pointer to the location of the element in the vector
	vector<int>::iterator it1 = lower_bound(A.begin(), A.end(), 13); // >=13
	vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 13); // >13

	cout << "first iterator: " << *it1 << "\t" << "second iterator: " << *it2 << "\t";

	cout << "position: " << it2 - it1 << endl; // difference in the positions of the first and second iterator

	// vector::push_back
}
















// int main ()
	{
		std::vector<int> myvector;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do 
		{
			std::cin >> myint;
			myvector.push_back (myint);
		} while (myint);

		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n"; //The example uses push_back to add a new element to the vector each time a new integer is read.
	}
}