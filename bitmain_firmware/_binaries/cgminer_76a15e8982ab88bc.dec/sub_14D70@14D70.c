const char *__fastcall sub_14D70(const char *a1)
{
  if ( sscanf(a1, "%d:%d", &dword_786A8, &dword_786A4) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( dword_786A8 > 23 || dword_786A4 > 59 || dword_786A8 < 0 || dword_786A4 < 0 )
    return "Invalid time set.";
  byte_7869C = 1;
  return 0;
}
