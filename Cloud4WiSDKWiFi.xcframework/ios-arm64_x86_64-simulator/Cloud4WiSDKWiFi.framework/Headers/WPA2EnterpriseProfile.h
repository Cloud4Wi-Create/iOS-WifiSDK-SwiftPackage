//
//  WPA2EnterpriseProfile.h
//  Cloud4WiSDKWiFi
//

#ifndef WPA2EnterpriseProfile_h
#define WPA2EnterpriseProfile_h

@interface WPA2EnterpriseProfile : NSObject

@property NSString *ssid;
@property NSString *outerIdentity;
@property NSString *username;
@property NSArray<NSString *> *trustedServerNames;
@property NSString *installedBy;
@property NSDate *installed;

- (instancetype)initWithDictionary:(NSDictionary *) dict;

@end



#endif /* WPA2EnterpriseProfile_h */
