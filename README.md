# Foxtrot-OTP
This is a C++ class-based implementation of the one-time pad cryptographic method.

<b>Small Disclaimer Before we begin:</b>

<b>This implementation is not necessarily cryptographically secure.</b> WHile the one-time-pad method itself is definitely secure, this 
implementation may not (is probably not, in fact) commercially secure. This is because no secure memory management takes place - keys and plain-text are passed around as `std::string`s and `std::vector<int>`s, so may reside in memory after the termination of the application.

It is therefore not advisable to implement Foxtrot on a shared computer with the expectation of security.
