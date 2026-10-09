// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// AptPalantir's one-time callback registration.  The callback names and
// handlers are retained from the retail string/data cross-references; the
// address-derived registration thunks are named directly at the call sites, as
// retail reaches them through ILT thunks.

#include "../../../../inputs/reference/shims/stringinline/StringInline.h"

class BFMERetailAsciiString
{
public:
	BFMERetailAsciiString( const char *text );
	~BFMERetailAsciiString() { releaseBuffer(); }

private:
	void releaseBuffer();
	void *m_data;
};

typedef void (__cdecl *BannerAptCallback)();

class BannerAptCallbackHolder
{
public:
	BannerAptCallbackHolder( BannerAptCallback callback );

private:
	void *m_callback;
};

struct PalantirFunctorSlot
{
	PalantirFunctorSlot( void *slot ) : m_slot( slot ) {}

	void *m_slot;
};

class PalantirFunctorWrapperHead
{
public:
	PalantirFunctorWrapperHead() : m_refCount( 0 ) {}
	virtual void anchor();

	unsigned int m_refCount;
};

class PalantirCallbackWrapper : public PalantirFunctorWrapperHead
{
public:
	__forceinline PalantirCallbackWrapper( const PalantirFunctorSlot &slot )
		: m_slot( slot ) {}

	PalantirFunctorSlot m_slot;
};

class PalantirCallbackHolder
{
public:
	__forceinline PalantirCallbackHolder( const PalantirFunctorSlot &binding )
	{
		m_ptr = new PalantirCallbackWrapper( binding );
		if( m_ptr != 0 )
			m_ptr->m_refCount++;
	}

	PalantirCallbackWrapper *m_ptr;
};

class PalantirPlayerSideWrapper : public PalantirFunctorWrapperHead
{
public:
	__forceinline PalantirPlayerSideWrapper( const PalantirFunctorSlot &slot )
		: m_slot( slot ) {}

	PalantirFunctorSlot m_slot;
};

class PalantirPlayerSideHolder
{
public:
	__forceinline PalantirPlayerSideHolder( const PalantirFunctorSlot &binding )
	{
		m_ptr = new PalantirPlayerSideWrapper( binding );
		if( m_ptr != 0 )
			m_ptr->m_refCount++;
	}

	PalantirPlayerSideWrapper *m_ptr;
};

class WindowManager
{
public:
	#define WINDOW_MANAGER_SLOT( n ) virtual void windowManagerSlot##n() = 0
	WINDOW_MANAGER_SLOT( 0 ); WINDOW_MANAGER_SLOT( 1 ); WINDOW_MANAGER_SLOT( 2 );
	WINDOW_MANAGER_SLOT( 3 ); WINDOW_MANAGER_SLOT( 4 ); WINDOW_MANAGER_SLOT( 5 );
	WINDOW_MANAGER_SLOT( 6 ); WINDOW_MANAGER_SLOT( 7 ); WINDOW_MANAGER_SLOT( 8 );
	WINDOW_MANAGER_SLOT( 9 ); WINDOW_MANAGER_SLOT( 10 ); WINDOW_MANAGER_SLOT( 11 );
	WINDOW_MANAGER_SLOT( 12 ); WINDOW_MANAGER_SLOT( 13 ); WINDOW_MANAGER_SLOT( 14 );
	#undef WINDOW_MANAGER_SLOT
	virtual int loadAptWindow( AsciiString directory, AsciiString file,
		int unknown1, int unknown2, int unknown3 ) = 0;
	void registerAptCallback( const BFMERetailAsciiString &name,
		BannerAptCallbackHolder callback );
};

// Retail calls these three registration entry points through ILT thunks, so the
// call sites name the thunks directly instead of a member of WindowManager.
extern void j_00043ad6();
extern void j_00026328();
extern void j_0003a0bc();

extern WindowManager *g_rva012F19E8WindowManager;

// Globals the retail image holds at fixed addresses.  dir32_addresses.csv
// records the names below for these addresses; none of them is a literal
// cast any more, so the linked build resolves them by name.
extern unsigned char g_aptPalantirCallbacksRegistered;					// retail 0x012F4AFC
extern unsigned char g_aptPalantirShowRequested;		// retail 0x012F4AFD
extern unsigned char g_aptPalantirCloseRequested;							// retail 0x012F4AFE
extern const char *volatile g_012B7D7C;	// retail 0x012B7D7C, player-side name; volatile keeps retail's eax load
extern int g_aptPalantirWindow;						// retail 0x012B7D80
extern unsigned char g_aptPalantirClosed;		// retail 0x012B7D84

// retail 0x012F4B00: ?TheBfmeObject_00C701F0@@3VGen_00C701F0Target@@A
class Gen_00C701F0Target;
extern Gen_00C701F0Target TheBfmeObject_00C701F0;

