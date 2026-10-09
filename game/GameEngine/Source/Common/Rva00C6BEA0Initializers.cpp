// cl: /O2 /MD
// Address-derived initialization routine: INT3 / MOV [absolute], address / RET / INT3.
// The source-pointer globals below are the names dir32_addresses.csv records
// for these addresses, as the FXParticleSystem TUs that read them declare them.
namespace FXParticleSystem {
	extern void **defaultModuleTag6SourceAt4;	// retail 0x012F6C98
	extern void **defaultModuleTag6SourceAt8;	// retail 0x012F6C9C
	extern void **streakDrawSourceAt8;	// retail 0x012F6CA0
	extern void **streakDrawSourceAt4;	// retail 0x012F6CA4
	extern void **quadDrawSourceAt8;	// retail 0x012F6CA8
	extern void **quadDrawSourceAt4;	// retail 0x012F6CAC
	extern void **butterflyDrawSourceAt8;	// retail 0x012F6CB0
	extern void **butterflyDrawSourceAt4;	// retail 0x012F6CB4
	extern void **renderObjectDrawSourceAt8;	// retail 0x012F6CB8
	extern void **renderObjectDrawSourceAt4;	// retail 0x012F6CBC
	extern void **lightningDrawSourceAt8;	// retail 0x012F6CC0
	extern void **lightningDrawSourceAt4;	// retail 0x012F6CC4
	extern void **defaultModuleTag1SourceAt4;	// retail 0x012F6CD0
	extern void **defaultModuleTag1SourceAt8;	// retail 0x012F6CD4
	extern void **defaultModuleTag0SourceAt4;	// retail 0x012F6CE0
	extern void **defaultModuleTag0SourceAt8;	// retail 0x012F6CE4
	extern void **defaultModuleTag3SourceAt4;	// retail 0x012F6CF0
	extern void **defaultModuleTag3SourceAt8;	// retail 0x012F6CF4
	extern void **defaultModuleTag2SourceAt4;	// retail 0x012F6D00
	extern void **defaultModuleTag2SourceAt8;	// retail 0x012F6D04
	extern void **defaultModuleTag7SourceAt4;	// retail 0x012F6D10
	extern void **defaultModuleTag7SourceAt8;	// retail 0x012F6D14
	extern void **lifeEventSourceAt8;	// retail 0x012F6D18
	extern void **lifeEventSourceAt4;	// retail 0x012F6D1C
	extern void **renderObjectUpdateSourceAt8;	// retail 0x012F6D20
	extern void **renderObjectUpdateSourceAt4;	// retail 0x012F6D24
	extern void **terrainCollisionSourceAt8;	// retail 0x012F6D28
	extern void **terrainCollisionSourceAt4;	// retail 0x012F6D2C
	extern void **orthoEmissionVelocitySourceAt4;	// retail 0x012F6D30
	extern void **orthoEmissionVelocitySourceAt8;	// retail 0x012F6D34
	extern void **sphericalEmissionVelocitySourceAt8;	// retail 0x012F6D38
	extern void **sphericalEmissionVelocitySourceAt4;	// retail 0x012F6D3C
	extern void **hemisphericalEmissionVelocitySourceAt8;	// retail 0x012F6D40
	extern void **hemisphericalEmissionVelocitySourceAt4;	// retail 0x012F6D44
	extern void **cylindricalEmissionVelocitySourceAt8;	// retail 0x012F6D48
	extern void **cylindricalEmissionVelocitySourceAt4;	// retail 0x012F6D4C
	extern void **outwardEmissionVelocitySourceAt8;	// retail 0x012F6D50
	extern void **outwardEmissionVelocitySourceAt4;	// retail 0x012F6D54
	extern void **pointEmissionVolumeSourceAt4;	// retail 0x012F6D58
	extern void **pointEmissionVolumeSourceAt8;	// retail 0x012F6D5C
	extern void **lineEmissionVolumeSourceAt8;	// retail 0x012F6D60
	extern void **lineEmissionVolumeSourceAt4;	// retail 0x012F6D64
	extern void **boxEmissionVolumeSourceAt8;	// retail 0x012F6D68
	extern void **boxEmissionVolumeSourceAt4;	// retail 0x012F6D6C
	extern void **sphereEmissionVolumeSourceAt8;	// retail 0x012F6D70
	extern void **sphereEmissionVolumeSourceAt4;	// retail 0x012F6D74
	extern void **cylinderEmissionVolumeSourceAt8;	// retail 0x012F6D78
	extern void **cylinderEmissionVolumeSourceAt4;	// retail 0x012F6D7C
	extern void **lightningEmissionSourceAt8;	// retail 0x012F6D80
	extern void **lightningEmissionSourceAt4;	// retail 0x012F6D84
}

