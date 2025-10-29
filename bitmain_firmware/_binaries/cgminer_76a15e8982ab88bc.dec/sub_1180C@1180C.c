bool sub_1180C()
{
  struct tm *v0; // r0
  int v1; // r12
  int v3; // r2
  int tm_hour; // r1
  int v5; // r2
  time_t tv_sec; // [sp+4h] [bp-Ch] BYREF
  struct timeval v7; // [sp+8h] [bp-8h] BYREF

  if ( !byte_7869C && !byte_78418 )
    return 1;
  sub_2A7A4(&v7);
  tv_sec = v7.tv_sec;
  v0 = localtime(&tv_sec);
  if ( !byte_7869C )
  {
    tm_hour = v0->tm_hour;
    return tm_hour < dword_78424 || tm_hour == dword_78424 && v0->tm_min < dword_78420;
  }
  if ( !byte_78418 )
  {
    v1 = v0->tm_hour;
    if ( v1 >= dword_786A8 && (v1 != dword_786A8 || v0->tm_min >= dword_786A4) )
    {
      byte_7869C = 0;
      return 1;
    }
    return 0;
  }
  if ( dword_786A8 >= dword_78424 && (dword_786A8 != dword_78424 || dword_786A4 >= dword_78420) )
  {
    v3 = v0->tm_hour;
    if ( dword_786A8 <= v3 )
    {
      if ( dword_786A8 != v3 || v0->tm_min >= dword_786A4 )
        return 1;
    }
    else if ( dword_78424 > v3 )
    {
      return 1;
    }
    return dword_78424 == v3 && v0->tm_min < dword_78420;
  }
  v5 = v0->tm_hour;
  return (dword_78424 > v5 || dword_78424 == v5 && v0->tm_min < dword_78420)
      && dword_786A8 <= v5
      && (dword_786A8 != v5 || v0->tm_min >= dword_786A4);
}
