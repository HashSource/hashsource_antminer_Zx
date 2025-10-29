unsigned __int8 __fastcall bit_read(unsigned __int8 *y, int x)
{
  int v2; // r3
  int v3; // r3
  bool v4; // cf
  int v5; // r1
  int v6; // r3
  int v7; // r1
  int v8; // r3
  int v9; // r1
  int v10; // r3
  int v11; // r1
  int v12; // r3
  int v13; // r1
  int v14; // r3
  int v15; // r1
  int v16; // r3
  int v17; // r1
  int v18; // r3
  int v19; // r1

  v2 = x & 7;
  if ( x <= 0 )
    v2 = -(-x & 7);
  switch ( v2 )
  {
    case 0:
      v6 = x + 7;
      v4 = x < 0;
      v7 = x & ~(x >> 31);
      if ( v4 )
        v7 = v6;
      LOBYTE(y) = y[v7 >> 3] & 1;
      break;
    case 1:
      v8 = x + 7;
      v4 = x < 0;
      v9 = x & ~(x >> 31);
      if ( v4 )
        v9 = v8;
      y = (unsigned __int8 *)((y[v9 >> 3] >> 1) & 1);
      break;
    case 2:
      v10 = x + 7;
      v4 = x < 0;
      v11 = x & ~(x >> 31);
      if ( v4 )
        v11 = v10;
      y = (unsigned __int8 *)((y[v11 >> 3] >> 2) & 1);
      break;
    case 3:
      v12 = x + 7;
      v4 = x < 0;
      v13 = x & ~(x >> 31);
      if ( v4 )
        v13 = v12;
      y = (unsigned __int8 *)((y[v13 >> 3] >> 3) & 1);
      break;
    case 4:
      v14 = x + 7;
      v4 = x < 0;
      v15 = x & ~(x >> 31);
      if ( v4 )
        v15 = v14;
      y = (unsigned __int8 *)((y[v15 >> 3] >> 4) & 1);
      break;
    case 5:
      v16 = x + 7;
      v4 = x < 0;
      v17 = x & ~(x >> 31);
      if ( v4 )
        v17 = v16;
      y = (unsigned __int8 *)((y[v17 >> 3] >> 5) & 1);
      break;
    case 6:
      v18 = x + 7;
      v4 = x < 0;
      v19 = x & ~(x >> 31);
      if ( v4 )
        v19 = v18;
      y = (unsigned __int8 *)((y[v19 >> 3] >> 6) & 1);
      break;
    case 7:
      v3 = x + 7;
      v4 = x < 0;
      v5 = x & ~(x >> 31);
      if ( v4 )
        v5 = v3;
      y = (unsigned __int8 *)(y[v5 >> 3] >> 7);
      break;
    default:
      LOBYTE(y) = 0;
      break;
  }
  return (unsigned __int8)y;
}
