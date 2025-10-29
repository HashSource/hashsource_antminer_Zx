int __fastcall sub_193B4(int a1)
{
  int v2; // r3
  int v3; // r0
  int v4; // r2
  int v5; // r12
  int v6; // r1
  bool v7; // zf
  int v8; // r2
  int v9; // r0
  int v10; // r12
  int v11; // r2
  int v12; // r2
  struct timespec v14; // [sp+0h] [bp-1014h] BYREF
  struct timeval v15; // [sp+8h] [bp-100Ch] BYREF
  char v16[4080]; // [sp+10h] [bp-1004h] BYREF

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_7704C) )
    sub_B414("hash_pop", 7715);
  if ( dword_77050 && *(_DWORD *)(*(_DWORD *)(dword_77050 + 1832) + 12) )
  {
    if ( !byte_7B4C8 )
      goto LABEL_18;
    goto LABEL_14;
  }
  if ( byte_77055 && dword_75DD8 < dword_75DDC )
  {
    ++dword_75DD8;
    byte_77055 = 0;
  }
  byte_77056 = 1;
  if ( a1 )
  {
    do
    {
      sub_2A84C(&v15);
      v14.tv_nsec = 1000 * v15.tv_usec;
      v14.tv_sec = v15.tv_sec + 10;
      pthread_cond_signal(&stru_7B1A0);
      if ( pthread_cond_timedwait((pthread_cond_t *)(dword_7B620 + 40), (pthread_mutex_t *)dword_7704C, &v14) )
      {
        if ( !byte_7B4C8 )
        {
          byte_7B4C8 = 1;
          if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
          {
            strcpy(v16, "Waiting for work to be available from pools.");
            sub_38730(4, v16, 0);
          }
        }
      }
    }
    while ( !dword_77050 || !*(_DWORD *)(*(_DWORD *)(dword_77050 + 1832) + 12) );
    if ( !byte_7B4C8 )
    {
LABEL_18:
      v2 = dword_77050;
      if ( dword_77050 )
      {
        v3 = *(_DWORD *)(dword_77050 + 1832);
        if ( dword_77058 < *(_DWORD *)(v3 + 12)
          && (a1 = *(_DWORD *)(dword_77050 + 1840), !*(_BYTE *)(dword_77050 + 1761))
          && *(_DWORD *)(dword_77050 + 1764) )
        {
          while ( a1 )
          {
            if ( *(_BYTE *)(a1 + 1761) )
            {
              v4 = *(_DWORD *)(a1 + 1836);
              if ( v4 )
                goto LABEL_22;
              goto LABEL_61;
            }
            if ( !*(_DWORD *)(a1 + 1764) )
              break;
            a1 = *(_DWORD *)(a1 + 1840);
          }
        }
        else
        {
          a1 = dword_77050;
        }
      }
      else
      {
        v3 = MEMORY[0x728];
        a1 = 0;
      }
      v4 = *(_DWORD *)(a1 + 1836);
      if ( !v4 )
      {
LABEL_61:
        if ( !*(_DWORD *)(a1 + 1840) )
        {
          free(*(void **)v3);
          free(*(void **)(dword_77050 + 1832));
          dword_77050 = 0;
LABEL_43:
          if ( !*(_BYTE *)(a1 + 1761) && *(_DWORD *)(a1 + 1764) )
            --dword_77058;
          pthread_cond_signal(&stru_7B1A0);
          pthread_cond_signal((pthread_cond_t *)(dword_7B620 + 40));
          dword_7B948 = time(0);
          goto LABEL_45;
        }
      }
LABEL_22:
      v5 = *(_DWORD *)(v3 + 20);
      v6 = a1 + 1832;
      if ( *(_DWORD *)(v3 + 16) - v5 == a1 )
      {
        *(_DWORD *)(v3 + 16) = v4 + v5;
        v4 = *(_DWORD *)(a1 + 1836);
      }
      v7 = v4 == 0;
      if ( v4 )
      {
        v5 = *(_DWORD *)(v2 + 1832);
        v3 = *(_DWORD *)(a1 + 1840);
      }
      else
      {
        v4 = *(_DWORD *)(a1 + 1840);
      }
      if ( v7 )
      {
        v2 = v4;
        dword_77050 = v4;
      }
      else
      {
        v4 += *(_DWORD *)(v5 + 20);
      }
      if ( !v7 )
      {
        *(_DWORD *)(v4 + 8) = v3;
        v4 = *(_DWORD *)(a1 + 1840);
      }
      if ( v4 )
        *(_DWORD *)(v4 + *(_DWORD *)(*(_DWORD *)(v2 + 1832) + 20) + 4) = *(_DWORD *)(a1 + 1836);
      v8 = 12 * ((*(_DWORD *)(*(_DWORD *)(v2 + 1832) + 4) - 1) & *(_DWORD *)(a1 + 1860));
      --*(_DWORD *)(**(_DWORD **)(v2 + 1832) + v8 + 4);
      v9 = **(_DWORD **)(v2 + 1832);
      v10 = *(_DWORD *)(v9 + v8);
      if ( v10 == v6 )
      {
        v2 = *(_DWORD *)(a1 + 1848);
        *(_DWORD *)(v9 + v8) = v2;
      }
      v11 = *(_DWORD *)(a1 + 1844);
      if ( v10 == v6 )
        v2 = dword_77050;
      if ( v11 )
        *(_DWORD *)(v11 + 16) = *(_DWORD *)(a1 + 1848);
      v12 = *(_DWORD *)(a1 + 1848);
      if ( v12 )
        *(_DWORD *)(v12 + 12) = *(_DWORD *)(a1 + 1844);
      --*(_DWORD *)(*(_DWORD *)(v2 + 1832) + 12);
      goto LABEL_43;
    }
LABEL_14:
    if ( byte_7AD48 || byte_78E08 || dword_766C4 > 3 )
    {
      strcpy(v16, "Work available from pools, resuming.");
      sub_38730(4, v16, 0);
    }
    byte_7B4C8 = 0;
    goto LABEL_18;
  }
LABEL_45:
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_7704C) )
    sub_B5C4("hash_pop", 7782);
  off_75ED8();
  return a1;
}
