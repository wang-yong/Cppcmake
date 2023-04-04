/*
 * Copyright (c) 2023 Tencent Inc. All rights reserved.
 * @CreateTime   : 2023-04-04 15:48:33
 * @Author       : yowang
 * @Desctiption  :
 */
//
// Created by seanxfpan on 5/11/22.
// Copyright (c) 2022 Tencent. All rights reserved.
//

// 这个测试验证了 clock_gettime 获取纳秒时间的逻辑性能和 gettimeofday 差不多
// 在容器的 kvm clock 实现中
// 考虑到 gettimeofday 已经被废弃, 后续可以使用 clock_gettime 代替
//
// 2022-05-11T07:46:01+00:00
// Running /tmp/green_land/cmake-build-release/src/common/clock/clock_benchmark
// Run on (16 X 2494.14 MHz CPU s)
// CPU Caches:
//  L1 Data 32 KiB (x16)
//  L1 Instruction 32 KiB (x16)
//  L2 Unified 4096 KiB (x16)
//  L3 Unified 28160 KiB (x1)
// Load Average: 2.05, 2.87, 2.03
//-----------------------------------------------------------
// Benchmark                 Time             CPU   Iterations
//-----------------------------------------------------------
// BM_gettimeofday        29.2 ns         29.2 ns     23462218
// BM_clock_gettime       29.8 ns         29.8 ns     23468774

#include <benchmark/benchmark.h>
#include <sys/time.h> // NOLINT(modernize-deprecated-headers) // 测试用

namespace test {
inline uint64_t getNowUs() {
  struct timeval tv {};
  gettimeofday(&tv, nullptr);
  return tv.tv_sec * 1000000 + tv.tv_usec;
}
inline uint64_t getNowUsByClock() {
  struct timespec tv {};
  clock_gettime(CLOCK_REALTIME, &tv);
  return tv.tv_sec * 1000000 + tv.tv_nsec / 1000;
}
} // namespace test

static void BM_clock_gettime(benchmark::State &state) {
  for (auto _ : state) {
    test::getNowUsByClock();
  }
}
static void BM_gettimeofday(benchmark::State &state) {
  for (auto _ : state) {
    test::getNowUs();
  }
}

BENCHMARK(BM_gettimeofday);
BENCHMARK(BM_clock_gettime);

BENCHMARK_MAIN();
