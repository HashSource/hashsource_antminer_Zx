int __fastcall sub_2AEE0(int a1)
{
  int v2; // r0
  int *v4; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "Closing socket for stratum pool %d", *(_DWORD *)a1);
    sub_38730(7, s, 0);
  }
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 728)) )
    sub_B708("suspend_stratum", 3354);
  sub_28AE8(a1);
  v2 = *(_DWORD *)(a1 + 612);
  *(_BYTE *)(a1 + 667) = 0;
  *(_BYTE *)(a1 + 665) = 0;
  if ( v2 )
    close(v2);
  *(_DWORD *)(a1 + 612) = 0;
  if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 728)) )
  {
    v4 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v4, "util.c", "suspend_stratum", 3356);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  return off_75ED8();
}
