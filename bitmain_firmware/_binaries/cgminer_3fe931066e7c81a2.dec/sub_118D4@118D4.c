bool sub_118D4()
{
  struct tm *v0; // r0
  int v1; // r12
  int v3; // r2
  int tm_hour; // r1
  int v5; // r2
  time_t tv_sec; // [sp+4h] [bp-Ch] BYREF
  struct timeval v7; // [sp+8h] [bp-8h] BYREF

  if ( !byte_7B874 && !byte_7B5F0 )
    return 1;
  sub_2A84C(&v7);
  tv_sec = v7.tv_sec;
  v0 = localtime(&tv_sec);
  if ( !byte_7B874 )
  {
    tm_hour = v0->tm_hour;
    return tm_hour < dword_7B5FC || tm_hour == dword_7B5FC && v0->tm_min < dword_7B5F8;
  }
  if ( !byte_7B5F0 )
  {
    v1 = v0->tm_hour;
    if ( v1 >= dword_7B880 && (v1 != dword_7B880 || v0->tm_min >= dword_7B87C) )
    {
      byte_7B874 = 0;
      return 1;
    }
    return 0;
  }
  if ( dword_7B880 >= dword_7B5FC && (dword_7B880 != dword_7B5FC || dword_7B87C >= dword_7B5F8) )
  {
    v3 = v0->tm_hour;
    if ( dword_7B880 <= v3 )
    {
      if ( dword_7B880 != v3 || v0->tm_min >= dword_7B87C )
        return 1;
    }
    else if ( dword_7B5FC > v3 )
    {
      return 1;
    }
    return dword_7B5FC == v3 && v0->tm_min < dword_7B5F8;
  }
  v5 = v0->tm_hour;
  return (dword_7B5FC > v5 || dword_7B5FC == v5 && v0->tm_min < dword_7B5F8)
      && dword_7B880 <= v5
      && (dword_7B880 != v5 || v0->tm_min >= dword_7B87C);
}
