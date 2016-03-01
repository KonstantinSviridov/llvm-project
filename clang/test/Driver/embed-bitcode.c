// RUN: %clang -ccc-print-bindings -c %s -fembed-bitcode 2>&1 | FileCheck %s
// CHECK: clang
// CHECK: clang

// RUN: %clang %s -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-CC
// CHECK-CC: -cc1
// CHECK-CC: -emit-llvm-bc
// CHECK-CC: -cc1
// CHECK-CC: -emit-obj
// CHECK-CC: -fembed-bitcode
// CHECK-CC: ld
// CHECK-CC: -bitcode_bundle

// RUN: %clang %s -save-temps -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-SAVE-TEMP
// CHECK-SAVE-TEMP: -cc1
// CHECK-SAVE-TEMP: -E
// CHECK-SAVE-TEMP: -cc1
// CHECK-SAVE-TEMP: -emit-llvm-bc
// CHECK-SAVE-TEMP: -cc1
// CHECK-SAVE-TEMP: -S
// CHECK-SAVE-TEMP: -fembed-bitcode
// CHECK-SAVE-TEMP: -cc1as
// CHECK-SAVE-TEMP: ld
// CHECK-SAVE-TEMP: -bitcode_bundle

// RUN: %clang -c %s -flto -fembed-bitcode 2>&1 -### | FileCheck %s -check-prefix=CHECK-LTO
// CHECK-LTO: -cc1
// CHECK-LTO: -emit-llvm-bc
// CHECK-LTO-NOT: warning: argument unused during compilation: '-fembed-bitcode'
// CHECK-LTO-NOT: -cc1
// CHECK-LTO-NOT: -fembed-bitcode

// RUN: %clang -c %s -fembed-bitcode-marker 2>&1 -### | FileCheck %s -check-prefix=CHECK-MARKER
// CHECK-MARKER: -cc1
// CHECK-MARKER: -emit-obj
// CHECK-MARKER: -fembed-bitcode-marker
// CHECK-MARKER-NOT: -cc1