extern void *Rva00EF6C90;
void Rva00C6BED0() { FXParticleSystem::defaultModuleTag6SourceAt4 = &Rva00EF6C90; }

namespace FXParticleSystem {
template<int N> struct DefaultModuleKey {
private: static const char *GetValue();
public: static const char *Read() { return GetValue(); }
};
template<int N> struct DefaultModuleName {
private: static const char *GetValue();
public: static const char *Read() { return GetValue(); }
};
}
extern "C" int __cdecl atexit(void (__cdecl *)());
void Rva00C70430SetGlobal();


// 0x00C6BEA0: independent INT3-bounded initializer.
void Rva00C6BEA0() { atexit(Rva00C70430SetGlobal); }


// 0x00C6BEB0: independent INT3-bounded initializer.
void Rva00C6BEB0() { Rva00EF6C90 = (void *)FXParticleSystem::DefaultModuleKey<6>::Read(); }

extern void *Rva00EF6C94;
// 0x00C6BEC0: independent INT3-bounded initializer.
void Rva00C6BEC0() { Rva00EF6C94 = (void *)FXParticleSystem::DefaultModuleName<6>::Read(); }

// 0x00C6BEE0: independent INT3-bounded initializer.
void Rva00C6BEE0() { FXParticleSystem::defaultModuleTag6SourceAt8 = (void **)&Rva00EF6C94; }

extern char Rva00D139F4;
// 0x00C6BEF0: independent INT3-bounded initializer.
void Rva00C6BEF0() { FXParticleSystem::streakDrawSourceAt8 = (void **)&Rva00D139F4; }

extern char Rva00D139F8;
// 0x00C6BF00: independent INT3-bounded initializer.
void Rva00C6BF00() { FXParticleSystem::streakDrawSourceAt4 = (void **)&Rva00D139F8; }

extern char Rva00D1375C;
// 0x00C6BF10: independent INT3-bounded initializer.
void Rva00C6BF10() { FXParticleSystem::quadDrawSourceAt8 = (void **)&Rva00D1375C; }

extern char Rva00D13760;
// 0x00C6BF20: independent INT3-bounded initializer.
void Rva00C6BF20() { FXParticleSystem::quadDrawSourceAt4 = (void **)&Rva00D13760; }

extern char Rva00D13540;
// 0x00C6BF30: independent INT3-bounded initializer.
void Rva00C6BF30() { FXParticleSystem::butterflyDrawSourceAt8 = (void **)&Rva00D13540; }

extern char Rva00D13544;
// 0x00C6BF40: independent INT3-bounded initializer.
void Rva00C6BF40() { FXParticleSystem::butterflyDrawSourceAt4 = (void **)&Rva00D13544; }

extern char Rva00D13798;
// 0x00C6BF50: independent INT3-bounded initializer.
void Rva00C6BF50() { FXParticleSystem::renderObjectDrawSourceAt8 = (void **)&Rva00D13798; }

extern char Rva00D1379C;
// 0x00C6BF60: independent INT3-bounded initializer.
void Rva00C6BF60() { FXParticleSystem::renderObjectDrawSourceAt4 = (void **)&Rva00D1379C; }

extern char Rva00D13670;
// 0x00C6BF70: independent INT3-bounded initializer.
void Rva00C6BF70() { FXParticleSystem::lightningDrawSourceAt8 = (void **)&Rva00D13670; }

