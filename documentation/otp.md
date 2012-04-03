# Ti.SecurID.Otp

## Description
The Otp class contains the following information:

* One-time password (OTP) value that was generated upon request
* Number of seconds remaining before the OTP changes.

## Properties

### string otp [read-only]
Gets the OTP value.

### int timeRemaining [read-only]
Gets the time remaining in the current OTP interval.