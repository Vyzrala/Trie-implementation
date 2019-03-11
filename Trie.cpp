
#include <iostream>
#include <string>
using namespace std;

struct TrieNode {

	TrieNode *word[26];
	string trans;
	bool isEnd;

};
 TrieNode* getNode() {
	TrieNode* pNode = new TrieNode;

	pNode->isEnd= false;

	for (int i = 0; i < 26; i++) {
		pNode->word[i] = NULL;
		//pNode->trans = "";
	}
	
	//pNode->trans = NULL;

	return pNode;
}

void insert(TrieNode* root, string word, string tlum) {

	TrieNode* nowy = root;
	for (int i = 0; i < word.length(); i++) {
		int index = word[i] - 'a';
		if (!nowy->word[index]) {
			nowy->word[index] = getNode();
		}
		nowy = nowy->word[index];
	}
	nowy->isEnd = true;
	nowy->trans = tlum;
}
void query(TrieNode* root, string word) {
	TrieNode* szuk = root;
	

	for (int i = 0; i < word.length(); i++) {

		int index = word[i] - 'a';
		if (!szuk->word[index]) {
			cout << '-' << endl;
			return;
		}
		szuk = szuk->word[index];
	}
	if (szuk->isEnd) {
		cout << szuk->trans << endl;
	}
	else {
		cout << '-' << endl;
	}
}
void print(TrieNode* root) {
	//TrieNode* sentence = root;
	if (root == NULL) {
		return;
	}
	if (root->isEnd) {
		cout << root->trans << endl;
	}
	for (int i = 0; i < 26; i++) {
		if (root->word[i] != NULL) {
			//word[i] = i + 'a';
			print(root->word[i]);
		}
	}
}
void star(TrieNode* root, string word) {

	TrieNode* sentence=root;
	for (int i = 0; i < word.length(); i++) {
		int index = word[i] - 'a';
		if (!sentence->word[index]) {
			cout << '-' << endl;
			return;
		}
		sentence = sentence->word[index];
	}

	print(sentence);

}

int main()
{
	TrieNode* root = getNode();
	char a;
	string word, tlum;

while (cin>>a){
if(a=='+'){
cin >> word >> tlum;
insert(root, word, tlum);

}
if(a=='?'){
cin >> word;
query(root, word);
}
if(a=='*'){
cin >> word;
star(root, word);
}

}
	



    return 0;
}

