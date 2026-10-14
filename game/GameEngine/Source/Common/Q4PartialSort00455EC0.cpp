// ??$__partial_sort@PAHHUQ4Sort004567A0@@@_STL@@YAXPAH000UQ4Sort004567A0@@@Z
// Open-BFME5: STLport __partial_sort over a four-byte scalar with
// Q4Sort004567A0, retail 0x00455EC0, 121 bytes.  Sibling of the other
// Q4Sort partial-sort instantiations (Q4PartialSort00754C60.cpp); own TU so
// Q4IntrosortLoop.cpp's matched rows stay put.
//
// Identity: the 140-byte __introsort_loop Q4Sort004567A0 body in Q4IntrosortLoop.cpp
// calls this address.  Its callees in body order are the matched heap
// builder 00453C20 (Rva00453C20), the Q4Sort004567A0 comparator behind
// 0x00451E90, the matched Q4Sort004567A0 __adjust_heap at 0x00453290 and the
// matched Q4Sort004567A0 sort_heap at 0x004546F0.
//
// The comparator is copied into a local of the heap callees' comparator type
// before the heap calls: that one copy makes MSVC 7.1 keep the comparator
// word in ebp and reload `last`, as retail does, where passing the by-value
// parameter straight through left it in a transient register.
//
// cl: -GX-
// stlport

struct Q4Sort004567A0
{
	void *m_state;
	bool operator()(int, int) const;
};

struct Q3HeapCompare { void *m_state; };
void Rva00453C20(int **first, int **last, Q3HeapCompare compare);

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
	Q4Sort004567A0 c;
	c.m_state = comp.m_state;
	// The matched cdecl heap builder reads the first three dwords; retail
	// also pushes two unused STL tag arguments.
	reinterpret_cast<void (__cdecl *)(RandomAccessIterator, RandomAccessIterator,
		Q4Sort004567A0, Tp *, int *)>(&Rva00453C20)(first, middle, c, (Tp *)0, (int *)0);
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

template void __partial_sort<int *, int, Q4Sort004567A0>(
	int *, int *, int *, int *, Q4Sort004567A0);

}

