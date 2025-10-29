int __fastcall sub_336EC(int a1, int a2, _BYTE *a3, int a4)
{
  int v7; // r2
  int v8; // r3
  int v9; // r4
  _DWORD *v10; // r0
  _DWORD *v11; // r0
  _DWORD *v12; // r0
  _DWORD *v13; // r0
  _DWORD *v14; // r0
  _DWORD *v15; // r0
  _DWORD *v16; // r0
  int result; // r0
  _DWORD *v18; // r0
  _DWORD *v19; // r0
  _DWORD *v20; // r0
  _DWORD *v21; // r0
  _DWORD *v22; // r0
  _DWORD *v23; // r0
  _DWORD *v24; // r1
  char *v25; // r2
  int v26; // r3

  if ( a3 )
  {
    v7 = LOBYTE((*_ctype_tolower_loc())[(unsigned __int8)*a3]);
    *a3 = v7;
    switch ( v7 )
    {
      case 'd':
        v8 = (unsigned __int8)byte_75C49 ^ 1;
        byte_75C49 ^= 1u;
        byte_75C48 = v8;
        if ( v8 )
          goto LABEL_4;
        break;
      case 'n':
        byte_75C48 = 0;
        byte_75C49 = 0;
        byte_78AA0 = 0;
        byte_781A8 = 0;
        byte_78680 = 0;
        byte_78682 = 0;
        break;
      case 'p':
        byte_78680 ^= 1u;
        byte_75C48 = byte_78680;
        break;
      case 'q':
        byte_78AA0 ^= 1u;
        break;
      case 'r':
        v25 = &byte_781A8;
        goto LABEL_15;
      case 's':
        byte_78940 = 1;
        break;
      case 'v':
        v25 = &byte_75C48;
LABEL_15:
        v26 = (unsigned __int8)*v25 ^ 1;
        *v25 = v26;
        if ( v26 )
LABEL_4:
          byte_78AA0 = 0;
        break;
      case 'w':
        byte_78682 ^= 1u;
        break;
      default:
        break;
    }
  }
  sub_32ECC((unsigned int *)a1, 79, 0, 0, a4);
  if ( a4 )
  {
    v9 = sub_30638((unsigned int *)a1, ",\"DEBUG\":[");
    v10 = sub_32E60(0, "Silent", &byte_78940, 0);
    v11 = sub_32E60(v10, "Quiet", &byte_78AA0, 0);
    v12 = sub_32E60(v11, "Verbose", &byte_75C48, 0);
    v13 = sub_32E60(v12, "Debug", &byte_75C49, 0);
    v14 = sub_32E60(v13, "RPCProto", &byte_781A8, 0);
    v15 = sub_32E60(v14, "PerDevice", &byte_78680, 0);
    v16 = sub_32E60(v15, "WorkTime", &byte_78682, 0);
    result = sub_323A4((unsigned int *)a1, (int)v16, 1, 0);
    if ( v9 )
      *(_BYTE *)(a1 + 13) = 1;
  }
  else
  {
    sub_30638((unsigned int *)a1, "DEBUG,");
    v18 = sub_32E60(0, "Silent", &byte_78940, 0);
    v19 = sub_32E60(v18, "Quiet", &byte_78AA0, 0);
    v20 = sub_32E60(v19, "Verbose", &byte_75C48, 0);
    v21 = sub_32E60(v20, "Debug", &byte_75C49, 0);
    v22 = sub_32E60(v21, "RPCProto", &byte_781A8, 0);
    v23 = sub_32E60(v22, "PerDevice", &byte_78680, 0);
    v24 = sub_32E60(v23, "WorkTime", &byte_78682, 0);
    return sub_323A4((unsigned int *)a1, (int)v24, 0, 0);
  }
  return result;
}
