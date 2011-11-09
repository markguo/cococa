/**
 *    \file   test_class.cpp
 *    \brief  
 *    \date   2011Äê08ÔÂ31ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <stdio.h>
#include <queue>
class Parent
{ public:
	virtual void foo(){printf("Parent::foo\n");}
};

class Child: public Parent
{ public:
	virtual void foo(){printf("Child::foo\n");}
};

void f1(Parent p){p.foo();}
void f2(Parent *p){p->foo();}
void f3(Parent &p){p.foo();}
int main(int argc, char **argv)
{
    Child o;
    f1(o);
    f2(&o);
    f3(o);

    return 0;
}

struct Node{
    Node *left;
    Node *right;
};

void traverse(Node *root, void (*visit)(Node *node))
{
    std::queue<Node *> q;

    q.push(root);
    while(!q.empty())
    {
	Node *node = q.front();
	visit(q.front());
	if(node->left)
	    q.push(node->left);
	if(node->right)
	    q.push(node->right);
    }
}
