int sub_1AB08()
{
  int v0; // r4
  int v1; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r3
  char v6[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_75C49 )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 6 )
      goto LABEL_31;
    strcpy(v6, "Received kill message");
    sub_385C8(7, v6, 1);
    if ( byte_75C49 )
    {
      if ( byte_77B70 || byte_75C48 )
      {
LABEL_7:
        strcpy(v6, "Killing off watchpool thread");
        sub_385C8(7, v6, 1);
        goto LABEL_8;
      }
LABEL_31:
      if ( dword_73504 <= 6 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
LABEL_8:
  sub_2F2A8((int)sub_2A36C, dword_77F24 + (dword_73EE8 << 6), 1000);
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v6, "Killing off watchdog thread");
    sub_385C8(7, v6, 1);
  }
  sub_2F2A8((int)sub_2A36C, dword_77F24 + (dword_73EEC << 6), 1000);
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v6, "Shutting down mining threads");
    sub_385C8(7, v6, 1);
  }
  if ( dword_78994 > 0 )
  {
    v0 = 0;
    do
    {
      v1 = v0++;
      v2 = sub_1AA90(v1);
      v3 = dword_78994;
      if ( v2 )
      {
        v4 = *(_DWORD *)(v2 + 36);
        if ( v4 )
          *(_BYTE *)(v4 + 364) = 1;
      }
    }
    while ( v0 < v3 );
  }
  sleep(1u);
  sub_2F2A8((int)sub_1AE44, 0, 3000);
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    strcpy(v6, "Killing off API thread");
    sub_385C8(7, v6, 1);
  }
  return sub_2F2A8((int)sub_2A36C, dword_77F24 + (dword_73D30 << 6), 1000);
}
