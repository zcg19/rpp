//import "chs.h"

#include "rp.h"
#include "char.h"
#include "int.h"
#include "uint.h"

#include "short.h"
#include "ushort.h"
#include "float.h"
#include "var.h"

#include "rbuf.h"
#include "rstr.h"
#include "rstrw.h"

#include "func.h"
#include "new.h"

#ifdef _JIT
#include "int8_j.h"
#include "double_j.h"
#include "rf_j.h"
#include "rff_j.h"
#include "rcode_n.h"
#include "rmutex_j.h"
#endif

#ifdef _RVM
#include "int8.h"
#include "double.h"
#include "rf.h"
#include "rff.h"
#include "rcode.h"
#include "rmutex.h"
#endif

#ifdef _WIN
#include "int8_n.h"
#include "double_n.h"
#include "rf_n.h"
#include "rff_n.h"
#include "rcode_n.h"
#include "rmutex_n.h"
#endif

#ifdef _GRUB
#include "int8_n.h"
#include "double_n.h"
#include "rf_g.h"
#include "rcode_n.h"
#endif

#include "ralgo.h"

//#define var rt
#define vector rbuf
#define string rstr
#define bool int
#define rbool int
#define long int8
#define int64 int8
#define uchar char
#define wchar ushort

#define true 1
#define false 0

#define null 0p
#define NULL 0p

#define elif else if
#define while for
#define default else
#define namespace friend class
#define goto jmp
#define struct class
#define static friend
#define const
#define inline
#define asm
#define auto
#define then
#define volatile
#define register
#define signed
#define unsigned
#define operator

#define <- =
#define <> !=
#define :: .

#define puts rf.print
#define putsl rf.printl
#define getsl rf.scanl
#define findf rf.find_func

//与do...while相反
mac until(a)
{
	if(a)
	{
		break;
	}
}