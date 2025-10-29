bool is_power_protocal_v2()
{
  bool v0; // cc

  v0 = (unsigned int)dword_185768 > 0x62;
  if ( dword_185768 != 98 )
    v0 = (unsigned int)(dword_185768 - 100) > 2;
  return !v0;
}
