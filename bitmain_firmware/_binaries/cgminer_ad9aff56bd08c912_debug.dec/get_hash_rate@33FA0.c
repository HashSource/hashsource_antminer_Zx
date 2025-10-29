void __noreturn get_hash_rate()
{
  double *v0; // r5
  int v1; // r4
  double v2; // d8
  int v3; // r7
  int v4; // s24
  const char *v5; // r1
  int v6; // r6
  uint64_t *v7; // r11
  double v8; // r0
  double v9; // d7
  double *v10; // r3
  double v11; // d6
  const char *v12; // r1
  int v13; // r6
  int v14; // r3
  double v15; // d6
  timeval old_h; // [sp+0h] [bp-164h] BYREF
  timeval new_h; // [sp+8h] [bp-15Ch] BYREF
  int index[4]; // [sp+10h] [bp-154h] BYREF
  double each_chain_h[4][10]; // [sp+20h] [bp-144h] BYREF

  memset(each_chain_h, 0, sizeof(each_chain_h));
  memset(index, 0, sizeof(index));
  cgtime(&old_h);
  cgtime(&new_h);
  while ( 1 )
  {
    v0 = each_chain_h_avg;
    cgtime(&new_h);
    v1 = 0;
    v2 = 0.0;
    v3 = new_h.tv_usec - old_h.tv_usec + (new_h.tv_usec - old_h.tv_usec < 0 ? 0xF4000 : 0);
    v4 = new_h.tv_sec - old_h.tv_sec;
    if ( new_h.tv_usec - old_h.tv_usec < 0 )
    {
      v3 += 576;
      v4 = new_h.tv_sec - old_h.tv_sec - 1;
    }
    do
    {
      if ( dev.chain_exist[v1] )
      {
        v6 = index[v1];
        v7 = &h_each_chain[v1];
        v8 = (double)(0xFFFF * *v7);
        v9 = 0.0;
        *v7 = 0;
        v10 = each_chain_h[v1];
        each_chain_h[v1][v6] = v8 / ((double)(v3 + 1) / 1000000.0 + (double)v4);
        do
        {
          v11 = *v10++;
          v9 = v9 + v11;
        }
        while ( v10 != each_chain_h[v1 + 1] );
        LOWORD(v12) = 21528;
        *v0 = v9;
        HIWORD(v12) = (unsigned int)" (sendc=%d)" >> 16;
        v13 = v6 + 1;
        sprintf(&displayed_rate[16 * v1], v12, v9 / 1000.0 / 10.0);
        v15 = *v0;
        if ( v13 <= 9 )
          index[v1] = v13;
        else
          v14 = 0;
        if ( v13 > 9 )
          index[v1] = v14;
        v2 = v2 + v15 / 10.0;
      }
      ++v1;
      ++v0;
    }
    while ( v1 != 4 );
    LOWORD(v5) = 21528;
    HIWORD(v5) = (unsigned int)" (sendc=%d)" >> 16;
    sprintf(displayed_hash_rate, v5, v2);
    geach_chain_h_all = v2;
    copy_time(&old_h, &new_h);
    sleep(5u);
  }
}
