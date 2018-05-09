#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
struct WordType {
  public:
    string word;
    int count;
};

struct TreeNode {
    WordType info;
    TreeNode* left;
    TreeNode* right;
};

class ListType {
  public:
    ListType();
    void InsertOrIncrement(string letters);
    void PrintList(ofstream&);

  private:
    TreeNode* root;
};

string GetString(ifstream&);
const int MAX_LETTERS = 20;
int main() {
    ListType list;
    string inFileName;
    string outFileName;
    string outputLabel;
    ifstream inFile;
    ofstream outFile;
    string letters;
    int minimumLength;

    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());
    if (!inFile)
        cout << "file not found";

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;

    cout << "Enter the minimum size word to be considered." << endl;
    cin >> minimumLength;

    // Read the text stripping of words and inserting them into
    // list.  If a word is already there, its count is incremented.
    letters = GetString(inFile);
    while (inFile) {
        if (letters.length() >= minimumLength)
            list.InsertOrIncrement(letters);
        letters = GetString(inFile);
    }

    list.PrintList(outFile);
    outFile.close();
    inFile.close();
    return 0;
}

string GetString(ifstream& inFile)
// Post: Non alphanumeric characters as skipped. Alphanumeric characters are
//       read and concatenated on a string until a non-alphanumeric character is
//       read or end of file is reached. Letters are all converted to lowercase.
{
    char letter;
    string letters = "";

    inFile.get(letter);
    while (inFile && !isalnum(letter))
        inFile.get(letter);

    if (!inFile)
        // No legal character found; empty string returned.
        return letters;
    else {  // Read and collect characters.
        do {
            letter = tolower(letter);
            letters = letters + letter;
            inFile.get(letter);
        } while (isalnum(letter) && inFile);
    }
    return letters;
}

ListType::ListType() {
    root = NULL;
}

void Process(TreeNode*& tree, std::string letters) {
    if (tree == NULL) {
        tree = new TreeNode;
        tree->info.word = letters;
        tree->info.count = 1;
        tree->left = NULL;
        tree->right = NULL;
    } else if (tree->info.word == letters)
        tree->info.count++;
    else if (tree->info.word > letters)
        Process(tree->left, letters);
    else
        Process(tree->right, letters);
}

void ListType::InsertOrIncrement(string letters) {
    Process(root, letters);
}

void Print(TreeNode*& tree, ofstream& outFile) {
    if (tree != NULL) {
        Print(tree->left, outFile);
        outFile << tree->info.word;
        outFile << " " << tree->info.count;
        outFile << endl;
        Print(tree->right, outFile);
    }
}

void ListType::PrintList(ofstream& outFile) {
    Print(root, outFile);
}
