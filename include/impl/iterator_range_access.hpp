#ifndef JESSY_CPPLIB_IMPL_ITERATOR_RANGE_ACCESS_HPP
#define JESSY_CPPLIB_IMPL_ITERATOR_RANGE_ACCESS_HPP

#ifdef __GNUG__
#pragma system_header
#endif

#include <impl/cstddef.hpp>

namespace std::impl
{

  template<typename ContainerType>
  auto constexpr begin(ContainerType & container) -> decltype(container.begin())
  {
    return container.begin();
  }

  template<typename ContainerType>
  auto constexpr begin(ContainerType const & container) -> decltype(container.begin())
  {
    return container.begin();
  }

  template<typename ElementType, std::impl::size_t Size>
  auto constexpr begin(ElementType (&array /* NOLINT */)[Size]) noexcept -> ElementType *
  {
    return &array[0];
  }

  template<typename ContainerType>
  auto constexpr end(ContainerType & container) -> decltype(container.end())
  {
    return container.end();
  }

  template<typename ContainerType>
  auto constexpr end(ContainerType const & container) -> decltype(container.end())
  {
    return container.end();
  }

  template<typename ElementType, std::impl::size_t Size>
  auto constexpr end(ElementType (&array /* NOLINT */)[Size]) noexcept -> ElementType *
  {
    return &array[0] + Size;
  }

}  // namespace std::impl

namespace std
{

  using impl::begin;
  using impl::end;

}  // namespace std

namespace std::impl
{

  template<typename ContainerType>
  auto constexpr cbegin(ContainerType const & container) noexcept(noexcept(std::begin(container)))
      -> decltype(std::begin(container))
  {
    return std::begin(container);
  }

  template<typename ContainerType>
  auto constexpr cend(ContainerType const & container) noexcept(noexcept(std::end(container))) -> decltype(std::end(container))
  {
    return std::end(container);
  }

}  // namespace std::impl

#endif