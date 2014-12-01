/**
 * Your Copyright Here
 *
 * Appcelerator Titanium is Copyright (c) 2009-2010 by Appcelerator, Inc.
 * and licensed under the Apache Public License (version 2)
 */
#import "TiSecuridModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"

@implementation TiSecuridModule

#pragma mark Internal

-(id)moduleGUID
{
	return @"48964144-e5ce-4c80-9578-1d95243ca184";
}

-(NSString*)moduleId
{
	return @"ti.securid";
}

#pragma Public APIs

-(id)libraryInfo
{
    int major, minor;
    [SecurIDLib getLibraryInfo:&major minor:&minor];
    return [NSString stringWithFormat:@"%i.%i", major, minor];
}

-(id)deviceId
{
    return [SecurIDLib getDeviceId];
}

-(void)importTokenFromCtf:(id)args
{
    NSString* ctfString = [args objectAtIndex:0];
    NSString* tokenPassword = [args objectAtIndex:1];
    bool acceptUntrustedCert = [args count] > 2 ? [TiUtils boolValue:[args objectAtIndex:2] def:NO] : NO;
    
    NSMutableString* serialNumber = [[NSMutableString alloc] initWithString:@""];
    [[SecurIDLib getInstance] importTokenFromCtf:ctfString
                                     ctfPassword:tokenPassword
                                    serialNumber:serialNumber];
    [serialNumber autorelease];
}

-(void)importTokenFromCtkip:(id)args
{
    NSString* ctkipUrl = [args objectAtIndex:0];
    NSString* ctkipActivationCode = [args objectAtIndex:1];
    bool acceptUntrustedCert = [args count] > 2 ? [TiUtils boolValue:[args objectAtIndex:2] def:NO] : NO;
    
    [[SecurIDLib getInstance] importTokenFromCtkip:ctkipUrl
                                     ctkipAuthCode:ctkipActivationCode
                                      validateCert:acceptUntrustedCert
                                          delegate:self];
}

-(void)importTokenFromFile:(id)args
{
    NSString* tokenFilePath = [args objectAtIndex:0];
    NSString* tokenFilePassword = [args objectAtIndex:1];
    
    NSMutableString* serialNumber = [[NSMutableString alloc] initWithString:@""];
    
    NSURL* fromURL = [TiUtils toURL:[args objectForKey:@"fileURL"] proxy:self];
    
    NSError* error = nil;
    NSURLResponse* response = nil;
    NSURLRequest* fileUrlRequest = [[NSURLRequest alloc] initWithURL:fromURL];
    NSData* fileData = [NSURLConnection 
                        sendSynchronousRequest:fileUrlRequest
                        returningResponse:&response
                        error:&error];
    
    if (error == nil) {
        [[SecurIDLib getInstance] importTokenFromFile:fileData filePassword:tokenFilePassword serialNumber:serialNumber];
    }
    else {
        [self fireEvent:@"error" withObject:[NSDictionary dictionaryWithObjectsAndKeys:
                                             [error localizedDescription],@"error",
                                             NUMINT([error code]),@"type",
                                             nil]];
    }
    [fileUrlRequest release];
    [serialNumber autorelease];
}

-(id)retrieveTokens:(id)args
{
    NSArray* tokenList = [[SecurIDLib getInstance] getTokenList];
    NSMutableArray* retVal = [NSMutableArray arrayWithCapacity:[tokenList count]];
    
    for (NSObject<SecurIDTokenProtocol>* token in tokenList) {
        [retVal addObject:[TiSecuridTokenMetadataProxy proxyWithToken:token]];
    }
    
    return retVal;
}

-(id)retrieveOtp:(id)args
{
    NSString* serialNumber = [args objectAtIndex:0];
    NSString* pin = [args objectAtIndex:1];
    
    NSMutableString* otpString = [[NSMutableString alloc] initWithString:@""];
    NSUInteger secsRemaining = 0;
    
    [[SecurIDLib getInstance] getOtp:serialNumber pin:pin otp:otpString secs:&secsRemaining];
    
    NSDictionary* retVal = [NSDictionary dictionaryWithObjectsAndKeys:
                            otpString, @"otp",
                            NUMINT(secsRemaining), @"timeRemaining",
                            nil];
    [otpString release];
    return retVal;
}

-(id)retrieveNextOtp:(id)args
{
    NSString* serialNumber = [args objectAtIndex:0];
    NSString* pin = [args objectAtIndex:1];
    
    NSMutableString* otpString = [[NSMutableString alloc] initWithString:@""];
    NSUInteger secsRemaining = 0;
    
    [[SecurIDLib getInstance] getNextOtp:serialNumber pin:pin otp:otpString secs:&secsRemaining];
    
    NSDictionary* retVal = [NSDictionary dictionaryWithObjectsAndKeys:
                            otpString, @"otp",
                            NUMINT(secsRemaining), @"timeRemaining",
                            nil];
    [otpString release];
    return retVal;
}

-(void)deleteToken:(id)args
{
    NSString* serialNumber = [args objectAtIndex:0];
    [[SecurIDLib getInstance] deleteToken:serialNumber];
}

#pragma mark SecurIDLib Delegate

/*! \brief Provisioning of a token using CT-KIP successfully completed.
 *
 *  \param [in] serialNumber Serial number of the token that was provisioned.
 */
- (void)ctkipImportFinished:(NSString*)serialNumber
{
    // Note: we don't do anything with this quite yet. Maybe in the future?
    // Android doesn't expose an event like this as of the writing of this module.
}

/*! \brief Provisioning of a token using CT-KIP failed.
 *
 *  \param [in] error Error identifying the failure. ([error code] will contain a SECURID_STATUS code)
 */
- (void)ctkipImportFailed:(NSError*)error
{
    [self fireEvent:@"error" withObject:[NSDictionary dictionaryWithObjectsAndKeys:
                                         [error localizedDescription],@"error",
                                         NUMINT([error code]),@"type",
                                         nil]];
}

@end