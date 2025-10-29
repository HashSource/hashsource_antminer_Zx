void __fastcall sub_252E4(int a1)
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
  pthread_t v13; // [sp+Ch] [bp-808h] BYREF
  char s[2052]; // [sp+10h] [bp-804h] BYREF

  if ( !*(_DWORD *)(a1 + 76) )
  {
    if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
    {
      strcpy(s, "Get A Error Data To Push!DROP!\r\n");
      sub_38438(4, s, 0);
    }
    return;
  }
  v2 = *(_DWORD **)(a1 + 260);
  sub_2B13C((struct timeval *)(a1 + 432));
  if ( byte_615C9 )
  {
    v3 = *(_DWORD *)(sub_1C36C(*(_DWORD *)(a1 + 256)) + 36);
    if ( pthread_mutex_lock(&mutex) )
      sub_B4E4("submit_work_async", 8238);
    ++*(_DWORD *)(v3 + 36);
    ++*((_QWORD *)v2 + 1);
    v4 = *(double *)(v3 + 200) + *(double *)(a1 + 376);
    ++qword_639C8;
    *(double *)(v3 + 200) = v4;
    v5 = *(double *)(a1 + 376);
    v6 = *((double *)v2 + 9) + v5;
    v7 = v5 + dbl_63B88;
    *((double *)v2 + 9) = v6;
    dbl_63B88 = v7;
    if ( pthread_mutex_unlock(&mutex) )
      sub_B694("submit_work_async", 8245);
    off_60178();
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf(
        s,
        0x800u,
        "Accepted %s %d benchmark share nonce %08x",
        *(const char **)(*(_DWORD *)(v3 + 4) + 8),
        *(_DWORD *)(v3 + 8),
        *(_DWORD *)(a1 + 76));
      sub_38438(7, s, 0);
    }
    return;
  }
  if ( !sub_2282C(a1, 1) )
  {
    v8 = (unsigned __int8)byte_630C1;
    goto LABEL_17;
  }
  if ( byte_600AD )
  {
    v8 = (unsigned __int8)byte_630C1;
    if ( !byte_630C1 )
      goto LABEL_37;
    if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
      goto LABEL_36;
    snprintf(s, 0x800u, "Pool %d stale share detected, submitting as user requested", *v2);
    goto LABEL_48;
  }
  if ( *((_BYTE *)v2 + 104) )
  {
    v8 = (unsigned __int8)byte_630C1;
    if ( !byte_630C1 )
    {
LABEL_37:
      *(_BYTE *)(a1 + 281) = 1;
LABEL_17:
      if ( *(_BYTE *)(a1 + 284) )
      {
        if ( v8 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          snprintf(s, 0x800u, "Pushing pool %d work to stratum queue", *v2);
          sub_38438(7, s, 0);
        }
        if ( !sub_2AB68(v2[174], a1) )
        {
          if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
          {
            strcpy(s, "Discarding work from removed pool");
            sub_38438(7, s, 0);
          }
          sub_152B8((void **)a1);
        }
      }
      else
      {
        if ( v8 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          strcpy(s, "Pushing submit work to work thread");
          sub_38438(7, s, 0);
        }
        if ( pthread_create(&v13, 0, sub_F7C0, (void *)a1) )
        {
          strcpy(s, "Failed to create submit_work_thread");
          sub_38438(3, s, 1);
          sub_16724(1);
        }
      }
      return;
    }
    if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
    {
LABEL_36:
      v8 = 1;
      goto LABEL_37;
    }
    snprintf(s, 0x800u, "Pool %d stale share detected, submitting as pool requested", *v2);
LABEL_48:
    sub_38438(7, s, 0);
    v8 = (unsigned __int8)byte_630C1;
    goto LABEL_37;
  }
  if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf(s, 0x800u, "Pool %d stale share detected, discarding", *v2);
    sub_38438(7, s, 0);
  }
  sub_1D408("discard", (_DWORD *)a1);
  if ( pthread_mutex_lock(&mutex) )
    sub_B4E4("submit_work_async", 8263);
  v9 = *((double *)v2 + 11);
  ++v2[30];
  v10 = *(double *)(a1 + 376);
  v11 = v9 + v10;
  ++*(_QWORD *)&dword_64220;
  v12 = v10 + dbl_639D0;
  *((double *)v2 + 11) = v11;
  dbl_639D0 = v12;
  if ( pthread_mutex_unlock(&mutex) )
    sub_B694("submit_work_async", 8268);
  off_60178();
  sub_152B8((void **)a1);
}
