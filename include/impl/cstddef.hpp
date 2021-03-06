#ifndef JESSY_CPPLIB_IMPL_CSTDDEF
#define JESSY_CPPLIB_IMPL_CSTDDEF

#include <stddef.h>  // NOLINT

namespace std::impl
{

  inline namespace cstddef
  {

    using ::max_align_t;
    using ::ptrdiff_t;
    using ::size_t;

    using nullptr_t = decltype(nullptr);

    enum class byte : unsigned char
    {
    };

    template<typename IntType>
    constexpr auto operator<<(byte b, IntType shift) noexcept -> byte
    {
      return static_cast<byte>(static_cast<unsigned char>(b) << shift);
    }

    template<typename IntType>
    constexpr auto operator<<=(byte & b, IntType shift) noexcept -> byte &
    {
      return b = (b << shift);
    }

    template<typename IntType>
    constexpr auto operator>>(byte b, IntType shift) noexcept -> byte
    {
      return static_cast<byte>(static_cast<unsigned char>(b) >> shift);
    }

    template<typename IntType>
    constexpr auto operator>>=(byte & b, IntType shift) noexcept -> byte &
    {
      return b = (b >> shift);
    }

    constexpr auto operator|(byte l, byte r) noexcept -> byte
    {
      return static_cast<byte>(static_cast<unsigned char>(l) | static_cast<unsigned char>(r));
    }

    constexpr auto operator|=(byte & l, byte r) noexcept -> byte
    {
      return l = (l | r);
    }

    constexpr auto operator&(byte l, byte r) noexcept -> byte
    {
      return static_cast<byte>(static_cast<unsigned char>(l) & static_cast<unsigned char>(r));
    }

    constexpr auto operator&=(byte & l, byte r) noexcept -> byte
    {
      return l = (l & r);
    }

    constexpr auto operator^(byte l, byte r) noexcept -> byte
    {
      return static_cast<byte>(static_cast<unsigned char>(l) ^ static_cast<unsigned char>(r));
    }

    constexpr auto operator^=(byte & l, byte r) noexcept -> byte
    {
      return l = (l ^ r);
    }

    constexpr auto operator~(byte b) noexcept -> byte
    {
      return static_cast<byte>(~static_cast<unsigned char>(b));
    }

    template<typename IntType>
    constexpr auto to_integer(byte b) noexcept -> IntType
    {
      return static_cast<IntType>(b);
    }

  }  // namespace cstddef

}  // namespace std::impl

#endif