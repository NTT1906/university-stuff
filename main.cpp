#include <iostream>
#include <fstream>

using namespace std;

int main() {
	return 0;
}
























































//vector<Company> readFile(const string &file_name) {
//	ifstream file(file_name.c_str());
//	if (!file.is_open()) {
//		return {};
//	}
//	string line, tmp;
//	getline(file, tmp); // skip first line - headers
//	vector<Company> companies;
//	while (getline(file, line)) {
//		Company com;
//		size_t pos1 = line.find('|');
//		size_t pos2 = line.find('|', pos1 + 1);
//
//		com.name = line.substr(0, pos1);
//		com.tax_code = line.substr(pos1 + 1, pos2 - pos1 - 1);
//		com.address = line.substr(pos2 + 1);
//
//		companies.push_back(com);
//	}
//	file.close();
//	return companies;
//}

struct NODE{
	int key;
	NODE *pLeft;
	NODE *pRight;
	int height;
};

int NodeHeight(NODE *node) {
	return node == nullptr ? 0 : node->height;
}

int NodeBalance(NODE *node) {
	return node == nullptr ? 0 : NodeHeight(node->pLeft) - NodeHeight(node->pRight);
}

//          node		         child
//         /    \			    /     \
//      child       -> grandchild     node
//      /   \
//grandchild
void rightRotate(NODE *&pRoot) {
	NODE *child = pRoot->pLeft;
	NODE *grandchild = child->pRight;

	// rotate right
	pRoot->pLeft = grandchild;
	child->pRight = pRoot;

	pRoot->height = 1 + max(NodeHeight(grandchild), NodeHeight(pRoot->pRight));
	child->height = 1 + max(NodeHeight(pRoot), NodeHeight(child->pLeft));
}

//     node
//    /     \             child
//        child    ->    /     \
//        /     \      node   grandchild
//   		grandchild
void leftRotate(NODE *&pRoot) {
	NODE *child = pRoot->pRight;
	NODE *grandchild = child->pLeft;

	// rotate left
	pRoot->pRight = grandchild;
	child->pLeft = pRoot;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(grandchild));
	child->height = 1 + max(NodeHeight(pRoot), NodeHeight(child->pRight));
}

void Insert(NODE *&pRoot, int x) {
	if (pRoot == nullptr) {
		pRoot = new NODE{x, nullptr, nullptr, 0};
		return;
	}

	if (x < pRoot->key) Insert(pRoot->pLeft, x);
	else if (x > pRoot->key) Insert(pRoot->pRight, x);
	else return;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(pRoot->pRight));
	int balance = NodeBalance(pRoot);

	if (balance > 1 && x != pRoot->pLeft->key) {
		NODE *tmp = pRoot->pLeft;
		if (x > tmp->key) { // if true LR, else RR
			tmp = tmp->pRight;
			leftRotate(pRoot->pLeft);
			pRoot->pLeft = tmp;
		}
		rightRotate(pRoot);
		pRoot = tmp;
		return;
	}
	if (balance < -1 && x != pRoot->pRight->key) {
		NODE *tmp = pRoot->pRight;
		if (x < tmp->key) { // if true RL, else LL
			tmp = tmp->pLeft;
			rightRotate(pRoot->pRight);
			pRoot->pRight = tmp;
		}
		leftRotate(pRoot);
		pRoot = tmp;
	}
}

void Remove(NODE *&pRoot, int x) {
	if (pRoot == nullptr) return;

	if (x < pRoot->key) Remove(pRoot->pLeft, x);
	else if (x > pRoot->key) Remove(pRoot->pRight, x);
	else if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr) { // leaf
		delete pRoot;
		pRoot = nullptr;
	} else if (pRoot->pLeft == nullptr) { // 1 right child
		NODE *tmp = pRoot->pRight;
		delete pRoot;
		pRoot = tmp;
	} else if (pRoot->pRight == nullptr) { // 1 left child
		NODE *tmp = pRoot->pLeft;
		delete pRoot;
		pRoot = tmp;
	} else { // 2 childs
		NODE *leftmost = pRoot->pRight;
		while (leftmost->pLeft != nullptr) leftmost = leftmost->pLeft;
		pRoot->key = leftmost->key;
		Remove(pRoot->pRight, leftmost->key);
	}

	// after deletion, pRoot can be nullptr if it is leaf
	if (pRoot == nullptr) return;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(pRoot->pRight));

	if (NodeBalance(pRoot) > 1) {
		NODE *tmp = pRoot->pLeft;
		if (NodeBalance(tmp) < 0) { // if true LR, else LL
			tmp = tmp->pRight;
			leftRotate(pRoot->pLeft);
			pRoot->pLeft = tmp;
		}
		rightRotate(pRoot);
		pRoot = tmp;
		return;
	}

	if (NodeBalance(pRoot) < -1) {
		NODE *tmp = pRoot->pRight;
		if (NodeBalance(tmp) > 0) { // if true RL, else RR
			tmp = tmp->pLeft;
			rightRotate(pRoot->pRight);
			pRoot->pRight = tmp;
		}
		leftRotate(pRoot);
		pRoot = tmp;
	}
}
//////////// return node way:
NODE* rightRotate2(NODE *&pRoot) {
	NODE *child = pRoot->pLeft;
	NODE *grandchild = child->pRight;

	// rotate right
	pRoot->pLeft = grandchild;
	child->pRight = pRoot;

	pRoot->height = 1 + max(NodeHeight(grandchild), NodeHeight(pRoot->pRight));
	child->height = 1 + max(NodeHeight(pRoot), NodeHeight(child->pLeft));
	return child;
}

