#! /bin/sh

set -ex

./scripts/tests.sh

cmake -H. -B _builds -DBUILD_COVERAGE=On
cmake --build _builds --target gcov
cmake --build _builds --target test
gcovr -r  . 
