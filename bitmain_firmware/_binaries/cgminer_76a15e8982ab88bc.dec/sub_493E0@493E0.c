// positive sp value has been detected, the output may be wrong!
void __fastcall sub_493E0(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r4

  *(_DWORD *)(v13 + 1186) = a1;
  *(_DWORD *)(v13 + 1190) = a2;
  *(_DWORD *)(v13 + 1194) = a3;
  *(_DWORD *)(v13 + 1198) = a4;
  sub_48B34(v13);
  __asm { POP             {R4-R11,PC} }
}