// Apt callback entry points, reached through the ILT addresses noted.  Each
// thunk jumps to the matched body of the same name.  The player-side functor
// has no recorded name, so it keeps its address.
struct PalantirPoint;
void aptPalantirOnInitialized();	// ILT retail 0x0041F62C, OnInitialized
void aptPalantirOnClosed();	// ILT retail 0x00434022, OnClosed
void aptPalantirOnButtonAlert( char *command );	// ILT retail 0x004127BA, OnBttnAlert
void aptPalantirOnButtonCommand( char *command );	// ILT retail 0x00401942, OnBttnCommand
void aptPalantirOnRollOverButtonCommand();	// ILT retail 0x00420428, OnRollOverBttnCommand
void aptPalantirOnButtonSkillUpgrade();	// ILT retail 0x0043B0C5, OnBttnSkillUpgrade
void aptPalantirOnButtonSpell( char *command );	// ILT retail 0x0043F6E8, OnBttnSpell
void aptPalantirOnButtonSpellStore();	// ILT retail 0x00441597, OnBttnSpellStore
void aptPalantirOnButtonOptions();	// ILT retail 0x00448C07, OnBttnOptions
void aptPalantirOnButtonHeroSelect( char *command );	// ILT retail 0x0044A606, OnBttnHeroSelect
void aptPalantirOnSpellBookUIShown();	// ILT retail 0x0042F01D, OnSpellBookUIShown
void aptPalantirOnRegionPortraitClosed( void *portrait );	// ILT retail 0x0041CFF3, OnRegionPortraitClosed
void g_00415253();		// retail 0x00415253, player-side functor
void aptPalantirRenderRadar( const PalantirPoint *, const PalantirPoint * );	// ILT retail 0x00444544, RenderRadar functor
void aptPalantirRenderRadarViewBox();	// ILT retail 0x00419501, RenderRadarViewBox functor
void aptPalantirClipRadar( const PalantirPoint *, const PalantirPoint * );	// ILT retail 0x0043E4E6, ClipRadar functor
void aptPalantirRenderMovie( const PalantirPoint *, const PalantirPoint * );	// ILT retail 0x0041A0F0, RenderMovie functor
void aptPalantirRenderGlobe( const PalantirPoint *, const PalantirPoint * );	// ILT retail 0x0042D09C, RenderGlobe functor

void d_00565f30()
{
	if( g_rva012F19E8WindowManager == 0 || g_aptPalantirCallbacksRegistered != 0 )
		return;

	int windowIndex = g_rva012F19E8WindowManager->loadAptWindow(
		"Apt\\",
		*reinterpret_cast<AsciiString *>( &TheBfmeObject_00C701F0 ), 0, 0, -1 );
	g_aptPalantirWindow = windowIndex;
	if( windowIndex == -1 )
		return;

	typedef void (WindowManager::*SetupPalantirFn)();
	union { void (*fn)(); SetupPalantirFn call; } setupPalantir = { j_00043ad6 };
	(g_rva012F19E8WindowManager->*setupPalantir.call)();

	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnInitialized" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnInitialized ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnClosed" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnClosed ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnAlert" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonAlert ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnCommand" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonCommand ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnRollOverBttnCommand" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnRollOverButtonCommand ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnSkillUpgrade" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonSkillUpgrade ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnSpell" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonSpell ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnSpellStore" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonSpellStore ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnOptions" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonOptions ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnBttnHeroSelect" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnButtonHeroSelect ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnSpellBookUIShown" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnSpellBookUIShown ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::OnRegionPortraitClosed" );
		g_rva012F19E8WindowManager->registerAptCallback( name,
			reinterpret_cast<BannerAptCallback>( &aptPalantirOnRegionPortraitClosed ) );
	}

	{
		const char *playerSide = g_012B7D7C;
		BFMERetailAsciiString name( playerSide );
		typedef void (WindowManager::*RegisterPalantirPlayerSideFn)(
			const BFMERetailAsciiString &, int, PalantirPlayerSideHolder );
		union { void (*fn)(); RegisterPalantirPlayerSideFn call; }
			registerPalantirPlayerSide = { j_0003a0bc };
		(g_rva012F19E8WindowManager->*registerPalantirPlayerSide.call)( name, 0,
			PalantirFunctorSlot( reinterpret_cast<void *>( &g_00415253 ) ) );
	}

	typedef void (WindowManager::*RegisterPalantirCallbackFn)(
		const BFMERetailAsciiString &, PalantirCallbackHolder );
	union { void (*fn)(); RegisterPalantirCallbackFn call; }
		registerPalantirCallback = { j_00026328 };

	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::RenderRadar" );
		(g_rva012F19E8WindowManager->*registerPalantirCallback.call)( name,
			PalantirFunctorSlot( reinterpret_cast<void *>( &aptPalantirRenderRadar ) ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::RenderRadarViewBox" );
		(g_rva012F19E8WindowManager->*registerPalantirCallback.call)( name,
			PalantirFunctorSlot( reinterpret_cast<void *>( &aptPalantirRenderRadarViewBox ) ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::ClipRadar" );
		(g_rva012F19E8WindowManager->*registerPalantirCallback.call)( name,
			PalantirFunctorSlot( reinterpret_cast<void *>( &aptPalantirClipRadar ) ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::RenderMovie" );
		(g_rva012F19E8WindowManager->*registerPalantirCallback.call)( name,
			PalantirFunctorSlot( reinterpret_cast<void *>( &aptPalantirRenderMovie ) ) );
	}
	if( g_rva012F19E8WindowManager )
	{
		BFMERetailAsciiString name( "AptPalantir::RenderGlobe" );
		(g_rva012F19E8WindowManager->*registerPalantirCallback.call)( name,
			PalantirFunctorSlot( reinterpret_cast<void *>( &aptPalantirRenderGlobe ) ) );
	}

	g_aptPalantirShowRequested = 0;
	g_aptPalantirCloseRequested = false;
	g_aptPalantirClosed = 1;
	g_aptPalantirCallbacksRegistered = 1;
}
