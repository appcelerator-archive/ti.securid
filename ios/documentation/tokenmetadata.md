# Ti.SecurID.TokenMetadata

## Description

This class provides access to token metadata.

## Methods

### bool isTokenExpired(int currentTime)
Checks for token expiration

## Properties

### string nickname
Gets or sets token nickname

###string serialNumber [read-only]
Gets token serial number

### string deviceBindingData [read-only]
Reserved for use by RSA

### int interval [read-only]
Gets interval in seconds between the current one-time password (OTP) and the next OTP

### int length [read-only]
Gets length of one-time password (OTP)

### int mode [read-only]
Reserved for use by RSA

### int type [read-only]
Gets token type

### int expirationDate [read-only]
Gets token expiration date