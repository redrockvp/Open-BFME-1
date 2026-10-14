// ?method@Rva0040AC30Owner@@QAEXHH@Z
// partial score=1.0 date=2026-10-14
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport

#include <map>

class MaterialPassClass
{
public:
	MaterialPassClass(void);
	virtual ~MaterialPassClass();

	char m_bfmePad[0x34];
};

extern int g_bfme5MatPassCount;

class Bfme5MaterialPass : public MaterialPassClass
{
public:
	Bfme5MaterialPass(int a, int b);
	virtual ~Bfme5MaterialPass();

	int m_bfme38;
	int m_bfme3c;
	int m_bfme40;
	int m_bfme44;
};

class State;

// The shared tree is spelled twice, as the recorded callees spell it: retail reaches its find
// through the State* instantiation's body (StateMachine.cpp) and its insert_unique through the
// four-byte-value instantiation (RvaTreeInsertUniqueUnsigned.cpp).
struct Rva0040AAD0Value
{
	char m_body[ 4 ];
};

typedef _STL::pair<const unsigned int, Rva0040AAD0Value> Rva0040AAD0Pair;
typedef _STL::_Rb_tree<unsigned int,
	Rva0040AAD0Pair,
	_STL::_Select1st<Rva0040AAD0Pair>,
	_STL::less<unsigned int>,
	_STL::allocator<Rva0040AAD0Pair> > Rva0040AAD0Tree;

typedef _STL::pair<const unsigned int, State *> Rva0040AC30Pair;
typedef _STL::_Rb_tree<unsigned int,
	Rva0040AC30Pair,
	_STL::_Select1st<Rva0040AC30Pair>,
	_STL::less<unsigned int>,
	_STL::allocator<Rva0040AC30Pair> > Rva0040AC30Tree;

extern Rva0040AC30Tree g_rva012F10DCTree;	// @0x012F10DC, shared with Rva0040AD80ReferenceState.cpp

class Rva0040AC30Owner
{
public:
	void method(int a1, int a2);

private:
	int m_prefix;
	Bfme5MaterialPass *m_firstReferent;	// +0x04 (fresh, non-tree)
	Bfme5MaterialPass *m_secondReferent;	// +0x08 (tree get-or-create)
	int m_flag;				// +0x0C
};

// Open BFME 2: Code/GameEngine/Source/GameClient/Rva0040AD80ReferenceState_Rva00362c9f.cpp
void Rva0040AC30Owner::method(int a1, int a2)
{
	Rva0040AC30Tree::iterator it = g_rva012F10DCTree.find(reinterpret_cast<const unsigned int &>(a1));
	if (it == g_rva012F10DCTree.end())
	{
		Bfme5MaterialPass *material = new Bfme5MaterialPass(a1, a2);
		m_secondReferent = material;
		Rva0040AAD0Value value;
		*reinterpret_cast<Bfme5MaterialPass **>(&value) = material;
		reinterpret_cast<Rva0040AAD0Tree &>(g_rva012F10DCTree).insert_unique(Rva0040AAD0Pair(static_cast<unsigned int>(a1), value));
		Bfme5MaterialPass *reload = m_secondReferent;
		reload->m_bfme40 = 1;
	}
	else
	{
		m_secondReferent = reinterpret_cast<Bfme5MaterialPass *>(it->second);
		++*(int *)((char *)m_secondReferent + 4);
	}
	m_firstReferent = new Bfme5MaterialPass(a1, a2);
	m_firstReferent->m_bfme40 = 0;
	m_flag = 0;
}
