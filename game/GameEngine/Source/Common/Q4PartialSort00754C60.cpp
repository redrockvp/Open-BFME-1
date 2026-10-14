// ??$__partial_sort@PAHHUQ4Sort00755050@@@_STL@@YAXPAH000UQ4Sort00755050@@@Z
// Open-BFME5: STLport __partial_sort over a four-byte scalar with
// Q4Sort00755050, retail 0x00754C60, 121 bytes.  Sibling of the
// Q4Sort0034BFC0/Q4Sort004566F0/Q4Sort004567A0 instantiations; own TU so
// Q4IntrosortLoop.cpp's matched rows stay put.
//
// Identity: the 140-byte __introsort_loop Q4Sort00755050 body in
// Q4IntrosortLoop.cpp calls this address.  The heap callees (make_heap at
// 0x00753DD0, __adjust_heap at 0x007538A0, sort_heap at 0x007547E0) are the
// matched Q4Cmp00753DD0 instantiations, and the comparator call goes through
// the ILT thunk to the 0x00752B80 operator().
//
// The comparator is copied into a local before the heap calls: that one copy
// makes MSVC 7.1 keep the comparator word in ebp and reload `last`, as retail
// does, where passing the by-value parameter straight through left it in a
// transient register.  The copy has the heap callees' comparator type.
//
// cl: -GX-
// stlport

struct Q4Sort00755050
{
	void *m_state;
	bool operator()(int, int) const;
};

struct Q4Cmp00753DD0 { void *m_state; };
struct Q3HeapCompare { void *m_state; };
void Rva00753DD0(int **first, int **last, Q3HeapCompare compare);

namespace _STL
{

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __adjust_heap(RandomAccessIterator first, Distance holeIndex,
	Distance len, Tp val, Compare comp);

template <class RandomAccessIterator, class Compare>
void sort_heap(RandomAccessIterator first, RandomAccessIterator last,
	Compare comp);

template <class RandomAccessIterator, class Tp, class Compare>
void __partial_sort(RandomAccessIterator first, RandomAccessIterator middle,
	RandomAccessIterator last, Tp *, Compare comp)
{
	Q4Cmp00753DD0 c;
	c.m_state = comp.m_state;
	// The matched cdecl heap builder reads the first three dwords; retail
	// also pushes two unused STL tag arguments.
	reinterpret_cast<void (__cdecl *)(RandomAccessIterator, RandomAccessIterator,
		Q4Cmp00753DD0, Tp *, int *)>(&Rva00753DD0)(first, middle, c, (Tp *)0, (int *)0);
	for (RandomAccessIterator i = middle; i < last; ++i)
	{
		if (comp(*i, *first))
		{
			Tp item = *i;
			*i = *first;
			__adjust_heap(first, 0, (int)(middle - first), item, c);
		}
	}
	sort_heap(first, middle, c);
}

template void __partial_sort<int *, int, Q4Sort00755050>(
	int *, int *, int *, int *, Q4Sort00755050);

}
