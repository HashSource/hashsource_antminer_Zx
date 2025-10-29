void __fastcall sub_455CC(int a1)
{
  int i; // r4
  int v3; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(s, 0x1000u, "%s: analog_mux_reg_value = %08x", "select_core_to_check_temperature", a1);
    sub_385C8(5, s, 0);
  }
  for ( i = 0; i != 4; ++i )
  {
    v3 = i;
    sub_4548C(v3, a1);
  }
}
