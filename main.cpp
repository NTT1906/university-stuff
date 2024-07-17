#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

struct Student{
	string id, fullName;
	double it1, it2, it3;
};

vector<Student> readStudentFromFile(const string& fileName) {
	ifstream file;
	file.open(fileName.c_str());
	if (!file.is_open()) {
		return {};
	}
	vector<Student> r;
	int n = 0;
	string temp;
	getline(file, temp, '\n'); //Skip first line
	while (!file.eof()) {
		Student tStu = {};
		getline(file, tStu.id, ' ');
		getline(file, tStu.fullName, ' ');
		double *startP = &tStu.it1, *endP = &tStu.it2;
		while (startP < endP) {
			file >> *startP;
			startP += 1;
		}
		r.push_back(tStu);
	}
	file.close();
	return r;
}

int *readFile(const char *fileName, int &n) {
	ifstream file(fileName);
	if (!file.is_open()) return nullptr;

	file >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		file >> a[i];
	}
	file.close();
	return a;
}

vector<int> readFile2Vector(const char *fileName, int &n) {
	ifstream file(fileName);
	if (!file.is_open()) {
		return {};
	}
	file >> n;
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; i++) {
		file >> a[i];
	}
	file.close();
	return a;
}

void insertionSort(std::vector<Student>& students) {
	int n = students.size();
	for (int i = 1; i < n; ++i) {
		Student key = students[i];
		int j = i - 1;
		while (j >= 0 && students[j].fullName > key.fullName) {
			students[j + 1] = students[j];
			--j;
		}
		students[j + 1] = key;
	}
}

// int found = str.find_last_of(' '); // find last word
// str.substr(found+1)

int main() {
	/// AVL tree code
//	NODE *root = nullptr;
//	root = insert(root, 9);
//	root = insert(root, 5);
//	root = insert(root, 10);
//	root = insert(root, 0);
//	root = insert(root, 6);
//	root = insert(root, 11);
//	root = insert(root, -1);
//	root = insert(root, 1);
//	root = insert(root, 2);
//
//	cout << "Preorder traversal of the constructed AVL tree is \n";
//
//	root = remove(root, 10);
//
//	removeTree(root);
	return 0;
}

///// AVL tree
//struct NODE{
//	int key;
//	NODE *left;
//	NODE *right;
//	int height;
//};
//
//NODE *createNODE(int data) {
//	return new NODE{data, nullptr, nullptr, 1};
//}
//
//int NodeHeight(NODE *node) {
//	return node == nullptr ? 0 : node->height;
//}
//
//int NodeBalance(NODE *node) {
//	 return node == nullptr ? 0 : NodeHeight(node->left) - NodeHeight(node->right);
//}
//
//NODE *rightRotate(NODE *y) {
//	NODE *x = y->left;
//	NODE *T2 = x->right;
//
//	x->right = y;
//	y->left = T2;
//
//	y->height = max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
//	x->height = max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
//
//	return x;
//}
//
//NODE *leftRotate(NODE *x) {
//	NODE *y = x->right;
//	NODE *T2 = y->left;
//
//	y->left = x;
//	x->right = T2;
//
//	x->height = max(NodeHeight(x->left), NodeHeight(x->right)) + 1;
//	y->height = max(NodeHeight(y->left), NodeHeight(y->right)) + 1;
//
//	return y;
//}
//
//NODE *insert(NODE *node, int key) {
//	// 1. Perform the normal BST rotation
//	if (node == nullptr) return createNODE(key);
//
//	if (key < node->key) {
//		node->left = insert(node->left, key);
//	} else if (key > node->key) {
//		node->right = insert(node->right, key);
//	} else {
//		// Equal keys not allowed
//		return node;
//	}
//
//	// 2. Update height of this ancestor node
//	node->height = 1 + max(NodeHeight(node->left), NodeHeight(node->right));
//
//	// 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
//	int balance = NodeBalance(node);
//
//	// If this node becomes unbalanced, then there are 4 cases
//
//	// Left Left Case
//	if (balance > 1 && key < node->left->key)
//		return rightRotate(node);
//
//	// Right Right Case
//	if (balance < -1 && key > node->right->key)
//		return leftRotate(node);
//
//	// Left Right Case
//	if (balance > 1 && key > node->left->key) {
//		node->left = leftRotate(node->left);
//		return rightRotate(node);
//	}
//
//	// Right Left Case
//	if (balance < -1 && key < node->right->key) {
//		node->right = rightRotate(node->right);
//		return leftRotate(node);
//	}
//
//	/* return the (unchanged) node pointer */
//	return node;
//}
//
///* Given a non-empty binary search tree, return the node with minimum key value
//found in that tree. Note that the entire tree does not need to be searched. */
//NODE *minValueNode(NODE *node) {
//	NODE *current = node;
//
//	/* loop down to find the leftmost leaf */
//	while (current->left != nullptr)
//		current = current->left;
//
//	return current;
//}
//
//NODE *remove(NODE *&node, int key) {
//	// STEP 1: PERFORM STANDARD BST DELETE
//	if (node == nullptr) return node;
//
//	// If the key to be deleted is smaller than the root's key, then it lies in left subtree
//	if (key < node->key)
//		node->left = remove(node->left, key);
//		// If the key to be deleted is greater than the root's key, then it lies in right subtree
//	else if (key > node->key)
//		node->right = remove(node->right, key);
//		// if key is same as root's key, then This is the node to be deleted
//	else {
//		// node with only one child or no child
//		if ((node->left == nullptr) || (node->right == nullptr)) {
//			NODE *temp = node->left ? node->left : node->right;
//
//			// No child case
//			if (temp == nullptr) {
//				temp = node;
//				node = nullptr;
//			} else // One child case
//				*node = *temp; // Copy the contents of the non-empty child
//			delete temp;
//		} else {
//			// node with two children: Get the inorder successor (smallest in the right subtree)
//			NODE *temp = minValueNode(node->right);
//
//			// Copy the inorder successor's data to this node
//			node->key = temp->key;
//
//			// Delete the inorder successor
//			node->right = remove(node->right, temp->key);
//		}
//	}
//
//	// If the tree had only one node then return
//	if (node == nullptr) return nullptr;
//
//	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
//	node->height = 1 + max(NodeHeight(node->left), NodeHeight(node->right));
//
//	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
//	int balance = NodeBalance(node);
//
//	// If this node becomes unbalanced, then there are 4 cases
//
//	// Left Left Case
//	if (balance > 1 && NodeBalance(node->left) >= 0)
//		return rightRotate(node);
//
//	// Left Right Case
//	if (balance > 1 && NodeBalance(node->left) < 0) {
//		node->left = leftRotate(node->left);
//		return rightRotate(node);
//	}
//
//	// Right Right Case
//	if (balance < -1 && NodeBalance(node->right) <= 0)
//		return leftRotate(node);
//
//	// Right Left Case
//	if (balance < -1 && NodeBalance(node->right) > 0) {
//		node->right = rightRotate(node->right);
//		return leftRotate(node);
//	}
//
//	return node;
//}
//
//void removeTree(NODE *&pRoot) {
//	if (pRoot == nullptr) return;
//	removeTree(pRoot->left);
//	removeTree(pRoot->right);
//	delete pRoot;
//}
//
//bool isAVL(NODE *node) {
//	if (node == nullptr) return true;
//	return abs(NodeBalance(node)) <= 1 && isAVL(node->left) && isAVL(node->right);
//}

