/**
 *    \file   test_delete_const_pointer.cpp
 *    \brief  
 *    \date   2011Äê05ÔÂ22ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */


class A
{

};

int main()
{
    const A * a = new A();

    delete a;
}
