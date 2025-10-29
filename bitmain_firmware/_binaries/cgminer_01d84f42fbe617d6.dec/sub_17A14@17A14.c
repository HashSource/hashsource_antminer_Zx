int __fastcall sub_17A14(int a1)
{
  int v2; // r3
  int v3; // r0
  int v4; // r2
  int v5; // r1
  int v6; // r12
  bool v7; // zf
  int v8; // r2
  int v9; // r1
  int v10; // r0
  int v11; // r2
  int v12; // r2
  struct timespec v14; // [sp+0h] [bp-814h] BYREF
  struct timeval v15; // [sp+8h] [bp-80Ch] BYREF
  char v16[2052]; // [sp+10h] [bp-804h] BYREF

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_612C8) )
    sub_B4E4("hash_pop", 7716);
  if ( dword_612CC && *(_DWORD *)(*(_DWORD *)(dword_612CC + 344) + 12) )
  {
    if ( !byte_612D0 )
      goto LABEL_18;
    goto LABEL_14;
  }
  if ( byte_612D1 && dword_60070 < dword_60074 )
  {
    ++dword_60070;
    byte_612D1 = 0;
  }
  byte_612D2 = 1;
  if ( a1 )
  {
    do
    {
      sub_2B13C(&v15);
      v14.tv_sec = v15.tv_sec + 10;
      v14.tv_nsec = 1000 * v15.tv_usec;
      pthread_cond_signal(&stru_63748);
      if ( pthread_cond_timedwait((pthread_cond_t *)(dword_63BC0 + 40), (pthread_mutex_t *)dword_612C8, &v14) )
      {
        if ( !byte_612D0 )
        {
          byte_612D0 = 1;
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            strcpy(v16, "Waiting for work to be available from pools.");
            sub_38438(4, v16, 0);
          }
        }
      }
    }
    while ( !dword_612CC || !*(_DWORD *)(*(_DWORD *)(dword_612CC + 344) + 12) );
    if ( !byte_612D0 )
    {
LABEL_18:
      v2 = dword_612CC;
      if ( dword_612CC )
      {
        v3 = *(_DWORD *)(dword_612CC + 344);
        if ( dword_612D4 < *(_DWORD *)(v3 + 12)
          && (a1 = *(_DWORD *)(dword_612CC + 352), !*(_BYTE *)(dword_612CC + 273))
          && *(_DWORD *)(dword_612CC + 276) )
        {
          while ( a1 )
          {
            if ( *(_BYTE *)(a1 + 273) )
            {
              v4 = *(_DWORD *)(a1 + 348);
              if ( v4 )
                goto LABEL_22;
              goto LABEL_61;
            }
            if ( !*(_DWORD *)(a1 + 276) )
              break;
            a1 = *(_DWORD *)(a1 + 352);
          }
        }
        else
        {
          a1 = dword_612CC;
        }
      }
      else
      {
        v3 = MEMORY[0x158];
        a1 = 0;
      }
      v4 = *(_DWORD *)(a1 + 348);
      if ( !v4 )
      {
LABEL_61:
        if ( !*(_DWORD *)(a1 + 352) )
        {
          free(*(void **)v3);
          free(*(void **)(dword_612CC + 344));
          dword_612CC = 0;
LABEL_43:
          if ( !*(_BYTE *)(a1 + 273) && *(_DWORD *)(a1 + 276) )
            --dword_612D4;
          pthread_cond_signal(&stru_63748);
          pthread_cond_signal((pthread_cond_t *)(dword_63BC0 + 40));
          dword_63EE8 = time(0);
          goto LABEL_45;
        }
      }
LABEL_22:
      v5 = *(_DWORD *)(v3 + 20);
      v6 = a1 + 344;
      if ( *(_DWORD *)(v3 + 16) - v5 == a1 )
      {
        *(_DWORD *)(v3 + 16) = v4 + v5;
        v4 = *(_DWORD *)(a1 + 348);
      }
      v7 = v4 == 0;
      if ( v4 )
      {
        v3 = *(_DWORD *)(v2 + 344);
        v5 = *(_DWORD *)(a1 + 352);
      }
      else
      {
        v4 = *(_DWORD *)(a1 + 352);
      }
      if ( v7 )
      {
        v2 = v4;
        dword_612CC = v4;
      }
      else
      {
        v4 += *(_DWORD *)(v3 + 20);
      }
      if ( !v7 )
      {
        *(_DWORD *)(v4 + 8) = v5;
        v4 = *(_DWORD *)(a1 + 352);
      }
      if ( v4 )
        *(_DWORD *)(v4 + *(_DWORD *)(*(_DWORD *)(v2 + 344) + 20) + 4) = *(_DWORD *)(a1 + 348);
      v8 = 12 * ((*(_DWORD *)(*(_DWORD *)(v2 + 344) + 4) - 1) & *(_DWORD *)(a1 + 372));
      --*(_DWORD *)(**(_DWORD **)(v2 + 344) + v8 + 4);
      v9 = **(_DWORD **)(v2 + 344);
      v10 = *(_DWORD *)(v9 + v8);
      if ( v10 == v6 )
      {
        v2 = *(_DWORD *)(a1 + 360);
        *(_DWORD *)(v9 + v8) = v2;
      }
      v11 = *(_DWORD *)(a1 + 356);
      if ( v10 == v6 )
        v2 = dword_612CC;
      if ( v11 )
        *(_DWORD *)(v11 + 16) = *(_DWORD *)(a1 + 360);
      v12 = *(_DWORD *)(a1 + 360);
      if ( v12 )
        *(_DWORD *)(v12 + 12) = *(_DWORD *)(a1 + 356);
      --*(_DWORD *)(*(_DWORD *)(v2 + 344) + 12);
      goto LABEL_43;
    }
LABEL_14:
    if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
    {
      strcpy(v16, "Work available from pools, resuming.");
      sub_38438(4, v16, 0);
    }
    byte_612D0 = 0;
    goto LABEL_18;
  }
LABEL_45:
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_612C8) )
    sub_B694("hash_pop", 7783);
  off_60178();
  return a1;
}