//     node
//    /     \             child
//        child    ->    /     \
//        /     \      node   grandchild
//   		grandchild
NODE* leftRotate2(NODE *&pRoot) {
	NODE *child = pRoot->pRight;
	NODE *grandchild = child->pLeft;

	// rotate left
	pRoot->pRight = grandchild;
	child->pLeft = pRoot;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(grandchild));
	child->height = 1 + max(NodeHeight(pRoot), NodeHeight(child->pRight));
	return child;
}

NODE* Insert2(NODE *&pRoot, int x) {
	if (pRoot == nullptr) {
		return new NODE{x, nullptr, nullptr, 0};;
	}

	if (x < pRoot->key) pRoot->pLeft = Insert2(pRoot->pLeft, x);
	else if (x > pRoot->key) pRoot->pRight = Insert2(pRoot->pRight, x);
	else return pRoot;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(pRoot->pRight));
	int balance = NodeBalance(pRoot);

	if (balance > 1 && x != pRoot->pLeft->key) {
		if (x > pRoot->pLeft->key) { // if true LR, else RR
			pRoot->pLeft = leftRotate2(pRoot->pLeft);
		}
		pRoot = rightRotate2(pRoot);
	}
	if (balance < -1 && x != pRoot->pRight->key) {
		if (x <  pRoot->pRight->key) { // if true RL, else LL
			pRoot->pRight = rightRotate2(pRoot->pRight);
			pRoot->pRight = tmp;
		}
		pRoot = leftRotate2(pRoot);
	}
}

NODE* Remove2(NODE *&pRoot, int x) {
	if (pRoot == nullptr) return;

	if (x < pRoot->key) Remove(pRoot->pLeft, x);
	else if (x > pRoot->key) Remove(pRoot->pRight, x);
	else if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr) { // leaf
		delete pRoot;
		pRoot = nullptr;
	} else if (pRoot->pLeft == nullptr) { // 1 right child
		NODE *tmp = pRoot->pRight;
		delete pRoot;
		pRoot = tmp;
	} else if (pRoot->pRight == nullptr) { // 1 left child
		NODE *tmp = pRoot->pLeft;
		delete pRoot;
		pRoot = tmp;
	} else { // 2 childs
		NODE *leftmost = pRoot->pRight;
		while (leftmost->pLeft != nullptr) leftmost = leftmost->pLeft;
		pRoot->key = leftmost->key;
		pRoot->pRight = Remove2(pRoot->pRight, leftmost->key);
	}

	// after deletion, pRoot can be nullptr if it is leaf
	if (pRoot == nullptr) return;

	pRoot->height = 1 + max(NodeHeight(pRoot->pLeft), NodeHeight(pRoot->pRight));

	if (NodeBalance(pRoot) > 1) {
		NODE *tmp = pRoot->pLeft;
		if (NodeBalance(tmp) < 0) { // if true LR, else LL
			tmp = tmp->pRight;
			leftRotate(pRoot->pLeft);
			pRoot->pLeft = tmp;
		}
		rightRotate(pRoot);
		pRoot = tmp;
		return;
	}

	if (NodeBalance(pRoot) < -1) {
		NODE *tmp = pRoot->pRight;
		if (NodeBalance(tmp) > 0) { // if true RL, else RR
			tmp = tmp->pLeft;
			rightRotate(pRoot->pRight);
			pRoot->pRight = tmp;
		}
		leftRotate(pRoot);
		pRoot = tmp;
	}
}


