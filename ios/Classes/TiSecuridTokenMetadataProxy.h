/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2011 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import "TiProxy.h"
#import "TiUtils.h"
#import "SecurIDTokenProtocol.h"

@interface TiSecuridTokenMetadataProxy : TiProxy {
    NSObject<SecurIDTokenProtocol>* token;
}

-(id)initWithToken:(NSObject<SecurIDTokenProtocol>*)value;
+(id)proxyWithToken:(NSObject<SecurIDTokenProtocol>*)value;

@end
