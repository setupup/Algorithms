/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 
HuffmanTree
*/
#include <iostream>
using namespace std;
template<class Type>
class Huffman{
	friend BinaryTree<int> HuffmanTree(Type[], int);
public:
	operator Type() const
	{
		return weight;
	}
private:
	BinaryTree<int> tree;
	Type weight;
};
template<class Type>
BinaryTree<int> HuffmanTree(Type f[], int n)
{
	Huffman<Type>* w = new Huffman<Type>[n + 1];
	BinaryTree<int> z, zero;
	for (int i = 1; i <= n; i++)
	{
		z.MakeTree(i, zero, zero);
		w[i].weight = f[i];
		w[i].tree = z;
	}
	//initial the priority queue
	MinHeap<Huffman<Type>> Q(1);
	Q.Initialize(w, n, n);
	Huffman<Type> x, y;
	for (int i = 1; i < n; i++)
	{
		Q.DeleteMin(x);
		Q.DeleteMin(y);
		z.MakeTree(0, x.tree, y.tree);
		x.weight += y.weight;
		x.tree = z;
		Q.Insert(x);
	}
	Q.DeleteMin(x);
	Q.Deactive();
	delete[] w;
	return x.tree;
}
int main(int argc, char* argv[])
{

}