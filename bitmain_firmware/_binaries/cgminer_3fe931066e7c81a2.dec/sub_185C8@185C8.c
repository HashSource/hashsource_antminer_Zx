void __fastcall sub_185C8(_DWORD *a1)
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
  _DWORD *v11; // r1
  int v12; // r3
  int v13; // r1
  int v14; // r1
  int v15; // r12
  int v16; // r3
  int v17; // r3
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_7704C) )
    sub_B414("clear_pool_work", 7016);
  v2 = dword_77050;
  if ( dword_77050 )
  {
    v4 = *(_DWORD *)(dword_77050 + 1840);
    v3 = 0;
    while ( 1 )
    {
      if ( *(_DWORD **)(v2 + 1748) == a1 )
      {
        v5 = *(_DWORD *)(v2 + 1836);
        if ( v5 || *(_DWORD *)(v2 + 1840) )
        {
          v6 = dword_77050;
          v7 = v2 + 1832;
          v8 = *(_DWORD *)(dword_77050 + 1832);
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
            dword_77050 = v6;
            v8 = v6;
          }
          if ( !v10 )
          {
            *(_DWORD *)(v5 + 8) = v8;
            v8 = *(_DWORD *)(v2 + 1840);
          }
          if ( v8 )
            *(_DWORD *)(v8 + *(_DWORD *)(*(_DWORD *)(v6 + 1832) + 20) + 4) = *(_DWORD *)(v2 + 1836);
          v11 = *(_DWORD **)(v6 + 1832);
          v12 = 3 * ((v11[1] - 1) & *(_DWORD *)(v2 + 1860));
          v13 = *v11 + 12 * ((v11[1] - 1) & *(_DWORD *)(v2 + 1860));
          --*(_DWORD *)(v13 + 4);
          v14 = **(_DWORD **)(v6 + 1832);
          v15 = *(_DWORD *)(v14 + 4 * v12);
          if ( v15 == v7 )
          {
            v6 = *(_DWORD *)(v2 + 1848);
            *(_DWORD *)(v14 + 4 * v12) = v6;
          }
          v16 = *(_DWORD *)(v2 + 1844);
          if ( v15 == v7 )
            v6 = dword_77050;
          if ( v16 )
            *(_DWORD *)(v16 + 16) = *(_DWORD *)(v2 + 1848);
          v17 = *(_DWORD *)(v2 + 1848);
          if ( v17 )
            *(_DWORD *)(v17 + 12) = *(_DWORD *)(v2 + 1844);
          --*(_DWORD *)(*(_DWORD *)(v6 + 1832) + 12);
        }
        else
        {
          free(**(void ***)(dword_77050 + 1832));
          free(*(void **)(dword_77050 + 1832));
          dword_77050 = 0;
        }
        ++v3;
        sub_15780((void **)v2);
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
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_7704C) )
    sub_B5C4("clear_pool_work", 7026);
  off_75ED8();
  if ( v3 && byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    snprintf(s, 0x1000u, "Cleared %d work items due to stratum disconnect on pool %d", v3, *a1);
    sub_38730(7, s, 0);
  }
}