bool isBST(NODE *&pRoot) {
	if (pRoot == nullptr) return true;
	if (pRoot->pLeft != nullptr && pRoot->pLeft->key > pRoot->key) return false;
	if (pRoot->pRight != nullptr && pRoot->pRight->key < pRoot->key) return false;
	return isBST(pRoot->pLeft) && isBST(pRoot->pRight);
}

bool isAVL(NODE *&pRoot) {
	if (pRoot == nullptr) return true;
	if (!isBST(pRoot)) return false;
	return abs(NodeBalance(pRoot)) <= 1 && isAVL(pRoot->pLeft) && isAVL(pRoot->pRight);
}

vector<vector<int>> readAdjacencyMatrixFile(const string &filename) {
	ifstream file(filename); // Lỗi trên một số trình biên dịch, máy t không bị bao giờ nhưng máy trường bị
	ifstream file(filename.c_str()); // <- phải thêm cái này
	vector<vector<int>> matrix;
	string line;

	if (!file.is_open()) {
		cout << "Unable to open file " << filename << "\n";
		return matrix;
	}
	int size;
	file >> size;

	matrix.resize(size, vector<int>(size));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			file >> matrix[i][j];
		}
	}

	file.close();
	return matrix;
}

vector<vector<int>> convertMatrixToList(const vector<vector<int>> &matrix) {
	size_t size{matrix.size()};
	vector<vector<int>> adjList(size);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (matrix[i][j] == 1) {
				adjList[i].push_back(j);
			}
		}
	}

	return adjList;
}

void printAdjacencyList(const vector<vector<int>> &adjList) {
	for (const auto &i: adjList) {
		for (int j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

// P2
vector<vector<int>> readAdjacencyListFile(const string &filename, int &numVertices) {
	ifstream file(filename.c_str());
	vector<vector<int>> adjList;
	string line;

	if (!file.is_open()) {
		cout << "Unable to open file " << filename << "\n";
		return adjList;
	}

	file >> numVertices;
	adjList.resize(numVertices);

	for (int i = 0; i < numVertices; ++i) {
		int vertex;
		while (file >> vertex) {
			adjList[i].push_back(vertex);
			if (file.peek() == '\n') break;
		}
	}

	file.close();
	return adjList;
}

vector<vector<int>> convertListToMatrix(const vector<vector<int>> &adjList, int numVertices) {
	vector<vector<int>> matrix(numVertices, vector<int>(numVertices, 0));

	for (int i = 0; i < adjList.size(); ++i) {
		for (int j = 0; j < adjList[i].size(); ++j) {
			matrix[i][adjList[i][j]] = 1;
		}
	}

	return matrix;
}

void printAdjacencyMatrix(const vector<vector<int>> &matrix) {
	for (const auto &row: matrix) {
		for (const auto &val: row) {
			cout << val << " ";
		}
		cout << endl;
	}
}

// P3
bool isDirected(const vector<vector<int>> &matrix) {
	size_t size = matrix.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (matrix[i][j] != matrix[j][i]) {
				return true;
			}
		}
	}
	return false;
}

int countVertexes(const vector<vector<int>> &matrix) {
	return int(matrix.size());
}

int countEdges(const vector<vector<int>> &matrix) {
	int edges = 0;
	for (const auto &i: matrix) {
		for (int j: i) {
			edges += j;
		}
	}
	if (!isDirected(matrix)) {
		edges /= 2;
	}
	return edges;
}

vector<int> vertexDegrees(const vector<vector<int>> &matrix) {
	size_t size{matrix.size()};
	vector<int> degrees(size, 0);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			degrees[i] += matrix[i][j];
		}
	}
	return degrees;
}

void identifyVertices(const vector<vector<int>> &matrix, vector<int> &isolated, vector<int> &leaf) {
	vector<int> degrees = vertexDegrees(matrix);
	size_t size{degrees.size()};

	for (int i = 0; i < size; ++i) {
		if (degrees[i] == 0) {
			isolated.push_back(i);
		} else if (degrees[i] == 1) {
			leaf.push_back(i);
		}
	}
}

bool isComplete(const vector<vector<int>> &matrix) {
	size_t size{matrix.size()};
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i != j && matrix[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool isCircular(const vector<vector<int>> &matrix) {
	size_t n = matrix.size();
	vector<int> degree(n, 0);
	int edgeCount = 0;

	// count degrees and edges of each vertex
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 1) {
				degree[i]++;
				edgeCount++;
			}
		}
	}

	// check that each vertex has exactly two edges
	for (int i = 0; i < n; ++i) {
		if (degree[i] != 2) { // if any vertex doesn't have exactly 2 edges, it's not a circular graph
			return false;
		}
	}

	// Check that the total number of edges is correct
	return edgeCount == 2 * n;
}

