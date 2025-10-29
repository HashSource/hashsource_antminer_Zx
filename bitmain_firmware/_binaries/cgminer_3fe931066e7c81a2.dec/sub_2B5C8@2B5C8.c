int __fastcall sub_2B5C8(int a1, char *a2, int a3)
{
  int v6; // r7
  int v7; // r5
  int *v9; // r0
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( byte_7B380 && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "SEND: %s", a2);
    sub_38730(7, s, 0);
  }
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 728)) )
    sub_B708("stratum_send", 1893);
  if ( *(_BYTE *)(a1 + 665) )
  {
    v7 = sub_29404(a1, a2, a3);
    v6 = v7 == 0;
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 665);
    v7 = 3;
  }
  if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 728)) )
  {
    v9 = _errno_location();
    snprintf(s, 0x1000u, "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d", *v9, "util.c", "stratum_send", 1896);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  off_75ED8();
  if ( v7 == 2 )
  {
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      strcpy(s, "Failed to send in stratum_send");
      sub_38730(7, s, 0);
      sub_2AEE0(a1);
      return v6;
    }
    goto LABEL_21;
  }
  if ( v7 != 3 )
  {
    if ( v7 != 1 )
      return v6;
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(s, 0x1000u, "Write select failed on pool %d sock", *(_DWORD *)a1);
      sub_38730(7, s, 0);
    }
LABEL_21:
    sub_2AEE0(a1);
    return v6;
  }
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(s, "Stratum send failed due to no pool stratum_active");
    sub_38730(7, s, 0);
  }
  return v6;
}
