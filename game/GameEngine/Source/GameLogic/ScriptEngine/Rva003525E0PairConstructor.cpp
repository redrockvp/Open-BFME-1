// cl: /DNDEBUG /MD /EHsc
// ??0Rva003525E0Pair@@QAE@PBURva003525E0Source@@@Z
// Address-derived constructor (retail 0x003525E0, 200 B, ret 4): deep-copies two optional script
// nodes from a source pair. The first copy is a plain new-expression; the second sits in a
// catch(...) that frees the first node (its held item through ScriptPoolObject::deleteInstance,
// then operator delete) and rethrows. The 160-byte gen_asm extent stopped before the catch tail;
// the FuncInfo at the constructor's handler stub and the ret 4 + int3 padding give the 200 bytes.

class ScriptPoolObject
{
public:
	void deleteInstance(int);
};

struct Rva00350380Item;
struct Rva00350410Item;

class Rva00350380Node
{
public:
	Rva00350380Node(const Rva00350380Node &src);
	~Rva00350380Node() { if (m_item) ((ScriptPoolObject *)m_item)->deleteInstance(1); }

	Rva00350380Item *m_item;
	int m_b;
	int m_c;
};

class Rva00350410Node
{
public:
	Rva00350410Node(const Rva00350410Node &src);

	Rva00350410Item *m_item;
	int m_b;
	int m_c;
};

struct Rva003525E0Source
{
	Rva00350380Node *m_first;
	Rva00350410Node *m_second;
};

class Rva003525E0Pair
{
public:
	Rva003525E0Pair(const Rva003525E0Source *src);

	Rva00350380Node *m_first;
	Rva00350410Node *m_second;
};

Rva003525E0Pair::Rva003525E0Pair(const Rva003525E0Source *src)
{
	Rva00350380Node *first;
	if (src->m_first)
	{
		first = new Rva00350380Node(*src->m_first);
	}
	else
		first = 0;
	m_first = first;

	try
	{
		Rva00350410Node *second;
		if (src->m_second)
		{
			second = new Rva00350410Node(*src->m_second);
		}
		else
			second = 0;
		m_second = second;
	}
	catch (...)
	{
		delete m_first;
		throw;
	}
}