extern char Rva00D13674;
// 0x00C6BF80: independent INT3-bounded initializer.
void Rva00C6BF80() { FXParticleSystem::lightningDrawSourceAt4 = (void **)&Rva00D13674; }

extern void *Rva00EF6CC8;
// 0x00C6BF90: independent INT3-bounded initializer.
void Rva00C6BF90() { Rva00EF6CC8 = (void *)FXParticleSystem::DefaultModuleKey<1>::Read(); }

extern void *Rva00EF6CCC;
// 0x00C6BFA0: independent INT3-bounded initializer.
void Rva00C6BFA0() { Rva00EF6CCC = (void *)FXParticleSystem::DefaultModuleName<1>::Read(); }

// 0x00C6BFB0: independent INT3-bounded initializer.
void Rva00C6BFB0() { FXParticleSystem::defaultModuleTag1SourceAt4 = (void **)&Rva00EF6CC8; }

// 0x00C6BFC0: independent INT3-bounded initializer.
void Rva00C6BFC0() { FXParticleSystem::defaultModuleTag1SourceAt8 = (void **)&Rva00EF6CCC; }

extern void *Rva00EF6CD8;
// 0x00C6BFD0: independent INT3-bounded initializer.
void Rva00C6BFD0() { Rva00EF6CD8 = (void *)FXParticleSystem::DefaultModuleKey<0>::Read(); }

extern void *Rva00EF6CDC;
// 0x00C6BFE0: independent INT3-bounded initializer.
void Rva00C6BFE0() { Rva00EF6CDC = (void *)FXParticleSystem::DefaultModuleName<0>::Read(); }

// 0x00C6BFF0: independent INT3-bounded initializer.
void Rva00C6BFF0() { FXParticleSystem::defaultModuleTag0SourceAt4 = (void **)&Rva00EF6CD8; }

// 0x00C6C000: independent INT3-bounded initializer.
void Rva00C6C000() { FXParticleSystem::defaultModuleTag0SourceAt8 = (void **)&Rva00EF6CDC; }

extern void *Rva00EF6CE8;
// 0x00C6C010: independent INT3-bounded initializer.
void Rva00C6C010() { Rva00EF6CE8 = (void *)FXParticleSystem::DefaultModuleKey<3>::Read(); }

extern void *Rva00EF6CEC;
// 0x00C6C020: independent INT3-bounded initializer.
void Rva00C6C020() { Rva00EF6CEC = (void *)FXParticleSystem::DefaultModuleName<3>::Read(); }

// 0x00C6C030: independent INT3-bounded initializer.
void Rva00C6C030() { FXParticleSystem::defaultModuleTag3SourceAt4 = (void **)&Rva00EF6CE8; }

// 0x00C6C040: independent INT3-bounded initializer.
void Rva00C6C040() { FXParticleSystem::defaultModuleTag3SourceAt8 = (void **)&Rva00EF6CEC; }

extern void *Rva00EF6CF8;
// 0x00C6C050: independent INT3-bounded initializer.
void Rva00C6C050() { Rva00EF6CF8 = (void *)FXParticleSystem::DefaultModuleKey<2>::Read(); }

extern void *Rva00EF6CFC;
// 0x00C6C060: independent INT3-bounded initializer.
void Rva00C6C060() { Rva00EF6CFC = (void *)FXParticleSystem::DefaultModuleName<2>::Read(); }

// 0x00C6C070: independent INT3-bounded initializer.
void Rva00C6C070() { FXParticleSystem::defaultModuleTag2SourceAt4 = (void **)&Rva00EF6CF8; }

// 0x00C6C080: independent INT3-bounded initializer.
void Rva00C6C080() { FXParticleSystem::defaultModuleTag2SourceAt8 = (void **)&Rva00EF6CFC; }

extern void *Rva00EF6D08;
// 0x00C6C090: independent INT3-bounded initializer.
void Rva00C6C090() { Rva00EF6D08 = (void *)FXParticleSystem::DefaultModuleKey<7>::Read(); }

