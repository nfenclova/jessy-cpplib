#ifndef JESSY_CPPLIB_IMPL_ITERATOR_TAGS_HPP
#define JESSY_CPPLIB_IMPL_ITERATOR_TAGS_HPP

#ifdef __GNUG__
#pragma system_header
#endif

namespace std::impl
{

  struct input_iterator_tag
  {
  };

  struct output_iterator_tag
  {
  };

  struct forward_iterator_tag : input_iterator_tag
  {
  };

  struct bidirectional_iterator_tag : forward_iterator_tag
  {
  };

  struct random_access_iterator_tag : bidirectional_iterator_tag
  {
  };

  struct contiguous_iterator_tag : random_access_iterator_tag
  {
  };

}  // namespace std::impl

#endif