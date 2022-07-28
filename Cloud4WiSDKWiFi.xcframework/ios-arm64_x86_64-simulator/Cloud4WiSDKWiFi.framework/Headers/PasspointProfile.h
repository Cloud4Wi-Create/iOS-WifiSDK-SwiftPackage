//
//  PasspointProfile.h
//  Cloud4WiSDKWiFi
//

#ifndef PasspointProfile_h
#define PasspointProfile_h

@interface PasspointProfile : NSObject

@property NSString *realm;
@property NSString *friendlyName;
@property BOOL roaming;
@property NSString *outerIdentity;
@property NSString *username;
@property NSArray<NSString *> *trustedServerNames;
@property NSString *installedBy;
@property NSDate *installed;

- (instancetype)initWithDictionary:(NSDictionary *) dict;

@end



#endif /* PasspointProfile_h */
