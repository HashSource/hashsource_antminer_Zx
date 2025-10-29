void __fastcall poolpriority(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *v6; // r2
  char *v7; // r3
  int v8; // r6
  char *v9; // r10
  char *v10; // r0
  char *v11; // r4
  const char *v12; // r0
  int v13; // r0
  int v14; // r12
  int v15; // r1
  pool **v16; // r4
  char *v17; // r2
  int v18; // r0
  int v20; // lr
  char *v21; // r2
  int v22; // r3
  pool *v24; // r0
  char v25; // [sp+7h] [bp-1h] BYREF
  io_data *v26; // [sp+8h] [bp+0h] BYREF
  bool v27[8]; // [sp+Ch] [bp+4h]

  *(_DWORD *)v27 = isjson;
  v26 = io_data;
  if ( !total_pools )
  {
    message(io_data, 8, 0, 0, v27[0]);
    goto LABEL_29;
  }
  if ( !param || !*param )
  {
    message(v26, 25, 0, 0, v27[0]);
    goto LABEL_29;
  }
  if ( total_pools > 0 )
  {
    v6 = &v25;
    v7 = (char *)&v26 + total_pools - 1;
    do
      *++v6 = 0;
    while ( v6 != v7 );
  }
  v8 = 0;
  v9 = param;
  while ( 1 )
  {
    v10 = strchr(v9, 44);
    v11 = v10;
    if ( v10 )
    {
      v11 = v10 + 1;
      *v10 = 0;
    }
    v12 = v9;
    v9 = v11;
    v13 = strtol(v12, 0, 10);
    v14 = v8 + 1;
    if ( v13 < 0 )
      break;
    v15 = total_pools;
    if ( total_pools <= v13 )
      break;
    if ( v27[v13 - 4] )
    {
      message(v26, 74, v13, 0, v27[0]);
LABEL_29:
      __asm { POP.W           {R4-R11,PC} }
    }
    *(_DWORD *)&v27[4 * v13 - 4] = v8++;
    v27[v13 - 4] = 1;
    if ( !v11 || !*v11 )
    {
      v16 = pools;
      v17 = &v25;
      v18 = 0;
      do
      {
        if ( *++v17 )
          v16[v18]->prio = *(_DWORD *)&v27[4 * v18 - 4];
        ++v18;
      }
      while ( v17 != &v25 + v15 );
      v20 = 0;
      while ( 1 )
      {
        v21 = &v25;
        v22 = 0;
        while ( 1 )
        {
          if ( !*++v21 )
          {
            v24 = v16[v22];
            if ( v24->prio == v20 )
              break;
          }
          if ( v15 == ++v22 )
            goto LABEL_24;
        }
        v24->prio = v14++;
        v27[v22 - 4] = 1;
LABEL_24:
        if ( v15 == ++v20 )
        {
          if ( current_pool()->prio )
            switch_pools(0);
          message(v26, 73, 0, 0, v27[0]);
          __asm { POP.W           {R4-R11,PC} }
        }
      }
    }
  }
  message(v26, 26, v13, 0, v27[0]);
  goto LABEL_29;
}
