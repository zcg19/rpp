namespace rff
{
	void* fopen_w(wchar* name,wchar* mode)
	{
		push mode
		push name
		rn invoke _wfopen
		add esp,8
		mov s_ret,eax
	}
	
	int remove_w(wchar* name)
	{
		push name
		rn invoke _wremove
		mov s_ret,eax
		add esp,4
	}
	
	int rename_w(wchar* oldname,wchar* newname)
	{
		push newname
		push oldname
		rn invoke _wrename
		mov s_ret,eax
		add esp,8
	}

	void* fopen(char* name,char* mode)
	{
		push mode
		push name
		rn invoke fopen
		add esp,8
		mov s_ret,eax
	}
	
	int fclose(void* fp)
	{
		push fp
		rn invoke fclose
		add esp,4
		mov s_ret,eax
	}
	
	int fread(char* data,int size,int count,void* fp)
	{
		push fp
		push count
		push size
		push data
		rn invoke fread
		add esp,16
		mov s_ret,eax
	}
	
	int fwrite(char* data,int size,int count,void* fp)
	{
		push fp
		push count
		push size
		push data
		rn invoke fwrite
		add esp,16
		mov s_ret,eax
	}
	
	void fseek(void* fp,int off,int origin)
	{
		push origin
		push off
		push fp
		rn invoke fseek
		add esp,12
	}
	
	void fseek8(void* fp,int8 off,int origin)
	{
		fseek(fp,off.toint,origin)
		/*push origin
		push [ebp+(s_off off+4)]
		push off
		push fp
		rn invoke _fseeki64
		add esp,16*/
	}
	
	int ftell(void* fp)
	{
		push fp
		rn invoke ftell
		mov s_ret,eax
		add esp,4
	}
	
	int8 ftell8(void* fp)
	{
		return ftell(fp)
		/*push fp
		rn invoke _ftelli64
		mov s_ret,eax
		mov [ebp+(s_off s_ret+4)],edx
		add esp,4*/
	}
}