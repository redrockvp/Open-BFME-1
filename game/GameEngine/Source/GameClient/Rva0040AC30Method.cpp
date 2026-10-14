// ?method@Rva0040AC30Owner@@QAEXHH@Z
// Address-derived method of Rva0040AC30Owner (retail 0x0040AC30, 244 B, ret 8, void): looks up
// or creates the shared material pass in the global tree at 0x012F10DC, then allocates a
// second private pass. The retail body returns nothing, so it is a plain method rather than
// a constructor; the value reload before the flag store keeps the pass in eax.
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

// The shared tree is the four-byte-value instantiation the recorded insert_unique callee spells
// (RvaTreeInsertUniqueUnsigned.cpp); its find<unsigned> is reached through ILT 0x00005560.
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

// 0x012F10DC holds the tree instance; retail's dynamic initializer (0x00C6B3D0) constructs it, so
// the one definition of the storage is the init struct in Rva00C6B390StaticInitializers.cpp
// (shared with Rva0040AD80ReferenceState.cpp), viewed here as the tree.
struct Rva00C6B3D0Init;
extern Rva00C6B3D0Init g_rva012F10DC;

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
	Rva0040AAD0Tree::iterator it = reinterpret_cast<Rva0040AAD0Tree &>(g_rva012F10DC).find(reinterpret_cast<const unsigned int &>(a1));
	if (it == reinterpret_cast<Rva0040AAD0Tree &>(g_rva012F10DC).end())
	{
		Bfme5MaterialPass *material = new Bfme5MaterialPass(a1, a2);
		m_secondReferent = material;
		Rva0040AAD0Value value;
		*reinterpret_cast<Bfme5MaterialPass **>(&value) = material;
		reinterpret_cast<Rva0040AAD0Tree &>(g_rva012F10DC).insert_unique(Rva0040AAD0Pair(static_cast<unsigned int>(a1), value));
		Bfme5MaterialPass *reload = m_secondReferent;
		reload->m_bfme40 = 1;
	}
	else
	{
		m_secondReferent = *reinterpret_cast<Bfme5MaterialPass **>(&it->second);
		++*(int *)((char *)m_secondReferent + 4);
	}
	m_firstReferent = new Bfme5MaterialPass(a1, a2);
	m_firstReferent->m_bfme40 = 0;
	m_flag = 0;
}
