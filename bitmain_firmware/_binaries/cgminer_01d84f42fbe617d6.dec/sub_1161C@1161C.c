bool sub_1161C()
{
  struct tm *v0; // r0
  int v1; // r12
  int v3; // r2
  int tm_hour; // r1
  int v5; // r2
  time_t tv_sec; // [sp+4h] [bp-Ch] BYREF
  struct timeval v7; // [sp+8h] [bp-8h] BYREF

  if ( !byte_63E14 && !byte_63B90 )
    return 1;
  sub_2B13C(&v7);
  tv_sec = v7.tv_sec;
  v0 = localtime(&tv_sec);
  if ( !byte_63E14 )
  {
    tm_hour = v0->tm_hour;
    return tm_hour < dword_63B9C || tm_hour == dword_63B9C && v0->tm_min < dword_63B98;
  }
  if ( !byte_63B90 )
  {
    v1 = v0->tm_hour;
    if ( v1 >= dword_63E20 && (v1 != dword_63E20 || v0->tm_min >= dword_63E1C) )
    {
      byte_63E14 = 0;
      return 1;
    }
    return 0;
  }
  if ( dword_63E20 >= dword_63B9C && (dword_63E20 != dword_63B9C || dword_63E1C >= dword_63B98) )
  {
    v3 = v0->tm_hour;
    if ( dword_63E20 <= v3 )
    {
      if ( dword_63E20 != v3 || v0->tm_min >= dword_63E1C )
        return 1;
    }
    else if ( dword_63B9C > v3 )
    {
      return 1;
    }
    return dword_63B9C == v3 && v0->tm_min < dword_63B98;
  }
  v5 = v0->tm_hour;
  return (dword_63B9C > v5 || dword_63B9C == v5 && v0->tm_min < dword_63B98)
      && dword_63E20 <= v5
      && (dword_63E20 != v5 || v0->tm_min >= dword_63E1C);
}
