// ?xfer@Rva001A78B0Xfer@@QAEXPAVXfer@@@Z
// cl: /DNDEBUG /MD /EHsc /Igame /Igame/Libraries/Include
// Retail 0x001A78B0, 329 bytes (ret 4 at +0x196). Address-derived identity: a
// versioned Xfer of a record that is not named by any caller here. Layout from
// the Xfer slots it drives: Coord3D at +0x00; a particle-system handle at +0x0c
// (the 0x008CA1 helper onto Rva0010C3E0, skipped on a CRC pass); version >= 2
// adds an unsigned at +0x10; a ThingTemplate pointer at +0x14 that is saved as
// the template's name (+0x20) and looked up again with
// BfmeThingFactory::findTemplate on load; a flag at +0x18; Coord3D at +0x1c;
// an int at +0x28; flags at +0x2c/+0x2d and a short at +0x2e.
#include "Libraries/Source/WWVegas/WWLib/ascii_string.h"

typedef bool Bool;

#include "Lib/Coord3D.h"

struct VersionA78B0 { unsigned char current; unsigned char version; };

class Xfer { public:
 virtual void pad00();
 virtual bool isLoading();
 virtual void pad02();
 virtual bool isCRC();
 virtual void pad04();
 virtual void pad05();
 virtual void pad06();
 virtual void pad07();
 virtual void pad08();
 virtual void pad09();
 virtual void version(VersionA78B0 *);
 virtual void pad11();
 virtual void pad12();
 virtual void pad13();
 virtual void pad14();
 virtual void pad15();
 virtual void pad16();
 virtual void pad17();
 virtual void pad18();
 virtual void pad19();
 virtual void pad20();
 virtual void pad21();
 virtual void pad22();
 virtual void pad23();
 virtual void coord(Coord3D *);
 virtual void pad25();
 virtual void text(AsciiString *);
 virtual void pad27();
 virtual void pad28();
 virtual void uint(unsigned int *);
 virtual void integer(int *);
 virtual void pad31();
 virtual void sshort(short *);
 virtual void pad33();
 virtual void pad34();
 virtual void boolean(bool *);
};

// StringBase<char>'s buffer header: refcount, length, capacity, data.
struct BfmeAsciiHeader
{
	int m_refCount;
	unsigned short m_length;
	unsigned short m_capacity;
	char m_data[1];
};

struct BfmeAsciiView
{
	const BfmeAsciiHeader *m_data;
};

class MidVirtualSlot90Receiver;
void Rva0010C3E0(MidVirtualSlot90Receiver *receiver, void *context);

class ThingTemplate
{
public:
	const AsciiString &getName() const { return m_nameString; }
private:
	char m_unmodelled000[0x20];
	AsciiString m_nameString;
};

class BfmeThingFactory
{
public:
	const ThingTemplate *findTemplate(const AsciiString &name);
};

extern BfmeThingFactory *TheThingFactory;

class Rva001A78B0Xfer
{
public:
	void xfer(Xfer *xfer);

	Coord3D m_position;
	void *m_effect;
	unsigned int m_flags10;
	const ThingTemplate *m_template;
	Bool m_flag18;
	Coord3D m_target;
	int m_value28;
	Bool m_flag2c;
	Bool m_flag2d;
	short m_value2e;
};

void Rva001A78B0Xfer::xfer(Xfer *xfer)
{
	VersionA78B0 v;
	v.current = 1;
	v.version = 2;
	xfer->version(&v);
	xfer->coord(&m_position);
	if (!xfer->isCRC())
		Rva0010C3E0((MidVirtualSlot90Receiver *)xfer, &m_effect);
	AsciiString name;
	if (!xfer->isLoading() && m_template)
		name = m_template->getName();
	xfer->text(&name);
	if (xfer->isLoading()) {
		const BfmeAsciiView &view = *(const BfmeAsciiView *)&name;
		if (view.m_data && view.m_data->m_length)
			m_template = TheThingFactory->findTemplate(name);
		else
			m_template = 0;
	}
	xfer->boolean(&m_flag18);
	xfer->coord(&m_target);
	xfer->integer(&m_value28);
	xfer->sshort(&m_value2e);
	xfer->boolean(&m_flag2c);
	xfer->boolean(&m_flag2d);
	if (v.version >= 2)
		xfer->uint(&m_flags10);
}