extern void *Rva00EF6D0C;
// 0x00C6C0A0: independent INT3-bounded initializer.
void Rva00C6C0A0() { Rva00EF6D0C = (void *)FXParticleSystem::DefaultModuleName<7>::Read(); }

// 0x00C6C0B0: independent INT3-bounded initializer.
void Rva00C6C0B0() { FXParticleSystem::defaultModuleTag7SourceAt4 = (void **)&Rva00EF6D08; }

// 0x00C6C0C0: independent INT3-bounded initializer.
void Rva00C6C0C0() { FXParticleSystem::defaultModuleTag7SourceAt8 = (void **)&Rva00EF6D0C; }

extern char Rva00D143E8;
// 0x00C6C0D0: independent INT3-bounded initializer.
void Rva00C6C0D0() { FXParticleSystem::lifeEventSourceAt8 = (void **)&Rva00D143E8; }

extern char Rva00D143EC;
// 0x00C6C0E0: independent INT3-bounded initializer.
void Rva00C6C0E0() { FXParticleSystem::lifeEventSourceAt4 = (void **)&Rva00D143EC; }

extern char Rva00D149E0;
// 0x00C6C0F0: independent INT3-bounded initializer.
void Rva00C6C0F0() { FXParticleSystem::renderObjectUpdateSourceAt8 = (void **)&Rva00D149E0; }

extern char Rva00D149E4;
// 0x00C6C100: independent INT3-bounded initializer.
void Rva00C6C100() { FXParticleSystem::renderObjectUpdateSourceAt4 = (void **)&Rva00D149E4; }

extern char Rva00D144B4;
// 0x00C6C110: independent INT3-bounded initializer.
void Rva00C6C110() { FXParticleSystem::terrainCollisionSourceAt8 = (void **)&Rva00D144B4; }

extern char Rva00D144B8;
// 0x00C6C120: independent INT3-bounded initializer.
void Rva00C6C120() { FXParticleSystem::terrainCollisionSourceAt4 = (void **)&Rva00D144B8; }

extern char Rva00D13EF8;
// 0x00C6C130: independent INT3-bounded initializer.
void Rva00C6C130() { FXParticleSystem::orthoEmissionVelocitySourceAt4 = (void **)&Rva00D13EF8; }

extern char Rva00D13EFC;
// 0x00C6C140: independent INT3-bounded initializer.
void Rva00C6C140() { FXParticleSystem::orthoEmissionVelocitySourceAt8 = (void **)&Rva00D13EFC; }

extern char Rva00D14088;
// 0x00C6C150: independent INT3-bounded initializer.
void Rva00C6C150() { FXParticleSystem::sphericalEmissionVelocitySourceAt8 = (void **)&Rva00D14088; }

extern char Rva00D1408C;
// 0x00C6C160: independent INT3-bounded initializer.
void Rva00C6C160() { FXParticleSystem::sphericalEmissionVelocitySourceAt4 = (void **)&Rva00D1408C; }

extern char Rva00D13D7C;
// 0x00C6C170: independent INT3-bounded initializer.
void Rva00C6C170() { FXParticleSystem::hemisphericalEmissionVelocitySourceAt8 = (void **)&Rva00D13D7C; }

extern char Rva00D13D80;
// 0x00C6C180: independent INT3-bounded initializer.
void Rva00C6C180() { FXParticleSystem::hemisphericalEmissionVelocitySourceAt4 = (void **)&Rva00D13D80; }

extern char Rva00D13B3C;
// 0x00C6C190: independent INT3-bounded initializer.
void Rva00C6C190() { FXParticleSystem::cylindricalEmissionVelocitySourceAt8 = (void **)&Rva00D13B3C; }

extern char Rva00D13B40;
// 0x00C6C1A0: independent INT3-bounded initializer.
void Rva00C6C1A0() { FXParticleSystem::cylindricalEmissionVelocitySourceAt4 = (void **)&Rva00D13B40; }