// check if input graph is bigraph using bfs
bool isBigraph(const vector<vector<int>> &matrix) {
	size_t n = matrix.size();
	vector<int> color(n, -1);

	for (int start = 0; start < n; ++start) {
		if (color[start] == -1) {  // if not colored yet
			queue<int> q;
			q.push(start);
			color[start] = 0;

			while (!q.empty()) {
				int u = q.front();
				q.pop();

				for (int v = 0; v < n; ++v) {
					if (matrix[u][v] == 1) {
						if (color[v] == -1) {  // if not colored, color it with opposite color of previous vertex
							color[v] = 1 - color[u];
							q.push(v);
						} else if (color[v] == color[u]) {  // if already colored and same color, not bipartite
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool isCompleteBigraph(const vector<vector<int>> &matrix) {
	return isComplete(matrix) && isBigraph(matrix);
}

int countConnectedComponents(const vector<vector<int>> &matrix, vector<int> &componentSizes) {
	size_t n = matrix.size();
	vector<bool> visited(n, false);
	int components = 0;

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			components++;
			int size = 0;
			queue<int> q;
			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int v = q.front();
				q.pop();
				size++;

				for (int j = 0; j < n; ++j) {
					if (matrix[v][j] == 1 && !visited[j]) {
						q.push(j);
						visited[j] = true;
					}
				}
			}
			componentSizes.push_back(size);
		}
	}
	return components;
}

// P4
vector<vector<int>> convertToUndirected(const vector<vector<int>> &directedMatrix) {
	size_t n = directedMatrix.size();
	vector<vector<int>> undirectedMatrix = directedMatrix;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (directedMatrix[i][j] == 1) {
				undirectedMatrix[j][i] = 1;
			}
		}
	}

	return undirectedMatrix;
}

// P5
vector<vector<int>> generateComplementGraph(const vector<vector<int>> &matrix) {
	size_t n = matrix.size();
	vector<vector<int>> complementMatrix(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j && matrix[i][j] == 0) {
				complementMatrix[i][j] = 1;
			}
		}
	}

	return complementMatrix;
}

// P6
vector<vector<int>> generateConverseGraph(const vector<vector<int>> &matrix) {
	size_t n = matrix.size();
	vector<vector<int>> converseMatrix(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] == 1) {
				converseMatrix[j][i] = 1;
			}
		}
	}

	return converseMatrix;
}

// P7
vector<int> findEulerianCircuit(vector<vector<int>> &matrix, int start = 0) {
	size_t n = matrix.size();
	stack<int> currentPath;
	vector<int> circuit;

	currentPath.push(start);  // start from vertex 0
	int currentVertex = start;

	while (!currentPath.empty()) {
		if (find(matrix[currentVertex].begin(), matrix[currentVertex].end(), 1) != matrix[currentVertex].end()) {
			// ì there are remaining edges, add the current vertex to the stack and move to the next vertex
			currentPath.push(currentVertex);

			// find the next vertex with an edge
			for (int nextVertex = 0; nextVertex < n; ++nextVertex) {
				if (matrix[currentVertex][nextVertex] == 1) {
					matrix[currentVertex][nextVertex] = 0;  // remove the edge
					currentVertex = nextVertex;
					break;
				}
			}
		} else {
			// if no more edges, add the vertex to the circuit and backtrack
			circuit.push_back(currentVertex);
			currentVertex = currentPath.top();
			currentPath.pop();
		}
	}

	// the order need to be revered to be correct
	reverse(circuit.begin(), circuit.end());
	return circuit;
}

// P8
void spanning_tree_dfs(const vector<vector<int>> &matrix, vector<bool> &visited, int start) {
	stack<int> s;
	s.push(start);
	visited[start] = true;

	while (!s.empty()) {
		int v = s.top();
		s.pop();
		cout << v << " ";

		for (int i = 0; i < matrix[v].size(); ++i) {
			if (matrix[v][i] == 1 && !visited[i]) {
				s.push(i);
				visited[i] = true;
			}
		}
	}
}

void spanning_tree_bfs(const vector<vector<int>> &matrix, vector<bool> &visited, int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int i = 0; i < matrix[v].size(); ++i) {
			if (matrix[v][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {
	return 0;
}
