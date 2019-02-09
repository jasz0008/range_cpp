# range_cpp
C++ implementation of Python range function

### Build
```
git clone https://github.com/jasz0008/range-cpp.git
mkdir -p range-cpp/_build % cd range-cpp/_build
cmake -G "Unix Makefiles" ..
cmake --build .
```

### Usage
```cpp
#include <rangecpp/range.hpp>
#include <vector>
...

std::vector<int> a(42);
std::vector<int> b(42);
std::vector<int> c(42);

for (const size_t i: range(42)) {
   a[i] = b[i] + c[i];
}

```
