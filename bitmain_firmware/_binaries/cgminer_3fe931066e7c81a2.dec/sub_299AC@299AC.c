int __fastcall sub_299AC(int a1, _DWORD *a2, unsigned int a3)
{
  unsigned int v5; // r1
  char *v6; // r5
  size_t v8; // r3
  void *v9; // r0
  size_t v10; // r6
  _BYTE *v11; // r0
  int v12; // r3
  int *v13; // r0
  int *v14; // r0
  int *v15; // r0
  char s[4096]; // [sp+10h] [bp-1000h] BYREF

  v5 = a3;
  if ( a3 )
    v5 = 1;
  v6 = sub_292F4(a2, v5);
  if ( !v6 )
    return 0;
  if ( pthread_mutex_lock((pthread_mutex_t *)(a1 + 244)) )
    sub_B708("parse_extranonce_equihash", 2522);
  if ( pthread_rwlock_wrlock((pthread_rwlock_t *)(a1 + 268)) )
  {
    v15 = _errno_location();
    snprintf(
      s,
      0x1000u,
      "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",
      *v15,
      "util.c",
      "parse_extranonce_equihash",
      2522);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  free(*(void **)(a1 + 636));
  *(_DWORD *)(a1 + 636) = v6;
  v8 = strlen(v6) >> 1;
  v9 = *(void **)(a1 + 640);
  *(_DWORD *)(a1 + 1588) = v8;
  free(v9);
  v10 = *(_DWORD *)(a1 + 1588);
  v11 = calloc(v10, 1u);
  *(_DWORD *)(a1 + 640) = v11;
  if ( !v11 )
  {
    snprintf(
      s,
      0x1000u,
      "%s: Failed to calloc pool->nonce1bin in %s %s():%d",
      "parse_extranonce_equihash",
      "util.c",
      "parse_extranonce_equihash",
      2530);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  sub_29830(v11, *(unsigned __int8 **)(a1 + 636), v10);
  v12 = 64 - *(_DWORD *)(a1 + 1588);
  *(_QWORD *)(a1 + 648) = 0;
  *(_DWORD *)(a1 + 656) = v12;
  if ( pthread_rwlock_unlock((pthread_rwlock_t *)(a1 + 268)) )
  {
    v14 = _errno_location();
    snprintf(
      s,
      0x1000u,
      "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v14,
      "util.c",
      "parse_extranonce_equihash",
      2536);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  if ( pthread_mutex_unlock((pthread_mutex_t *)(a1 + 244)) )
  {
    v13 = _errno_location();
    snprintf(
      s,
      0x1000u,
      "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",
      *v13,
      "util.c",
      "parse_extranonce_equihash",
      2536);
    sub_38730(3, s, 1);
    sub_16CA8(1);
  }
  off_75ED8();
  if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 5 )
    return 1;
  snprintf(s, 0x1000u, "Pool %d extranonce set to %s", *(_DWORD *)a1, v6);
  sub_38730(6, s, 0);
  return 1;
}
