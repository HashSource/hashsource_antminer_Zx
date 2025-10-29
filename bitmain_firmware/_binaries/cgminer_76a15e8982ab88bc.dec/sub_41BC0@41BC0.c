int __fastcall sub_41BC0(int a1, int a2)
{
  int result; // r0

  switch ( a2 % 8 )
  {
    case 0:
      result = *(_BYTE *)(a1 + a2 / 8) & 1;
      break;
    case 1:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 1) & 1;
      break;
    case 2:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 2) & 1;
      break;
    case 3:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 3) & 1;
      break;
    case 4:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 4) & 1;
      break;
    case 5:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 5) & 1;
      break;
    case 6:
      result = (*(unsigned __int8 *)(a1 + a2 / 8) >> 6) & 1;
      break;
    case 7:
      result = *(unsigned __int8 *)(a1 + a2 / 8) >> 7;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
