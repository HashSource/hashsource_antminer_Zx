void sub_22ED0()
{
  _DWORD *v0; // r4
  int v1; // r6
  _DWORD *v2; // r5
  int v3; // r1
  int v4; // r2
  _DWORD *v5; // r0
  int v6; // r3
  int v7; // r12
  bool v8; // zf
  int v9; // r3
  _DWORD *v10; // r3
  int v11; // r1
  int v12; // r3
  _DWORD *v13; // r12
  int v14; // r3
  int v15; // r3
  char v16[4096]; // [sp+0h] [bp-1000h] BYREF

  if ( pthread_mutex_lock((pthread_mutex_t *)dword_73E6C) )
    sub_B35C("discard_stale", 5214);
  v0 = (_DWORD *)dword_73E74;
  if ( dword_73E74 )
  {
    v2 = *(_DWORD **)(dword_73E74 + 1840);
    v1 = 0;
    while ( 1 )
    {
      if ( sub_22A8C((int)v0, 0) )
      {
        v3 = v0[459];
        if ( v3 || v0[460] )
        {
          v4 = dword_73E74;
          v5 = v0 + 458;
          v6 = *(_DWORD *)(dword_73E74 + 1832);
          v7 = *(_DWORD *)(v6 + 20);
          if ( (_DWORD *)(*(_DWORD *)(v6 + 16) - v7) == v0 )
          {
            *(_DWORD *)(v6 + 16) = v3 + v7;
            v3 = v0[459];
          }
          v8 = v3 == 0;
          if ( v3 )
            v7 = *(_DWORD *)(v4 + 1832);
          v9 = v0[460];
          if ( v3 )
          {
            v3 += *(_DWORD *)(v7 + 20);
          }
          else
          {
            v4 = v0[460];
            dword_73E74 = v4;
          }
          if ( !v8 )
          {
            *(_DWORD *)(v3 + 8) = v9;
            v9 = v0[460];
          }
          if ( v9 )
            *(_DWORD *)(v9 + *(_DWORD *)(*(_DWORD *)(v4 + 1832) + 20) + 4) = v0[459];
          v10 = *(_DWORD **)(v4 + 1832);
          v11 = 3 * ((v10[1] - 1) & v0[465]);
          --*(_DWORD *)(*v10 + 4 * v11 + 4);
          v12 = **(_DWORD **)(v4 + 1832);
          v13 = *(_DWORD **)(v12 + 4 * v11);
          if ( v13 == v5 )
          {
            v4 = v0[462];
            *(_DWORD *)(v12 + 4 * v11) = v4;
          }
          v14 = v0[461];
          if ( v13 == v5 )
            v4 = dword_73E74;
          if ( v14 )
            *(_DWORD *)(v14 + 16) = v0[462];
          v15 = v0[462];
          if ( v15 )
            *(_DWORD *)(v15 + 12) = v0[461];
          --*(_DWORD *)(*(_DWORD *)(v4 + 1832) + 12);
        }
        else
        {
          free(**(void ***)(dword_73E74 + 1832));
          free(*(void **)(dword_73E74 + 1832));
          dword_73E74 = 0;
        }
        ++v1;
        sub_158EC((int)v0);
      }
      if ( !v2 )
        break;
      v0 = v2;
      v2 = (_DWORD *)v2[460];
    }
  }
  else
  {
    v1 = 0;
  }
  pthread_cond_signal(&stru_77FC8);
  if ( pthread_mutex_unlock((pthread_mutex_t *)dword_73E6C) )
    sub_B50C("discard_stale", 5225);
  off_72D18();
  if ( v1 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v16, 0x1000u, "Discarded %d stales that didn't match current hash", v1);
    sub_385C8(7, v16, 0);
  }
}
