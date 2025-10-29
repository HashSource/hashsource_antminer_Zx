int __fastcall sub_1A600(int a1)
{
  _DWORD *v2; // r6
  int v3; // r7
  int v4; // r12
  int *v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // t1
  int v9; // r2
  bool v10; // cc
  int v11; // r2
  char v12; // r3
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // r0
  int v17; // r4
  int v19; // r3
  int v20; // r2
  int v21; // r0
  char s[4100]; // [sp+8h] [bp-1004h] BYREF

  if ( pthread_mutex_lock(&stru_78838) )
    sub_B35C("switch_pools", 5101);
  if ( pthread_rwlock_wrlock(&stru_78850) )
    sub_B3C8("switch_pools", 5101);
  v2 = (_DWORD *)dword_73E9C;
  v3 = *(_DWORD *)dword_73E9C;
  if ( a1 && (v4 = *(_DWORD *)(a1 + 4)) != 0 )
  {
    if ( dword_77FC0 > 0 )
    {
      v5 = (int *)dword_78260;
      v6 = dword_78260 + 4 * dword_77FC0;
      while ( 1 )
      {
        v8 = *v5++;
        v7 = v8;
        v9 = *(_DWORD *)(v8 + 4);
        v10 = v9 < v4;
        v11 = v9 + 1;
        if ( v10 )
          *(_DWORD *)(v7 + 4) = v11;
        if ( v5 == (int *)v6 )
          break;
        v4 = *(_DWORD *)(a1 + 4);
      }
    }
    *(_DWORD *)(a1 + 4) = 0;
    v12 = dword_73D34;
    if ( (unsigned int)dword_73D34 > 4 )
      goto LABEL_37;
  }
  else
  {
    v12 = dword_73D34;
    if ( (unsigned int)dword_73D34 > 4 )
      goto LABEL_37;
  }
  v13 = 1 << v12;
  if ( (v13 & 0x19) != 0 )
  {
    if ( dword_77FC0 > 0 )
    {
      v14 = 0;
      while ( 1 )
      {
        v15 = v14++;
        v16 = sub_11F70(v15);
        if ( !*(_BYTE *)(v16 + 129) && *(_DWORD *)(v16 + 132) == 1 )
          break;
        if ( dword_77FC0 <= v14 )
          goto LABEL_37;
      }
      v17 = *(_DWORD *)(dword_78260 + 4 * *(_DWORD *)v16);
      goto LABEL_21;
    }
LABEL_37:
    v17 = *(_DWORD *)(dword_78260 + 4 * v3);
    goto LABEL_21;
  }
  if ( (v13 & 6) == 0 )
    goto LABEL_37;
  if ( a1 && !*(_BYTE *)(a1 + 129) )
  {
    v17 = *(_DWORD *)(dword_78260 + 4 * *(_DWORD *)a1);
    goto LABEL_21;
  }
  if ( dword_77FC0 <= 1 )
    goto LABEL_37;
  v19 = v3;
  v20 = 1;
  while ( 1 )
  {
    ++v19;
    ++v20;
    v21 = 4 * v19;
    if ( v19 >= dword_77FC0 )
    {
      v19 = 0;
      v21 = 0;
    }
    v17 = *(_DWORD *)(dword_78260 + v21);
    if ( !*(_BYTE *)(v17 + 129) && *(_DWORD *)(v17 + 132) == 1 )
      break;
    if ( v20 == dword_77FC0 )
    {
      v17 = *(_DWORD *)(dword_78260 + 4 * v3);
      break;
    }
  }
LABEL_21:
  dword_73E9C = v17;
  if ( pthread_rwlock_unlock(&stru_78850) )
    sub_B578("switch_pools", 5163);
  if ( pthread_mutex_unlock(&stru_78838) )
    sub_B50C("switch_pools", 5163);
  off_72D18();
  if ( byte_7844D )
    sub_1859C(v17, (_BYTE *)(v17 + 130));
  if ( v2 != (_DWORD *)v17 && dword_73D34 != 3 && dword_73D34 != 4 )
  {
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      snprintf(s, 0x1000u, "Switching to pool %d %s", *(_DWORD *)v17, *(const char **)(v17 + 196));
      sub_385C8(4, s, 0);
    }
    sub_1922C(v2);
  }
  if ( pthread_mutex_lock(&stru_73EA0) )
    sub_B35C("switch_pools", 5178);
  pthread_cond_broadcast(&stru_73EB8);
  if ( pthread_mutex_unlock(&stru_73EA0) )
    sub_B50C("switch_pools", 5180);
  return off_72D18();
}
