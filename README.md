# Foxtrot-OTP
This is a C++ class-based implementation of the one-time pad cryptographic method.

##Small Disclaimer Before we begin:

<b>This implementation is not necessarily cryptographically secure.</b> While the one-time-pad method itself is secure, this 
implementation may not (is probably not, in fact) commercially secure. This is because no secure memory management takes place - keys and plain-text are passed around as `std::string` and `std::vector<int>`, so may reside in memory after the termination of the application.

It is therefore not advisable to implement Foxtrot on a shared computer with the expectation of security.
