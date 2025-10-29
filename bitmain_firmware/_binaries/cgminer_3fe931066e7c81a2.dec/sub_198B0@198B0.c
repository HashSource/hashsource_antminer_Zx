int __fastcall sub_198B0(int a1, int a2)
{
  int v4; // r1
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(
      s,
      0x1000u,
      "%s%d: invalid nonce - HW error",
      *(const char **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 8),
      *(_DWORD *)(*(_DWORD *)(a1 + 36) + 8));
    sub_38730(7, s, 0);
  }
  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("inc_hw_errors_with_diff", 8309);
  v4 = dword_7B8A4;
  *(_DWORD *)(*(_DWORD *)(a1 + 36) + 44) += a2;
  dword_7B8A4 = v4 + a2;
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("inc_hw_errors_with_diff", 8312);
  off_75ED8();
  return (*(int (__fastcall **)(int))(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 84))(a1);
}
