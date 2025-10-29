const char *__fastcall sub_14DEC(const char *a1)
{
  if ( sscanf(a1, "%d:%d", &dword_78424, &dword_78420) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( dword_78424 > 23 || dword_78420 > 59 || dword_78424 < 0 || dword_78420 < 0 )
    return "Invalid time set.";
  byte_78418 = 1;
  return 0;
}
