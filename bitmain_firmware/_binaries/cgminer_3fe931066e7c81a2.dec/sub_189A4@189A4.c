int __fastcall sub_189A4(int a1)
{
  int v2; // r1
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(
      s,
      0x1000u,
      "%s %d: invalid nonce - HW error",
      *(const char **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 8),
      *(_DWORD *)(*(_DWORD *)(a1 + 36) + 8));
    sub_38730(7, s, 1);
  }
  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("inc_hw_errors", 8296);
  v2 = dword_7B8A4;
  ++*(_DWORD *)(*(_DWORD *)(a1 + 36) + 44);
  dword_7B8A4 = v2 + 1;
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("inc_hw_errors", 8299);
  off_75ED8();
  return (*(int (__fastcall **)(int))(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 84))(a1);
}
