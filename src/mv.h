#ifndef MV_H
#define MV_H

/// remove_reference
template<typename _Tp>
  struct rm_reference
  { typedef _Tp   type; };

template<typename _Tp>
  struct rm_reference<_Tp&>
  { typedef _Tp   type; };

template<typename _Tp>
  struct rm_reference<_Tp&&>
  { typedef _Tp   type; };

template<typename _Tp>
  constexpr typename rm_reference<_Tp>::type&&
  mv(_Tp&& __t) noexcept
  { return static_cast<typename rm_reference<_Tp>::type&&>(__t); }

#endif
