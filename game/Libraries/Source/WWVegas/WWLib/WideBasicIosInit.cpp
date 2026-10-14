// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport

// STLport basic_ios<wchar_t>::init, retail 0x0083F9B0.  Wide twin of the
// char body in stlport_basic_ios_init.cpp, but this TU sees the
// no-exceptions ios_base::_M_throw_failure (fputs("ios failure", stderr))
// inline, so the failure report is expanded in place.

#include <istream>
#include <ostream>
#include <stdio.h>

namespace _STL {
inline void ios_base::_M_throw_failure()
{
  const char *__arg = "ios failure";
  fputs(__arg, stderr);
}
}

// The existing retail imbue provider owns the locale/cache update.
template <>
_STL::locale
_STL::basic_ios<wchar_t, _STL::char_traits<wchar_t> >::imbue(const _STL::locale &);

template void
_STL::basic_ios<wchar_t, _STL::char_traits<wchar_t> >::init(
    _STL::basic_streambuf<wchar_t, _STL::char_traits<wchar_t> > *);
