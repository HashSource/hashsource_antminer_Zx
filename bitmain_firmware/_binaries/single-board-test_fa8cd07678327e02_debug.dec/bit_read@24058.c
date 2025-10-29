unsigned __int8 __cdecl bit_read(unsigned __int8 *y, int x)
{
  int v2; // r3
  unsigned __int8 v3; // r3

  v2 = x & 7;
  if ( x <= 0 )
    v2 = -(-x & 7);
  switch ( v2 )
  {
    case 0:
      v3 = (y[x / 8] & 1) != 0;
      break;
    case 1:
      v3 = (y[x / 8] & 2) != 0;
      break;
    case 2:
      v3 = (y[x / 8] & 4) != 0;
      break;
    case 3:
      v3 = (y[x / 8] & 8) != 0;
      break;
    case 4:
      v3 = (y[x / 8] & 0x10) != 0;
      break;
    case 5:
      v3 = (y[x / 8] & 0x20) != 0;
      break;
    case 6:
      v3 = (y[x / 8] & 0x40) != 0;
      break;
    case 7:
      v3 = y[x / 8] >> 7;
      break;
    default:
      v3 = 0;
      break;
  }
  return v3;
}
