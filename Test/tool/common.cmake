
MACRO(add_gtest_benchmark target_name)
  add_executable(${target_name} "${target_name}.cc")
  target_link_libraries(${target_name} benchmark ${CMAKE_THREAD_LIBS_INIT} gtest_main)
ENDMACRO()


MACRO(add_gtest_benchmark_default target_name)
  add_gtest_benchmark(${target_name})

  # 这里默认指定了压测最少运行 0.01 秒, 如果实际执行小于这个时间, 则会自动执行多次
  add_test(NAME ${target_name} COMMAND ${target_name} --benchmark_min_time=0.01)
ENDMACRO()