# Ti.SecurID Module

## Description

The RSA SecurID Software Token API provides classes to implement, manage, and use RSA SecurID software tokens running on mobile devices.

## Getting Started

View the [Using Titanium Modules](http://docs.appcelerator.com/titanium/2.0/#!/guide/Using_Titanium_Modules) document for instructions on getting
started with using this module in your application.

## Accessing the Ti.SecurID Module

To access this module from JavaScript, you would do the following:

	var securID = require("ti.securid");


## Methods

### void importTokenFromCtf(string ctfString, string tokenPassword)
Imports a token from a CTF String and stores it in the token database.

### void importTokenFromCtkip(string ctkipUrl, string ctkipActivationCode, bool acceptUntrustedCertificates)
Imports a token record using CT-KIP and stores it in the token database.

### void importTokenFromFile(string tokenFilePath, string tokenFilePassword)
Imports a token record from an SDTID file and stores it in the token database.

### [Ti.SecurID.TokenMetadata][][] retrieveTokens()
Gets a list of all token records currently stored in the token database.

### [Ti.SecurID.Otp][] retrieveOtp(string serialNumber, string pin)
Gets an Otp object for the current OTP interval.

### [Ti.SecurID.Otp][] retrieveNextOtp(string serialNumber, string pin)
Gets an Otp object for the next OTP interval.

### void deleteToken(string serialNumber)
Deletes the specified token record from the token database.

## Properties

### string libraryInfo [read-only]
Gets the SDK library version information.

### string deviceId [read-only]
Returns an identifier that may be used to bind a token record to a specific device.

## Events

### error
Occurs when there is an error completing one of the methods in this module.

* string error: A localized message about the error.
* string type: The type of error.

## Usage
See example.

## Author
Dawson Toth

## Module History
View the [change log](changelog.html) for this module.

## Feedback and Support
Please direct all questions, feedback, and concerns to [info@appcelerator.com](mailto:info@appcelerator.com?subject=Android%20SecurID%20Module).

## License
Copyright(c) 2010-2011 by Appcelerator, Inc. All Rights Reserved. Please see the LICENSE file included in the distribution for further details.

[Ti.SecurID.Otp]: otp.html
[Ti.SecurID.TokenMetadata]: tokenmetadata.html