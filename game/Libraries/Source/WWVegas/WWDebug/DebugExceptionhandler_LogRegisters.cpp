// cl: /DNDEBUG /MD /EHs-c- /Oy-
// Open-BFME: DebugExceptionhandler::LogRegisters, converted from the
// verified GeneralsMD debug exception implementation.

#include "windows.h"

// Retail string storage. These addresses contain separate NUL-terminated
// strings, not members of the preceding vtables in the address index.
// Match the existing declaration in GameEngine/Source/Common/BfmeConv492.cpp.
extern "C" unsigned char bfmeTextBME[];

// This TU uses the BFME Debug interface as a local ABI view.  The retail
// exception logger dispatches the unsigned-long writer at +0x28, the string
// writer at +0x38, and SetPrefixAndRadix at +0x50.  The fields used by the
// inline manipulators are at +0x9f44/+0x9f48 in the BFME object.
class Debug
{
public:
    class Hex {};
    class Dec {};
    class Bin {};

    class Width
    {
        friend class Debug;
        int m_width;

    public:
        explicit Width(int width): m_width(width) {}
    };

    class FillChar
    {
        friend class Debug;
        char m_fill;

    public:
        explicit FillChar(char fill=' '): m_fill(fill) {}
    };

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    // MSVC places this overload group in reverse declaration order.  These
    // are the retail slots +0x28 through +0x38; the three middle overloads
    // are part of the existing Debug interface and are not called here.
    virtual Debug &operator<<(const char *);
    virtual Debug &operator<<(int);
    virtual Debug &operator<<(unsigned);
    virtual Debug &operator<<(long);
    virtual Debug &operator<<(unsigned long);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void SetPrefixAndRadix(const char *, int);

    Debug &operator<<(const Hex &)
    {
        SetPrefixAndRadix("0x", 16);
        return *this;
    }

    Debug &operator<<(const Dec &)
    {
        SetPrefixAndRadix((const char *)bfmeTextBME, 10);
        return *this;
    }

    Debug &operator<<(const Bin &)
    {
        SetPrefixAndRadix("%", 2);
        return *this;
    }

    Debug &operator<<(const Width &width)
    {
        m_width = width.m_width;
        return *this;
    }

    Debug &operator<<(const FillChar &fill)
    {
        m_fillChar = fill.m_fill;
        return *this;
    }

private:
    unsigned char m_pad[0x9f40];
    int m_width;
    char m_fillChar;
};

class DebugExceptionhandler
{
    static void LogRegisters(Debug &, struct _EXCEPTION_POINTERS *);
};

// ?LogRegisters@DebugExceptionhandler@@CAXAAVDebug@@PAU_EXCEPTION_POINTERS@@@Z
void DebugExceptionhandler::LogRegisters(Debug &dbg, struct _EXCEPTION_POINTERS *exptr)
{
    struct _CONTEXT &ctx = *exptr->ContextRecord;

    dbg << Debug::FillChar('0')
        << Debug::Hex()
        << "EAX:" << Debug::Width(8) << ctx.Eax
        << " EBX:" << Debug::Width(8) << ctx.Ebx
        << " ECX:" << Debug::Width(8) << ctx.Ecx
        << "\n"
        << "EDX:" << Debug::Width(8) << ctx.Edx
        << " ESI:" << Debug::Width(8) << ctx.Esi
        << " EDI:" << Debug::Width(8) << ctx.Edi
        << "\n"
        << "EIP:" << Debug::Width(8) << ctx.Eip
        << " ESP:" << Debug::Width(8) << ctx.Esp
        << " EBP:" << Debug::Width(8) << ctx.Ebp
        << "\n"
        << "Flags:" << Debug::Bin() << Debug::Width(32) << ctx.EFlags
        << Debug::Hex() << "\n"
        << "CS:" << Debug::Width(4) << ctx.SegCs
        << " DS:" << Debug::Width(4) << ctx.SegDs
        << " SS:" << Debug::Width(4) << ctx.SegSs
        << "\nES:" << Debug::Width(4) << ctx.SegEs
        << " FS:" << Debug::Width(4) << ctx.SegFs
        << " GS:" << Debug::Width(4) << ctx.SegGs
        << "\n" << Debug::FillChar() << Debug::Dec();
}
