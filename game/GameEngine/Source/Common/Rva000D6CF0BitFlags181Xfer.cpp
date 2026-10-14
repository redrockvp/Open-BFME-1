// ?xfer@Rva000D6CF0BitFlags@@QAEXPAVXfer@@@Z
// cl: /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Igame
// Retail 0x000D6CF0, 476-byte extent ending on the _CxxThrowException call
// plus its throw-site INT3. The 181-bit KindOf-sized named transfer: name table
// VA 0x012AA068 (TheKindOfBitNames, 181 names) and the 24-byte bitset (0x18)
// counted through the byte table g_bfmeTableDH. Same algorithm and Xfer slot
// usage as the byte-matched sibling 0x001CB270 (Rva001CB270BitFlagsXfer.cpp);
// the light-CRC path calls BitFlags<181>::xfer at 0x000D3DF0. The name lookup
// is BitFlags<181>::getSingleBitFromName at 0x000CB330 through ILT 0x0004AFFC.
// Address-derived identity: no owner of the table is proven here.
// stlport
#include <bitset>
#include "Libraries/Source/WWVegas/WWLib/ascii_string.h"

struct XferException { char *text; int tag; };
extern "C" XferException *__cdecl bfmeFormatText(XferException *,int,const char *,...);
extern void __declspec(noreturn) __stdcall _CxxThrowException(void *,void *);
extern int g_guardTargetTypeThrowInfo;

struct __declspec(align(4)) Version000D6CF0 { unsigned char version,current; };

class Xfer { public:
 virtual void pad00();
 virtual void pad04();
 virtual bool save();
 virtual void pad0C();
 virtual bool crc();
 virtual void pad14();
 virtual void pad18();
 virtual void pad1C();
 virtual void pad20();
 virtual void pad24();
 virtual void version(Version000D6CF0 *);
 virtual void pad2C();
 virtual void pad30();
 virtual void pad34();
 virtual void pad38();
 virtual void pad3C();
 virtual void pad40();
 virtual void pad44();
 virtual void pad48();
 virtual void pad4C();
 virtual void pad50();
 virtual void pad54();
 virtual void pad58();
 virtual void pad5C();
 virtual void pad60();
 virtual void pad64();
 virtual void text(AsciiString *);
 virtual void pad6C();
 virtual void pad70();
 virtual void pad74();
 virtual void integer(int *);
};

template<int N> class BitFlags { public:
 _STL::bitset<N> bits;
 void xfer(Xfer *);
 static int getSingleBitFromName(const char *);
};

extern const char *TheKindOfBitNames[];

class Rva000D6CF0BitFlags { _STL::bitset<181> bits; public: void xfer(Xfer *xfer); };

void Rva000D6CF0BitFlags::xfer(Xfer *xfer)
{
 Version000D6CF0 v; v.version=1; v.current=1;
 xfer->version(&v);
 if (xfer->crc()) { ((BitFlags<181> *)this)->xfer(xfer); return; }
 if (xfer->save()) {
  int count=bits.count();
  xfer->integer(&count);
  for (int i=0;i<181;++i) {
   if (bits._Unchecked_test(i) && TheKindOfBitNames[i]) {
    AsciiString name(TheKindOfBitNames[i]);
    xfer->text(&name);
    --count;
   }
  }
 } else {
  bits.reset();
  int count;
  xfer->integer(&count);
  AsciiString name;
  for (int i=0;i<count;++i) {
   xfer->text(&name);
   int bit=BitFlags<181>::getSingleBitFromName(name.str());
   if (bit<0) {
    XferException error;
    bfmeFormatText(&error,0,0);
    _CxxThrowException(&error,&g_guardTargetTypeThrowInfo);
   }
   bits._Unchecked_set(bit);
  }
 }
}
