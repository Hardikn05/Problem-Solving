#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
	bool isend;
	vector<TrieNode*> child;
	vector<string> word;
	TrieNode() {
		isend = false;
		child.resize(26, NULL);
	}
};
TrieNode* r;
void insert(string w)
{
	string t = w;
	TrieNode* dummy = r;
	for (int i = 0; i < t.size(); i++)
	{
		if (dummy->child[t[i] - 'a'])
		{
			dummy = dummy->child[t[i] - 'a'];
			dummy->word.push_back(w);
		}
		else
		{
			dummy->child[t[i] - 'a'] = new TrieNode();
			dummy = dummy->child[t[i] - 'a'];
			dummy->word.push_back(w);
		}
	}
	dummy->isend = true;
}
void solve(string w)
{
	TrieNode* t = r;
	for (int i = 0; i < w.size(); i++)
	{
		if (t->child[w[i] - 'a'])
		{
			t = t->child[w[i] - 'a'];
		}
		else
		{
			cout << "No suggestions\n";
			return;
		}
	}
	for (auto it : t->word)
		cout << it << " ";
	cout << endl;
}
int main() {
	r = new TrieNode();
	int n;
	cin >> n;
	while (n--)
	{
		string t;
		cin >> t;
		insert(t);
	}
	string t;
	cin >> t;
	solve(t);
	return 0;
}
