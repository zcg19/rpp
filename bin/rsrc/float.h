class float
{
	rd4 m_in
	
	~float()
	{
	}

	float()
	{
	}

	float(float a)
	{
		mov esi,[esp+4]
		mov [esi],[esp+8]
	}

	float(float& a)
	{
		mov edi,[esp+4]
		mov esi,[esp+8]
		mov [edi],[esi]
	}
	
	double todouble()
	{
		return double(this)
	}
	
	void operator=(float a)
	{
		mov esi,[esp+4]
		mov [esi],[esp+8]
	}

	void operator=(float& a)
	{
		mov edi,[esp+4]
		mov esi,[esp+8]
		mov [edi],[esi]
	}
	
	void operator=(double a)
	{
		this=a.tofloat
	}
}