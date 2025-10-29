unsigned int __fastcall sub_3BBA8(int a1, _BYTE *a2, unsigned int a3)
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
      v3 = 4400;
      v4 = 1101;
      goto LABEL_3;
    case 1:
      v3 = 4408;
      v4 = 1103;
      goto LABEL_3;
    case 2:
      v3 = 4416;
      v4 = 1105;
      goto LABEL_3;
    case 3:
      v3 = 4424;
      v4 = 1107;
      goto LABEL_3;
    case 4:
      v3 = 4432;
      v4 = 1109;
      goto LABEL_3;
    case 5:
      v3 = 4440;
      v4 = 1111;
      goto LABEL_3;
    case 6:
      v3 = 4448;
      v4 = 1113;
      goto LABEL_3;
    case 7:
      v3 = 4456;
      v4 = 1115;
      goto LABEL_3;
    case 8:
      v3 = 4464;
      v4 = 1117;
      goto LABEL_3;
    case 9:
      v3 = 4472;
      v4 = 1119;
LABEL_3:
      v5 = a3 >> 2;
      *(_DWORD *)(dword_75C50[0] + v3) = a3 & 0x3FF | 0x80000000;
      if ( a3 >> 2 )
      {
        result = 4 * v5;
        v7 = a2;
        do
        {
          v8 = *(_DWORD *)(dword_75C50[0] + 4 * v4);
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
        v11 = *(_DWORD *)(dword_75C50[0] + 4 * v4);
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
