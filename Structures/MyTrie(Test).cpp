#include <iostream>
#include <map>

using namespace std;

struct TrieNode
{
 	map<char,TrieNode*> children;
 	bool endOfWord;
 	TrieNode()
 	{
 		endOfWord=false;
 	}
};

void insert(TrieNode *root,string word)
{
 	TrieNode *current=root;
 	for(int i=0;i<word.size();i++)
 	{
 		char ch=word[i];
 		TrieNode *node=current->children[ch];
 		if(!node)
 		{
 			node=new TrieNode();
 			current->children[word[i]]=node;
 		}
 		current=node;
 	}
 	current->endOfWord=true;
}

bool prefixsearch(TrieNode *root,string word)
{
 	TrieNode *current=root;
 	for(int i=0;i<word.size();i++)
 	{
 		char ch=word[i];
 		TrieNode *node=current->children[ch];
 		if(!node)
 			return false;
 	current=node;
 	}
 	return true;
}

int main()
{
 	TrieNode *root=new TrieNode();
 	insert(root,"trie");
 	insert(root,"try");
 	insert(root,"tried");
 	insert(root,"trim");
 	insert(root,"tries");
 	string p;
 	cout<<"Enter the prefix to be searched :";
 	cin>>p;
 	cout<<prefixsearch(root,p)<<endl;
 	delete root;
 	return 0;
}
