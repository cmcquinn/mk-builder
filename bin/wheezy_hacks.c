// Due to assorted bad luck:
// http://stackoverflow.com/a/27944574
//
// There is not a good solution for a gcc 4.7 cross-compile tool-chain
// for Debian Wheezy.  So we use the 4.9 version from Jessie and fixup
// the missing cxxabi features expected by 4.9 but not provided by the
// libstdc++ 4.7 on Wheezy in this file, which is included by hacking
// the compiler calls in the Docker mk-builder images

// A working abi error call from gcc-4.7
extern "C" void
__cxa_bad_typeid();

// Map the missing abi error function to one that actually exists
extern "C" void
__cxa_throw_bad_array_new_length ()
{ __cxa_bad_typeid(); }

