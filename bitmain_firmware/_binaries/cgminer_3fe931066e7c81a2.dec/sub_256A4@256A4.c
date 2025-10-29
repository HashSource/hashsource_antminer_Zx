void __fastcall sub_256A4(int a1)
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
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
    {
      strcpy(s, "Get A Error Data To Push!DROP!\r\n");
      sub_38730(4, s, 0);
    }
    return;
  }
  v2 = *(_DWORD **)(a1 + 1748);
  sub_2A84C((struct timeval *)(a1 + 1920));
  if ( byte_7730D )
  {
    v3 = *(_DWORD *)(sub_1B124(*(_DWORD *)(a1 + 1744)) + 36);
    if ( pthread_mutex_lock(&stru_7AD4C) )
      sub_B414("submit_work_async", 8236);
    ++*(_DWORD *)(v3 + 36);
    ++*((_QWORD *)v2 + 1);
    v4 = *(double *)(v3 + 200) + *(double *)(a1 + 1864);
    ++qword_7B420;
    *(double *)(v3 + 200) = v4;
    v5 = *(double *)(a1 + 1864);
    v6 = *((double *)v2 + 13) + v5;
    v7 = v5 + dbl_7B5E8;
    *((double *)v2 + 13) = v6;
    dbl_7B5E8 = v7;
    if ( pthread_mutex_unlock(&stru_7AD4C) )
      sub_B5C4("submit_work_async", 8243);
    off_75ED8();
    if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
    {
      snprintf(
        s,
        0x1000u,
        "Accepted %s %d benchmark share nonce %08x",
        *(const char **)(*(_DWORD *)(v3 + 4) + 8),
        *(_DWORD *)(v3 + 8),
        *(_DWORD *)(a1 + 76));
      sub_38730(7, s, 0);
    }
    return;
  }
  if ( !sub_22B44(a1, 1) )
  {
    v8 = (unsigned __int8)byte_78E09;
    goto LABEL_17;
  }
  if ( byte_75E0D )
  {
    v8 = (unsigned __int8)byte_78E09;
    if ( !byte_78E09 )
      goto LABEL_37;
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
      goto LABEL_36;
    snprintf(s, 0x1000u, "Pool %d stale share detected, submitting as user requested", *v2);
    goto LABEL_48;
  }
  if ( *((_BYTE *)v2 + 136) )
  {
    v8 = (unsigned __int8)byte_78E09;
    if ( !byte_78E09 )
    {
LABEL_37:
      *(_BYTE *)(a1 + 1769) = 1;
LABEL_17:
      if ( *(_BYTE *)(a1 + 1772) )
      {
        if ( v8 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          snprintf(s, 0x1000u, "Pushing pool %d work to stratum queue", *v2);
          sub_38730(7, s, 0);
        }
        if ( !sub_2A240(v2[188], a1) )
        {
          if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
          {
            strcpy(s, "Discarding work from removed pool");
            sub_38730(7, s, 0);
          }
          sub_15780((void **)a1);
        }
      }
      else
      {
        if ( v8 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
        {
          strcpy(s, "Pushing submit work to work thread");
          sub_38730(7, s, 0);
        }
        if ( pthread_create(&v13, 0, sub_FC10, (void *)a1) )
        {
          strcpy(s, "Failed to create submit_work_thread");
          sub_38730(3, s, 1);
          sub_16CA8(1);
        }
      }
      return;
    }
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
    {
LABEL_36:
      v8 = 1;
      goto LABEL_37;
    }
    snprintf(s, 0x1000u, "Pool %d stale share detected, submitting as pool requested", *v2);
LABEL_48:
    sub_38730(7, s, 0);
    v8 = (unsigned __int8)byte_78E09;
    goto LABEL_37;
  }
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "Pool %d stale share detected, discarding", *v2);
    sub_38730(7, s, 0);
  }
  sub_1B600("discard", (_DWORD *)a1);
  if ( pthread_mutex_lock(&stru_7AD4C) )
    sub_B414("submit_work_async", 8261);
  v9 = *((double *)v2 + 15);
  ++v2[38];
  v10 = *(double *)(a1 + 1864);
  v11 = v9 + v10;
  ++*(_QWORD *)&dword_7BC80;
  v12 = v10 + dbl_7B428;
  *((double *)v2 + 15) = v11;
  dbl_7B428 = v12;
  if ( pthread_mutex_unlock(&stru_7AD4C) )
    sub_B5C4("submit_work_async", 8266);
  off_75ED8();
  sub_15780((void **)a1);
}
