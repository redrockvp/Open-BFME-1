// cl: /O2 /MD
// retail .rdata, owned here (data_rows.csv): the AutoFindHealingUpdate vtables installed by the
// constructor at 0x00281480.  UpdateModuleInterface at 0x010BB2F0 (2 slots), BehaviorModuleInterface
// at 0x010BB300 (41 slots) and the ObjectModule primary at 0x010BB3C4 (11 slots, slot 0 the scalar
// deleting destructor).  Every slot is an ILT thunk j_XXXXXXXX (RVA = slot - 0x400000) read from
// retail bytes.
extern void j_00002aea();
extern void j_00003184();
extern void j_000031b6();
extern void j_0000493f();
extern void j_000055fb();
extern void j_000058ee();
extern void j_0000682f();
extern void j_000075e5();
extern void j_00008972();
extern void j_0000a6c3();
extern void j_0000c22f();
extern void j_0000c84c();
extern void j_0000dae4();
extern void j_0000f641();
extern void j_0000fe16();
extern void j_00011b5d();
extern void j_00014ad3();
extern void j_000153e3();
extern void j_00017521();
extern void j_00017fcb();
extern void j_0001c50d();
extern void j_0001dd45();
extern void j_0001fe06();
extern void j_00020608();
extern void j_00020b6c();
extern void j_0002260b();
extern void j_00022d59();
extern void j_00024d0c();
extern void j_00028817();
extern void j_0002b99a();
extern void j_0002c9f3();
extern void j_0002d2d6();
extern void j_0002d669();
extern void j_0002e393();
extern void j_0002f419();
extern void j_0002f879();
extern void j_000300a3();
extern void j_00033447();
extern void j_00034342();
extern void j_00036ee9();
extern void j_00038609();
extern void j_0003975c();
extern void j_0003b3ae();
extern void j_0003cdd5();
extern void j_00041821();
extern void j_00044e04();
extern void j_000451d8();
extern void j_00045bec();
extern void j_0004763b();
extern void j_00048491();
extern void j_00048ca2();
extern void j_00048d7e();
extern void j_0004985f();
extern void j_00049f94();

extern const void *const g_Va010BB2F0[] = {
	(const void *)j_0000fe16,
	(const void *)j_0004985f,
};

extern const void *const g_Va010BB300[] = {
	(const void *)j_0000a6c3,
	(const void *)j_00002aea,
	(const void *)j_00008972,
	(const void *)j_000055fb,
	(const void *)j_00036ee9,
	(const void *)j_00020608,
	(const void *)j_0003cdd5,
	(const void *)j_000153e3,
	(const void *)j_000058ee,
	(const void *)j_0000493f,
	(const void *)j_00022d59,
	(const void *)j_0002d669,
	(const void *)j_00048d7e,
	(const void *)j_00045bec,
	(const void *)j_000031b6,
	(const void *)j_00017fcb,
	(const void *)j_00034342,
	(const void *)j_0002260b,
	(const void *)j_0001fe06,
	(const void *)j_0001dd45,
	(const void *)j_00033447,
	(const void *)j_0002b99a,
	(const void *)j_0002d2d6,
	(const void *)j_0002f879,
	(const void *)j_0000dae4,
	(const void *)j_0003975c,
	(const void *)j_00044e04,
	(const void *)j_000451d8,
	(const void *)j_00003184,
	(const void *)j_0000682f,
	(const void *)j_00049f94,
	(const void *)j_00020b6c,
	(const void *)j_0002c9f3,
	(const void *)j_0002e393,
	(const void *)j_00024d0c,
	(const void *)j_0000c84c,
	(const void *)j_00038609,
	(const void *)j_0002f419,
	(const void *)j_00014ad3,
	(const void *)j_0004763b,
	(const void *)j_00017521,
};

extern const void *const g_Va010BB3C4[] = {
	(const void *)j_00048491,
	(const void *)j_00028817,
	(const void *)j_000075e5,
	(const void *)j_0001c50d,
	(const void *)j_00011b5d,
	(const void *)j_0000c22f,
	(const void *)j_0003b3ae,
	(const void *)j_00041821,
	(const void *)j_00048ca2,
	(const void *)j_000300a3,
	(const void *)j_0000f641,
};


