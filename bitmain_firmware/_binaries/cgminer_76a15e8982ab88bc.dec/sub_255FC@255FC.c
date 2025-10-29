void __fastcall sub_255FC(int a1)
{
  _DWORD *v2; // r5
  int v3; // r6
  double v4; // d16
  double v5; // d16
  double v6; // d17
  double v7; // d16
  int v8; // r2
  double v9; // d18
  double v10; // d16
  double v11; // d17
  double v12; // d16
  pthread_t v13; // [sp+Ch] [bp-1008h] BYREF
  char s[4100]; // [sp+10h] [bp-1004h] BYREF

  if ( !*(_DWORD *)(a1 + 76) )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      strcpy(s, "Get A Error Data To Push!DROP!\r\n");
      sub_385C8(4, s, 0);
    }
    return;
  }
  v2 = *(_DWORD **)(a1 + 1748);
  sub_2A7A4((struct timeval *)(a1 + 1920));
  if ( byte_74149 )
  {
    v3 = *(_DWORD *)(sub_1AA90(*(_DWORD *)(a1 + 1744)) + 36);
    if ( pthread_mutex_lock(&stru_77B74) )
      sub_B35C("submit_work_async", 8223);
    ++*(_DWORD *)(v3 + 36);
    ++*((_QWORD *)v2 + 1);
    v4 = *(double *)(v3 + 200) + *(double *)(a1 + 1864);
    ++qword_78248;
    *(double *)(v3 + 200) = v4;
    v5 = *(double *)(a1 + 1864);
    v6 = *((double *)v2 + 13) + v5;
    v7 = v5 + dbl_78410;
    *((double *)v2 + 13) = v6;
    dbl_78410 = v7;
    if ( pthread_mutex_unlock(&stru_77B74) )
      sub_B50C("submit_work_async", 8230);
    off_72D18();
    if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
    {
      snprintf(
        s,
        0x1000u,
        "Accepted %s %d benchmark share nonce %08x",
        *(const char **)(*(_DWORD *)(v3 + 4) + 8),
        *(_DWORD *)(v3 + 8),
        *(_DWORD *)(a1 + 76));
      sub_385C8(7, s, 0);
    }
    return;
  }
  if ( !sub_22A8C(a1, 1) )
  {
    v8 = (unsigned __int8)byte_75C49;
    goto LABEL_17;
  }
  if ( byte_72C4D )
  {
    v8 = (unsigned __int8)byte_75C49;
    if ( !byte_75C49 )
      goto LABEL_37;
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
      goto LABEL_36;
    snprintf(s, 0x1000u, "Pool %d stale share detected, submitting as user requested", *v2);
    goto LABEL_48;
  }
  if ( *((_BYTE *)v2 + 136) )
  {
    v8 = (unsigned __int8)byte_75C49;
    if ( !byte_75C49 )
    {
LABEL_37:
      *(_BYTE *)(a1 + 1769) = 1;
LABEL_17:
      if ( *(_BYTE *)(a1 + 1772) )
      {
        if ( v8 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          snprintf(s, 0x1000u, "Pushing pool %d work to stratum queue", *v2);
          sub_385C8(7, s, 0);
        }
        if ( !sub_2A198(v2[188], a1) )
        {
          if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            strcpy(s, "Discarding work from removed pool");
            sub_385C8(7, s, 0);
          }
          sub_156B8((void **)a1);
        }
      }
      else
      {
        if ( v8 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          strcpy(s, "Pushing submit work to work thread");
          sub_385C8(7, s, 0);
        }
        if ( pthread_create(&v13, 0, sub_FB48, (void *)a1) )
        {
          strcpy(s, "Failed to create submit_work_thread");
          sub_385C8(3, s, 1);
          sub_16BE0(1);
        }
      }
      return;
    }
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
    {
LABEL_36:
      v8 = 1;
      goto LABEL_37;
    }
    snprintf(s, 0x1000u, "Pool %d stale share detected, submitting as pool requested", *v2);
LABEL_48:
    sub_385C8(7, s, 0);
    v8 = (unsigned __int8)byte_75C49;
    goto LABEL_37;
  }
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "Pool %d stale share detected, discarding", *v2);
    sub_385C8(7, s, 0);
  }
  sub_1AF6C("discard", (_DWORD *)a1);
  if ( pthread_mutex_lock(&stru_77B74) )
    sub_B35C("submit_work_async", 8248);
  v9 = *((double *)v2 + 15);
  ++v2[38];
  v10 = *(double *)(a1 + 1864);
  v11 = v9 + v10;
  ++*(_QWORD *)&dword_78AA8;
  v12 = v10 + dbl_78250;
  *((double *)v2 + 15) = v11;
  dbl_78250 = v12;
  if ( pthread_mutex_unlock(&stru_77B74) )
    sub_B50C("submit_work_async", 8253);
  off_72D18();
  sub_156B8((void **)a1);
}
