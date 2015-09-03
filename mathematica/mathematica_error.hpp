// ====================================================================
// Exception types for Mathematica link
// ====================================================================

#ifndef MATHEMATICA_ERROR_H
#define MATHEMATICA_ERROR_H

#include <string>

namespace mathematica {

class Error {
public:
   virtual ~Error() {}
   virtual std::string what() const = 0;
};

/**
 * @class InitializationError
 * @brief Initialization of Mathematica environment failed
 */
class InitializationError : public Error {
public:
   explicit InitializationError(const std::string& message_)
      : message(message_)
      {}
   virtual ~InitializationError() {}
   virtual std::string what() const { return message; }
private:
   std::string message;
};

/**
 * @class LinkOpenError
 * @brief Opening link to Mathematica failed
 */
class LinkOpenError : public Error {
public:
   explicit LinkOpenError(const std::string& message_)
      : message(message_)
      {}
   virtual ~LinkOpenError() {}
   virtual std::string what() const { return message; }
private:
   std::string message;
};

} // namespace mathematica

#endif
