int __fastcall sub_2282C(int a1, int a2)
{
  int v5; // r7
  int v6; // r8
  int v7; // r7
  const char *v8; // lr
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int *v13; // lr
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r1
  int v19; // r2
  int v20; // r9
  struct timeval v21; // [sp+0h] [bp-808h] BYREF
  _DWORD v22[10]; // [sp+8h] [bp-800h] BYREF
  __int16 v23; // [sp+30h] [bp-7D8h]

  if ( byte_615C9 || dword_612AC )
    return 0;
  if ( *(_DWORD *)(a1 + 336) != dword_6136C )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      strcpy((char *)v22, "Work stale due to block mismatch");
      sub_38438(7, (const char *)v22, 0);
      return 1;
    }
    return 1;
  }
  v5 = *(_DWORD *)(a1 + 276);
  v6 = *(_DWORD *)(a1 + 260);
  if ( v5 <= dword_60090 )
    v5 = dword_60094;
  if ( !a2 && *(_BYTE *)(v6 + 632) )
  {
    if ( !*(_BYTE *)(v6 + 633) || !*(_BYTE *)(v6 + 635) )
    {
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        strcpy((char *)v22, "Work stale due to stratum inactive");
        sub_38438(7, (const char *)v22, 0);
        return 1;
      }
      return 1;
    }
    if ( pthread_mutex_lock((pthread_mutex_t *)(v6 + 212)) )
      sub_B4E4("stale_work", 4917);
    if ( pthread_rwlock_rdlock((pthread_rwlock_t *)(v6 + 236)) )
      sub_B76C("stale_work", 4917);
    if ( pthread_mutex_unlock((pthread_mutex_t *)(v6 + 212)) )
      sub_B694("stale_work", 4917);
    v20 = strcmp(*(const char **)(a1 + 288), *(const char **)(v6 + 640));
    if ( pthread_rwlock_unlock((pthread_rwlock_t *)(v6 + 236)) )
      sub_B700("stale_work", 4920);
    off_60178();
    if ( v20 )
    {
      if ( !byte_630C1 || !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
        return 1;
      v8 = "Work stale due to stratum job_id mismatch";
LABEL_42:
      v9 = *(_DWORD *)v8;
      v10 = *((_DWORD *)v8 + 1);
      v11 = *((_DWORD *)v8 + 2);
      v12 = *((_DWORD *)v8 + 3);
      v13 = (int *)(v8 + 16);
      v22[0] = v9;
      v22[1] = v10;
      v22[2] = v11;
      v22[3] = v12;
      v14 = *v13;
      v15 = v13[1];
      v16 = v13[2];
      v17 = v13[3];
      v13 += 4;
      v22[4] = v14;
      v22[5] = v15;
      v22[6] = v16;
      v22[7] = v17;
      v18 = v13[1];
      v19 = v13[2];
      v22[8] = *v13;
      v22[9] = v18;
      v23 = v19;
      sub_38438(7, (const char *)v22, 0);
      return 1;
    }
  }
  v7 = v5 - (int)(*(double *)(v6 + 440) * 5.0 + 1.0);
  sub_2B13C(&v21);
  if ( v7 < 5 )
    v7 = 5;
  if ( v21.tv_sec - *(_DWORD *)(a1 + 264) >= v7 )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      strcpy((char *)v22, "Work stale due to expiry");
      sub_38438(7, (const char *)v22, 0);
      return 1;
    }
    return 1;
  }
  if ( byte_63BC5 && !a2 && v6 != sub_1D644() && !*(_BYTE *)(a1 + 282) && dword_611AC != 3 && dword_611AC != 4 )
  {
    if ( !byte_630C1 || !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
      return 1;
    v8 = "Work stale due to fail only pool mismatch";
    goto LABEL_42;
  }
  return 0;
}
