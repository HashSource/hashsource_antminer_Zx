int __fastcall sub_3387C(int a1, int a2, _BYTE *a3, int a4)
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
        v8 = (unsigned __int8)byte_78E09 ^ 1;
        byte_78E09 ^= 1u;
        byte_78E08 = v8;
        if ( v8 )
          goto LABEL_4;
        break;
      case 'n':
        byte_78E08 = 0;
        byte_78E09 = 0;
        byte_7BC78 = 0;
        byte_7B380 = 0;
        byte_7B858 = 0;
        byte_7B85A = 0;
        break;
      case 'p':
        byte_7B858 ^= 1u;
        byte_78E08 = byte_7B858;
        break;
      case 'q':
        byte_7BC78 ^= 1u;
        break;
      case 'r':
        v25 = &byte_7B380;
        goto LABEL_15;
      case 's':
        byte_7BB18 = 1;
        break;
      case 'v':
        v25 = &byte_78E08;
LABEL_15:
        v26 = (unsigned __int8)*v25 ^ 1;
        *v25 = v26;
        if ( v26 )
LABEL_4:
          byte_7BC78 = 0;
        break;
      case 'w':
        byte_7B85A ^= 1u;
        break;
      default:
        break;
    }
  }
  sub_3305C((unsigned int *)a1, 79, 0, 0, a4);
  if ( a4 )
  {
    v9 = sub_307C8((unsigned int *)a1, ",\"DEBUG\":[");
    v10 = sub_32FF0(0, "Silent", &byte_7BB18, 0);
    v11 = sub_32FF0(v10, "Quiet", &byte_7BC78, 0);
    v12 = sub_32FF0(v11, "Verbose", &byte_78E08, 0);
    v13 = sub_32FF0(v12, "Debug", &byte_78E09, 0);
    v14 = sub_32FF0(v13, "RPCProto", &byte_7B380, 0);
    v15 = sub_32FF0(v14, "PerDevice", &byte_7B858, 0);
    v16 = sub_32FF0(v15, "WorkTime", &byte_7B85A, 0);
    result = sub_32534((unsigned int *)a1, (int)v16, 1, 0);
    if ( v9 )
      *(_BYTE *)(a1 + 13) = 1;
  }
  else
  {
    sub_307C8((unsigned int *)a1, "DEBUG,");
    v18 = sub_32FF0(0, "Silent", &byte_7BB18, 0);
    v19 = sub_32FF0(v18, "Quiet", &byte_7BC78, 0);
    v20 = sub_32FF0(v19, "Verbose", &byte_78E08, 0);
    v21 = sub_32FF0(v20, "Debug", &byte_78E09, 0);
    v22 = sub_32FF0(v21, "RPCProto", &byte_7B380, 0);
    v23 = sub_32FF0(v22, "PerDevice", &byte_7B858, 0);
    v24 = sub_32FF0(v23, "WorkTime", &byte_7B85A, 0);
    return sub_32534((unsigned int *)a1, (int)v24, 0, 0);
  }
  return result;
}
