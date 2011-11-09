/*
 * =====================================================================================
 *
 *       Filename:  test_vtable_layout.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2009 06:32:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

class A {
    public:
        virtual void f() {}
};

class C : public virtual A {
    public:
        virtual void f() { }
};


int main()
{
    A * a = new C;

    return 0;
}
