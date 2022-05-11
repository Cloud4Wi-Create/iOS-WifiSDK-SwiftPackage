//
//  CustomerCreateResponse.h
//  Cloud4WiSDKWiFi
//

#ifndef CustomerCreateResponse_h
#define CustomerCreateResponse_h

@interface CustomerCreateResponse : NSObject

@property NSString *status;
@property NSString *generated;
@property NSString *id;
@property NSString *organizationId;
@property NSString *locationId;
@property NSString *hotspotId;
@property NSString *username;
@property NSString *password;
@property NSNumber *mailSent;

- (instancetype) initWithJSONString: (NSString *) jsonString
                              error: (NSError **) error;

@end


#endif /* CustomerCreateResponse_h */
