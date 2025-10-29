void __noreturn get_hash_rate()
{
  double *v0; // r5
  int v1; // r4
  double v2; // d8
  int v3; // r7
  int v4; // s24
  int v5; // r6
  uint64_t *v6; // r11
  double v7; // r0
  double v8; // d7
  double *v9; // r3
  double v10; // d6
  int v11; // r6
  int v12; // r3
  double v13; // d6
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
        v5 = index[v1];
        v6 = &h_each_chain[v1];
        v7 = (double)(0xFFFF * *v6);
        v8 = 0.0;
        *v6 = 0;
        v9 = each_chain_h[v1];
        each_chain_h[v1][v5] = v7 / ((double)(v3 + 1) / 1000000.0 + (double)v4);
        do
        {
          v10 = *v9++;
          v8 = v8 + v10;
        }
        while ( v9 != each_chain_h[v1 + 1] );
        *v0 = v8;
        v11 = v5 + 1;
        sprintf(&displayed_rate[16 * v1], "%.2f", v8 / 1000.0 / 10.0);
        v13 = *v0;
        if ( v11 <= 9 )
          index[v1] = v11;
        else
          v12 = 0;
        if ( v11 > 9 )
          index[v1] = v12;
        v2 = v2 + v13 / 10.0;
      }
      ++v1;
      ++v0;
    }
    while ( v1 != 4 );
    sprintf(displayed_hash_rate, "%.2f", v2);
    geach_chain_h_all = v2;
    copy_time(&old_h, &new_h);
    sleep(5u);
  }
}
