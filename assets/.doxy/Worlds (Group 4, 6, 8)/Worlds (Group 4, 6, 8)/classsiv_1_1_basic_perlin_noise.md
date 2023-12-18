

# Class siv::BasicPerlinNoise

**template &lt;class Float class Float&gt;**



[**ClassList**](annotated.md) **>** [**siv**](namespacesiv.md) **>** [**BasicPerlinNoise**](classsiv_1_1_basic_perlin_noise.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::mt19937 | [**default\_random\_engine**](#typedef-default_random_engine)  <br> |
| typedef typename default\_random\_engine::result\_type | [**seed\_type**](#typedef-seed_type)  <br> |
| typedef std::array&lt; std::uint8\_t, 256 &gt; | [**state\_type**](#typedef-state_type)  <br> |
| typedef Float | [**value\_type**](#typedef-value_type)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  SIVPERLIN\_NODISCARD\_CXX20 constexpr | [**BasicPerlinNoise**](#function-basicperlinnoise-13) () noexcept<br> |
|  SIVPERLIN\_NODISCARD\_CXX20 | [**BasicPerlinNoise**](#function-basicperlinnoise-23) (seed\_type seed) <br> |
|  SIVPERLIN\_CONCEPT\_URBG SIVPERLIN\_NODISCARD\_CXX20 | [**BasicPerlinNoise**](#function-basicperlinnoise-33) (URBG && urbg) <br> |
|  constexpr void | [**deserialize**](#function-deserialize) (const state\_type & state) noexcept<br> |
|  value\_type | [**noise1D**](#function-noise1d) (value\_type x) noexcept const<br> |
|  value\_type | [**noise1D\_01**](#function-noise1d_01) (value\_type x) noexcept const<br> |
|  value\_type | [**noise2D**](#function-noise2d) (value\_type x, value\_type y) noexcept const<br> |
|  value\_type | [**noise2D\_01**](#function-noise2d_01) (value\_type x, value\_type y) noexcept const<br> |
|  value\_type | [**noise3D**](#function-noise3d) (value\_type x, value\_type y, value\_type z) noexcept const<br> |
|  value\_type | [**noise3D\_01**](#function-noise3d_01) (value\_type x, value\_type y, value\_type z) noexcept const<br> |
|  value\_type | [**normalizedOctave1D**](#function-normalizedoctave1d) (value\_type x, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**normalizedOctave1D\_01**](#function-normalizedoctave1d_01) (value\_type x, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**normalizedOctave2D**](#function-normalizedoctave2d) (value\_type x, value\_type y, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**normalizedOctave2D\_01**](#function-normalizedoctave2d_01) (value\_type x, value\_type y, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**normalizedOctave3D**](#function-normalizedoctave3d) (value\_type x, value\_type y, value\_type z, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**normalizedOctave3D\_01**](#function-normalizedoctave3d_01) (value\_type x, value\_type y, value\_type z, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave1D**](#function-octave1d) (value\_type x, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave1D\_01**](#function-octave1d_01) (value\_type x, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave1D\_11**](#function-octave1d_11) (value\_type x, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave2D**](#function-octave2d) (value\_type x, value\_type y, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave2D\_01**](#function-octave2d_01) (value\_type x, value\_type y, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave2D\_11**](#function-octave2d_11) (value\_type x, value\_type y, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave3D**](#function-octave3d) (value\_type x, value\_type y, value\_type z, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave3D\_01**](#function-octave3d_01) (value\_type x, value\_type y, value\_type z, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  value\_type | [**octave3D\_11**](#function-octave3d_11) (value\_type x, value\_type y, value\_type z, std::int32\_t octaves, value\_type persistence=value\_type(0.5)) noexcept const<br> |
|  void | [**reseed**](#function-reseed-12) (seed\_type seed) <br> |
|  SIVPERLIN\_CONCEPT\_URBG void | [**reseed**](#function-reseed-22) (URBG && urbg) <br> |
|  constexpr const state\_type & | [**serialize**](#function-serialize) () noexcept const<br> |




























## Public Types Documentation




### typedef default\_random\_engine 

```C++
using default_random_engine =  std::mt19937;
```






### typedef seed\_type 

```C++
using seed_type =  typename default_random_engine::result_type;
```






### typedef state\_type 

```C++
using state_type =  std::array<std::uint8_t, 256>;
```






### typedef value\_type 

```C++
using value_type =  Float;
```



## Public Functions Documentation




### function BasicPerlinNoise [1/3]

```C++
inline SIVPERLIN_NODISCARD_CXX20 constexpr siv::BasicPerlinNoise::BasicPerlinNoise () noexcept
```






### function BasicPerlinNoise [2/3]

```C++
inline explicit SIVPERLIN_NODISCARD_CXX20 siv::BasicPerlinNoise::BasicPerlinNoise (
    seed_type seed
) 
```






### function BasicPerlinNoise [3/3]

```C++
inline explicit SIVPERLIN_CONCEPT_URBG SIVPERLIN_NODISCARD_CXX20 siv::BasicPerlinNoise::BasicPerlinNoise (
    URBG && urbg
) 
```






### function deserialize 

```C++
inline constexpr void siv::BasicPerlinNoise::deserialize (
    const state_type & state
) noexcept
```






### function noise1D 

```C++
inline value_type siv::BasicPerlinNoise::noise1D (
    value_type x
) noexcept const
```






### function noise1D\_01 

```C++
inline value_type siv::BasicPerlinNoise::noise1D_01 (
    value_type x
) noexcept const
```






### function noise2D 

```C++
inline value_type siv::BasicPerlinNoise::noise2D (
    value_type x,
    value_type y
) noexcept const
```






### function noise2D\_01 

```C++
inline value_type siv::BasicPerlinNoise::noise2D_01 (
    value_type x,
    value_type y
) noexcept const
```






### function noise3D 

```C++
inline value_type siv::BasicPerlinNoise::noise3D (
    value_type x,
    value_type y,
    value_type z
) noexcept const
```






### function noise3D\_01 

```C++
inline value_type siv::BasicPerlinNoise::noise3D_01 (
    value_type x,
    value_type y,
    value_type z
) noexcept const
```






### function normalizedOctave1D 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave1D (
    value_type x,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function normalizedOctave1D\_01 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave1D_01 (
    value_type x,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function normalizedOctave2D 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave2D (
    value_type x,
    value_type y,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function normalizedOctave2D\_01 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave2D_01 (
    value_type x,
    value_type y,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function normalizedOctave3D 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave3D (
    value_type x,
    value_type y,
    value_type z,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function normalizedOctave3D\_01 

```C++
inline value_type siv::BasicPerlinNoise::normalizedOctave3D_01 (
    value_type x,
    value_type y,
    value_type z,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave1D 

```C++
inline value_type siv::BasicPerlinNoise::octave1D (
    value_type x,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave1D\_01 

```C++
inline value_type siv::BasicPerlinNoise::octave1D_01 (
    value_type x,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave1D\_11 

```C++
inline value_type siv::BasicPerlinNoise::octave1D_11 (
    value_type x,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave2D 

```C++
inline value_type siv::BasicPerlinNoise::octave2D (
    value_type x,
    value_type y,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave2D\_01 

```C++
inline value_type siv::BasicPerlinNoise::octave2D_01 (
    value_type x,
    value_type y,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave2D\_11 

```C++
inline value_type siv::BasicPerlinNoise::octave2D_11 (
    value_type x,
    value_type y,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave3D 

```C++
inline value_type siv::BasicPerlinNoise::octave3D (
    value_type x,
    value_type y,
    value_type z,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave3D\_01 

```C++
inline value_type siv::BasicPerlinNoise::octave3D_01 (
    value_type x,
    value_type y,
    value_type z,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function octave3D\_11 

```C++
inline value_type siv::BasicPerlinNoise::octave3D_11 (
    value_type x,
    value_type y,
    value_type z,
    std::int32_t octaves,
    value_type persistence=value_type(0.5)
) noexcept const
```






### function reseed [1/2]

```C++
inline void siv::BasicPerlinNoise::reseed (
    seed_type seed
) 
```






### function reseed [2/2]

```C++
inline SIVPERLIN_CONCEPT_URBG void siv::BasicPerlinNoise::reseed (
    URBG && urbg
) 
```






### function serialize 

```C++
inline constexpr const state_type & siv::BasicPerlinNoise::serialize () noexcept const
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/PerlinNoise.hpp`

