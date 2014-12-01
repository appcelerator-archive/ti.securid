//
//  SecurIDTokenProtocol.h
//  SecurIDLib
//
//  Copyright (c) 2010-2012 EMC Corporation. All Rights Reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  Enumeration of token types.
 *
 */
typedef enum _IPS_TOKEN_TYPE
{
    /*! \brief Undefined token type. */
    IPS_TOKEN_TYPE_UNDEFINED  = -1,
    /*! \brief PINless token. */
    IPS_TOKEN_TYPE_PINLESS    = 1,
    /*! \brief Fob-style token. */
    IPS_TOKEN_TYPE_KEYFOB     = 2,
    /*! \brief PINpad-style token. */
    IPS_TOKEN_TYPE_PINPAD     = 3
} IPS_TOKEN_TYPE;


/*!
 *  The SecurIDTokenProtocol defines the interface for metadata associated with a token.
 *
 */
@protocol SecurIDTokenProtocol

/*! \brief Get token nickname.
 *
 *  \return Return token nickname.
 */
-(NSString*)tokenNickname;

/*! \brief Get token serial number.
 *
 *  \return Return token serial number.
 */
-(NSString*)tokenSerialNumber;

/*! \brief Get token interval.
 *
 *  \return Return token interval in seconds (30 or 60).
 */
-(NSInteger)otpInterval;

/*! \brief Get OTP length (6 or 8 digits).
 *
 *  \return Return OTP length.
 */
-(NSInteger)otpDigits;

/*! \brief Get token type.
 *
 *  \return Return token type (see IPS_TOKEN_TYPE).
 */
-(IPS_TOKEN_TYPE)tokenType;

/*! \brief Get token expiration.
 *
 *  \return Return token expiration (seconds since midnight UTC of January 1, 1970).
 */
-(NSUInteger)tokenExpirationDate;

/*! \brief Determine if token supports transaction signing.
 *
 *  \return Return YES if token supports transaction signing, otherwise NO is returned.
 */
-(BOOL)supportsTransactionSigning;



@end
