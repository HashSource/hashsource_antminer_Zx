int __fastcall sub_18D24(int a1)
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

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_73E6C) )
    sub_B35C("hash_pop", 7702);
  if ( dword_73E74 && *(_DWORD *)(*(_DWORD *)(dword_73E74 + 1832) + 12) )
  {
    if ( !byte_782F0 )
      goto LABEL_18;
    goto LABEL_14;
  }
  if ( byte_73E78 && dword_72C14 < dword_72C18 )
  {
    ++dword_72C14;
    byte_73E78 = 0;
  }
  byte_73E79 = 1;
  if ( a1 )
  {
    do
    {
      sub_2A7A4(&v15);
      v14.tv_nsec = 1000 * v15.tv_usec;
      v14.tv_sec = v15.tv_sec + 10;
      pthread_cond_signal(&stru_77FC8);
      if ( pthread_cond_timedwait((pthread_cond_t *)(dword_78448 + 40), (pthread_mutex_t *)dword_73E6C, &v14) )
      {
        if ( !byte_782F0 )
        {
          byte_782F0 = 1;
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            strcpy(v16, "Waiting for work to be available from pools.");
            sub_385C8(4, v16, 0);
          }
        }
      }
    }
    while ( !dword_73E74 || !*(_DWORD *)(*(_DWORD *)(dword_73E74 + 1832) + 12) );
    if ( !byte_782F0 )
    {
LABEL_18:
      v2 = dword_73E74;
      if ( dword_73E74 )
      {
        v3 = *(_DWORD *)(dword_73E74 + 1832);
        if ( dword_73E7C < *(_DWORD *)(v3 + 12)
          && (a1 = *(_DWORD *)(dword_73E74 + 1840), !*(_BYTE *)(dword_73E74 + 1761))
          && *(_DWORD *)(dword_73E74 + 1764) )
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
          a1 = dword_73E74;
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
          free(*(void **)(dword_73E74 + 1832));
          dword_73E74 = 0;
LABEL_43:
          if ( !*(_BYTE *)(a1 + 1761) && *(_DWORD *)(a1 + 1764) )
            --dword_73E7C;
          pthread_cond_signal(&stru_77FC8);
          pthread_cond_signal((pthread_cond_t *)(dword_78448 + 40));
          dword_78770 = time(0);
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
        dword_73E74 = v4;
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
        v2 = dword_73E74;
      if ( v11 )
        *(_DWORD *)(v11 + 16) = *(_DWORD *)(a1 + 1848);
      v12 = *(_DWORD *)(a1 + 1848);
      if ( v12 )
        *(_DWORD *)(v12 + 12) = *(_DWORD *)(a1 + 1844);
      --*(_DWORD *)(*(_DWORD *)(v2 + 1832) + 12);
      goto LABEL_43;
    }
LABEL_14:
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      strcpy(v16, "Work available from pools, resuming.");
      sub_385C8(4, v16, 0);
    }
    byte_782F0 = 0;
    goto LABEL_18;
  }
LABEL_45:
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_73E6C) )
    sub_B50C("hash_pop", 7769);
  off_72D18();
  return a1;
}
