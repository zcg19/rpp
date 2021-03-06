/*
该程序只能用win_jit模式运行（Ctrl+F5）
代码来自《windows程序设计》第三章
*/

mac c_text "HelloWin"

void main()
{
	WNDCLASSA wndclass
	wndclass.style=OR(CS_HREDRAW,CS_VREDRAW)
	wndclass.lpfnWndProc=&proc_c
	wndclass.cbClsExtra=0
	wndclass.cbWndExtra=0
	wndclass.hInstance=rf.get_hins
	wndclass.hIcon=@LoadIconA(null,IDI_APPLICATION)
	wndclass.hCursor=@LoadCursorA(null,IDC_ARROW)
	wndclass.hbrBackground=@GetStockObject(WHITE_BRUSH)
	wndclass.lpszMenuName=null
	wndclass.lpszClassName=c_text
	ifn @RegisterClassA(&wndclass)
		return
	void* hwnd=@CreateWindowExA(0,c_text,c_text,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		null,null,rf.get_hins,null)
	@ShowWindow(hwnd,SW_SHOW)
	@UpdateWindow(hwnd)
	MSG msg
	while @GetMessageA(&msg,null,0,0)
		@TranslateMessage(&msg)
		@DispatchMessageA(&msg)
}

int proc(void* hwnd,int message,int wParam,int lParam)
{
	switch message
	case WM_CREATE
		return 0
	case WM_PAINT
		PAINTSTRUCT ps
		void* hdc=@BeginPaint(hwnd,&ps)
		RECT rect
		@GetClientRect(hwnd,&rect)
		@DrawTextA(hdc,c_text,-1,&rect,OR(OR(
			DT_SINGLELINE,DT_CENTER),DT_VCENTER))
		@EndPaint(hwnd,&ps)
		return 0
	case WM_DESTROY
		@PostQuitMessage(0)
		return 0
	return @DefWindowProcA(hwnd,message,wParam,lParam)
}

//C++回调RPP时需要保护寄存器，其实这段代码可用元编程自动生成
int proc_c(void* hwnd,int message,int wParam,int lParam)
{
	push ebx
	push esi
	push edi
	int ret=proc(hwnd,message,wParam,lParam)
	pop edi
	pop esi
	pop ebx
	mov eax,ret
}

struct PAINTSTRUCT
{
	void* hdc
	bool fErase
	RECT rcPaint
	bool fRestore
	bool fIncUpdate
	uchar rgbReserved[32]
}

struct MSG
{
	void* hwnd
	int message
	int wParam
	int lParam
	uint time
	POINT pt
	uint lPrivate
}

struct POINT
{
	int x
	int y
}

struct RECT
{
	int left
	int top
	int right
	int bottom
}

struct WNDCLASSA
{
	uint style
	void* lpfnWndProc
	int cbClsExtra
	int cbWndExtra
	void* hInstance
	void* hIcon
	void* hCursor
	void* hbrBackground
	char* lpszMenuName
	char* lpszClassName
}

#define CS_VREDRAW 0x0001
#define CS_HREDRAW 0x0002
#define IDI_APPLICATION 32512
#define IDC_ARROW 32512
#define WHITE_BRUSH 0
#define WS_OVERLAPPEDWINDOW 13565952
#define CW_USEDEFAULT 0x80000000
#define SW_SHOW 5
#define WM_CREATE 0x0001
#define WM_DESTROY 0x0002
#define WM_PAINT 0x000F

#define DT_CENTER 0x00000001
#define DT_RIGHT 0x00000002
#define DT_VCENTER 0x00000004
#define DT_BOTTOM 0x00000008
#define DT_WORDBREAK 0x00000010
#define DT_SINGLELINE 0x00000020