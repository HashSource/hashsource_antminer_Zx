const char *__fastcall sub_14E38(const char *a1)
{
  if ( sscanf(a1, "%d:%d", &dword_7B5FC, &dword_7B5F8) != 2 )
    return "Invalid time set, should be HH:MM";
  if ( dword_7B5FC > 23 || dword_7B5F8 > 59 || dword_7B5FC < 0 || dword_7B5F8 < 0 )
    return "Invalid time set.";
  byte_7B5F0 = 1;
  return 0;
}
