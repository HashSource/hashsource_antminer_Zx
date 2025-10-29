void __fastcall sub_1922C(_DWORD *a1)
{
  int v2; // r4
  int v3; // r7
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r0
  int v8; // r3
  int v9; // r12
  bool v10; // zf
  int v11; // r3
  int v12; // r1
  int v13; // r1
  int v14; // r12
  int v15; // r3
  int v16; // r3
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_73E6C) )
    sub_B35C("clear_pool_work", 7016);
  v2 = dword_73E74;
  if ( dword_73E74 )
  {
    v4 = *(_DWORD *)(dword_73E74 + 1840);
    v3 = 0;
    while ( 1 )
    {
      if ( *(_DWORD **)(v2 + 1748) == a1 )
      {
        v5 = *(_DWORD *)(v2 + 1836);
        if ( v5 || *(_DWORD *)(v2 + 1840) )
        {
          v6 = dword_73E74;
          v7 = v2 + 1832;
          v8 = *(_DWORD *)(dword_73E74 + 1832);
          v9 = *(_DWORD *)(v8 + 20);
          if ( *(_DWORD *)(v8 + 16) - v9 == v2 )
          {
            *(_DWORD *)(v8 + 16) = v5 + v9;
            v5 = *(_DWORD *)(v2 + 1836);
          }
          v10 = v5 == 0;
          if ( v5 )
          {
            v9 = *(_DWORD *)(v6 + 1832);
            v8 = *(_DWORD *)(v2 + 1840);
          }
          else
          {
            v6 = *(_DWORD *)(v2 + 1840);
          }
          if ( v5 )
          {
            v5 += *(_DWORD *)(v9 + 20);
          }
          else
          {
            dword_73E74 = v6;
            v8 = v6;
          }
          if ( !v10 )
          {
            *(_DWORD *)(v5 + 8) = v8;
            v8 = *(_DWORD *)(v2 + 1840);
          }
          if ( v8 )
            *(_DWORD *)(v8 + *(_DWORD *)(*(_DWORD *)(v6 + 1832) + 20) + 4) = *(_DWORD *)(v2 + 1836);
          v11 = 3 * ((*(_DWORD *)(*(_DWORD *)(v6 + 1832) + 4) - 1) & *(_DWORD *)(v2 + 1860));
          v12 = **(_DWORD **)(v6 + 1832) + 12 * ((*(_DWORD *)(*(_DWORD *)(v6 + 1832) + 4) - 1) & *(_DWORD *)(v2 + 1860));
          --*(_DWORD *)(v12 + 4);
          v13 = **(_DWORD **)(v6 + 1832);
          v14 = *(_DWORD *)(v13 + 4 * v11);
          if ( v14 == v7 )
          {
            v6 = *(_DWORD *)(v2 + 1848);
            *(_DWORD *)(v13 + 4 * v11) = v6;
          }
          v15 = *(_DWORD *)(v2 + 1844);
          if ( v14 == v7 )
            v6 = dword_73E74;
          if ( v15 )
            *(_DWORD *)(v15 + 16) = *(_DWORD *)(v2 + 1848);
          v16 = *(_DWORD *)(v2 + 1848);
          if ( v16 )
            *(_DWORD *)(v16 + 12) = *(_DWORD *)(v2 + 1844);
          --*(_DWORD *)(*(_DWORD *)(v6 + 1832) + 12);
        }
        else
        {
          free(**(void ***)(dword_73E74 + 1832));
          free(*(void **)(dword_73E74 + 1832));
          dword_73E74 = 0;
        }
        ++v3;
        sub_156B8((void **)v2);
        if ( !v4 )
          goto LABEL_31;
      }
      else if ( !v4 )
      {
        goto LABEL_31;
      }
      v2 = v4;
      v4 = *(_DWORD *)(v4 + 1840);
    }
  }
  v3 = 0;
LABEL_31:
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_73E6C) )
    sub_B50C("clear_pool_work", 7026);
  off_72D18();
  if ( v3 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(s, 0x1000u, "Cleared %d work items due to stratum disconnect on pool %d", v3, *a1);
    sub_385C8(7, s, 0);
  }
}