///// Quick Sort
//int medianOfThree(int *a, int first, int last) {
//	int mid = (first + last) / 2;
//	if ((a[first] > a[mid]) ^ (a[first] > a[last])) return first;
//	if ((a[mid] > a[first]) ^ (a[mid] > a[last])) return mid;
//	return last;
//}
//
//int partition(int *a, int first, int last) {
//	int pivotIndex = medianOfThree(a, first, last);
//	int pivotValue = a[pivotIndex];
//	swap(a[pivotIndex], a[last]);
//	pivotIndex = first;
//	for (int i = first; i < last; ++i) {
//		if (a[i] <= pivotValue) {
//			swap(a[i], a[pivotIndex++]);
//		}
//	}
//	swap(a[pivotIndex], a[last]);
//	return pivotIndex;
//}
//
//void quickSortRecur(int *a, int first, int last) {
//	if (first < last) {
//		int pivotIndex = partition(a, first, last);
//		quickSortRecur(a, first, pivotIndex - 1);
//		quickSortRecur(a, pivotIndex + 1, last);
//	}
//}

//std::vector<Student> readStudentFromFile(const std::string& fileName) {
//	std::ifstream file(fileName);
//	std::vector<Student> students;
//	std::string line;
//
//	if (file.is_open()) {
//		// Skip the header line
//		std::getline(file, line);
//
//		while (std::getline(file, line)) {
//			std::istringstream iss(line);
//			Student student;
//			iss >> student.id;
//			std::string tmp;
//			while (iss >> tmp) {
//				if (isdigit(tmp[0])) {
//					iss.putback(tmp[0]);
//					break;
//				}
//				student.fullName += tmp + " ";
//			}
//			student.fullName.pop_back(); // Remove the trailing space
//			iss >> student.it1 >> student.it2 >> student.it3;
//			student.gpa = calculateGPA(student.it1, student.it2, student.it3);
//			students.push_back(student);
//		}
//		file.close();
//	}
//	return students;
//}
//void printSecondHighestGPA(const std::vector<Student>& studentList) {
//	if (studentList.empty()) return;
//
//	std::vector<double> gpas;
//	for (const auto& student : studentList) {
//		gpas.push_back(student.gpa);
//	}
//
//	std::sort(gpas.begin(), gpas.end(), std::greater<double>());
//	double highestGPA = gpas[0];
//	double secondHighestGPA = highestGPA;
//
//	for (const auto& gpa : gpas) {
//		if (gpa < highestGPA) {
//			secondHighestGPA = gpa;
//			break;
//		}
//	}
//
//	std::vector<Student> secondHighestGPAStudents;
//	for (const auto& student : studentList) {
//		if (student.gpa == secondHighestGPA) {
//			secondHighestGPAStudents.push_back(student);
//		}
//	}
//
//	insertionSort(secondHighestGPAStudents); // Using insertion sort instead of std::sort
//
//	for (const auto& student : secondHighestGPAStudents) {
//		std::cout << student.id << " " << student.fullName << std::endl;
//	}
//}

