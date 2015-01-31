class double
{
	rd8 m_in;

	~double()
	{
	}

	double()
	{
	}

	double(double a)
	{
		mov esi,this
		mov [esi],[ebp+s_off a]
		mov [esi+4],[ebp+(s_off a+4)]
	}

	double(double& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
		mov [edi+4],[esi+4]
	}
	
	//这个整数转浮点很慢
	double(int a)
	{
		rstr s(a)
		rf.sscanf(s.cstr,"%lf",&this)
	}

	double(uint a)
	{
		rstr s(a)
		rf.sscanf(s.cstr,"%lf",&this)
	}
	
	double(float a)
	{
		push this
		push a
		calle "_float_to_double"
		add esp,8
	}

	int toint()
	{
		rbuf<char> buf(128)
		rf.sprintf8(buf.begin,"%.0lf",this)
		return rstr(buf.begin).toint
	}

	rstr torstr()
	{
		rstr ret(this)
		return ret
	}
	
	float tofloat()
	{
		s=torstr
		float ret
		rf.sscanf(s.cstr,"%f",&ret)
		return ret
	}
	
	friend double operator neg(double a)
	{
		return 0.0-a;
	}

	operator=(double a)
	{
		mov esi,this
		mov [esi],[ebp+s_off a]
		mov [esi+4],[ebp+(s_off a+4)]
	}

	operator=(double& a)
	{
		mov edi,this
		mov esi,a
		mov [edi],[esi]
		mov [edi+4],[esi+4]
	}

	friend operator<->(double& a,double& b)
	{
		c=a
		a=b
		b=c
	}

	operator+=(double a)
	{
		lea esi,a
		push esi
		push this
		calle "fadd8"
		add esp,8
	}

	operator-=(double a)
	{
		lea esi,a
		push esi
		push this
		calle "fsub8"
		add esp,8
	}

	operator*=(double a)
	{
		lea esi,a
		push esi
		push this
		calle "fmul8"
		add esp,8
	}
	
	operator/=(double a)
	{
		lea esi,a
		push esi
		push this
		calle "fdiv8"
		add esp,8
	}

	friend double operator+(double a,double b) 
	{
		a+=b
		return a
	}

	friend double operator-(double a,double b)
	{
		a-=b
		return a
	}

	friend double operator*(double a,double b)
	{
		a*=b
		return a
	}

	friend double operator/(double a,double b)
	{
		a/=b
		return a
	}

	friend bool operator<(double a,double b)
	{
		lea esi,b
		push esi
		lea esi,a
		push esi
		calle "fclsb8"
		mov s_ret,eax
		add esp,8
	}

	friend bool operator<=(double a,double b)
	{
		return a<b||a==b;
	}

	friend bool operator==(double a,double b)
	{
		cesb a,b
		if (ebx)
		{
			cesb [ebp+(s_off a+4)],[ebp+(s_off b+4)]
		}
		mov s_ret,ebx
	}

	friend bool operator!=(double a,double b)
	{
		return !(a==b)
	}

	friend bool operator>(double a,double b)
	{
		return b<a;
	}

	friend bool operator>=(double a,double b)
	{
		return a>b||a==b;
		//return b<=a;
	}
	
	double abs()
	{
		if this<0.0
			return 0.0-this
		return this
	}

	clear()
	{
		mov esi,this
		mov [esi],0
		mov [esi+4],0
	}

	bool empty()
	{
		return 0==this
	}

	print()
	{
		rf.print this
	}

	printl()
	{
		rf.printl this
	}
};