const char *__fastcall sub_14EB4(const char *a1)
{
  if ( sscanf(a1, "%d:%d", &dword_7B880, &dword_7B87C) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( dword_7B880 > 23 || dword_7B87C > 59 || dword_7B880 < 0 || dword_7B87C < 0 )
    return "Invalid time set.";
  byte_7B874 = 1;
  return 0;
}
