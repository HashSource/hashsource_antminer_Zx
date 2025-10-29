int sub_1B19C()
{
  int v0; // r4
  int v1; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r3
  char v6[4100]; // [sp+0h] [bp-1004h] BYREF

  if ( byte_78E09 )
  {
    if ( !byte_7AD48 && !byte_78E08 && dword_766C4 <= 6 )
      goto LABEL_31;
    strcpy(v6, "Received kill message");
    sub_38730(7, v6, 1);
    if ( byte_78E09 )
    {
      if ( byte_7AD48 || byte_78E08 )
      {
LABEL_7:
        strcpy(v6, "Killing off watchpool thread");
        sub_38730(7, v6, 1);
        goto LABEL_8;
      }
LABEL_31:
      if ( dword_766C4 <= 6 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
LABEL_8:
  sub_2F438((int)sub_2A414, dword_7B0FC + (dword_770B0 << 6), 1000);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v6, "Killing off watchdog thread");
    sub_38730(7, v6, 1);
  }
  sub_2F438((int)sub_2A414, dword_7B0FC + (dword_770B4 << 6), 1000);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v6, "Shutting down mining threads");
    sub_38730(7, v6, 1);
  }
  if ( dword_7BB6C > 0 )
  {
    v0 = 0;
    do
    {
      v1 = v0++;
      v2 = sub_1B124(v1);
      v3 = dword_7BB6C;
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
  sub_2F438((int)sub_1B4D8, 0, 3000);
  if ( byte_78E09 && (byte_7AD48 || byte_78E08 || dword_766C4 > 6) )
  {
    strcpy(v6, "Killing off API thread");
    sub_38730(7, v6, 1);
  }
  return sub_2F438((int)sub_2A414, dword_7B0FC + (dword_76EF8 << 6), 1000);
}
