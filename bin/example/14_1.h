/*
元编程
该示例只能以JIT模式运行
*/

import eval.h

void main()
{
	evalue('putsl 123')
	eval('putsl 123',get_cur_func,get_cur_ebp)

	a=2
	evalue('putsl a')
	evalue('a=3')
	putsl a

	putsl evalue('return 99')
	putsl eval('return eval(\'return 98\',null,0)',get_cur_func,get_cur_ebp)

	C c
	c.test 
}

class C
{
	int m_c=5
	
	void test()
	{
		putsl(get_cur_func->name)
		putsl(get_up_func->name)
		putsl(get_cur_func->ptci->name)

		evalue('putsl this.m_c')
	}
}