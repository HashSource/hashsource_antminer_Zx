int __fastcall sub_346A0(unsigned int *a1, int a2, char *nptr, unsigned __int8 a4, int a5)
{
  unsigned int *v6; // r6
  int v7; // r2
  int v8; // r1
  int v9; // r7
  int v11; // r4
  unsigned __int8 v12; // [sp+18h] [bp+18h]

  v6 = a1;
  if ( dword_77FC0 )
  {
    if ( nptr && *nptr )
    {
      v9 = strtol(nptr, 0, 10);
      if ( pthread_mutex_lock(&stru_78838) )
        sub_B6BC("switchpool", 2907);
      sub_32000(&stru_78850, "switchpool", 2907);
      if ( pthread_mutex_unlock(&stru_78838) )
        sub_B794("switchpool", 2907);
      if ( v9 >= 0 && v9 < dword_77FC0 )
      {
        v11 = *(_DWORD *)(dword_78260 + 4 * v9);
        *(_DWORD *)(v11 + 132) = 1;
        if ( pthread_rwlock_unlock(&stru_78850) )
          sub_B728("switchpool", 2917);
        off_72D18();
        sub_1A600(v11);
        v12 = a4;
        a1 = v6;
        v7 = v9;
        v8 = 27;
      }
      else
      {
        if ( pthread_rwlock_unlock(&stru_78850) )
          sub_B728("switchpool", 2910);
        off_72D18();
        v12 = a4;
        a1 = v6;
        v7 = v9;
        v8 = 26;
      }
    }
    else
    {
      v7 = 0;
      v12 = a4;
      v8 = 25;
    }
  }
  else
  {
    v7 = 0;
    v12 = a4;
    v8 = 8;
  }
  return sub_32ECC(a1, v8, v7, 0, v12);
}
