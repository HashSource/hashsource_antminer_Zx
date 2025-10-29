// Alternative name is 'should_run.part.15'
bool should_run()
{
  struct tm *v0; // r0
  _BOOL4 enable; // r4
  _BOOL4 v2; // lr
  __int64 v3; // kr00_8
  int tm_hour; // r4
  _BOOL4 v7; // lr
  _BOOL4 v8; // r1
  _BOOL4 v9; // r7
  _BOOL4 v10; // r2
  time_t tmp_time; // [sp+4h] [bp-10h] BYREF
  timeval tv; // [sp+8h] [bp-Ch] BYREF

  cgtime(&tv);
  tmp_time = tv.tv_sec;
  v0 = localtime(&tmp_time);
  enable = schedstart.enable;
  if ( schedstart.enable )
  {
    v2 = schedstop.enable;
    v3 = *(_QWORD *)&v0->tm_min;
    if ( schedstop.enable )
    {
      if ( schedstop.tm.tm_hour > schedstart.tm.tm_hour
        || (schedstop.tm.tm_min > schedstart.tm.tm_min ? (v8 = schedstop.tm.tm_hour == schedstart.tm.tm_hour) : (v8 = 0),
            v8) )
      {
        if ( schedstop.tm.tm_hour > SHIDWORD(v3)
          || (schedstop.tm.tm_min > (int)v3 ? (v2 = schedstop.tm.tm_hour == HIDWORD(v3)) : (v2 = 0), v2) )
        {
          if ( schedstart.tm.tm_hour <= SHIDWORD(v3) )
          {
            v10 = schedstart.tm.tm_min > (int)v3 && schedstart.tm.tm_hour == HIDWORD(v3);
            return !v10;
          }
          else
          {
            return 0;
          }
        }
      }
      else if ( schedstart.tm.tm_hour > SHIDWORD(v3)
             || (schedstart.tm.tm_min > (int)v3 ? (v9 = schedstart.tm.tm_hour == HIDWORD(v3)) : (v9 = 0), v9) )
      {
        if ( schedstop.tm.tm_hour <= SHIDWORD(v3) )
          return schedstop.tm.tm_min > (int)v3 && schedstop.tm.tm_hour == HIDWORD(v3);
      }
    }
    else if ( schedstart.tm.tm_hour <= SHIDWORD(v3)
           && (schedstart.tm.tm_min <= (int)v3 || schedstart.tm.tm_hour != HIDWORD(v3)) )
    {
      schedstart.enable = schedstop.enable;
      return enable;
    }
    return v2;
  }
  tm_hour = v0->tm_hour;
  if ( tm_hour < schedstop.tm.tm_hour )
    return 1;
  v7 = v0->tm_min < schedstop.tm.tm_min;
  if ( tm_hour != schedstop.tm.tm_hour )
    return 0;
  return v7;
}
