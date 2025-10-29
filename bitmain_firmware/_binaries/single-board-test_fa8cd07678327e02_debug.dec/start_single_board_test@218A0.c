void start_single_board_test()
{
  pcba_runtime_init(cgpu.runtime);
  if ( !bm1744_hashboard_init() )
  {
    start_read_temp();
    singleboard_pattern_test();
    stop_read_temp();
  }
  pcba_runtime_exit(cgpu.runtime);
}
