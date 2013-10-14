// string_type.hpp  ----------------------------------------------------------//

// Copyright 2011-2013 Renato Tegon Forti

// Distributed under the Boost Software License, Version 1.0.
// See http://www.boost.org/LICENSE_1_0.txt

// Revision History
// 04-03-2013 dd-mm-yyyy - Initial Release

#ifndef BOOST_APPLICATION_BASE_TYPE_HPP
#define BOOST_APPLICATION_BASE_TYPE_HPP

// app
#include <boost/application/config.hpp>

namespace boost { namespace application {
   
   // This is a fundamental type for Boost.Application,
   // it is used to pack string, args, paths values, 
   // with it we can handle unicode (windows) and others
   // neededs types required by application lib
   template <typename Type>
   class  base_type
   {
   public:
      explicit base_type(const Type &s) 
         : s_(s) 
      {}

      const Type& get() const
      {
         return s_;
      }

   private:
      Type s_;
   };

   // pack for characters types used by application lib
   struct character_types
   {
      // basic string types to be used by application lib
#if defined(BOOST_APPLICATION_STD_WSTRING)
      typedef wchar_t char_type;
#else
      typedef char char_type;
#endif 
      typedef std::basic_string<char_type> string_type;
   };


}} // boost::application   

#endif // BOOST_APPLICATION_BASE_TYPE_HPP

