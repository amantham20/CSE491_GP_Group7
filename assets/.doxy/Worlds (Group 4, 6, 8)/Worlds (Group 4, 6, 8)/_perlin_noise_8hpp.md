

# File PerlinNoise.hpp



[**FileList**](files.md) **>** [**source**](dir_b2f33c71d4aa5e7af42a1ca61ff5af1b.md) **>** [**Worlds**](dir_9813a27ecb6dbdc5ed22cda8cf865019.md) **>** [**PerlinNoise.hpp**](_perlin_noise_8hpp.md)

[Go to the source code of this file](_perlin_noise_8hpp_source.md)



* `#include <cstdint>`
* `#include <algorithm>`
* `#include <array>`
* `#include <iterator>`
* `#include <numeric>`
* `#include <random>`
* `#include <type_traits>`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**siv**](namespacesiv.md) <br> |
| namespace | [**perlin\_detail**](namespacesiv_1_1perlin__detail.md) <br> |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**BasicPerlinNoise**](classsiv_1_1_basic_perlin_noise.md) &lt;class Float&gt;<br> |

















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**SIVPERLIN\_CONCEPT\_URBG**](_perlin_noise_8hpp.md#define-sivperlin_concept_urbg)  template &lt;class URBG, std::enable\_if\_t&lt;std::conjunction\_v&lt;std::is\_invocable&lt;URBG&&gt;, std::is\_unsigned&lt;std::invoke\_result\_t&lt;URBG&&gt;&gt;&gt;&gt;\* = nullptr&gt;<br> |
| define  | [**SIVPERLIN\_CONCEPT\_URBG\_**](_perlin_noise_8hpp.md#define-sivperlin_concept_urbg_)  template &lt;class URBG, std::enable\_if\_t&lt;std::conjunction\_v&lt;std::is\_invocable&lt;URBG&&gt;, std::is\_unsigned&lt;std::invoke\_result\_t&lt;URBG&&gt;&gt;&gt;&gt;\*&gt;<br> |
| define  | [**SIVPERLIN\_DEFAULT\_Y**](_perlin_noise_8hpp.md#define-sivperlin_default_y)  (0.12345)<br> |
| define  | [**SIVPERLIN\_DEFAULT\_Z**](_perlin_noise_8hpp.md#define-sivperlin_default_z)  (0.34567)<br> |
| define  | [**SIVPERLIN\_NODISCARD\_CXX20**](_perlin_noise_8hpp.md#define-sivperlin_nodiscard_cxx20)  <br> |
| define  | [**SIVPERLIN\_VERSION**](_perlin_noise_8hpp.md#define-sivperlin_version)  ((SIVPERLIN\_VERSION\_MAJOR \* 100 \* 100) + (SIVPERLIN\_VERSION\_MINOR \* 100) + (SIVPERLIN\_VERSION\_REVISION))<br> |
| define  | [**SIVPERLIN\_VERSION\_MAJOR**](_perlin_noise_8hpp.md#define-sivperlin_version_major)  3<br> |
| define  | [**SIVPERLIN\_VERSION\_MINOR**](_perlin_noise_8hpp.md#define-sivperlin_version_minor)  0<br> |
| define  | [**SIVPERLIN\_VERSION\_REVISION**](_perlin_noise_8hpp.md#define-sivperlin_version_revision)  0<br> |

## Macro Definition Documentation





### define SIVPERLIN\_CONCEPT\_URBG 

```C++
#define SIVPERLIN_CONCEPT_URBG template <class URBG, std::enable_if_t<std::conjunction_v<std::is_invocable<URBG&>, std::is_unsigned<std::invoke_result_t<URBG&>>>>* = nullptr>
```






### define SIVPERLIN\_CONCEPT\_URBG\_ 

```C++
#define SIVPERLIN_CONCEPT_URBG_ template <class URBG, std::enable_if_t<std::conjunction_v<std::is_invocable<URBG&>, std::is_unsigned<std::invoke_result_t<URBG&>>>>*>
```






### define SIVPERLIN\_DEFAULT\_Y 

```C++
#define SIVPERLIN_DEFAULT_Y (0.12345)
```






### define SIVPERLIN\_DEFAULT\_Z 

```C++
#define SIVPERLIN_DEFAULT_Z (0.34567)
```






### define SIVPERLIN\_NODISCARD\_CXX20 

```C++
#define SIVPERLIN_NODISCARD_CXX20 
```






### define SIVPERLIN\_VERSION 

```C++
#define SIVPERLIN_VERSION ((SIVPERLIN_VERSION_MAJOR * 100 * 100) + (SIVPERLIN_VERSION_MINOR * 100) + (SIVPERLIN_VERSION_REVISION))
```






### define SIVPERLIN\_VERSION\_MAJOR 

```C++
#define SIVPERLIN_VERSION_MAJOR 3
```






### define SIVPERLIN\_VERSION\_MINOR 

```C++
#define SIVPERLIN_VERSION_MINOR 0
```






### define SIVPERLIN\_VERSION\_REVISION 

```C++
#define SIVPERLIN_VERSION_REVISION 0
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/PerlinNoise.hpp`

