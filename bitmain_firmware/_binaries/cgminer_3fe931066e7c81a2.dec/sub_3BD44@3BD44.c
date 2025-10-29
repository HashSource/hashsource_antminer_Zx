unsigned int __fastcall sub_3BD44(int a1, _BYTE *a2, unsigned int a3)
{
  int v3; // r3
  int v4; // r10
  unsigned int v5; // r9
  unsigned int result; // r0
  _BYTE *v7; // r3
  int v8; // r12
  unsigned int v9; // r2
  _BYTE *v10; // r2
  int v11; // [sp+4h] [bp-4h]

  switch ( a1 )
  {
    case 0:
      v3 = 528;
      v4 = 133;
      goto LABEL_3;
    case 1:
      v3 = 536;
      v4 = 135;
      goto LABEL_3;
    case 2:
      v3 = 544;
      v4 = 137;
      goto LABEL_3;
    case 3:
      v3 = 552;
      v4 = 139;
      goto LABEL_3;
    case 4:
      v3 = 560;
      v4 = 141;
      goto LABEL_3;
    case 5:
      v3 = 568;
      v4 = 143;
      goto LABEL_3;
    case 6:
      v3 = 576;
      v4 = 145;
      goto LABEL_3;
    case 7:
      v3 = 584;
      v4 = 147;
      goto LABEL_3;
    case 8:
      v3 = 592;
      v4 = 149;
      goto LABEL_3;
    case 9:
      v3 = 600;
      v4 = 151;
LABEL_3:
      v5 = a3 >> 2;
      *(_DWORD *)(dword_78E10[0] + v3) = a3 & 0x3FF | 0x80000000;
      if ( a3 >> 2 )
      {
        result = 4 * v5;
        v7 = a2;
        do
        {
          v8 = *(_DWORD *)(dword_78E10[0] + 4 * v4);
          v7[3] = v8;
          *v7 = HIBYTE(v8);
          v7[1] = BYTE2(v8);
          v7[2] = BYTE1(v8);
          v7 += 4;
        }
        while ( v7 != &a2[4 * v5] );
      }
      else
      {
        result = 0;
      }
      v9 = a3 & 3;
      if ( v9 )
      {
        v11 = *(_DWORD *)(dword_78E10[0] + 4 * v4);
        if ( v9 == 2 )
        {
          a2[4 * v5] = HIBYTE(v11);
          a2[result + 1] = BYTE2(v11);
          result += 2;
        }
        else if ( v9 == 3 )
        {
          v10 = &a2[result];
          a2[4 * v5] = HIBYTE(v11);
          v10[1] = BYTE2(v11);
          v10[2] = BYTE1(v11);
          result += 3;
        }
        else
        {
          ++result;
          a2[4 * v5] = HIBYTE(v11);
        }
      }
      break;
    default:
      printf("%s: The uart%d is not supported!!!\n", "read_uart_data_in_fpga", a3);
      result = 0;
      break;
  }
  return result;
}
