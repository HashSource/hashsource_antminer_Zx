int __fastcall api_get_eeprom_fmt_version(int a1)
{
  if ( dword_185698[0] && *(_BYTE *)(dword_185698[0] + 80) )
    return *(unsigned __int8 *)(*(_DWORD *)(dword_185698[0] + 4 * dword_185698[a1 + 2]) + 2);
  sub_AEEE0();
  return 0;
}
