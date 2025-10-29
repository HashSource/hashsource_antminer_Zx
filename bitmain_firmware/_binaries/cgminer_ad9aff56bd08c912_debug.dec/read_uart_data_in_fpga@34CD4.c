unsigned int __fastcall read_uart_data_in_fpga(unsigned __int8 which_uart, unsigned __int8 *buf, unsigned int length)
{
  int v3; // r0
  int v4; // r9
  unsigned int v5; // r8
  unsigned __int8 *v6; // r3
  unsigned int v7; // r0
  unsigned int result; // r0
  unsigned int v9; // r2
  unsigned __int8 *v10; // r4
  const char *v11; // r0
  unsigned int v12; // [sp+4h] [bp-8h]

  switch ( which_uart )
  {
    case 0u:
      v3 = 132;
      v4 = 133;
      goto LABEL_3;
    case 1u:
      v3 = 134;
      v4 = 135;
      goto LABEL_3;
    case 2u:
      v3 = 136;
      v4 = 137;
      goto LABEL_3;
    case 3u:
      v3 = 138;
      v4 = 139;
      goto LABEL_3;
    case 4u:
      v3 = 140;
      v4 = 141;
      goto LABEL_3;
    case 5u:
      v3 = 142;
      v4 = 143;
      goto LABEL_3;
    case 6u:
      v3 = 144;
      v4 = 145;
      goto LABEL_3;
    case 7u:
      v3 = 146;
      v4 = 147;
      goto LABEL_3;
    case 8u:
      v3 = 148;
      v4 = 149;
      goto LABEL_3;
    case 9u:
      v3 = 150;
      v4 = 151;
LABEL_3:
      v5 = length >> 2;
      axi_fpga_addr[v3] = length & 0x3FF | 0x80000000;
      if ( length >> 2 )
      {
        v6 = buf;
        do
        {
          v6 += 4;
          v7 = axi_fpga_addr[v4];
          *(v6 - 1) = v7;
          *(v6 - 4) = HIBYTE(v7);
          *(v6 - 3) = BYTE2(v7);
          *(v6 - 2) = BYTE1(v7);
        }
        while ( v6 != &buf[4 * v5] );
      }
      result = length & 0xFFFFFFFC;
      v9 = length & 3;
      if ( v9 )
      {
        v10 = &buf[4 * v5];
        v12 = axi_fpga_addr[v4];
        if ( v9 == 2 )
        {
          buf[4 * v5] = HIBYTE(v12);
          v10[1] = BYTE2(v12);
          result += 2;
        }
        else if ( v9 == 3 )
        {
          result += 3;
          buf[4 * v5] = HIBYTE(v12);
          v10[1] = BYTE2(v12);
          v10[2] = BYTE1(v12);
        }
        else
        {
          buf[4 * v5] = HIBYTE(v12);
          ++result;
        }
      }
      break;
    default:
      LOWORD(v11) = -31356;
      HIWORD(v11) = (unsigned int)"a_mem_addr = 0x%x\n" >> 16;
      printf(v11, "read_uart_data_in_fpga", length);
      result = 0;
      break;
  }
  return result;
}
