int __fastcall check_asicnum(int asic_num, unsigned __int8 nonce)
{
  unsigned int v2; // r1
  unsigned int v3; // r1
  int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r1

  switch ( asic_num )
  {
    case 1:
      return asic_num;
    case 2:
      if ( (nonce & 0x80) != 0x80 )
        asic_num = 1;
      break;
    case 4:
      v4 = nonce & 0xC0;
      if ( v4 == 128 )
        goto LABEL_30;
      if ( v4 != 192 )
      {
        if ( v4 == 64 )
          asic_num = 2;
        else
          asic_num = 1;
      }
      break;
    case 8:
      v5 = nonce & 0xE0;
      if ( v5 == 128 )
        goto LABEL_51;
      if ( v5 <= 0x80 )
      {
        if ( v5 == 64 )
          goto LABEL_30;
        if ( v5 == 96 )
          goto LABEL_50;
        if ( v5 != 32 )
          goto LABEL_9;
        goto LABEL_26;
      }
      if ( v5 == 192 )
        goto LABEL_49;
      if ( v5 != 224 )
      {
        if ( v5 != 160 )
          goto LABEL_9;
        goto LABEL_40;
      }
      break;
    case 16:
      v2 = nonce & 0xF0;
      if ( v2 == 128 )
      {
        asic_num = 9;
      }
      else if ( v2 > 0x80 )
      {
        if ( v2 == 192 )
        {
          asic_num = 13;
        }
        else if ( v2 <= 0xC0 )
        {
          switch ( v2 )
          {
            case 0xA0u:
              asic_num = 11;
              break;
            case 0xB0u:
              asic_num = 12;
              break;
            case 0x90u:
              asic_num = 10;
              break;
            default:
              goto LABEL_9;
          }
        }
        else if ( v2 == 224 )
        {
          asic_num = 15;
        }
        else if ( v2 != 240 )
        {
          if ( v2 != 208 )
            goto LABEL_9;
          asic_num = 14;
        }
      }
      else if ( v2 == 64 )
      {
LABEL_51:
        asic_num = 5;
      }
      else if ( v2 > 0x40 )
      {
        switch ( v2 )
        {
          case '`':
LABEL_49:
            asic_num = 7;
            break;
          case 'p':
            asic_num = 8;
            break;
          case 'P':
LABEL_40:
            asic_num = 6;
            break;
          default:
            goto LABEL_9;
        }
      }
      else
      {
        switch ( v2 )
        {
          case 0x20u:
LABEL_30:
            asic_num = 3;
            break;
          case 0x30u:
LABEL_50:
            asic_num = 4;
            break;
          case 0x10u:
LABEL_26:
            asic_num = 2;
            break;
          default:
            goto LABEL_9;
        }
      }
      break;
    case 32:
      v6 = (unsigned __int8)((nonce & 0xF8) - 8);
      if ( v6 > 0xF0 )
        goto LABEL_9;
      asic_num = _func___12024[v6 + 1928];
      break;
    case 64:
      v3 = (unsigned __int8)((nonce & 0xFC) - 4);
      if ( v3 > 0xF8 )
LABEL_9:
        asic_num = 1;
      else
        asic_num = _func___12024[v3 + 2172];
      break;
    default:
      asic_num = 0;
      break;
  }
  return asic_num;
}