//// Helper function to check if a tree is a BST
//bool isBSTUtil(NODE* node, int min, int max) {
//	if (node == nullptr) {
//		return true;
//	}
//
//	if (node->data < min || node->data > max) {
//		return false;
//	}
//
//	return isBSTUtil(node->left, min, node->data - 1) &&
//		   isBSTUtil(node->right, node->data + 1, max);
//}
//
//bool isBST(NODE* pRoot) {
//	return isBSTUtil(pRoot, INT_MIN, INT_MAX);
//}
//
//// Helper function to check if a tree is full
//bool isFullTree(NODE* node) {
//	if (node == nullptr) {
//		return true;
//	}
//
//	if ((node->left == nullptr && node->right != nullptr) ||
//		(node->left != nullptr && node->right == nullptr)) {
//		return false;
//	}
//
//	return isFullTree(node->left) && isFullTree(node->right);
//}
//
//bool isFullBST(NODE* pRoot) {
//	return isBST(pRoot) && isFullTree(pRoot);
//}
//
//// Helper function to check if a tree is complete
//bool isCompleteTree(NODE* root) {
//	if (root == nullptr) return true;
//
//	std::queue<NODE*> q;
//	q.push(root);
//	bool flag = false;
//
//	while (!q.empty()) {
//		NODE* temp = q.front();
//		q.pop();
//
//		if (temp->left) {
//			if (flag) return false;
//			q.push(temp->left);
//		} else {
//			flag = true;
//		}
//
//		if (temp->right) {
//			if (flag) return false;
//			q.push(temp->right);
//		} else {
//			flag = true;
//		}
//	}
//
//	return true;
//}
//
//bool isCompleteBST(NODE* pRoot) {
//	return isBST(pRoot) && isCompleteTree(pRoot);
//}

//struct NODE {
//	int key;
//	NODE* pLeft;
//	NODE* pRight;
//};
//
//NODE* createNode(int data) {
//	return new NODE{data, nullptr, nullptr};
//}
//
//void Insert(NODE* &pRoot, int x) {
//	if (pRoot == nullptr) {
//		pRoot = createNode(x);
//		return;
//	}
//	if (x > pRoot->key) {
//		Insert(pRoot->pRight, x);
//	} else if (x < pRoot->key) {
//		Insert(pRoot->pLeft, x);
//	}
//}
//
//void NLR(NODE* pRoot) { //Pre order
//	if (pRoot == nullptr) return;
//	cout << pRoot->key << " ";
//	NLR(pRoot->pLeft);
//	NLR(pRoot->pRight);
//}
//
//void LNR(NODE* pRoot) { //In order
//	if (pRoot == nullptr) return;
//	LNR(pRoot->pLeft);
//	cout << pRoot->key << " ";
//	LNR(pRoot->pRight);
//}
//
//void LRN(NODE* pRoot) { // Post oder
//	if (pRoot == nullptr) return;
//	LRN(pRoot->pLeft);
//	LRN(pRoot->pRight);
//	cout << pRoot->key << " ";
//}
//
//#include <queue>
//void LevelOrder(NODE *pRoot) {
//	if (pRoot == nullptr) {
//		return;
//	}
//
//	queue<NODE *> q;
//	q.push(pRoot);
//	while (!q.empty()) {
//		NODE *front = q.front();
//		q.pop();
//		cout << front->key << " ";
//
//		if (front->pLeft != nullptr) {
//			q.push(front->pLeft);
//		}
//
//		if (front->pRight != nullptr) {
//			q.push(front->pRight);
//		}
//	}
//}
//
//int Height(NODE* pRoot) {
//	return pRoot == nullptr ? 0 : max(Height(pRoot->pLeft), Height(pRoot->pRight)) + 1;
//}
//
//int countNode(NODE* pRoot) {
//	if (pRoot == nullptr) return 0;
//	return 1 + countNode(pRoot->pLeft) + countNode(pRoot->pRight);
//}
//
//int sumNode(NODE* pRoot) {
//	if (pRoot == nullptr) return 0;
//	return pRoot->key + sumNode(pRoot->pLeft) + sumNode(pRoot->pRight);
//}
//
//void removeTree(NODE *&pRoot) {
//	if (pRoot == nullptr) return;
//	removeTree(pRoot->pLeft);
//	removeTree(pRoot->pRight);
//	delete pRoot;
//}
//
//int main() {
//	NODE* head = createNode(0);
//	Insert(head, 1);
//	Insert(head, 2);
//	Insert(head, 3);
//	Insert(head, 6);
//	Insert(head, 5);
//	LNR(head);
//	cout << "\n" << countNode(head);
//	cout << "\n" << sumNode(head);
//	removeTree(head);
//	return 0;
//}
