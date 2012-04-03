/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2011 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import "TiSecuridTokenMetadataProxy.h"

@implementation TiSecuridTokenMetadataProxy

-(id)initWithToken:(NSObject<SecurIDTokenProtocol>*)value
{
    if ((self = [super init])) {
        token = [value retain];
    }
    return self;
}

+(id)proxyWithToken:(NSObject<SecurIDTokenProtocol>*)value
{
    return [[[TiSecuridTokenMetadataProxy alloc] initWithToken:value] autorelease];
}

-(void)dealloc
{
    RELEASE_TO_NIL(token);
    [super dealloc];
}

#pragma mark Properties

-(id)nickname
{
    return [token tokenNickname];
}
-(id)serialNumber
{
    return [token tokenSerialNumber];
}
-(id)interval
{
    return NUMINT([token otpInterval]);
}
-(id)length
{
    return NUMINT([token otpDigits]);
}
-(id)type
{
    return NUMINT([token tokenType]);
}
-(id)expirationDate
{
    return NUMINT([token tokenExpirationDate]);
}

#pragma mark Methods

-(id)isTokenExpiring:(id)arg
{
    ENSURE_SINGLE_ARG(arg, NSNumber);
    return NUMINT([arg compare:[self expirationDate]]);
}

@end
