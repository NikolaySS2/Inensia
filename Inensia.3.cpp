#include <iostream>
#include <string>

using namespace std;

void recursiveFunction(string word, int n, string separator) {
	if (n <= 0) {
		return;
	}
	else if(n==1){
		cout<<word;
		return;
	}
	else {
		cout << word << separator;
		recursiveFunction(word, n - 1, separator);
	}
}

int main()
{
	string word,separator;
	int number;
	cin >> word >> number >> separator;
	recursiveFunction(word, number, separator);
}
