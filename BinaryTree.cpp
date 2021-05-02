#include<iostream>
using namespace std;
#include<fstream>

// Kh?i t?o c�y nh? ph�n t�m ki?m c�c s? nguy�n
// khai b�o c?u tr�c 1 c�i node
struct node
{
	int data;
	node *pLeft;
	node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// h�m th�m node v�o c�y
void ThemNode(TREE &t, int x)
{
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		// th�m node p sang b�n nh�nh tr�i
		if (x < t->data)
		{
			ThemNode(t->pLeft, x);
		}
		else if (x > t->data)
		{
			ThemNode(t->pRight, x);
		}
	}
}

// duy?t NLR
void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "  ";
		NLR(t->pLeft);
		NLR(t->pRight);
	}
}

// duy?t NRL
void NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << "  ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}


// duy?t LNR
void LNR(TREE t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data << "  ";
		LNR(t->pRight);		
	}
}
// duy?t RNL
void RNL(TREE t)
{
	if (t != NULL)
	{
		RNL(t->pRight);
		cout << t->data << "  ";
		RNL(t->pLeft);
	}
}

// duy?t LRN
void LRN(TREE t)
{
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->data << "  ";		
	}
}

// duy?t RLN
void RLN(TREE t)
{
	if (t != NULL)
	{
		RLN(t->pRight);
		RLN(t->pLeft);		
		cout << t->data << "  ";
	}
}

// h�m d?c file
void Doc_File(TREE &t, ifstream &filein)
{
	int n;
	filein >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		filein >> x;
		ThemNode(t, x);
	}
}

// h�m d?c file
void Doc_File_1(TREE &t, ifstream &filein)
{
	while (true)
	{
		int x;
		filein >> x;
		ThemNode(t, x);
		char c;
		filein >> c;
		if (filein.eof() == true)
		{
			break;
		}
	}
}

// h�m xu?t c�c node l�
void Xuat_Node_La(TREE t)
{
	if (t != NULL)
	{
		// x? l� c�i node hi?n t?i
		if (t->pLeft == NULL && t->pRight == NULL)
		{
			cout << t->data << "  ";
		}
		Xuat_Node_La(t->pLeft);
		Xuat_Node_La(t->pRight);
	}
}

// h�m xu?t c�c node c� 1 con
void Xuat_Node_1_Con(TREE t)
{
	if (t != NULL)
	{
		// x? l� c�i node hi?n t?i
		if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
		{
			cout << t->data << "  ";
		}
		Xuat_Node_1_Con(t->pLeft);
		Xuat_Node_1_Con(t->pRight);
	}
}

void Xuat_Node_2_Con(TREE t)
{
	if (t != NULL)
	{
		// x? l� c�i node hi?n t?i
		if (t->pLeft != NULL && t->pRight != NULL)
		{
			cout << t->data << "  ";
		}
		Xuat_Node_2_Con(t->pLeft);
		Xuat_Node_2_Con(t->pRight);
	}
}

// t�m ph?n t? l?n nh?t c?a c�y
int Tim_Max(TREE t)
{
	if (t->pRight != NULL)
	{
		Tim_Max(t->pRight);
	}
	else
	{
		return t->data;
	}
}

int main()
{
	TREE t;
	t = NULL; // kh?i t?o c�y

	/*ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	Doc_File(t, filein);*/

	ifstream filein;
	filein.open("INPUT.TXT", ios_base::in);
	Doc_File_1(t, filein);
	
	cout << "\nXuat cay theo dang NLR: ";
	NLR(t);

	cout << "\n\tNODE LA\n ";
	Xuat_Node_La(t);
	cout << "\n\tNODE 1 CON\n ";
	Xuat_Node_1_Con(t);
	cout << "\n\tNODE 2 CON\n ";
	Xuat_Node_2_Con(t);
	cout << "\n\n\t\t MAX: " << Tim_Max(t);

	filein.close();
	

	system("pause");
	return 0;
}
