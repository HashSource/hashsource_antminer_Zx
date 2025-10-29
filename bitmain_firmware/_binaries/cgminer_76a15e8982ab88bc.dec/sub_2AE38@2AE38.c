int __fastcall sub_2AE38(int a1)
{
  int v2; // r0
  int *v4; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "Closing socket for stratum pool %d", *(_DWORD *)a1);
    sub_385C8(7, s, 0);
  }
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 728)) )
    sub_B650("suspend_stratum", 3335);
  sub_28A40(a1);
  v2 = *(_DWORD *)(a1 + 612);
  *(_BYTE *)(a1 + 667) = 0;
  *(_BYTE *)(a1 + 665) = 0;
  if ( v2 )
    close(v2);
  *(_DWORD *)(a1 + 612) = 0;
  if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 728)) )
  {
    v4 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v4, "util.c", "suspend_stratum", 3337);
    sub_385C8(3, s, 1);
    sub_16BE0(1);
  }
  return off_72D18();
}