extern char Rva00D13F8C;
// 0x00C6C1B0: independent INT3-bounded initializer.
void Rva00C6C1B0() { FXParticleSystem::outwardEmissionVelocitySourceAt8 = (void **)&Rva00D13F8C; }

extern char Rva00D13F90;
// 0x00C6C1C0: independent INT3-bounded initializer.
void Rva00C6C1C0() { FXParticleSystem::outwardEmissionVelocitySourceAt4 = (void **)&Rva00D13F90; }

extern char Rva00D14020;
// 0x00C6C1D0: independent INT3-bounded initializer.
void Rva00C6C1D0() { FXParticleSystem::pointEmissionVolumeSourceAt4 = (void **)&Rva00D14020; }

extern char Rva00D14024;
// 0x00C6C1E0: independent INT3-bounded initializer.
void Rva00C6C1E0() { FXParticleSystem::pointEmissionVolumeSourceAt8 = (void **)&Rva00D14024; }

extern char Rva00D13DD4;
// 0x00C6C1F0: independent INT3-bounded initializer.
void Rva00C6C1F0() { FXParticleSystem::lineEmissionVolumeSourceAt8 = (void **)&Rva00D13DD4; }

extern char Rva00D13DD8;
// 0x00C6C200: independent INT3-bounded initializer.
void Rva00C6C200() { FXParticleSystem::lineEmissionVolumeSourceAt4 = (void **)&Rva00D13DD8; }

extern char Rva00D13A34;
// 0x00C6C210: independent INT3-bounded initializer.
void Rva00C6C210() { FXParticleSystem::boxEmissionVolumeSourceAt8 = (void **)&Rva00D13A34; }

extern char Rva00D13A38;
// 0x00C6C220: independent INT3-bounded initializer.
void Rva00C6C220() { FXParticleSystem::boxEmissionVolumeSourceAt4 = (void **)&Rva00D13A38; }

extern char Rva00D14100;
// 0x00C6C230: independent INT3-bounded initializer.
void Rva00C6C230() { FXParticleSystem::sphereEmissionVolumeSourceAt8 = (void **)&Rva00D14100; }

extern char Rva00D14104;
// 0x00C6C240: independent INT3-bounded initializer.
void Rva00C6C240() { FXParticleSystem::sphereEmissionVolumeSourceAt4 = (void **)&Rva00D14104; }

extern char Rva00D13C4C;
// 0x00C6C250: independent INT3-bounded initializer.
void Rva00C6C250() { FXParticleSystem::cylinderEmissionVolumeSourceAt8 = (void **)&Rva00D13C4C; }

extern char Rva00D13C50;
// 0x00C6C260: independent INT3-bounded initializer.
void Rva00C6C260() { FXParticleSystem::cylinderEmissionVolumeSourceAt4 = (void **)&Rva00D13C50; }

extern char Rva00D14268;
// 0x00C6C270: independent INT3-bounded initializer.
void Rva00C6C270() { FXParticleSystem::lightningEmissionSourceAt8 = (void **)&Rva00D14268; }

extern char Rva00D1426C;
// 0x00C6C280: independent INT3-bounded initializer.
void Rva00C6C280() { FXParticleSystem::lightningEmissionSourceAt4 = (void **)&Rva00D1426C; }


// 0x00C6C290: independent INT3-bounded initializer.
void Rva00C6C290() { Rva00EF6C90 = (void *)FXParticleSystem::DefaultModuleKey<6>::Read(); }


// 0x00C6C2A0: independent INT3-bounded initializer.
void Rva00C6C2A0() { Rva00EF6C94 = (void *)FXParticleSystem::DefaultModuleName<6>::Read(); }


// 0x00C6C2B0: independent INT3-bounded initializer.
void Rva00C6C2B0() { FXParticleSystem::defaultModuleTag6SourceAt4 = (void **)&Rva00EF6C90; }


// 0x00C6C2C0: independent INT3-bounded initializer.
void Rva00C6C2C0() { FXParticleSystem::defaultModuleTag6SourceAt8 = (void **)&Rva00EF6C94; }
