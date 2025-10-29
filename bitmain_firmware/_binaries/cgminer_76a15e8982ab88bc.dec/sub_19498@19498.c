int __fastcall sub_19498(int a1)
{
  int v2; // r1
  char s[4096]; // [sp+8h] [bp-1000h] BYREF

  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(
      s,
      0x1000u,
      "%s %d: invalid nonce - HW error",
      *(const char **)(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 8),
      *(_DWORD *)(*(_DWORD *)(a1 + 36) + 8));
    sub_385C8(7, s, 1);
  }
  if ( pthread_mutex_lock(&stru_77B74) )
    sub_B35C("inc_hw_errors", 8283);
  v2 = dword_786CC;
  ++*(_DWORD *)(*(_DWORD *)(a1 + 36) + 44);
  dword_786CC = v2 + 1;
  if ( pthread_mutex_unlock(&stru_77B74) )
    sub_B50C("inc_hw_errors", 8286);
  off_72D18();
  return (*(int (__fastcall **)(int))(*(_DWORD *)(*(_DWORD *)(a1 + 36) + 4) + 84))(a1);
}
