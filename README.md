# bazel_include_repro

## reproduction

To repro the issue demonstrated by this project, simply run

```bash
./smoke.sh
```

As of Bazel `5.3.2` users should expect to see logs similar to the following:

```
+ for workspace in '${WORKSPACES[@]}'
+ pushd /Users/user/Code/bazel_include_repro/repo_c
+ bazel test //...
INFO: Analyzed 2 targets (0 packages loaded, 0 targets configured).
INFO: Found 1 target and 1 test target...
INFO: Elapsed time: 0.149s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
//lib:repo_test                                                 (cached) PASSED in 0.1s

Executed 0 out of 1 test: 1 test passes.
INFO: Build completed successfully, 1 total action
+ popd
+ for workspace in '${WORKSPACES[@]}'
+ pushd /Users/user/Code/bazel_include_repro/repo_b
+ bazel test //...
INFO: Analyzed 2 targets (0 packages loaded, 0 targets configured).
INFO: Found 1 target and 1 test target...
INFO: Elapsed time: 0.170s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
//lib:repo_test                                                 (cached) PASSED in 0.1s

Executed 0 out of 1 test: 1 test passes.
INFO: Build completed successfully, 1 total action
+ popd
+ for workspace in '${WORKSPACES[@]}'
+ pushd /Users/user/Code/bazel_include_repro/repo_a
+ bazel test //...
INFO: Analyzed 2 targets (0 packages loaded, 0 targets configured).
INFO: Found 1 target and 1 test target...
ERROR: /private/var/tmp/_bazel_user/8c14b48967f1ce9aa170fa8eaa724499/external/repo_b/lib/BUILD.bazel:3:11: Compiling lib/repo_b.cc failed: (Aborted): wrapped_clang_pp failed: error executing command external/local_config_cc/wrapped_clang_pp '-D_FORTIFY_SOURCE=1' -fstack-protector -fcolor-diagnostics -Wall -Wthread-safety -Wself-assign -fno-omit-frame-pointer -O0 -DDEBUG '-std=c++11' ... (remaining 31 arguments skipped)

Use --sandbox_debug to see verbose messages from the sandbox and retain the sandbox build root for debugging
external/repo_b/lib/repo_b.cc:3:10: fatal error: 'external/repo_c/lib/repo_c.h' file not found
#include "external/repo_c/lib/repo_c.h"
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
Error in child process '/usr/bin/xcrun'. 1
INFO: Elapsed time: 0.576s, Critical Path: 0.44s
INFO: 4 processes: 4 internal.
FAILED: Build did NOT complete successfully
//lib:repo_test                                                       NO STATUS

FAILED: Build did NOT complete successfully
```

Note that the issue is also reproducible on Linux.

## Upstream Issue

https://github.com/bazelbuild/bazel/issues/16690
