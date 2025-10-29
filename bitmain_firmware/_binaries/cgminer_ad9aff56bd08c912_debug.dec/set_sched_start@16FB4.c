char *__fastcall set_sched_start(const char *arg)
{
  const char *v1; // r1
  char *result; // r0

  LOWORD(v1) = -2952;
  HIWORD(v1) = (unsigned int)", should be HH:MM" >> 16;
  if ( sscanf(arg, v1, &schedstart.tm.tm_hour, &schedstart.tm.tm_min) == 2 )
  {
    if ( schedstart.tm.tm_hour > 0x17u || schedstart.tm.tm_min > 0x3Bu )
    {
      return "Invalid time set.";
    }
    else
    {
      schedstart.enable = 1;
      return 0;
    }
  }
  else
  {
    LOWORD(result) = -3008;
    HIWORD(result) = (unsigned int)"d duplicate share detected as HW error" >> 16;
  }
  return result;
}
